#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int i = 0;
  bool fail;
  string input;
  vector<vector<string> > words(11, vector<string>());

  getline(cin,input);
  while(input != "quit"){
    i = input.size();
    fail = 0;
    for(int j = 0; j < words[i].size(); j++)
      if(words[i][j] == input)
        fail = 1;
    if(fail == 0)
      words[i].push_back(input);
    getline(cin, input);
  }
  for(i = 0; i < 11; i++){
    for(int j = 0; j < words[i].size(); j++){
      cout << words[i][j] << " ";
    }
    if(words[i].size() != 0)
      cout << endl;
  }
}
