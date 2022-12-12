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
    const int width {8};
    const int height {5};
    //char letters[41][161];
    char letters[height][width];
    int graph_matrix[height * width][height * width] = {{0}};
    int index {0};
    int dist[height * width][height * width] = {{0}};
    newfile.open("test.txt",ios::in); //open a file to perform read operation using file object
    while(getline(newfile, line)){
        for(int i = 0; i < line.size(); i++){
            letters[index][i] = line[i];
        }            
        index += 1;
    }
    cout << letters[0][0];
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i > 0){
                if(int(letters[i][j]) + 1 >= int(letters[i-1][j])){
                    graph_matrix[i*width + j][(i-1)*width + j] = 1;
                }
            }
            if(i < height-1){
                if(int(letters[i][j]) + 1 >= int(letters[i+1][j])){
                    graph_matrix[i*width + j][(i+1)*width + j] = 1;
                }
            }
            if(j > 0){
                if(int(letters[i][j]) + 1 >= int(letters[i][j-1])){
                    graph_matrix[i*width + j][i*width + j-1] = 1;
                }
            }
            if(j < width-1){
                if(int(letters[i][j]) + 1 >= int(letters[i][j+1])){
                    graph_matrix[i*width + j][i*width + j+1] = 1;
                }
            }
        }
    }
    cout << letters[0][0] << "\n";
    for(int i = 0; i < height * width; i++){
        for(int j = 0; j < height * width; j++){
            std::cout << graph_matrix[i][j];
            if(graph_matrix[i][j] == 0 && i!=j){
                graph_matrix[i][j] = width*height + 2;
            }
            //std::cout << graph_matrix[i][j];
        }
        std::cout << "\n";
    }
    for(int k = 0; k < width*height; k++){
        for(int i = 0; i < height * width; i++){
            for(int j = 0; j < height * width; j++){
                if(graph_matrix[i][j] > graph_matrix[i][k] + graph_matrix[k][j]){
                    graph_matrix[i][j] = graph_matrix[i][k] + graph_matrix[k][j];
                }        
            }
        }
    }

    cout << letters[0][0];
    for(int i = 0; i < height * width; i++){
        for(int j = 0; j < height * width; j++){
            std::cout << graph_matrix[i][j] << "  ";
            //std::cout << graph_matrix[i][j];
        }
        cout << i << "<-row   " << letters[(int)(i / 8)][i%8]<<"\n";
    }

    cout << graph_matrix[0][21] << "\n";
}