//
//  point.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef vertex_hpp
#define vertex_hpp

#include <tkgeometry/base/fgg.hpp>

using namespace std;

namespace tkht {

class Point : public FGG {

private:
  class Impl;
  Impl *impl;

public:
  double x, y;

  Point();
  Point(double x, double y);

  bool operator==(const Point &__v) const;
  ;
  bool operator!=(const Point &__v) const;
  double operator*(const Point &__v);

  /// @brief 排序算法，从左到右，从下到上
  static bool les(const Point &__v1, const Point &__v2);
};

} // namespace tkht

#endif /* vertex_hpp */
