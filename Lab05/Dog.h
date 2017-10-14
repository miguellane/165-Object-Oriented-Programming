#ifndef Dog_h
#define Dog_h

#include "Animal.h"

using namespace std;

class Dog : public Animal {
public:
    Dog(){
        cout << "Creating Dog" << endl;
        setName("Dog");
        setAge(0);
    }
    Dog(string name, int age){
        cout << "Creating Dog" << endl;
        setName(name);
        setAge(age);
    }
    ~Dog(){
        cout << "Deleting Dog" << endl;
    }
    
    void feed(){
        cout << "A bone, please!" << endl;
    }
};

#endif
