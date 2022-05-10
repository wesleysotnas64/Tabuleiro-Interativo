//g++ main.cpp casa.cpp cor.cpp ponto.cpp -lGL -lglut
#include <iostream>
#include <GL/glut.h>

#include "ponto.h"
#include "casa.h"

#define SIZE_VIEW 8
#define WIDTH  400
#define HEIGHT 400

void display();
void begin();
void inputKeys(unsigned char tecla, int x, int y);
void update();

void inicia_tabuleiro();
void tabuleiroDraw();

void MouseAndandoNaoPressionado (int x, int y);

Casa  tabuleiroCasas[SIZE_VIEW][SIZE_VIEW];
Casa c;

float x_cartes;
float y_cartes;

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tabuleiro 2D!");


    begin();

    glutIdleFunc(update);
    glutKeyboardFunc(inputKeys);
    glutPassiveMotionFunc(MouseAndandoNaoPressionado);
    glutDisplayFunc(display);

    glutMainLoop();
    
    return 0;
}

void update(){
    display();
}

void inputKeys(unsigned char tecla, int x, int y){
    if(tecla == 'b'){
        c.set_black(!c.get_black());
        Ponto p;
        p.set_coord(-4,4,0);
        c.set_pivot(p);
    }
}

void begin(){
    glClearColor(0.5f, 0.75f, 1.0f, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    inicia_tabuleiro();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa buffer
    

    /*as próximas linhas definem o modo de projeção e tamanho da matriz da tela*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-SIZE_VIEW/2,SIZE_VIEW/2,-SIZE_VIEW/2,SIZE_VIEW/2,-1,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    //c.drawn();
    tabuleiroDraw();

    glutSwapBuffers();
}

void inicia_tabuleiro(){
    float y = 4;
    float x;
    Ponto p;
    
    for(int i = 0; i < 8; i++){
        x = -4;
        for(int j = 0; j < 8; j++){
            p.set_coord(x,y,0);
            tabuleiroCasas[i][j].set_pivot(p);
            x++;
        }
        y--;
    }
}

void tabuleiroDraw(){
    bool black = true;

    //Cor c;
    //c.set_rgb(0,0,0);

    for(int i = 0; i < 8; i++){
        if(i%2 != 0) black = false;
        for(int j = 0; j < 8; j++){
            tabuleiroCasas[i][j].set_black(black);
            tabuleiroCasas[i][j].detect_hover(x_cartes, y_cartes);
            tabuleiroCasas[i][j].drawn();
            black = !black;
        }
        black = !black;
    }
}

void MouseAndandoNaoPressionado (int x, int y){
    //Aqui tem que converter o tamanho da janela para o viewport
    float x_convert = (float) x;
    float y_convert = (float) y;

    float x_proporcao = x_convert/WIDTH;
    float y_proporcao = y_convert/WIDTH;

    x_cartes = x_proporcao*SIZE_VIEW;
    y_cartes = y_proporcao*SIZE_VIEW;

    x_cartes = x_cartes-(SIZE_VIEW/2);
    y_cartes = -(y_cartes-(SIZE_VIEW/2));

    //printf("Mouse ANDANDO solto na janela. Posição: (%f, %f)\n", x_cartes-(SIZE_VIEW/2), -(y_cartes-(SIZE_VIEW/2)));

    //detectando hover para cada casa
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){ tabuleiroCasas[i][j].detect_hover(x_cartes, y_cartes);
        }
    }

}