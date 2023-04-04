//
//  triangle.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/triangle.hpp>

using namespace std;

namespace tkht {

class Triangle::Impl {
    
public:
    
};

Triangle::Triangle(Vertex x, Vertex y, Vertex z) {
    TKArray<Vertex> points({x, y, z}, Vertex::les);
    o = points[0]; p = points[1]; q = points[2];

    circumcircle = Circle(o, p, q);
    
    Polygon({o, p, q});
}

bool Triangle::operator==(const Triangle& __v) const {
    return (o == __v.o && p == __v.p && q == __v.q);
}

bool Triangle::operator!=(const Triangle& __v) const {
    return (o != __v.o || p != __v.p || q != __v.q);
}

bool Triangle::contain_vertex(Vertex vertex) {
    return vertex == o || vertex == p || vertex == q;
}

bool Triangle::contain_line(Line line) {
    return side_list.contain(line);
}

bool Triangle::conjoint(Triangle triangle) {
    return contain_vertex(triangle.o) || contain_vertex(triangle.p) || contain_vertex(triangle.q);
}

}

