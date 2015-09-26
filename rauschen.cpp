#include <math.h>
#include "rauschen.h"
#include <stdlib.h>

const float pi = 3.1415926f;

Rauschen::Rauschen()
: index(0), amplitude(0.3), time(0), backwards(false), tonart(3)
{}

Rauschen::~Rauschen()
{

}

float Rauschen::getValue(){
    random = rand() % 200 - 100;
    random = random / 100;

    if(backwards){
        time--;
    }else{
        time++;
    }
    if(time==100){
        backwards = true;
    }else if(time==0){
        backwards=false;
    }


    float value = 0;
    if(tonart==0){
        value = amplitude * random;
    }else if(tonart==1){
        value = amplitude * (time/100);
    }else if(tonart==2){
        if(backwards){
            value = amplitude * (-1)*(time/100);
        }else{
            value = amplitude * (time/100);
        }
    }else if(tonart==3){
        if(backwards){
            value = amplitude * 1;
        }else{
            value = amplitude * (-1);
        }

    }

    index++;
    return value;
}

void Rauschen::setAmplitude(float amplitude){
    this->amplitude = amplitude;
}
