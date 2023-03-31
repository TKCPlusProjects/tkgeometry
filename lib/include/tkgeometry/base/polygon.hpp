//
//  polygon.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/25.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <stdio.h>
#include <vector>

#include <tkgeometry/base/vertex.hpp>
#include <tkgeometry/base/line.hpp>

using namespace std;

namespace tkht
{
  class Polygon
  {
  private:
    class Impl;
    Impl *impl;

  public:
    vector<Vertex> vertex_list;
    vector<Line> side_list;

    ~Polygon();
    Polygon();
    Polygon(vector<Vertex> point_list);

    void init(vector<Vertex> point_list);

    bool containment(Vertex point);
  };
}

#endif /* polygon_hpp */
