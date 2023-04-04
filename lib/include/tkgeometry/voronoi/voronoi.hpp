//
//  voronoi.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef voronoi_hpp
#define voronoi_hpp

#include <tkgeometry/base/line.hpp>
#include <tkgeometry/base/rectangle.hpp>
#include <tkgeometry/base/triangle.hpp>

using namespace std;

namespace tkht {

class Voronoi {

private:
  class Impl;
  Impl *impl;

public:
  /// @brief 外心连线列表
  TKArray<Line> line_list; 

  Voronoi(Rectangle canvas, TKArray<Triangle> triangle_list);
};

} // namespace tkht

#endif /* voronoi_hpp */
