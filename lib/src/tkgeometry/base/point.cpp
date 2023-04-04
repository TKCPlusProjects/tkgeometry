//
//  vertex.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/point.hpp>

#include <math.h>
#include <stdlib.h>

using namespace std;

namespace tkht {

class Point::Impl {

public:
};

Point::Point() : FGG(), x(0), y(0) {}

Point::Point(double x, double y) : FGG(), x(x), y(y) {}

bool Point::operator==(const Point &__v) const {
  return abs(x - __v.x) < 0.01 && abs(y - __v.y) < 0.01;
}

bool Point::operator!=(const Point &__v) const {
  return abs(x - __v.x) > 0.01 && abs(y - __v.y) > 0.01;
}

double Point::operator*(const Point &__v) { return x * __v.y - __v.x * y; }

bool Point::les(const Point &__v1, const Point &__v2) {
  return __v1.x == __v2.x ? __v1.y < __v2.y : __v1.x < __v2.x;
}

} // namespace tkht
