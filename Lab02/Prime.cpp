#include <iostream>
using namespace std;
  
int main(){
  int input;
  bool trigger;
  cin >> input;
  for(int i = 2; i < input; i++){
    trigger = true;
    for(int j = i-1; j > 1; j--){
      if(i % j == 0){
        trigger = false;
        break;
    } }
    if(trigger == true)
      cout << i << endl;
  }
}
