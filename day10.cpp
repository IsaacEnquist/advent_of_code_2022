#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int check_add_cycle(int x, int cycle){
    if( (cycle + 20) % 40 == 0){
            return x*cycle;
    }
    return 0;  
}

int main(){
   fstream newfile;
   string line;
   int x {1};
   int cycle {0};
   int total {0};
   newfile.open("day10.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line) && cycle < 221){
        if(line.compare("noop")==0){
            cycle += 1;
            total = total + check_add_cycle(x, cycle);
        }
        else{
            cycle += 1;
            total = total + check_add_cycle(x, cycle);
            cycle += 1;
            total = total + check_add_cycle(x, cycle);
            x += stoi(line.substr(5));
        }
   }
   cout << total;
}