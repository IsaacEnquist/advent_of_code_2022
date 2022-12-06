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
    bool end = true;
    int i {1};
    newfile.open("day6.txt",ios::in); //open a file to perform read operation using file object
    getline(newfile, line);
    char letter[14];
    
    for(int k = 0; k < 14; k++){
        letter[k] = line[13];
    }

    while(true){
        letter[i%14] = line[i];
        i +=1;
        end = true;
        for(int k = 0; k < 14; k++){
            for(int j = k+1; j < 14; j++){
                if(letter[k] == letter[j]){
                    cout << letter[k] << "\n";
                    end = false;
                    break;
                }
            }
        }
        if(end){

            break;
        }
        
    }
   
    cout << i;

}