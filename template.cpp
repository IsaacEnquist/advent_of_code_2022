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
   newfile.open("day1.txt",ios::in); //open a file to perform read operation using file object
      while(getline(newfile, line)){

   }
}