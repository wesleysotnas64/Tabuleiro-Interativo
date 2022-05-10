#ifndef COR_H
#define COR_H
 
class Cor{
    private:
        float rgb[3];

    public:
        Cor();

        void set_rgb(float r, float g, float b);
        void set_r(float r);
        void set_g(float g);
        void set_b(float b);

        Cor get_rgb();
        float get_r();
        float get_g();
        float get_b();
};

#endif
