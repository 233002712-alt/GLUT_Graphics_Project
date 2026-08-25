#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

using namespace std;
struct Fish {
    float x, y;
    float speed;
    float scale;
    float r, g, b;
    int type; 
};
struct Bubble {
    float x, y;
    float speed;
    float size;
};
Fish fishes[] = {
    { -150.0f, 480.0f, 3.2f, 0.75f, 1.0f, 0.4f, 0.0f, 0 }, 
    { -300.0f, 340.0f, 2.2f, 0.90f, 1.0f, 0.8f, 0.0f, 0 }, 
    { -200.0f, 200.0f, 3.8f, 0.70f, 0.9f, 0.2f, 0.5f, 0 }, 
    { -250.0f, 400.0f, 2.8f, 0.80f, 0.0f, 0.8f, 0.9f, 1 }, 
    { -400.0f, 270.0f, 3.5f, 0.75f, 0.9f, 0.1f, 0.1f, 1 }, 
    { -180.0f, 110.0f, 1.9f, 0.85f, 0.2f, 0.8f, 0.3f, 1 }  
};

Bubble bubbles[] = {
    { 150.0f, 40.0f, 2.5f, 14.0f },
    { 175.0f, 10.0f, 3.0f, 10.0f },
    { 580.0f, 20.0f, 2.2f, 16.0f },
    { 620.0f, 80.0f, 2.8f, 12.0f }
};

int totalFishes = 6;
int totalBubbles = 4;
void drawGrassCluster(float startX) {
    glColor3f(0.0f, 0.6f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(startX, 0);
    glVertex2f(startX + 10, 0);
    glVertex2f(startX - 10, 60);

    glVertex2f(startX + 8, 0);
    glVertex2f(startX + 18, 0);
    glVertex2f(startX + 13, 85);

    glColor3f(0.0f, 0.4f, 0.1f);
    glVertex2f(startX + 15, 0);
    glVertex2f(startX + 25, 0);
    glVertex2f(startX + 32, 50);
    glEnd();
}

void drawSparseGrass() {
    drawGrassCluster(120.0f);
    drawGrassCluster(380.0f);
    drawGrassCluster(650.0f);
}

void drawSingleBubble(Bubble b) {
    glColor3f(0.85f, 0.95f, 1.0f);
    glLineWidth(2.0f); 

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 20) {
        float degInRad = i * 3.1416f / 180.0f;
        glVertex2f(b.x + cos(degInRad) * b.size, b.y + sin(degInRad) * b.size);
    }
    glEnd();
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glVertex2f(b.x + b.size * 0.4f, b.y + b.size * 0.4f);
    glEnd();
}

void drawOvalFish(Fish f) {
    glColor3f(f.r * 0.7f, f.g * 0.7f, f.b * 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(-20, 20);
    glVertex2f(-40, 45);
    glVertex2f(-50, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-20, -20);
    glVertex2f(-35, -40);
    glVertex2f(-45, -15);
    glEnd();
    glColor3f(f.r, f.g, f.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 15) {
        float rad = i * 3.1416f / 180.0f;
        glVertex2f(cos(rad) * 50 - 20, sin(rad) * 25);
    }
    glEnd();
    glColor3f(f.r * 0.85f, f.g * 0.85f, f.b * 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(-65, 0);
    glVertex2f(-100, 35);
    glVertex2f(-85, 0);
    glVertex2f(-100, -35);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 30) {
        float rad = i * 3.1416f / 180.0f;
        glVertex2f(15 + cos(rad) * 5, 8 + sin(rad) * 5);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glVertex2f(16, 8);
    glEnd();
}
void drawKiteFish(Fish f) {
    glColor3f(f.r, f.g, f.b);
    glBegin(GL_POLYGON);
    glVertex2f(30, 0);     
    glVertex2f(-20, 35);   
    glVertex2f(-60, 0);    
    glVertex2f(-20, -35);  
    glEnd();
    glColor3f(f.r * 0.8f, f.g * 0.8f, f.b * 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-60, 0);
    glVertex2f(-95, 30);
    glVertex2f(-80, 0);

    glVertex2f(-60, 0);
    glVertex2f(-80, 0);
    glVertex2f(-95, -30);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 30) {
        float rad = i * 3.1416f / 180.0f;
        glVertex2f(10 + cos(rad) * 4.5f, 6 + sin(rad) * 4.5f);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glVertex2f(11, 6);
    glEnd();
}
void drawSingleFish(Fish f) {
    glPushMatrix();
    glTranslatef(f.x, f.y, 0);
    glScalef(f.scale, f.scale, 1.0f);

    if (f.type == 0) {
        drawOvalFish(f);
    }
    else {
        drawKiteFish(f);
    }

    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSparseGrass();

    for (int i = 0; i < totalBubbles; i++) {
        drawSingleBubble(bubbles[i]);
    }

    for (int i = 0; i < totalFishes; i++) {
        drawSingleFish(fishes[i]);
    }

    glutSwapBuffers();
}
void update(int value) {
    for (int i = 0; i < totalFishes; i++) {
        fishes[i].x += fishes[i].speed;
        if (fishes[i].x > 950.0f) {
            fishes[i].x = -150.0f;
        }
    }

    for (int i = 0; i < totalBubbles; i++) {
        bubbles[i].y += bubbles[i].speed;
        if (bubbles[i].y > 630.0f) {
            bubbles[i].y = -20.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.1f, 0.5f, 0.8f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3 Oval and 3 Kite Fishes with Big Bubbles - C++");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}