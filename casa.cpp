#include <iostream>
#include <GL/glut.h>

#include "cor.h"
#include "casa.h"


Casa::Casa(){
    pivot.set_coord(0,0,0);
    set_size(1);

    set_hover(false);
    set_select(false);
    set_black(false);

    Cor c;
    c.set_rgb(1,1,1);
    set_cor(c);
}


void Casa::drawn(){

    //Definindo os vértices
    Ponto p;

    set_vertice(0, get_pivot());
    p.set_coord(pivot.get_coord_x(), pivot.get_coord_y() - get_size(), 0);
    set_vertice(1, p);
    p.set_coord(pivot.get_coord_x() + get_size(), pivot.get_coord_y() - get_size(), 0);
    set_vertice(2, p);
    p.set_coord(pivot.get_coord_x() + get_size(), pivot.get_coord_y(), 0);
    set_vertice(3, p);

    //Cor cor_aux;
    
    //if(get_black()) cor_aux.set_rgb(0,0,0);
    //else cor_aux.set_rgb(1,1,1);

    //set_cor(cor_aux);

    glColor3f(get_cor().get_r(), get_cor().get_g(), get_cor().get_b());
    glBegin(GL_QUADS);
        for(int i = 0; i < 4; i++) glVertex2f(get_vertice(i).get_coord_x(), get_vertice(i).get_coord_y());
    glEnd();

}

void Casa::detect_hover(float x_mouse, float y_mouse){
    bool inferior_e = (x_mouse > get_vertice(1).get_coord_x() && y_mouse > get_vertice(1).get_coord_y());
    bool superior_d = (x_mouse < get_vertice(3).get_coord_x() && y_mouse < get_vertice(3).get_coord_y());
    //if(inferior_e && superior_d) printf("Hover na casa: x: %f  |  y: %f\n", get_pivot().get_coord_x(), get_pivot().get_coord_y());
    Cor c_buffer;
    Cor c_hover;

    c_buffer.set_rgb(get_cor().get_r(), get_cor().get_g(), get_cor().get_b());
    c_hover.set_rgb(0,1,0);
    if(inferior_e && superior_d){
        set_hover(true);
        c_buffer.set_rgb(get_cor().get_r(), get_cor().get_g(), get_cor().get_b());
        c_hover.set_rgb(0,1,0);

        set_cor(c_hover);
    } else{
        set_cor(c_buffer);
    }
}

Ponto Casa::get_vertice(int i){
    return vertice[i];
}

Ponto Casa::get_pivot(){
    return pivot.get_coord();
}

Cor Casa::get_cor(){
    return cor.get_rgb();
}

float Casa::get_size(){
    return size;
}

bool Casa::get_hover(){
    return hover;
}

bool Casa::get_black(){
    return black;
}

bool Casa::get_select(){
    return select;
}

void Casa::set_vertice(int i, Ponto p){
    vertice[i].set_coord(p.get_coord_x(), p.get_coord_y(), p.get_coord_z());
}

void Casa::set_pivot(Ponto p){
    pivot.set_coord(p.get_coord_x(), p.get_coord_y(), p.get_coord_z());
}

void Casa::set_cor(Cor c){
    cor.set_rgb(c.get_r(), c.get_g(), c.get_b());
}

void Casa::set_size(float s){
    size = s;
}

void Casa::set_hover(bool h){
    hover = h;
}

void Casa::set_black(bool b){
    black = b;

    Cor c;

    if(get_black()) c.set_rgb(0,0,0);
    else c.set_rgb(1,1,1);

    set_cor(c);
}

void Casa::set_select(bool s){
    select = s;
}