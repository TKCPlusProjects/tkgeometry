//
//  vertex.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef vertex_hpp
#define vertex_hpp

#include <tkgeometry/base/fgg.hpp>

using namespace std;

namespace tkht {

class Vertex : public FGG {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    double x;
    double y;
    
    Vertex();
    Vertex(double x, double y);
    
    bool operator==(const Vertex& __v) const;;
    bool operator!=(const Vertex& __v) const;
    double operator*(const Vertex& __v);

    static bool les (const Vertex& __v1, const Vertex& __v2);
};

}

#endif /* vertex_hpp */
