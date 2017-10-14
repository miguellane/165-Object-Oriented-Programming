#ifndef Circle_h
#define Circle_h

using namespace std;

class Circle{
    double x;
    double y;
    double r;
public:
    double area;
    Circle(){
      this->x = 0;
      this->y = 0;
      this->r = 1;
      updateArea();
    }
    Circle(double x, double y, double r){
      this->x = x;
      this->y = y;
      this->r = r;
      updateArea();
    }
    void updateArea(){
      this->area = 3.14159265359 * r * r;
    }
    double getX(){
        return x;
    }
    void setX(double x){
        this->x = x;
    }
    double getY(){
        return y;
    }
    void setY(double y){
        this->y = y;
    }  
    double getR(){
        return r;
    }
    void setR(double r){
        this->r = r;
        updateArea();
    }    
    
};

#endif
