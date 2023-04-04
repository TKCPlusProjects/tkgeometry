//
//  delaunay.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/19.
//

#ifndef delaunay_hpp
#define delaunay_hpp

#include <tkgeometry/base/rectangle.hpp>
#include <tkgeometry/base/triangle.hpp>

using namespace std;

using namespace std;

namespace tkht {

class Delaunay {

private:
  class Impl;
  Impl *impl;

public:
  /// @brief 三角形列表
  TKArray<Triangle> triangle_list;

  Delaunay(Rectangle canvas, TKArray<Point> vertex_list);
};

} // namespace tkht

#endif /* delaunay_hpp */
