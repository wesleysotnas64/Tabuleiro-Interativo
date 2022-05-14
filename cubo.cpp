#include <iostream>
#include <GL/glut.h>

#include "cubo.h"

Cubo::Cubo(){
    Ponto p;
    p.set_coord(0,0,0);

    set_pivot(p);
}

void Cubo::drawn(){
    //implementação do cubo sendo desenhado

    //primeiro vai setar os vértices

    //depois chama o glBegin pra desenhar os vértices, usando o vertice[i].get_coor_

    //tem que desenhar as 6 faces do cubo

    // na internet tem implementação de um cubo
}

Ponto Cubo::get_vertice(int i){

}

Ponto Cubo::get_pivot(){

}

Cor   Cubo::get_cor(){

}

float Cubo::get_size(){

}

void Cubo::set_vertice(int  i, Ponto p){

}

void Cubo::set_pivot (Ponto p){

}

void Cubo::set_cor(Cor c){

}

void Cubo::set_size  (float s){

}