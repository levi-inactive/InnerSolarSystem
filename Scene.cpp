#include "Scene.h"

#include "Sphere.h"

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
    Math3D model;

    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glFlush();

    model.push();
        glColor3f(1.0, 0.5, 0.0);
        Sphere sun(&model);
        sun.draw();

        model.push();
            model.translate(2, 0, 0);
            model.scale(0.4, 0.4, 0.4);
            glColor3f(1.0, 0.5, 0.5);
            Sphere mercury(&model);
            mercury.draw();
        model.pop();

        model.push();
            model.translate(3, 0, 0);
            model.scale(0.4, 0.4, 0.4);
            glColor3f(1.0, 1.0, 0.5);
            Sphere venus(&model);
            venus.draw();
        model.pop();

        model.push();
            model.translate(4, 0, 0);
            model.scale(0.5, 0.5, 0.5);
            glColor3f(0.0, 0.2, 1.0);
            Sphere earth(&model);
            earth.draw();

            model.push();
                model.translate(1, 0, 0);
                model.scale(0.5, 0.5, 0.5);
                glColor3f(1.0, 1.0, 1.0);
                Sphere moon(&model);
                moon.draw();
            model.pop();
        model.pop();

    model.pop();

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
