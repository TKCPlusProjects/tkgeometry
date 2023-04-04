//
//  rectangle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <tkgeometry/base/polygon.hpp>

using namespace std;

namespace tkht {

class Rectangle : public Polygon {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    double width, height;
    Vertex o, p;
    
    Rectangle(double w, double h);
    Rectangle(Vertex x, Vertex y);
    
    bool contain(Vertex vertex);
    TKArray<Vertex> crosses(Line line);
};

}

#endif /* rectangle_hpp */
