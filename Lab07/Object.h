#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

class Object{
public:
    static int count;
    
    Object(){
        count++;
    }
    Object(const Object &obj){
        count++;
    }

};

#endif
