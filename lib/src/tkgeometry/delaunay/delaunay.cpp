//
//  delaunay.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/19.
//

#include <tkgeometry/delaunay/delaunay.hpp>

using namespace std;

namespace tkht {

class Delaunay::Impl {

public:
};

Delaunay::Delaunay(Rectangle canvas, TKArray<Point> vertex_list) {
  // 超级三角形生成
  Triangle triangle_super = Triangle(
      Point(-(canvas.w / 2.0), 0), Point(+(canvas.w + canvas.w / 2.0), 0),
      Point(+(canvas.w / 2.0), (canvas.h) * 2.0));
  triangle_list.push(triangle_super);

  // 遍历顶点
  for (Point vertex : vertex_list) {
    // 目标三角形：不符合空圆特性（外接圆包含目标定点）的三角形
    // 记录目标三角形
    TKArray<Triangle> triangle_list_in_circle;
    for (Triangle triangle : triangle_list) {
      if (triangle.cc.contain(vertex)) {
        triangle_list_in_circle.push(triangle);
      }
    }
    // 移除目标三角形
    triangle_list -= triangle_list_in_circle;

    // 保留目标三角形的非重复边
    TKArray<Line> line_list;
    for (Triangle triangle : triangle_list_in_circle) {
      for (Line line : triangle.side_list) {
        line_list.push_diff(line);
      }
    }

    // 添加点和非重复边构成的三角形
    for (Line line : line_list)
      triangle_list.push(Triangle(vertex, line.o, line.p));
  }

  // 初始三角形及其相连三角形移除
  TKArray<Triangle> triangle_list_conjoint_super;
  for (Triangle triangle : triangle_list) {
    if (triangle.conjoint(triangle_super)) {
      triangle_list_conjoint_super.push(triangle);
    }
  }
  triangle_list -= triangle_list_conjoint_super;
}

} // namespace tkht
