#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int in;
  int sum = 0;
  vector<int> numbers;
  vector<int>::iterator it = numbers.begin();
  cin >> in;

  while(in != 0){
    if( in > 0){
      numbers.push_back(in);
    }else{
      while(it != numbers.end()){
        if(*it == -1*in)
          numbers.erase(it);
        else
          it++;
    } }
    cin >> in;
    it = numbers.begin();
  }
  for(int i = 0; i < numbers.size(); i++)
    sum+= numbers[i];
  cout << numbers.size() << " " << sum << endl;
}
