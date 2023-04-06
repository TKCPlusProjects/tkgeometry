#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <tkgeometry/tkgeometry.hpp>

#include <iostream>

using namespace std;
using namespace tkht;

int width, height = 0;

int margin = 50;

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
    Delaunay delaunay = Delaunay(canvas, scatterplot.vertex_list);
    Voronoi voronoi = Voronoi(canvas, delaunay.triangle_list);

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

    // 绘制顶点
    glColor3d(0.0f, 1.0f, 0.0f);
    glPointSize(15.0f);
    glBegin(GL_POINTS);
    for (Point vertex : scatterplot.vertex_list) {
      vertex2d(vertex.x, vertex.y);
    }
    glEnd();

    // 绘制三角形
    for (Triangle triangle : delaunay.triangle_list) {
      glColor3d(0.0f, 1.0f, 0.0f);
      glLineWidth(5.0f);
      glBegin(GL_LINE_LOOP);
      vertex2d(triangle.o.x, triangle.o.y);
      vertex2d(triangle.p.x, triangle.p.y);
      vertex2d(triangle.q.x, triangle.q.y);
      glEnd();
    }

    // 绘制三角形外心连线
    glColor3d(1.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    for (Line line : voronoi.line_list) {
      vertex2d(line.o.x, line.o.y);
      vertex2d(line.p.x, line.p.y);
    }
    glEnd();

    glfwSwapBuffers(window);
  }
}

void drawPolygon(GLFWwindow *window) {
  int _width;
  int _height;
  glfwGetWindowSize(window, &_width, &_height);

  if (width == _width && height == _height) {

  } else {
    width = _width;
    height = _height;

    // 计算数据
    Polygon polygon{
        Point(0.0f, 0.0f),
        Point(width - 2 * margin, 0.0f),
        Point(width - 2 * margin, height - 2 * margin),
        Point(0.0f, height - 2 * margin),
    };

    // 清空窗口
    glClear(GL_COLOR_BUFFER_BIT);

    // 绘制边框
    glColor3d(0.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    for (Point vertex : polygon.vertex_list) {
      vertex2d(vertex.x, vertex.y);
    }
    glEnd();

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

    drawVoronoi(window, 50);
    // drawPolygon(window);
  }

  glfwTerminate();

  return 0;
}
