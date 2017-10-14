#include <iostream>
using namespace std;

int main(){
  char ch;
  int in;
  
  cin >> ch;
  cin >> in;

  while(in != -2){
    if(in == -1)
      cout << endl;
    else
      for(int i = 0; i < in; i++)
        cout << ch;
    cin >> ch;
    cin >> in;
  }
}
