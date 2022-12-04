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
   char item;
   int strlength;
   bool notFound = false; 
   int total {0};
   newfile.open("day3.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        strlength = line.length();
        notFound = false;
        for(int i = 0; i < strlength/2; i++){
            item = line[i];
            for(int k = strlength / 2; k < strlength; k++){
                if(item == line[k]){
                    if(int(item) > 92){
                        total = total + item - 96;
                    }
                    else{
                        total = total + item - 38;
                    }
                    notFound = true;
                    break;
                }
            }
            if(notFound){
                break;
            }
        }
   }
   cout << total << "\n";
}