//
//  vertex.hpp
//  TKVoronoi
//
//  Created by ZhengXianda on 2022/8/22.
//

#ifndef vertex_hpp
#define vertex_hpp

#include <stdio.h>

using namespace std;

namespace tkht {

class Vertex {
    
private:
    
    class Impl;
    Impl *impl;
    
public:
    
    double x;
    double y;
    
    ~Vertex();
    Vertex();
    Vertex(double x, double y);
    
    bool operator==(const Vertex& __v);
    bool operator!=(const Vertex& __v);
    double operator*(const Vertex& __v);
    
    static bool les (const Vertex& __v1, const Vertex& __v2);
};

}

#endif /* vertex_hpp */
