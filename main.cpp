/*
 * GLUT Partial Proyect 2
 *
 * Written by Leví Carbellido and Julio Badillo 2020
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "Scene.h"

int main(int argc, char *argv[])
{
    Scene scene;
    scene.loop();

    return EXIT_SUCCESS;
}
