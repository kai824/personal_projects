// ans.cpp 26 Dec 16, 00:03:30 100 0.18 Judging completed in 5.703s on AWS Ireland.
#include "swapcup.h"
using namespace std;
short int a=2,b;//a is the cup the ball is currently at.
void startGame(){}

void swap(int A, int B) {
    if(A==a){
        a=B;
    }else if(B==a){
        a=A;
    }
}

int getAnswer() {
    return a;
}