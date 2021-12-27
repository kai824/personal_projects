// tetris.cpp 2 Dec 17, 10:24:14 0 0 Compilation failed on AWS Oregon.
#include "tetris.h"
#include<bits/stdc++.h>
using namespace std;
int rotation,position;
deque<string>board;

void init(int n){}

void new_figure(int f){
    if(f==1){
        rotation=0;position=0;
        return;
    }
    if(f==2){
        if(board.size()==0){
            rotation=0;position=0;
            board.push_back("110");
            return;
        }
        if(board.size()==1){
            if(board[0][1]=="1"){
                if(board[0][0]=="1"){
                    position=2;
                    rotation=1;
                    board[0]="001";
                    return;
                }else{
                    rotation=1;
                    position=0;
                    board[0]="100";
                    return;
                }
            }else{//board[0][1]=="0"
                if(board[0][0]=="1"){
                    rotation=0;
                    position=1;
                    board.pop_back();
                    return;
                }else{
                    rotation=0;
                    position=0;
                    board.pop_back();
                    return;
                }
            }
        }else if(board.size()==2){
            if(board[1][0]=="1"){
                rotation=0;
                position=1;
                board.pop_back();
                return;
            }else{
                position=0;
                rotation=0;
                board.pop_back();
                return;
            }
        }
        return;
    }
    if(f==3){
        if(board.size()==0){
            rotation=0;position=0;
            board.push_back("110");
            board.push_back("100");
            return;
        }
        if(board.size()==1){
            if(board[0][1]=="1"){
                if(board[0][0]=="1"){//110
                    position=1;
                    rotation=2;
                    board[0]="011";
                    return;
                }else{//011
                    rotation=3;
                    position=0;
                    board[0]="110";
                    return;
                }
            }else{//board[0][1]=="0"
                if(board[0][0]=="1"){//100
                    rotation=1;
                    position=1;
                    board[0]="001";
                    return;
                }else{//001
                    rotation=0;
                    position=0;
                    board[0]="100";
                    return;
                }
            }
        }else if(board.size()==2){
            if(board[1][0]=="1"){
                rotation=2;
                position=1;
                board.pop_back();
                board.pop_back();
                return;
            }else{
                position=0;
                rotation=3;
                board.pop_back();
                board.pop_back();
                return;
            }
        }
        return;
    }
}



int get_position() {
	return position;
}
int get_rotation() {
	return rotation;
}