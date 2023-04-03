//
//  line.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef line_hpp
#define line_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/vertex.hpp>

using namespace std;

namespace tkht {

class Line : public FGG {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    Vertex o, p;
    TKArray<Vertex> vertexs;
    
    double a, b, c; // 函数式：ax + by + c = 0;
    
    Line();
    Line(Vertex x, Vertex y);
    
    bool operator==(const Line& __v) const;
    
    Vertex middle();

    double substitute(Vertex t);
    double location_x(double y);
    double location_y(double x);
    Vertex intersection(Line line);
};

}

#endif /* line_hpp */
