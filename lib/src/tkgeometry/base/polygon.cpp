//
//  polygon.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/base/polygon.hpp>

using namespace std;

namespace tkht {

class Polygon::Impl {

public:
};

Polygon::Polygon() : FGG() {}

Polygon::Polygon(initializer_list<Point> point_list)
    : FGG(), vertex_list(point_list) {
  connect();
}

bool Polygon::operator==(const Polygon &__v) const {
  bool equal = false;

  int size = vertex_list.size();
  int __size = __v.vertex_list.size();
  if (size != __size)
    return equal;

  equal = true;
  TKArray<Point> array = vertex_list.sorted(Point::les);
  TKArray<Point> __array = __v.vertex_list.sorted(Point::les);
  for (size_t i = 0; i < min(size, __size); i++) {
    equal &= array[i] == __array[i];
    if (!equal)
      break;
  }

  return equal;
}

bool Polygon::operator!=(const Polygon &__v) const { return !operator==(__v); }

void Polygon::push(Point vertex) { vertex_list += vertex; }

void Polygon::push(TKArray<Point> vertex_list) { vertex_list += vertex_list; }

void Polygon::connect() {
  side_list.clear();
  int vertex_count = vertex_list.size();
  for (int i = 0, j = vertex_count - 1; i < vertex_count; j = i++) {
    Line side = Line(vertex_list[i], vertex_list[j]);
    side_list.push(side);
  }
}

bool Polygon::contain(Point point) {
  bool inside = false;
  for (Line side : side_list) {
    if (((side.o.y > point.y) != (side.p.y > point.y)) &&
        (point.x <
         ((side.p.x - side.o.x) * (point.y - side.o.y) / (side.p.y - side.o.y) +
          side.o.x))) {
      inside = !inside;
    }
  }
  return inside;
}
} // namespace tkht
