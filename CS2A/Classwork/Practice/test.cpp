#include <iostream>
#include <time.h>
using namespace std;

int main () {
    int num;
    for (int i = 0; i < (time(0) % 60) ; i++) 
        num = rand() % 1000000;
    cout << num << endl;
    return 0;
}
