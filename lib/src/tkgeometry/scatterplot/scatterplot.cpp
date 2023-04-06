//
//  scatterplot.cpp
//  tkgeometry
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

Scatterplot::Scatterplot(Rectangle canvas, double density) {
  double density_scale = sqrt(canvas.w * canvas.h / density);
  // 水平分布数量和间隔
  size_t density_h = floor(canvas.w / density_scale);
  double space_h = canvas.w / density_h;
  // 垂直分布数量和间隔
  size_t density_v = floor(canvas.h / density_scale);
  double space_v = canvas.h / density_v;

  for (size_t space_x = 0; space_x < density_h; space_x++) {
    for (size_t space_y = 0; space_y < density_v; space_y++) {
      double x = fmod(rand(), space_h) + space_x * space_h;
      double y = fmod(rand(), space_v) + space_y * space_v;
      vertex_list.push(Point(x, y));
    }
  }
}

} // namespace tkht
