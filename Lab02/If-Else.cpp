#include <iostream>
using namespace std;
  
int main(){
  int input;
  cin >> input;
  while(input != -1){
    if(input % 2 == 0)
      cout << "EVEN" << endl;
    else
      cout << "ODD" << endl;
    cin >> input;
  }
}
