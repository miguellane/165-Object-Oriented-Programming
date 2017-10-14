#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void printBin(int input){
    if(input/2 != 0)
        printBin(input/2);
    cout << input % 2;
}

int main(){
  int input;
  cin >> input;
  while(input != -1){
    printf("%x ",input);
    printBin(input);
    cout << endl;
    cin >> input;
  }
}
