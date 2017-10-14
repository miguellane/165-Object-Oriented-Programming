#include <iostream>

#include "Stack.h"

int main(int argc, const char * argv[]){
    int size;
    std::cin >> size;
    double* val = new double[size];

    Stack* myStack = new Stack;
    myStack->initialize();
    Stack::Link* head;    

    for(int i = 0; i < size; i++){
        std::cin >> *val;
        myStack->push(val);
        val++;
    }
    head = myStack->head;
    for(int i = 0; i < size; i++){
      val = static_cast<double*>(head->data);
      std::cout << *val << std::endl;
      head = head->next;
    }
    for(int i = 0; i < size; i++){
      myStack->pop();
    }
    myStack->cleanup();
    return 0;
}

