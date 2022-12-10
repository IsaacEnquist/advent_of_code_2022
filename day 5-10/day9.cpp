#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int been_there[1000][1000] = {{0}};
int posx[10];
int posy[10];

void update_pos(int rope_part){
    if(abs(posx[rope_part]-posx[rope_part - 1]) > 1 || abs(posy[rope_part]-posy[rope_part - 1]) > 1){

        if(abs(posx[rope_part]+1-posx[rope_part - 1]) + abs(posy[rope_part]-posy[rope_part - 1]) < 2){
            posx[rope_part] = posx[rope_part] + 1;
        }
        else if(abs(posx[rope_part]-1-posx[rope_part - 1]) + abs(posy[rope_part]-posy[rope_part - 1]) < 2){
            posx[rope_part] = posx[rope_part] - 1;
        }
        else if(abs(posx[rope_part]-posx[rope_part - 1]) + abs(posy[rope_part]+1-posy[rope_part - 1]) < 2){
            posy[rope_part] = posy[rope_part] + 1;
        }
        else if(abs(posx[rope_part]-posx[rope_part - 1]) + abs(posy[rope_part]-1-posy[rope_part - 1]) < 2){
            posy[rope_part] = posy[rope_part] - 1;
        }
        else if(abs(posx[rope_part]+1-posx[rope_part - 1]) + abs(posy[rope_part]+1-posy[rope_part - 1]) < 2){
            posx[rope_part] += 1;
            posy[rope_part] += 1;
        }
        else if(abs(posx[rope_part]+1-posx[rope_part - 1]) + abs(posy[rope_part]-1-posy[rope_part - 1]) < 2){
            posx[rope_part] += 1;
            posy[rope_part] -= 1;
        }
        else if(abs(posx[rope_part]-1-posx[rope_part - 1]) + abs(posy[rope_part]+1-posy[rope_part - 1]) < 2){
            posx[rope_part] -= 1;
            posy[rope_part] += 1;
        }
        else if(abs(posx[rope_part]-1-posx[rope_part - 1]) + abs(posy[rope_part]-1-posy[rope_part - 1]) < 2){
            posx[rope_part] -= 1;
            posy[rope_part] -= 1;
        }
        else{
            if(posx[rope_part] > posx[rope_part - 1]){
                posx[rope_part] -= 1;
            }
            else{
                posx[rope_part] += 1;
            }
            if(posy[rope_part] > posy[rope_part - 1]){
                posy[rope_part] -= 1;
            }
            else{
                posy[rope_part] += 1;
            }
        } 
        if(rope_part == 9){
            cout << posx[rope_part] << " <- x   y -> " << posy[rope_part] <<" " << posx[rope_part-1] << " <- x   y -> " << posy[rope_part-1] << "\n";
            been_there[posx[rope_part]][posy[rope_part]] = 1;
        }
    }
    //cout << posx[rope_part] << " <- x   y -> " << posy[rope_part] <<" " << posx[rope_part-1] << " <- x   y -> " << posy[rope_part-1] << " " << rope_part <<"\n";
}


int main(){
    fstream newfile;
    string line;
    std::fill_n(posx, 10, 500);
    std::fill_n(posy, 10, 500);

    been_there [500][500] = 1;
    newfile.open("day9.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        if(line[0] == 'U'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                posy[0] += 1;
                //cout << hposy <<"\n";
                for(int j = 1 ; j < 10 ; j++){
                    update_pos(j);
                }
            }
        }
        else if(line[0] == 'D'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                posy[0] -= 1;
                for(int j = 1 ; j < 10 ; j++){
                    update_pos(j);
                }
            }
        }
        else if(line[0] == 'R'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                posx[0] += 1;
                for(int j = 1 ; j < 10 ; j++){
                    update_pos(j);
                }
            }
        }
        else if(line[0] == 'L'){
            for(int i = 0; i < stoi(line.substr(2)); i++){
                posx[0] -= 1;
                for(int j = 1 ; j < 10 ; j++){
                    update_pos(j);
                }
            }
        }
        //cout << hposx << "<- x   y->" << hposy <<"\n";
        //cout << line[0] << "\n";
        //cout << stoi(line.substr(2)) << "\n";
    }
    int total {0};
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            total = total + been_there[i][j];
        }
    }
    cout << total;
}