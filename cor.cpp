#include "cor.h"

Cor::Cor(){
    set_rgb(1,1,1);
}

//SETTERS
void Cor::set_rgb(float r, float g, float b){
    set_r(r);
    set_g(g);
    set_b(b);
}

void Cor::set_r(float r){
    rgb[0] = r;
}

void Cor::set_g(float g){
    rgb[1] = g;
}

void Cor::set_b(float b){
    rgb[2] = b;
}

//GETTERS
Cor Cor::get_rgb(){
    Cor c;
    c.set_rgb(get_r(), get_g(), get_b());

    return c;
}

float Cor::get_r(){
    return rgb[0];
}

float Cor::get_g(){
    return rgb[1];
}

float Cor::get_b(){
    return rgb[2];
}
