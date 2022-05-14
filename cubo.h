#ifndef CUBO_H
#define CUBO_H

#include "ponto.h"
#include "cor.h"

class Cubo{
    private:
        Ponto pivot;
        Ponto vertice[8];
        Cor   cor;
        float size;

    public:
        Cubo();
        void drawn();

        Ponto get_vertice(int i);
        Ponto get_pivot();
        Cor   get_cor();
        float get_size();

        void set_vertice(int  i, Ponto p);
        void set_pivot (Ponto p);
        void set_cor(Cor c);
        void set_size  (float s);
};

#endif