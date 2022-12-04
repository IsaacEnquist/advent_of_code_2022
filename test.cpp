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
   newfile.open("day3.txt",ios::in); //open a file to perform read operation using file object
   for(int i = 0; i < 100; i++){
    getline(newfile, line);
    cout << line << "\n";
    getline(newfile, line);
    cout << line << "\n";
    getline(newfile, line);
    cout << line << "\n";
   }
}
