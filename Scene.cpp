#include "Scene.h"

#include "Sphere.h"
#include "Pyramid.h"

/********************
 * private:
 ********************/

void Scene::init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glClearColor(0, 0, 0, 0);
}

void Scene::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glFlush();

    /*Sphere sphere;
    sphere.draw();*/

    Pyramid pyramid;
    pyramid.draw();

    glutSwapBuffers();
}

void Scene::idle() {
    glutPostRedisplay();
}

void Scene::drawAxis() {
    // X axis in red.
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(-3.0,0.0,0.0);
        glVertex3f(3.0,0.0,0.0);
    glEnd();

    // Y axis in green.
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,-3.0,0.0);
        glVertex3f(0.0,3.0,0.0);
    glEnd();

    // Z axis in yellow.
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,-3.0);
        glVertex3f(0.0,0.0,3.0);
    glEnd();
}

/********************
 * public:
 ********************/

Scene::Scene() {
    int argc = 0;
    char* argv[] = {};

    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(windowX, windowY);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow(windowTitle);

    init();

    glutDisplayFunc((void(*)()) &display);
    glutIdleFunc((void(*)()) &idle);
}

Scene::Scene(int width, int height, int x, int y, char* title) {
    int argc = 0;
    char* argv[] = {};

    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x, y);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow(title);

    init();

    glutDisplayFunc((void(*)()) &display);
    glutIdleFunc((void(*)()) &idle);
}

Scene::~Scene() { }

void Scene::loop() {
    glutMainLoop();
}
