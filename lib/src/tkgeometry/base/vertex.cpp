//
//  vertex.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/vertex.hpp>

#include <stdlib.h>

using namespace std;

namespace tkht {

class Vertex::Impl {

public:
    
};

Vertex::~Vertex() = default;

Vertex::Vertex() : impl(new Vertex::Impl()) {
    Vertex(0, 0);
}

Vertex::Vertex(double x, double y) : impl(new Vertex::Impl()) {
    this->x = x;
    this->y = y;
}

bool Vertex::operator==(const Vertex& __v) {
    return abs(x - __v.x) < 0.01 && abs(y - __v.y) < 0.01;
}

bool Vertex::operator!=(const Vertex& __v) {
    return abs(x - __v.x) > 0.01 && abs(y - __v.y) > 0.01;
}

double Vertex::operator*(const Vertex& __v) {
    return x * __v.y - __v.x * y;
}

bool Vertex::les (const Vertex& __v1, const Vertex& __v2) {
    return __v1.x == __v2.x ? __v1.y < __v2.y : __v1.x < __v2.x;
}

}
