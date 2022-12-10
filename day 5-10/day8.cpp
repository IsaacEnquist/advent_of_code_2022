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

int check_top(int w, int h, int size, int total){
    if(h==0){
        return total - 1;
    }
    if(lines[h-1][w] -'0' < size){
        total = check_top(w, h-1, size, total + 1);
    }
    return total; 
}

int check_bot(int w, int h, int size, int total){
    if(h==height-1){
        return total - 1;
    }
    if(lines[h+1][w] -'0'< size){
        total = check_bot(w, h+1, size, total + 1);

    }
    return total; 
}

int check_right(int w, int h, int size, int total){
    if(w==width-1){
        return total - 1;
    }
    if(lines[h][w+1] -'0'< size){
        total = check_right(w+1, h, size, total + 1);
    }
    return total; 
}

int check_left(int w, int h, int size, int total){
    if(w == 0){
        return total - 1;
    }
    if(lines[h][w-1] -'0'< size){
        total = check_left(w-1, h, size, total + 1);
    }
    return total; 
}

int main(){
   fstream newfile;
   string line;
   int score {0};
   int current {0};
   newfile.open("day8.txt",ios::in); //open a file to perform read operation using file object
   for(int i = 0 ; i < height ; i++){
        getline(newfile, line);
        lines[i] = line;
   }

   for(int h = 1 ; h < height-1 ; h++){
        for(int w = 1 ; w < width-1 ; w++){
            current = check_top(w, h, lines[h][w] - '0', 1) * check_bot(w, h, lines[h][w] - '0', 1) * check_left(w, h, lines[h][w] - '0', 1) * check_right(w, h, lines[h][w] - '0', 1);
            if(score < current){
                score = current;
            }
        }
   }
   cout << score;
}