//
//  voronoi.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/voronoi/voronoi.hpp>

#include <vector>

using namespace std;

namespace tkht {

class Voronoi::Impl {
    
public:
    
};

Voronoi::~Voronoi() = default;

Voronoi::Voronoi() {
    Voronoi(Rectangle(), {});
}

Voronoi::Voronoi(Rectangle canvas, TKList<Triangle> triangle_list) {
    //寻找外心连接线
    for (Triangle triangle_origin : triangle_list) {
        for (Line line : triangle_origin.lines) {
            //选择三角形的一边，寻找共边三角形
            TKList<Line> line_coterminal;
            for (Triangle triangle : triangle_list) {
                if (triangle == triangle_origin) continue;
                if (triangle.contain_line(line)) {
                    line_coterminal.push_back(Line(triangle_origin.circumcircle.o, triangle.circumcircle.o));
                    break;
                }
            }
            
            if (line_coterminal.size() > 0) {
                line_list += line_coterminal;
            } else if (canvas.contain(triangle_origin.circumcircle.o)) {
                //若三角形外心在画布内，从外心向画布边缘方向做边的垂线
                
                //计算画布边缘 和 外心和边中点构成直线 的交点
                vector<Vertex> crosses = canvas.crosses(Line(triangle_origin.circumcircle.o, line.middle()));
                if (crosses.size() == 2) {
                    Vertex v1 = crosses[0];
                    Vertex v2 = crosses[1];
                    
                    //选择交点，该交点和三角形另一顶点在边的异侧，连线外心和交点
                    TKList<Vertex> v = triangle_origin.vertexs - line.vertexs;
                    if (line.substitute(v.front()) * line.substitute(v1) < 0) {
                        line_list += Line(triangle_origin.circumcircle.o, v1);
                    } else {
                        line_list += Line(triangle_origin.circumcircle.o, v2);
                    }
                }
            }
        }
    }
}

}
