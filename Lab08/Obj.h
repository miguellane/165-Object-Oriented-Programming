#include "Shared.h"
using namespace std;
class Obj : public Shared {
public:
    string n;
    Obj(string n) {
        this->n = n;
        cout << "New " << n << endl;
    } 
    ~Obj() {
        cout << "Delete " << n << endl;
    }
};
