//
//  triangle.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <tkgeometry/base/polygon.hpp>
#include <tkgeometry/base/circle.hpp>

using namespace std;

namespace tkht {

class Triangle : public Polygon {
    
private:
    
    class Impl;
    Impl *impl;
    
public:

    Vertex o, p, q;
    /// @brief 外接圆
    Circle cc;
    
    Triangle(Vertex _o, Vertex _p, Vertex _q);
    
    bool contain_vertex(Vertex vertex);
    bool contain_line(Line line);
    bool conjoint(Triangle triangle);
};

}

#endif /* triangle_hpp */
