//
//  rectangle.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/base/rectangle.hpp>

#include <vector>

using namespace std;

namespace tkht {

class Rectangle::Impl {
    
public:
    
};

Rectangle::~Rectangle() = default;

Rectangle::Rectangle() : impl(new Rectangle::Impl()) {
    Rectangle(Vertex(), Vertex());
}

Rectangle::Rectangle(double w, double h) : impl(new Rectangle::Impl()) {
    width = w;
    height = h;
    
    o = Vertex(0, 0);
    p = Vertex(w, h);
}

Rectangle::Rectangle(Vertex x, Vertex y) : impl(new Rectangle::Impl()) {
    vector<Vertex> line{x, y};
    sort(line.begin(), line.end(), Vertex::les);
    o = line[0]; p = line[1];
    
    width = p.x - o.x;
    height = p.y - o.y;
}

bool Rectangle::contain(Vertex vertex) {
    return vertex.x >= o.x && vertex.x <= p.x && vertex.y >= o.y && vertex.y <= p.y;
}

vector<Vertex> Rectangle::crosses(Line line) {
    vector<Vertex> crosses;
    double x, y;
    
    x = o.x; y = line.location_y(x);
    if (y >= o.y && y <= p.y) crosses.push_back(Vertex(x, y));
    
    x = p.x; y = line.location_y(x);
    if (y >= o.y && y <= p.y) crosses.push_back(Vertex(x, y));
    
    y = o.y; x = line.location_x(y);
    if (x >= o.x && x <= p.x) crosses.push_back(Vertex(x, y));
    
    y = p.y; x = line.location_x(y);
    if (x >= o.x && x <= p.x) crosses.push_back(Vertex(x, y));
    
    return crosses;
}

}
