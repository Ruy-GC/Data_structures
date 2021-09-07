#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

vector<int> bubble_sort(vector <int> a){
    //Algoritmo de ordenamiento
    int n = a.size();
    for (int i = 0;i < n ; i++){
        for (int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
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
    x = bubble_sort(x);
    for(int i = 0; i<nums; i++){
        cout<<x[i]<<" ";
    }

    return 0;
}