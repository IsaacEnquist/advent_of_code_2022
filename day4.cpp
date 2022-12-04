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
   string num;
   int range1bot;
   int range1top;
   int range2bot;
   int range2top;
   bool beforecomma;
   int total {0};
   newfile.open("day4.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        beforecomma = true;
        num = "";
        for(int i = 0; i < line.length() ; i++){
            if(line[i]=='-'){
                if(beforecomma){
                    range1bot = stoi(num);
                } else{
                    range2bot = stoi(num);
                }
                num = "";
            } else if(line[i]==','){
                range1top = stoi(num);
                num = "";
                beforecomma = false;
            } else{
                num = num + line[i];
            }
        }
        range2top = stoi(num);
        if(range1bot <= range2top && range2bot <= range1top){
            total += 1;
        } 
   }
   cout << total << "\n";
}