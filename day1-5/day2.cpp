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
   string me;
   string elf;
   int score {0};
   newfile.open("day2.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        elf = line[0];
        me = line[2];
        if(me.compare("X") == 0){
            if(elf.compare("A")==0){
                score = score + 3;
            }
            else if(elf.compare("C")==0){
                score = score + 2;
            }
            else{
                score = score + 1;
            }
            score = score + 0;
        }
        else if(me.compare("Y") == 0){
            if(elf.compare("A")==0){
                score = score + 1;
            }
            else if(elf.compare("B")==0){
                score = score + 2;
            }
            else{
                score = score + 3;
            }
            score = score + 3;
        }
        else{
            if(elf.compare("C")==0){
                score = score + 1;
            }
            else if(elf.compare("B")==0){
                score = score + 3;
            }
            else{
                score = score + 2;
            }
            score = score + 6;
        }
    }
    cout << score;
}