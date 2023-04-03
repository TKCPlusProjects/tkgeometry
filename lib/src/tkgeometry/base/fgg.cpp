//
//  line.cpp
//  tkgeometry
//
//  Created by ZhengXianda on 2023/4/3.
//

#include <tkgeometry/base/fgg.hpp>

using namespace std;

namespace tkht
{

  class FGG::Impl
  {
  };

  FGG::~FGG() = default;
  FGG::FGG() = default;

  bool FGG::operator==(const FGG &__v) const
  {
    return false;
  }

  bool FGG::operator<(const FGG &__v) const
  {
    return true;
  }
}
