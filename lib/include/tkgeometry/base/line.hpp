//
//  line.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef line_hpp
#define line_hpp

#include <stdio.h>

#include <tkutils/tkutils.hpp>
#include <tkgeometry/base/vertex.hpp>

using namespace std;

namespace tkht {

class Line {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    Vertex o, p;
    TKList<Vertex> vertexs;
    
    double a, b, c; // 函数式：ax + by + c = 0;
    
    ~Line();
    Line();
    Line(Vertex x, Vertex y);
    
    bool operator==(const Line& __v);
    
    double substitute(Vertex t);
    double location_x(double y);
    double location_y(double x);
    
    Vertex middle();
    Vertex intersection(Line line);
};

}

#endif /* line_hpp */
