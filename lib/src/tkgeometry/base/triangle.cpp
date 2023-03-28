//
//  triangle.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/triangle.hpp>

#include <vector>

using namespace std;

namespace tkht {

class Triangle::Impl {
    
public:
    
};

Triangle::~Triangle() = default;

Triangle::Triangle() : impl(new Triangle::Impl())  {
    Triangle(Vertex(), Vertex(), Vertex());
}

Triangle::Triangle(Vertex x, Vertex y, Vertex z) : impl(new Triangle::Impl()) {
    vector<Vertex> line{x, y, z};
    sort(line.begin(), line.end(), Vertex::les);
    o = line[0]; p = line[1]; q = line[2];
    vertexs = {o, p, q};
    
    op = Line(o, p);oq = Line(o, q);pq = Line(p, q);
    lines = {Line(o, p), Line(o, q), Line(p, q)};
    
    circumcircle = Circle(o, p, q);
}

bool Triangle::operator==(const Triangle& __v) {
    return (o == __v.o && p == __v.p && q == __v.q);
}

bool Triangle::operator!=(const Triangle& __v) {
    return (o != __v.o || p != __v.p || q != __v.q);
}

bool Triangle::contain_vertex(Vertex vertex) {
    return vertex == o || vertex == p || vertex == q;
}

bool Triangle::contain_line(Line line) {
    return lines.contain(line);
}

bool Triangle::conjoint(Triangle triangle) {
    return contain_vertex(triangle.o) || contain_vertex(triangle.p) || contain_vertex(triangle.q);
}

}

