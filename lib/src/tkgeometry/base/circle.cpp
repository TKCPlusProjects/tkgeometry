//
//  circle.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/31.
//

#include <tkgeometry/base/circle.hpp>

using namespace std;

namespace tkht {

class Circle::Impl {

public:
};

Circle::Circle() : FGG() { Circle(Point(), 0); }

Circle::Circle(Point o, double r) : FGG() {
  this->o = o;
  this->r = r;
}

Circle::Circle(Point left, Point mid, Point right) : FGG() {
  double m =
      (mid.x * mid.x + mid.y * mid.y) - (left.x * left.x + left.y * left.y);
  double u = (right.x * right.x + right.y * right.y) -
             (left.x * left.x + left.y * left.y);
  double s = 0.5 / ((mid.x - left.x) * (right.y - left.y) -
                    (mid.y - left.y) * (right.x - left.x));
  double ox = ((right.y - left.y) * m + (left.y - mid.y) * u) * s;
  double oy = ((left.x - right.x) * m + (mid.x - left.x) * u) * s;
  Point o = Point(ox, oy);
  double odx = left.x - ox;
  double ody = left.y - oy;
  double r = odx * odx + ody * ody;

  this->o = o;
  this->r = r;
}

bool Circle::contain(Point point) {
  return (point.x - o.x) * (point.x - o.x) + (point.y - o.y) * (point.y - o.y) <
         r;
}

} // namespace tkht
