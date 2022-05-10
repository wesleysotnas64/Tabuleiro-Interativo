#ifndef CASA_H
#define CASA_H
 
#include "ponto.h"
#include "cor.h"

class Casa{
    private:
        Ponto pivot;
        Ponto vertice[4];
        Cor   cor;
        float size;
        bool  hover;
        bool  black;
        bool  select;

    public:
        Casa();
        void drawn();

        void detect_hover(float x_mouse, float y_mouse);

        Ponto get_vertice(int i);
        Ponto get_pivot();
        Cor   get_cor();
        float get_size();
        bool  get_hover();
        bool  get_black();
        bool  get_select();

        void set_vertice(int  i, Ponto p);
        void set_pivot (Ponto p);
        void set_cor(Cor c);
        void set_size  (float s);
        void set_hover (bool  h);
        void set_black (bool  b);
        void set_select(bool  s);
};

#endif