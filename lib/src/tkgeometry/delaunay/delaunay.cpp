//
//  delaunay.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/19.
//

#include <tkgeometry/delaunay/delaunay.hpp>

using namespace std;

namespace tkht {

class Delaunay::Impl {
    
public:
    
};

Delaunay::~Delaunay() = default;

Delaunay::Delaunay() {
    Delaunay(Rectangle(), {});
}

Delaunay::Delaunay(Rectangle canvas, TKList<Vertex> vertex_list) {
    //超级三角形生成
    Triangle triangle_super = Triangle(Vertex(-(canvas.width/2.0 ), 0),
                                       Vertex(+(canvas.width + canvas.width/2.0), 0),
                                       Vertex(+(canvas.width/2.0), (canvas.height)*2.0));
    triangle_list.push_back(triangle_super);
    
    //遍历顶点
    for (Vertex vertex : vertex_list) {
        //目标三角形：不符合空圆特性（外接圆包含目标定点）的三角形
        //记录目标三角形
        TKList<Triangle> triangle_list_in_circle;
        for (Triangle triangle : triangle_list) {
            if (triangle.circumcircle.contain(vertex)) {
                triangle_list_in_circle.push_back(triangle);
            }
        }
        //移除目标三角形
        triangle_list -= triangle_list_in_circle;
        
        //保留目标三角形的非重复边
        TKList<Line> line_list;
        for (Triangle triangle : triangle_list_in_circle) {
            for (Line line : triangle.lines ) {
                line_list <<= line;
            }
        }
        //添加点和非重复边构成的三角形
        for (Line line : line_list) triangle_list.push_back(Triangle(vertex, line.o, line.p));
    }
    
    //初始三角形及其相连三角形移除
    TKList<Triangle> triangle_list_conjoint_super;
    for (Triangle triangle : triangle_list) {
        if (triangle.conjoint(triangle_super)) {
            triangle_list_conjoint_super.push_back(triangle);
        }
    }
    triangle_list -= triangle_list_conjoint_super;
}

}

