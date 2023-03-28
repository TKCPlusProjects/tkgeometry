//
//  circle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/31.
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>

#include <tkgeometry/base/vertex.hpp>

using namespace std;

namespace tkht {

class Circle {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    Vertex o;
    double r;
    
    ~Circle();
    Circle();
    Circle(Vertex o, double r);
    Circle(Vertex left, Vertex mid, Vertex right);
    
    bool contain(Vertex vertex);
};

}

#endif /* circle_hpp */
