//
//  triangle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/vertex.hpp>
#include <tkgeometry/base/line.hpp>
#include <tkgeometry/base/circle.hpp>

using namespace std;

namespace tkht {

class Triangle : public FGG {
    
private:
    
    class Impl;
    Impl *impl;
    
public:

    Vertex o, p, q;
    TKArray<Vertex> vertexs;
    
    Line op, oq, pq;
    TKArray<Line> lines;
    
    Circle circumcircle;
    
    Triangle();
    Triangle(Vertex x, Vertex y, Vertex z);
    
    bool operator==(const Triangle& __v) const;
    bool operator!=(const Triangle& __v) const;
    
    bool contain_vertex(Vertex vertex);
    bool contain_line(Line line);
    bool conjoint(Triangle triangle);
};

}

#endif /* triangle_hpp */
