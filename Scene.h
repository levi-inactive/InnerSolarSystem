#ifndef Scene_h
#define Scene_h

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Scene {
private:
    int windowWidth=640, windowHeight=480;
    int windowX=10, windowY=10;
    char* windowTitle="Proyecto Parcial 2";

    void resize(int, int);
    void display(void);
    void idle(void);
public:
    Scene();
    Scene(int, int, int, int, char*);
    ~Scene();

    void setWindowSize(int, int);
    void setWindowPosition(int, int);

    void loop();
};

#endif // Scene_h
