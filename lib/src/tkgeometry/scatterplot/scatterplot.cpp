//
//  scatterplot.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/9/1.
//

#include <tkgeometry/scatterplot/scatterplot.hpp>

#include <math.h>

using namespace std;

namespace tkht {

class Scatterplot::Impl {

public:

};

Scatterplot::~Scatterplot() = default;

Scatterplot::Scatterplot() {
    Scatterplot(Rectangle(), 0);
}

Scatterplot::Scatterplot(Rectangle canvas, int count) {
    double density_scale = sqrt(canvas.width * canvas.height / count);
    //水平分布数量和间隔
    int density_h = floor(canvas.width / density_scale);
    double space_h = canvas.width / density_h;
    //垂直分布数量和间隔
    int density_v = floor(canvas.height / density_scale);
    double space_v = canvas.height / density_v;
    
    for (int space_x = 0; space_x < density_h; space_x ++) {
        for (int space_y = 0; space_y < density_v; space_y ++) {
            int x = fmod(rand(), space_h)+space_x*space_h;
            int y = fmod(rand(), space_v)+space_y*space_v;
            vertex_list.push(Vertex(x, y));
        }
    }
}

}
