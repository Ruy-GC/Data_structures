#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

vector<int> selection_sort(vector <int> a){
    //Algoritmo de ordenamiento
    int n = a.size();
    for (int i = 0;i < n -1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[min_idx]){
                int temp = a[j];
                a[j] = a[min_idx];
                a[min_idx] = temp;
            }
        }
    }
    return a;
}

int main(){
    system("cls");
    int nums = 10;
    vector<int> x(nums,0);

    //use srand() for different outputs
    srand(time(0));

    generate(x.begin(),x.end(),[]() {
       return rand() % 100;
    });

    cout<<"Vector before sorting:"<<endl;
    for(int i = 0; i<nums; i++){
        cout<<x[i]<<" ";
    }

    cout<<"\nVector after sorting:"<<endl;
    x = selection_sort(x);
    for(int i = 0; i<nums; i++){
        cout<<x[i]<<" ";
    }

    return 0;
}