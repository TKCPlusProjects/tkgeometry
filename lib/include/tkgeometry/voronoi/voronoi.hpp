//
//  voronoi.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef voronoi_hpp
#define voronoi_hpp

#include <tkgeometry/base/line.hpp>
#include <tkgeometry/base/triangle.hpp>
#include <tkgeometry/base/rectangle.hpp>

using namespace std;

namespace tkht {

class Voronoi {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    TKArray<Line> line_list; //外心连线列表
    
    ~Voronoi();
    Voronoi();
    Voronoi(Rectangle canvas, TKArray<Triangle> triangle_list);
};

}

#endif /* voronoi_hpp */
