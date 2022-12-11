#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <array>
using namespace std;

long long int throw_to(int monkey, long long int value){
    int throw_to;
    switch (monkey) {
        case 0:
            if(value % 11 == 0){
                throw_to = 3;
            }
            else{
                throw_to = 4;
            }
            break;
        case 1:
            if(value % 2 == 0){
                throw_to = 6;
            }
            else{
                throw_to = 7;
            }                    
            break;
        case 2:
            if(value % 5 == 0){
                throw_to = 1;
            }
            else{
                throw_to = 5;
            }
            break;
        case 3:
            if(value % 17 == 0){
                throw_to = 2;
            }
            else{
                throw_to = 5;
            }    
            break;
        case 4:
            if(value % 19 == 0){
                throw_to = 2;
            }
            else{
                throw_to = 3;
            } 
            break;
        case 5:
            if(value % 7 == 0){
                throw_to = 1;
            }
            else{
                throw_to = 6;
            } 
            break;
        case 6:
            if(value % 3 == 0){
                throw_to = 0;
            }
            else{
                throw_to = 7;
            }         
            break;
        case 7:
            if(value % 13 == 0){
                throw_to = 4;
            }
            else{
                throw_to = 0;
            } 
            break;
    }
    return throw_to;
}


long long int update_value(int monkey, long long int value){
    switch (monkey) {
        case 0:
            value = (long long int)((value * 5) / 3);
            break;
        case 1:
            value = (long long int)((value * value) / 3);
            break;
        case 2:
            value = (long long int)((value * 7) / 3);
            break;
        case 3:
            value = (long long int)((value + 1) / 3);
            break;
        case 4:
            value = (long long int)((value + 3) / 3);
            break;
        case 5:
            value = (long long int)((value + 5) / 3);
            break;
        case 6:
            value = (long long int)((value + 8) / 3);
            break;
        case 7:
            value = (long long int)((value + 2) / 3);
            break;
    }
    return value;
}

int main(){
    long long int items[36] = {92, 73, 86, 83, 65, 51, 55, 93, 99, 67, 62, 61, 59, 98, 81, 89, 56, 61, 99, 97, 74, 68, 78, 73, 50, 95, 88, 53, 75, 50, 77, 98, 85, 94, 56, 89};
    int current_monkey[36] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7};
    int monkeys {8};
    int total_instpections[monkeys] = {0};
    for(int j = 0; j < 20; j++){
        for(int l = 0; l < monkeys; l++){
            for(int i = 0; i < 36; i++){
                if(current_monkey[i] == l){
                    total_instpections[l] += 1;
                    items[i] = update_value(l, items[i]);
                    current_monkey[i] = throw_to(l, items[i]);
                }
            }
            for(int k = 0; k < 36; k++){
                cout << items[k] << " ";
            }
            cout << "\n";
        }     
    }
    for(int k = 0; k < monkeys; k++){
        cout << total_instpections[k] << " ";
    }
}
