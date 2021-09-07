#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void readfile(vector <string> &data){

    string filename("bitacora.txt");
    string line;
    ifstream file(filename);

    if(!file.is_open()){
        cout<<"Could not pen the file "<<filename<<endl;
    }else{
        while(getline(file,line)){
            data.push_back(line);
        }
        
    }

}


int main(){
    vector<string> data;
    readfile(data);

    return 0;
}