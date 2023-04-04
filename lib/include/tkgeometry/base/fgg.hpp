//
//  fgg.hpp
//  tkgeometry
//
//  Created by ZhengXianda on 2023/4/3.
//

#ifndef shape_hpp
#define shape_hpp

#include <tkutils/tkutils.hpp>

#include <stdio.h>

using namespace std;

namespace tkht
{

  class FGG
  {

  private:
    class Impl;
    Impl *impl;

  public:
    ~FGG();
    FGG();

    bool operator==(const FGG &__v) const;
    bool operator!=(const FGG &__v) const;
    bool operator<(const FGG &__v) const;
  };
}

#endif /* shape_hpp */
