#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
float m, mm, x, y, Xst, Xen, Yst, Yen;
void dda()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,-1.0);
        glVertex2f(0.0,1.0);
    glEnd();
    m=(Yen-Yst)/(Xen-Xst);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4.7);
    if(m<1){
        if(Xst>Xen){
            swap(Xst,Xen);
            swap(Yst,Yen);
        }
        x=Xst; y=Yst;
        glBegin(GL_POINTS);
            glVertex2f(x/100,y/100);
        while(x<=Xen){
            x++;
            y+=m;
            glVertex2f(x/100,y/100);
        }
        glEnd();
    }
    else if(m>1){
    glColor3f(0.0,0.0,1.0);
        if(Xst>Xen){
            swap(Xst,Xen);
            swap(Yst,Yen);
        }
        x=Xst; y=Yst;
        mm=1/m;
        glBegin(GL_POINTS);
            glVertex2f(x/100,y/100);
        while(x<=Xen){
            y++;
            x+=mm;
            glVertex2f(x/100,y/100);
        }
        glEnd();
    }
    glFlush();
}

int main(int argc, char *argv[])
{
    cout<<"Enter starting points (X start, Y start): ";
    cin>>Xst>>Yst;
    cout<<"Enter Ending points (X end, Y end): ";
    cin>>Xen>>Yen;
    ///Xst=5, Yst=5, Xen=100, Yen=25;
    glutInit(&argc, argv);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("LAB 2");
    glutDisplayFunc(dda);
    glutMainLoop();
    return 0;
}
