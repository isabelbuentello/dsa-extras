#include <iostream>
using namespace std;



int main(){

    int **arr= new int*[10];
    for (int i=0; i<10; i++) {
        arr[i] = new int[10];
    }

    return 0;
}