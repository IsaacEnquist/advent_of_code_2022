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
   int max {0};
   int max2 {0};
   int max3 {0};
   int current {0};
   int temp {0};
   newfile.open("day1.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        if(line.compare("") == 0){
            if(current > max){
                temp = max;
                max = current;
                current = temp;
                if (current > max2){
                temp = max2;
                max2 = current;
                current = temp;
                    if (current > max3){
                    temp = max3;
                    max3 = current;
                    current = temp;
                    }
                }
            }
            current = 0;
        } else
        current = current + stoi(line);
        }
        cout << max << endl;
        cout << max2 << endl;
        cout << max3 << endl;
        cout << max+max2+max3 << endl;
   }

