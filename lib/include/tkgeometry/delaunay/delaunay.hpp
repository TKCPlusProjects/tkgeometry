//
//  delaunay.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/19.
//

#ifndef delaunay_hpp
#define delaunay_hpp

#include <tkgeometry/base/triangle.hpp>
#include <tkgeometry/base/rectangle.hpp>

using namespace std;

using namespace std;

namespace tkht {

class Delaunay {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    TKArray<Triangle> triangle_list; //三角形列表
    
    Delaunay(Rectangle canvas, TKArray<Vertex> vertex_list);
};

}

#endif /* delaunay_hpp */
