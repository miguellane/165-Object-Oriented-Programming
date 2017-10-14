#include <iostream>
#include <stdlib.h>
using namespace std;


class Counter{
public:
    int ID;
    static int count; 
    
	Counter() : ID(count++){
//		cout << ID << " created" << endl;
	}
    void* operator new(size_t size){
        void* n;
        n = malloc(size);
        cout << "new" << endl;
        return n;
    }
    void* operator new[](size_t size){
        void* n;
        n = new char[size];
        cout << "new "<< (size/sizeof(Counter)-1) << " counters starting at " << ((Counter*)n)[0].count << endl;
        return n;
    }

    void operator delete(void* d){
        free(d);
        cout << "delete" << endl;
    }
    void operator delete[](void* d){
        delete []d;
        cout << "delete counters" << endl;
    }
	~Counter(){
//        cout << ID << " destroyed" << endl;
	}
};
