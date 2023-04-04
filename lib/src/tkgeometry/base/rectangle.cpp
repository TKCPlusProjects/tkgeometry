//
//  rectangle.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/base/rectangle.hpp>

using namespace std;

namespace tkht {

class Rectangle::Impl {
    
public:
    
};

Rectangle::Rectangle(double _w, double _h) : Polygon({Vertex(0, 0), Vertex(_w, 0), Vertex(_w, _h), Vertex(0, _h)}) {
    w = _w;
    h = _h;
    
    o = vertex_list[0]; 
    p = vertex_list[2];
}

Rectangle::Rectangle(Vertex _o, Vertex _p) : Polygon({_o, Vertex(_o.x, _p.y), _p, Vertex(_p.x, _o.y)}) {
    o = _o; 
    p = _p;
    
    w = p.x - o.x;
    h = p.y - o.y;
}

bool Rectangle::contain(Vertex vertex) {
    return vertex.x >= o.x && vertex.x <= p.x && vertex.y >= o.y && vertex.y <= p.y;
}

TKArray<Vertex> Rectangle::crosses(Line line) {
    TKArray<Vertex> crosses;
    double x, y;
    
    x = o.x; y = line.location_y(x);
    if (y >= o.y && y <= p.y) crosses.push(Vertex(x, y));
    
    x = p.x; y = line.location_y(x);
    if (y >= o.y && y <= p.y) crosses.push(Vertex(x, y));
    
    y = o.y; x = line.location_x(y);
    if (x >= o.x && x <= p.x) crosses.push(Vertex(x, y));
    
    y = p.y; x = line.location_x(y);
    if (x >= o.x && x <= p.x) crosses.push(Vertex(x, y));
    
    return crosses;
}

}
