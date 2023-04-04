//
//  rectangle.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <tkgeometry/base/polygon.hpp>

using namespace std;

namespace tkht {

class Rectangle : public Polygon {

private:
  class Impl;
  Impl *impl;

public:
  Point o, p;
  double w, h;

  Rectangle(Point _x, Point _y);
  Rectangle(double _w, double _h);

  /// @brief 点是否在矩形内
  bool contain(Point point);

  /// @brief 矩形与直线的交点列表
  TKArray<Point> crosses(Line line);
};

} // namespace tkht

#endif /* rectangle_hpp */
