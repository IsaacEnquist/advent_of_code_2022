#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int pos;

int get_num(string line){
    string num = "";
    bool after_equal = false;
    for(int i = pos; i<line.size(); i++){
        if(line[i]==',' || line[i]==':'){
            pos = i+1;
            break;
        }
        if(after_equal){
            num += line[i];
        }
        if(line[i]=='='){
            after_equal = true;
        }
    }
    return stoi(num);
}

int main(){
   fstream newfile;
   string line;
   int size {35}; // Set to amount of lines of input
   int sensorx[size];
   int sensory[size];
   int beaconx[size];
   int beacony[size];
   int index = {0};
   int inspect_row {2000000};
   newfile.open("day15.txt",ios::in); //open a file to perform read operation using file object
      while(getline(newfile, line)){
        pos = 0;
        sensorx[index] = get_num(line);
        sensory[index] = get_num(line);
        beaconx[index] = get_num(line);
        beacony[index] = get_num(line);
        index += 1;
   }

    int beacon_dist;
    int dist_to_inspect_row;
    int rangetop[size];
    int rangebot[size];
    for(int i = 0; i < size; i++){
        beacon_dist = abs(sensorx[i] - beaconx[i]) + abs(sensory[i] - beacony[i]);
        dist_to_inspect_row = abs(sensory[i] - inspect_row);
        if (beacon_dist >= dist_to_inspect_row){
            rangetop[i] = sensorx[i] + beacon_dist - dist_to_inspect_row;
            rangebot[i] = sensorx[i] - beacon_dist + dist_to_inspect_row;
        }
        else{
            rangetop[i] = -8000000;
            rangebot[i] = -8000000;
        }
    }


    for(int i = 0; i < size; i++){
        if(rangetop[i] != -8000000){
            for(int j = i; j < size; j++){
                //cout << rangebot[i] << "   ibot itop   " << rangetop[i] << "    " << rangebot[j] << "   jbot jtop   " << rangetop[j] << "before\n";
                if(rangetop[j] != -8000000 && rangetop[i] != -8000000){
                    if(rangetop[j] > rangetop[i] && rangetop[i] >= rangebot[j]){
                        if(rangebot[i] >= rangebot[j]){ // Range cotained in other range
                            rangetop[i] = -8000000;
                            rangebot[i] = -8000000;
                        }
                        else{
                            rangetop[i] = rangebot[j] - 1;
                        }
                    }
                    if(rangebot[i] > rangebot[j] && rangebot[i] <= rangetop[j]){
                        if(rangetop[j] >= rangetop[i]){ // Range cotained in other range
                            rangetop[i] = -8000000;
                            rangebot[i] = -8000000;
                        }
                        else{
                            rangebot[i] = rangetop[j] + 1;
                        }
                    }
                }
            //cout << rangebot[i] << "   ibot itop   " << rangetop[i] << "    " << rangebot[j] << "   jbot jtop   " << rangetop[j] << "after\n";
            }
        }    
    }
    int no_beacon {0};
    for(int i = 0; i < size; i++){
        if(rangetop[i] != -8000000){
            no_beacon += rangetop[i] - rangebot[i] + 1;
        }
    }
    cout << no_beacon - 1;
}