//
//  rectangle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>

#include <tkgeometry/base/vertex.hpp>
#include <tkgeometry/base/line.hpp>

using namespace std;

namespace tkht {

class Rectangle {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    double width, height;
    Vertex o, p;
    
    ~Rectangle();
    Rectangle();
    Rectangle(double w, double h);
    Rectangle(Vertex x, Vertex y);
    
    bool contain(Vertex vertex);
    vector<Vertex> crosses(Line line);
};

}

#endif /* rectangle_hpp */