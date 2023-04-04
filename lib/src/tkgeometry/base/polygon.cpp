//
//  polygon.cpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#include <tkgeometry/base/polygon.hpp>

using namespace std;

namespace tkht
{

  class Polygon::Impl
  {

  public:
  };

  Polygon::Polygon() : FGG()
  {
  }

  Polygon::Polygon(initializer_list<Vertex> point_list) : FGG(), vertex_list(point_list)
  {
    connect();
  }

  void Polygon::push(Vertex point)
  {
    vertex_list += point;
  }

  void Polygon::push(TKArray<Vertex> point_list)
  {
    vertex_list += point_list;
  }

  void Polygon::connect()
  {
    side_list.clear();
    int vertex_count = vertex_list.size();
    for (int i = 0, j = vertex_count - 1; i < vertex_count; j = i++)
    {
      Line side = Line(vertex_list[i], vertex_list[j]);
      side_list.push(side);
    }
  }

  bool Polygon::containment(Vertex point)
  {
    bool inside = false;
    for (Line side : side_list)
    {
      if (((side.o.y > point.y) != (side.p.y > point.y)) &&
          (point.x < ((side.p.x - side.o.x) * (point.y - side.o.y) / (side.p.y - side.o.y) + side.o.x)))
      {
        inside = !inside;
      }
    }
    return inside;
  }
}
