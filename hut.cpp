#include <GL/freeglut.h>
#include <GL/freeglut_std.h>

void drawTriangle() {
    float triangleY = 1.0;
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 1.0 + triangleY);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -1.0 + triangleY);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -1.0 + triangleY);
    glEnd();
}

void drawPolygon() {
    float triangleY = -1.0;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); 
    glVertex2f(-1.0, 1.0 + triangleY);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -1.0 + triangleY);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -1.0 + triangleY);
    glColor3f(1.0, 0.0, 0.0); 
    glVertex2f(1.0, 1.0 + triangleY);
    glEnd();
}

void drawBorder(GLfloat x, GLfloat y, GLfloat size) {
    float triangleY = -1.0;
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0, 1.0 + triangleY);
    glVertex2f(-1.0, -1.0 + triangleY);
    glVertex2f(1.0, -1.0 + triangleY);
    glVertex2f(1.0, 1.0 + triangleY);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolygon();  
    drawTriangle(); 

    
    drawBorder(0.0, -2.0, 0.5);  

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); 
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    int width = 580, height = 500, x = (1368 - width) / 2, y = (768 - height) / 2;
    glutInitWindowSize(580, 510);
    glutInitWindowPosition(x, y);
    glutCreateWindow("A simple hut below :");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
