#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue queTest;
    queTest.CreateQueue();
    for (int i = 0; i < 102; i++){
        queTest.AddElement(i);
    }

    for (int i = 0; i < 50; ++i){
        queTest.PopQueue();
    }

    return  0;
}