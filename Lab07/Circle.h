#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Sortable.h"

class Circle : public Sortable {
    int rad;
public:
    Circle(){
        this->rad = 0;
    }
    Circle(int rad){
        this->rad = rad;
    }
    ~Circle(){
    }
    bool compare (const Sortable *s){
        const Circle *circ = dynamic_cast<const Circle*>(s);
        if(this->rad < circ->rad)
            return true;
        return false;
    }
    void print(){
        std::cout << "Circle with radius: " << this->rad << std::endl;
    }
};

#endif
