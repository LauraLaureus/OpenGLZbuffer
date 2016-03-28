//
//  View.c
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"

float puntos[8 * 6] = {
    -0.5,  0.5, 0.0, 1.0 ,0.0, 0.0,
    -0.8,  0.8, 0.0, 1.0, 0.0, 0.0,
    0.5,  0.5, 0.0, 1.0, 0.0, 0.0,
    0.8,  0.8, 0.0, 1.0, 0.0, 0.0,
    0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
    0.8, -0.8, 0.0, 1.0, 0.0, 0.0,
    -0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
    -0.8, -0.8, 0.0, 1.0, 0.0, 0.0
};

int indices[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 1 };


void Init(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-gl_width/2.0, gl_width/2.0, -gl_height/2.0, gl_height/2.0, gl_near, gl_far);
}


void Display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // // TO DO

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.2f, 0.2f, -2.5f);
    glVertex3f(0.2f, 0.2f, -3.5f);
    glVertex3f(0.8f, 0.2f, -2.5f);
    glVertex3f(0.8f, 0.2f, -3.5f);
    glEnd();
 
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.8f, 0.2f, -2.5f);
    glVertex3f(0.8f, 0.2f, -3.5f);
    glVertex3f(0.8f, 0.8f, -2.5f);
    glVertex3f(0.8f, 0.8f, -3.5f);
    glEnd();
    

    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.2f, 0.8f, -2.5f);
    glVertex3f(0.2f, 0.8f, -3.5f);
    glVertex3f(0.8f, 0.8f, -2.5f);
    glVertex3f(0.8f, 0.8f, -3.5f);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0.2f, 0.2f, -2.5f);
    glVertex3f(0.2f, 0.2f, -3.5f);
    glVertex3f(0.2f, 0.8f, -2.5f);
    glVertex3f(0.2f, 0.8f, -3.5f);
    glEnd();
    
   
    glFlush(); // actualiza el framebuffer
}

void ReshapeSize(int width, int height){
    float dx = gl_width;
    float dy = gl_height;
    
    dx *= (float)width / (float)w_width;
    dy *= (float)height / (float)w_height;
    
    glViewport(0, 0, width, height); // utiliza la totalidad de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_near, gl_far);
    glutPostRedisplay();
}