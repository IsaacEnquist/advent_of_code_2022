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
    int i {0};
    char letter[4] = {'j', 'j', 'j', 'j'};
    newfile.open("test.txt",ios::in); //open a file to perform read operation using file object
    getline(newfile, line);

    while(true){
        i +=1;
        letter[i%4] = line[i];
        if(letter[0] != letter[1] && letter[0] != letter[2] && letter[0] != letter[3] && letter[1] != letter[2] && letter[1] != letter[3] && letter[2] != letter[3]){
            break;
        }
    }
   
    cout << i;

}