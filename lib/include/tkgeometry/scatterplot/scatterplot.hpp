//
//  scatterplot.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/9/1.
//

#ifndef scatterplot_hpp
#define scatterplot_hpp

#include <stdio.h>

#include <tkutils/tkutils.hpp>
#include <tkgeometry/base/rectangle.hpp>

using namespace std;

namespace tkht {

class Scatterplot {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    TKList<Vertex> vertex_list; //顶点列表

    ~Scatterplot();
    Scatterplot();
    Scatterplot(Rectangle canvas, int count);
};

}

#endif /* scatterplot_hpp */
