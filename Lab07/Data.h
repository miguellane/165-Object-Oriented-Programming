#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include "Sortable.h"
class Data{
    std::vector<Sortable*> data;
public:
//    Data(){}
//    ~Data(){}

    void add(Sortable* obj){
        data.push_back(obj);
    }
    void print(){
        for(int i = 0; i < data.size(); i++)
            data[i]->print();
        std::cout << std::endl;
    }
    void sort(){
        for(int i = 0; i < data.size(); i++)
            for(int j = 0; j < data.size(); j++)
                if( data[i]->compare(data[j]) ){
                    Sortable* temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
    }
};
#endif
