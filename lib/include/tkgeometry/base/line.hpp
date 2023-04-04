//
//  line.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef line_hpp
#define line_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/point.hpp>

using namespace std;

namespace tkht {

class Line : public FGG {

private:
  class Impl;
  Impl *impl;

public:
  Point o, p;
  TKArray<Point> vertexs;

  double a, b, c; // 函数式：ax + by + c = 0;

  Line(Point x, Point y);

  bool operator==(const Line &__v) const;

  /// @brief 线段中点坐标
  Point middle();

  /// @brief 当前直线和指定点的方位，点在直线上方>0，点在直线=0，点在直线下方<0
  double substitute(Point t);
  /// @brief 当前直线指定y值处的x值
  double location_x(double y);
  /// @brief 当前直线指定x值处的y值
  double location_y(double x);
  /// @brief 当前直线和目标直线的交点
  Point intersection(Line line);
};

} // namespace tkht

#endif /* line_hpp */
