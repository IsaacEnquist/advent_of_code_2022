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
   int x {1};
   int cycle {0};
   int total {0};
   string sprite {"###....................................."};
   string crt {"#"};
   newfile.open("day10.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line) && cycle < 250){
        if(line.compare("noop")==0){
            cycle += 1;
            if(cycle % 40 == 0){
                cout << crt << "\n";
                crt = "";
                cycle = 0;
            }
            crt += sprite[cycle];
        }
        else{
            cycle += 1;
            if(cycle % 40 == 0){
                cout << crt << "\n";
                crt = "";
                cycle = 0;
            }
            crt += sprite[cycle];
            cycle += 1;
            if(cycle % 40 == 0){
                cout << crt << "\n";
                crt = "";
                cycle = 0;
            }
            sprite.replace(max(x-1, 0), max(min(3, 3 + x), 0), "...");
            x += stoi(line.substr(5));
            sprite.replace(max(x-1, 0), max(min(3, 3 + x), 0), "###");
            crt += sprite[cycle];
        }
   }
}