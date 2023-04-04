//
//  circle.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2022/8/31.
//

#ifndef circle_hpp
#define circle_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/point.hpp>

using namespace std;

namespace tkht {

class Circle : public FGG {

private:
  class Impl;
  Impl *impl;

public:
  /// @brief 圆心
  Point o;
  /// @brief 半径
  double r;

  Circle();
  Circle(Point o, double r);
  Circle(Point left, Point mid, Point right);

  /// @brief 点是否在圆内
  bool contain(Point point);
};

} // namespace tkht

#endif /* circle_hpp */
