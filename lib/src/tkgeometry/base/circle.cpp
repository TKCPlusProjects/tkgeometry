//
//  circle.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/31.
//

#include <tkgeometry/base/circle.hpp>

using namespace std;

namespace tkht {

class Circle::Impl {
    
public:
    
};

Circle::Circle() : impl(new Circle::Impl()) {
    Circle(Vertex(), 0);
}

Circle::Circle(Vertex o, double r) : impl(new Circle::Impl()) {
    this->o = o;
    this->r = r;
}

Circle::Circle(Vertex left, Vertex mid, Vertex right) : impl(new Circle::Impl()) {
    double m = (mid.x * mid.x + mid.y * mid.y) - (left.x*left.x + left.y * left.y);
    double u = (right.x * right.x + right.y *right.y) - (left.x*left.x + left.y * left.y);
    double s = 0.5 / ((mid.x - left.x) * (right.y - left.y) - (mid.y - left.y) * (right.x - left.x));
    double ox = ((right.y - left.y) * m + (left.y - mid.y) * u) * s;
    double oy = ((left.x - right.x) * m + (mid.x - left.x) * u) * s;
    Vertex o = Vertex(ox, oy);
    double odx = left.x - ox;
    double ody = left.y - oy;
    double r = odx * odx + ody * ody;
    
    this->o = o;
    this->r = r;
}

bool Circle::contain(Vertex vertex) {
    return (vertex.x - o.x)*(vertex.x - o.x) + (vertex.y - o.y)*(vertex.y - o.y) < r;
}

}
