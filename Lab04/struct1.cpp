#include <iostream>

#include "Stash.h"

int main(int argc, const char * argv[]){
    int size;
    std::cin >> size;
    double* val;

    Stash* myStash = new Stash;
    myStash->initialize(sizeof(double));
    
    for(int i = 0; i < size; i++){
        std::cin >> *val;
        myStash->add(val);
    }
    for(int i = 0; i < size; i++){
      val = static_cast<double*>(myStash->fetch(i));
      std::cout << *val << std::endl;
    }

    myStash->cleanup();
    return 0;
}

