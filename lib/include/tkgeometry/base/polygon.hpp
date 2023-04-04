//
//  polygon.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <tkgeometry/base/fgg.hpp>
#include <tkgeometry/base/vertex.hpp>
#include <tkgeometry/base/line.hpp>

using namespace std;

namespace tkht
{
  class Polygon : public FGG
  {
  private:
    class Impl;
    Impl *impl;

  public:
    TKArray<Vertex> vertex_list;
    TKArray<Line> side_list;

    Polygon();
    Polygon(initializer_list<Vertex> point_list);

    bool operator==(const Polygon &__v) const;
    bool operator!=(const Polygon &__v) const;

    void push(Vertex point);
    void push(TKArray<Vertex> point_list);

    void connect();
    bool containment(Vertex point);
  };
}

#endif /* polygon_hpp */
