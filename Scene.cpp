#include "Scene.h"

/********************
 * private:
 ********************/

void Scene::resize(int width, int height) {
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::display(void) {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1, 16, 16);
    glPopMatrix();

    glutSwapBuffers();
}

void Scene::idle(void) {
    glutPostRedisplay();
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

    glutReshapeFunc((void(*)(int, int)) &resize);
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

    glutReshapeFunc((void(*)(int, int)) &resize);
    glutDisplayFunc((void(*)()) &display);
    glutIdleFunc((void(*)()) &idle);
}

Scene::~Scene() { }

void Scene::loop() {
    glutMainLoop();
}
