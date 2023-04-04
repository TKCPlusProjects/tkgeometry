//
//  rectangle.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/base/rectangle.hpp>

using namespace std;

namespace tkht {

class Rectangle::Impl {

public:
};

Rectangle::Rectangle(Point _o, Point _p)
    : Polygon({_o, Point(_o.x, _p.y), _p, Point(_p.x, _o.y)}) {
  o = _o;
  p = _p;

  w = p.x - o.x;
  h = p.y - o.y;
}

Rectangle::Rectangle(double _w, double _h)
    : Polygon({Point(0, 0), Point(_w, 0), Point(_w, _h), Point(0, _h)}) {
  w = _w;
  h = _h;

  o = vertex_list[0];
  p = vertex_list[2];
}

bool Rectangle::contain(Point point) {
  return point.x >= o.x && point.x <= p.x && point.y >= o.y && point.y <= p.y;
}

TKArray<Point> Rectangle::crosses(Line line) {
  TKArray<Point> crosses;
  double x, y;

  x = o.x;
  y = line.location_y(x);
  if (y >= o.y && y <= p.y)
    crosses.push(Point(x, y));

  x = p.x;
  y = line.location_y(x);
  if (y >= o.y && y <= p.y)
    crosses.push(Point(x, y));

  y = o.y;
  x = line.location_x(y);
  if (x >= o.x && x <= p.x)
    crosses.push(Point(x, y));

  y = p.y;
  x = line.location_x(y);
  if (x >= o.x && x <= p.x)
    crosses.push(Point(x, y));

  return crosses;
}

} // namespace tkht
