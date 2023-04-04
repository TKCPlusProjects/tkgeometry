//
//  polygon.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/line.hpp>
#include <tkgeometry/base/point.hpp>

using namespace std;

namespace tkht {
class Polygon : public FGG {
private:
  class Impl;
  Impl *impl;

public:
  /// @brief 顶点列表
  TKArray<Point> vertex_list;
  /// @brief 边列表
  TKArray<Line> side_list;

  Polygon();
  Polygon(initializer_list<Point> vertex_list);

  bool operator==(const Polygon &__v) const;
  bool operator!=(const Polygon &__v) const;

  void push(Point vertex);
  void push(TKArray<Point> vertex_list);

  /// @brief 连接多边形的所有顶点，生成边数组
  void connect();
  /// @brief 点是否在多边形内
  bool contain(Point point);
};
} // namespace tkht

#endif /* polygon_hpp */
