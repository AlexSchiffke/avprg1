#ifndef Rauschen_H
#define Rauschen_H

class Rauschen{
public:
    Rauschen();
    ~Rauschen();
    float getValue();
    void setAmplitude(float amplitude);
private:
    int index;
    float amplitude;
    double random;
    double time;
    bool backwards;
    int tonart;
};

#endif
