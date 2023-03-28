//
//  triangle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <stdio.h>

#include <tkutils/tkutils.hpp>
#include <tkgeometry/base/vertex.hpp>
#include <tkgeometry/base/line.hpp>
#include <tkgeometry/base/circle.hpp>

using namespace std;

namespace tkht {

class Triangle {
    
private:
    
    class Impl;
    Impl *impl;
    
public:

    Vertex o, p, q;
    TKList<Vertex> vertexs;
    
    Line op, oq, pq;
    TKList<Line> lines;
    
    Circle circumcircle;
    
    ~Triangle();
    Triangle();
    Triangle(Vertex x, Vertex y, Vertex z);
    
    bool operator==(const Triangle& __v);
    bool operator!=(const Triangle& __v);
    
    bool contain_vertex(Vertex vertex);
    bool contain_line(Line line);
    bool conjoint(Triangle triangle);
};

}

#endif /* triangle_hpp */
