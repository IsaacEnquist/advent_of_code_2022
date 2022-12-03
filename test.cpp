#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
   fstream newfile;
   string line;
   int max {0};
   int current {0};
   newfile.open("day1.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        if(line.compare("") == 0){
            if(current > max){
                max = current;
            }
            current = 0;
        } else
        current = current + stoi(line);
        }
        cout << max << endl;
   }

