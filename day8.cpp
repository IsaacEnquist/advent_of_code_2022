#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string lines[99];
int width{99};
int height{99};

bool check_top(int w, int h, int size){
    if(h==0){
        return true;
    }
    if(lines[h-1][w] -'0' < size){
        if(check_top(w, h-1, size)){
            return true;
        }
    }
    return false; 
}

bool check_bot(int w, int h, int size){
    if(h==height-1){
        return true;
    }
    if(lines[h+1][w] -'0'< size){
        if(check_bot(w, h+1, size)){
            return true;
        }
    }
    return false; 
}

bool check_right(int w, int h, int size){
    if(w==width-1){
        return true;
    }
    if(lines[h][w+1] -'0'< size){
        if(check_right(w+1, h, size)){
            return true;
        }
    }
    return false; 
}

bool check_left(int w, int h, int size){
    if(w == 0){
        return true;
    }
    if(lines[h][w-1] -'0'< size){
        if(check_left(w-1, h, size)){
            return true;
        }
    }
    return false; 
}

int main(){
   fstream newfile;
   string line;
   int total{0};
   newfile.open("day8.txt",ios::in); //open a file to perform read operation using file object
   for(int i = 0 ; i < height ; i++){
        getline(newfile, line);
        lines[i] = line;
   }

   for(int h = 1 ; h < height-1 ; h++){
        for(int w = 1 ; w < width-1 ; w++){
            if(check_bot(w, h, lines[h][w]- '0') || check_top(w, h, lines[h][w] - '0') || check_left(w, h, lines[h][w]- '0') || check_right(w, h, lines[h][w] -'0')){
                total += 1;
            }
        }
   }
   cout << total  + height*2 + width*2 - 4;
}