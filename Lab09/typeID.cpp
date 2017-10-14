#include <iostream>
#include <typeinfo>
#include "SomeHeader.h"

using namespace std;

int main(int argc, const char * argv[])
{
    vector<A*> vec;
    initVec(vec);

    for(int i = 0; i < vec.size(); i++){
        cout << typeid(*vec[i]).name() << endl;
    }
    return 0;
}

