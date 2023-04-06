//
//  scatterplot.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/9/1.
//

#ifndef scatterplot_hpp
#define scatterplot_hpp

#include <tkgeometry/base/rectangle.hpp>

using namespace std;

namespace tkht {

class Scatterplot {

private:
  class Impl;
  Impl *impl;

public:
  /// @brief 顶点列表
  TKArray<Point> vertex_list;

  Scatterplot(Rectangle canvas, double density);
};

} // namespace tkht

#endif /* scatterplot_hpp */
