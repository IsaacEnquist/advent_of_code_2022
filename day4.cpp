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
                    //cout << range1bot << "r1b\n";
                }
                else{
                    range2bot = stoi(num);
                    //cout << range2bot << "r2b\n";
                }
                num = "";
            } else if(line[i]==','){
                range1top = stoi(num);
                num = "";
                beforecomma = false;
                //cout << range1top << "r1t\n";
            } else{
                num = num + line[i];
            }
        }
        range2top = stoi(num);
        //cout << range2top << "r2b\n";
        if(range1top - range1bot >= range2top - range2bot){
            if(range1top >= range2top && range2bot >= range1bot){
                total += 1;
            }
        } else if(range1top <= range2top && range2bot <= range1bot){
            total += 1;
        }
   }
   cout << total << "\n";
}