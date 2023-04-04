//
//  triangle.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <tkgeometry/base/circle.hpp>
#include <tkgeometry/base/polygon.hpp>

using namespace std;

namespace tkht {

class Triangle : public Polygon {

private:
  class Impl;
  Impl *impl;

public:
  Point o, p, q;
  /// @brief 外接圆
  Circle cc;

  Triangle(Point _o, Point _p, Point _q);

  /// @brief 目标顶点是否在三角形顶点列表中
  bool contain_vertex(Point vertex);
  /// @brief 目标边是否在三角形边列表中
  bool contain_line(Line line);
  /// @brief 目标三角形是否与三角形共边
  bool conjoint(Triangle triangle);
};

} // namespace tkht

#endif /* triangle_hpp */
