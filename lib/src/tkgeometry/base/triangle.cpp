//
//  triangle.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/triangle.hpp>

using namespace std;

namespace tkht {

class Triangle::Impl {

public:
};

Triangle::Triangle(Point _o, Point _p, Point _q) : Polygon({_o, _p, _q}) {
  o = _o;
  p = _p;
  q = _q;

  cc = Circle(o, p, q);
}

bool Triangle::contain_vertex(Point vertex) {
  return vertex == o || vertex == p || vertex == q;
}

bool Triangle::contain_line(Line line) { return side_list.contain(line); }

bool Triangle::conjoint(Triangle triangle) {
  return contain_vertex(triangle.o) || contain_vertex(triangle.p) ||
         contain_vertex(triangle.q);
}

} // namespace tkht
