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

Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
    
    o = Vertex(0, 0); 
    p = Vertex(width, height);

    Polygon({o, Vertex(width, 0), p, Vertex(0, height)});
}

Rectangle::Rectangle(Vertex x, Vertex y) {
    TKArray<Vertex> points({x, y}, Vertex::les);
    o = points[0]; p = points[1];
    
    width = p.x - o.x;
    height = p.y - o.y;

    Polygon({o, Vertex(width, 0), p, Vertex(0, height)});
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
