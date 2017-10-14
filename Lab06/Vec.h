#ifndef VEC_H
#define VEC_H

class Vec{
public:
  float x;
  float y;
  static Vec null;

  Vec(){
    this->x = 0;
    this->y = 0;
  }
  Vec(float x, float y){
    this->x = x;
    this->y = y;
  }
  ~Vec(){
  }
  void add(Vec that){
    this->x += that.x;
    this->y += that.y;
  }
  void print(){
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
  } 
};
Vec Vec::null = Vec();
#endif
