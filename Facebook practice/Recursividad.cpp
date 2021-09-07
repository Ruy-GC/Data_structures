#include <iostream>

using namespace std;

int fibonacci(int x){
    if (x <= 1) return 1;
    return fibonacci(x-1)+fibonacci(x-2);
}

int factorial(int x){
    if (x <= 1) return 1;
    return factorial(x-1)*x;
}

int main(){

    cout<<"Hello World Recursividad"<<endl;
    cout<<fibonacci(5)<<endl;
    cout<<factorial(5)<<endl;

    return 0;
}