#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int total {0};
int maxi {1014};
string lines[1014];
int i {1};

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
    return true;
}

int myFunction2(int size) {
  while((lines[i].substr(0,7)).compare("$ cd ..") == 1 && (lines[i].substr(0,6)).compare("$ cd /") == 1){
    if(check_number(lines[i].substr(0, lines[i].find(' ')))){
        size = size + stoi(lines[i].substr(0, lines[i].find(' ')));
    }
    i +=1;
    if(((lines[i-1].substr(0,4)).compare("$ cd")) == 0 && i-1 != maxi){
        size = size + myFunction2(0);
    }
    //cout << size << " i: " << i << "\n";
  }

  if(size < 100000){
        total = total + size;
  }
  
  if(((lines[i].substr(0,6)).compare("$ cd .")) == 0 && i != maxi){
    i += 1;
    return size;
  }
  else if(i == maxi){
    return size;
  }
  i = i - 1;
  return size;
}

void myFunction(int i){
    cout << lines[i].substr(0,2);
}

int main(){
   fstream newfile;
   string line;
   newfile.open("day7.txt",ios::in); //open a file to perform read operation using file object
    for(int i = 0 ; i<maxi ; i++){
        getline(newfile, line);
        lines[i] = line;
    }
    myFunction2(0);
    cout << total << " = total";
}