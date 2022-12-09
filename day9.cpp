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
    int been_there[600][600] = {{0}};
    int hposx {300};
    int hposy {300};
    int tposx {300};
    int tposy {300};
    been_there [300][300] = 1;
    newfile.open("day9.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        if(line[0] == 'U'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                hposy += 1;
                //cout << hposy <<"\n";
                if(abs(hposx-tposx) > 1 || abs(hposy-tposy) > 1){
                    tposx = hposx;
                    tposy = hposy - 1;
                    been_there[tposx][tposy] = 1;
                }
            }
        }
        else if(line[0] == 'D'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                hposy -= 1;
                if(abs(hposx-tposx) > 1 || abs(hposy-tposy) > 1){
                    tposx = hposx;
                    tposy = hposy + 1;
                    been_there[tposx][tposy] = 1;
                }
            }
        }
        else if(line[0] == 'R'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                hposx += 1;
                if(abs(hposx-tposx) > 1 || abs(hposy-tposy) > 1){
                    tposx = hposx - 1;
                    tposy = hposy;
                    been_there[tposx][tposy] = 1;
                }
            }
        }
        else if(line[0] == 'L'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                hposx -= 1;
                if(abs(hposx-tposx) > 1 || abs(hposy-tposy) > 1){
                    tposx = hposx + 1;
                    tposy = hposy;
                    been_there[tposx][tposy] = 1;
                }
            }
        }
        cout << hposx << "<- x   y->" << hposy <<"\n";
        //cout << line[0] << "\n";
        //cout << stoi(line.substr(2)) << "\n";
    }
    int total {0};
    for(int i = 0; i < 600; i++){
        for(int j = 0; j < 600; j++){
            total = total + been_there[i][j];
        }
    }
    cout << total;
}