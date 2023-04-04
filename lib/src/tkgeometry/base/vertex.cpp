//
//  vertex.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#include <tkgeometry/base/vertex.hpp>

#include <stdlib.h>
#include <math.h>

using namespace std;

namespace tkht {

class Vertex::Impl {

public:
    
};

Vertex::Vertex() : FGG(), x(0), y(0) {
    
}

Vertex::Vertex(double x, double y) : FGG(), x(x), y(y) {

}

bool Vertex::operator==(const Vertex& __v) const {
    return abs(x - __v.x) < 0.01 && abs(y - __v.y) < 0.01;
}

bool Vertex::operator!=(const Vertex& __v) const {
    return abs(x - __v.x) > 0.01 && abs(y - __v.y) > 0.01;
}

double Vertex::operator*(const Vertex& __v) {
    return x * __v.y - __v.x * y;
}

bool Vertex::les (const Vertex& __v1, const Vertex& __v2) {
    return __v1.x == __v2.x ? __v1.y < __v2.y : __v1.x < __v2.x;
}

}
