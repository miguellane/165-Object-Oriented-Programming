#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <iostream>
#include "Sortable.h"

using namespace std;

class Participant : public Sortable {
public:
    static bool (*comp_cb)(const Participant *, const Participant *);
    string name;
    int age;
    double score;

    Participant(string name, int age, double score){
        this->name = name;
        this->age = age;
        this->score = score;
    }
    ~Participant(){
    }
    bool compare (const Sortable *s){
        const Participant *part = dynamic_cast<const Participant*>(s);
/*        if(this->score > part->score){
            return true;
        }else if(this->score == part->score){
            if(this->age < part->age){
                return true;
            }else if(this->age == part->age){
                if(this->name < part->name)
                    return true;
            }
        }
        return false;
*/
        return comp_cb(part, this);
    }
    void print(){
        cout << name << "   " << age << "   " << score << endl;
    }
};

#endif
