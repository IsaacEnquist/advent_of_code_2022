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
   string crate_stack[9] = {"QWPSZRHD", "VBRWQHF", "CVSH", "HFG", "PGJBZ", "QTJHWFL", "ZTWDLVJN", "DTZCJGHF", "WPVMBH"};
   string move;
   string from;
   string to;
   string lifted_letters;
   int i;
   newfile.open("day5.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        move = "";
        from = "";
        to = "";
        i = 0;
        while(true){
            if(line[i]==' '){
                break;
            }
            move = move + line[i];
            i += 1;
        }
        i += 1;
        while(true){
            if(line[i]==' '){
                break;
            }
            from = from + line[i];

            i += 1;
        }
        i += 1;

        to = line.substr (i);

        lifted_letters = crate_stack[stoi(from) - 1].substr(crate_stack[stoi(from) - 1].size()-stoi(move));

        crate_stack[stoi(from) - 1].erase(crate_stack[stoi(from) - 1].size()-stoi(move));

        //reverse(lifted_letters.begin(), lifted_letters.end());

        crate_stack[stoi(to) - 1] = crate_stack[stoi(to) - 1] + lifted_letters;


   }
   for (int i = 0; i < 9; i++) {
        std::cout << crate_stack[i].substr(crate_stack[i].size() - 1) ;
    }
}

