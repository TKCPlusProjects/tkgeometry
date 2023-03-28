//
//  line.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/line.hpp>

#include <vector>
#include <math.h>

using namespace std;
    
namespace tkht {

class Line::Impl {
    
public:
    
};

Line::~Line() = default;

Line::Line() : impl(new Line::Impl()) {
    Line(Vertex(), Vertex());
}

Line::Line(Vertex x, Vertex y) : impl(new Line::Impl()) {
    vector<Vertex> line{x, y};
    sort(line.begin(), line.end(), Vertex::les);
    o = line[0]; p = line[1];
    vertexs = {o, p};
    
    a = p.y - o.y;
    b = o.x - p.x;
    c = p.x * o.y - o.x * p.y;
}

bool Line::operator==(const Line& __v) {
    return (o == __v.o && p == __v.p);
}

Vertex Line::middle() {
    return Vertex((o.x + p.x)/2.0, (o.y + p.y)/2.0);
}

Vertex Line::intersection(Line line) {
    double x = (b * line.c - c * line.b) / (a * line.b - b * line.a);
    double y = location_y(x);
    return Vertex(x, y);
}

double Line::substitute(Vertex t) {
    return a * t.x + b * t.y + c;
}

double Line::location_x(double y) {
    double x;
    if (a == 0) {
        x = INFINITY;
    } else {
        x = - (c + b*y) / a;
    }
    return x;
}

double Line::location_y(double x) {
    double y;
    if (b == 0) {
        y = INFINITY;
    } else {
        y = - (c + a*x) / b;
    }
    return y;
}

}
