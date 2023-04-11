#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <tkgeometry/tkgeometry.hpp>

#include <iostream>
#include <random>

using namespace std;
using namespace tkht;

typedef CGAL::Exact_predicates_exact_constructions_kernel                     K;
typedef CGAL::Delaunay_triangulation_2<K>                                    DT;
typedef CGAL::Delaunay_triangulation_adaptation_traits_2<DT>                 AT;
typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2<DT> AP;
typedef CGAL::Voronoi_diagram_2<DT,AT,AP>                                    VD;

typedef AT::Site_2                    Site_2;
typedef AT::Point_2                   Point_2;
typedef VD::Locate_result             Locate_result;
typedef VD::Vertex_handle             Vertex_handle;
typedef VD::Face_handle               Face_handle;
typedef VD::Halfedge_handle           Halfedge_handle;
typedef VD::Ccb_halfedge_circulator   Ccb_halfedge_circulator;

int width, height = 0;

int margin = 50;

// 建立随机数生成器
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(0.5f, 1.0f);

void vertex2d(GLdouble x, GLdouble y) {
  glVertex2d((x + margin) / width * 2.0f - 1.0f,
             (y + margin) / height * 2.0f - 1.0f);
}

void drawVoronoi(GLFWwindow *window, double density) {
  int _width;
  int _height;
  glfwGetWindowSize(window, &_width, &_height);

  if (width == _width && height == _height) {

  } else {
    width = _width;
    height = _height;

    // 计算数据
    Rectangle canvas = Rectangle(width - 2 * margin, height - 2 * margin);
    Scatterplot scatterplot = Scatterplot(canvas, density);

    DT dt;
    for (Point point : scatterplot.vertex_list) {
      dt.insert(Point_2(point.x, point.y));
    }

    VD vd;
    for (Point point : scatterplot.vertex_list) {
      vd.insert(Point_2(point.x, point.y));
    }

    // 清空窗口
    glClear(GL_COLOR_BUFFER_BIT);

    // 绘制边框
    glColor3d(0.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    for (Point vertex : canvas.vertex_list) {
      vertex2d(vertex.x, vertex.y);
    }
    glEnd();

    //绘制三角形剖分图
    for (auto it = dt.finite_faces_begin(); it != dt.finite_faces_end(); it++)
    {
      glColor3d(0.6f, 0.8f, 0.9f);
      glLineWidth(5.0f);
      glBegin(GL_POLYGON);
      Point_2 o = it->vertex(0)->point();
      Point_2 p = it->vertex(1)->point();
      Point_2 q = it->vertex(2)->point();
      vertex2d(CGAL::to_double(o.x()), CGAL::to_double(o.y()));
      vertex2d(CGAL::to_double(p.x()), CGAL::to_double(p.y()));
      vertex2d(CGAL::to_double(q.x()), CGAL::to_double(q.y()));
      glEnd();
    }

    // 绘制维诺图单元格
    for (auto it = vd.bounded_faces_begin(); it != vd.bounded_faces_end(); it++)
    {
      list <Point_2> buffer;
      Halfedge_handle he = it->ccb();
      do {
        if (he->is_segment()) {
          Point_2 point = he->source()->point();
          double x = CGAL::to_double(point.x());
          double y = CGAL::to_double(point.y());
          if (x >= canvas.o.x && x <= canvas.p.x && y >= canvas.o.y && y <= canvas.p.y) {
            buffer.push_back(point);
          } else {
            buffer.clear();
            break;
          }
        }
        he = he->next();
      } while (he != it->ccb());
      if (buffer.size() > 0) {
        glColor3d(dis(gen), dis(gen), dis(gen));
        glLineWidth(5.0f);
        glBegin(GL_POLYGON);
        for (Point_2 point : buffer) {
          vertex2d(CGAL::to_double(point.x()), CGAL::to_double(point.y()));
        }
        glEnd();
      }
    }
    
    glfwSwapBuffers(window);
  }
}

int main() {
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CLIENT_API | GLFW_SRGB_CAPABLE, GLFW_NO_API);
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "tkgeometry demo", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  glClearColor(0.9f, 0.9f, 0.9f, 1.0f);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    drawVoronoi(window, 200);
  }

  glfwTerminate();

  return 0;
}
