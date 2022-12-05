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
   bool notFound = false; 
   int total {0};
   string line1;
   string line2;
   string line3;
   bool found = false;
   newfile.open("day3.txt",ios::in); //open a file to perform read operation using file object
       for(int i = 0; i < 100; i++){
        getline(newfile, line);
        line1 = line; 
        getline(newfile, line);
        line2 = line;
        getline(newfile, line);
        line3 = line;
        found = false;
        notFound = false;
        for(int i = 0; i < line1.length(); i++){
            for(int j = 0; j < line2.length(); j++){
                if(line1[i] == line2[j]){
                    for(int k = 0; k < line3.length(); k++){
                        if(line1[i]==line3[k]){
                            if(int(line1[i]) > 92){
                                total = total + int(line1[i]) - 96;
                            }
                            else{
                                total = total + int(line1[i]) - 38;
                            }
                            
                            found = true;
                            break;
                            }
                        }
                    }
                    if(found){
                        break;
                    }
                }
                if(found){
                        break;
                }
            }

        }
   cout << total << "\n";
}


