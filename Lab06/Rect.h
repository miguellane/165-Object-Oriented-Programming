#ifndef RECT_H
#define RECT_H

#include "Vec.h"

class Rect{
public:
  float x;
  float y;
  float width;
  float height;

  Rect(){
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
  }
  Rect(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
  }
  ~Rect(){
  }
  bool contains(Vec that){
    if(this->x < that.x && that.x < this->x + this->width)
      if(this->y - this->height < that.y && that.y < this->y)
        return true;
    return false;
  }
};
#endif
