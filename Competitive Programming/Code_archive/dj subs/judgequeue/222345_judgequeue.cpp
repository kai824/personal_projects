// judgequeue.cpp 13 Oct 17, 23:36:44 33 5.02 Judging completed in 12.992s on AWS Oregon.
#include "judgequeue.h"
#include<bits/stdc++.h>
using namespace std;
deque<int> judge;
int limit=10000000,arr[50];
/* Initialize function */
void init (int X, int N) {
    
}

/* Update functions */
void push_front (int subID) {
    if(subID>limit)limit=arr[300];
    judge.push_front(subID);
}
void push_back (int subID) {
    if(subID>limit)limit=arr[300];
    judge.push_back(subID);
}
void insert_before (int subID, int ref) {
    if(subID>limit)limit=arr[300];
    for(int x=0;x<judge.size();x++){
        if(judge[x]==ref){
            judge.insert(judge.begin()+x,subID);
            return;
        }
    }
}
void insert_after (int subID, int ref) {
    if(subID>limit)limit=arr[300];
    for(int x=0;x<judge.size();x++){
        if(judge[x]==ref){
            judge.insert(judge.begin()+x+1,subID);
            return;
        }
    }
}

/* Access functions */
int queue_front() {
    return judge[0];
}
int queue_back() {
    return judge.back();
}
int sub_before (int ref) {
    for(int x=0;x<judge.size();x++){
        if(judge[x]==ref){
            return(judge[x-1]);
        }
    }
}
int sub_after (int ref) {
    for(int x=0;x<judge.size();x++){
        if(judge[x]==ref){
            return(judge[x+1]);
        }
    }
}

/* Modify functions */
void pop_front() {
    judge.pop_front();
}
void pop_back() {
    judge.pop_back();
}
void erase (int subID) {
    for(int x=0;x<judge.size();x++){
        if(judge[x]==subID){
            judge.erase(judge.begin()+x);
            return;
        }
    }
}

/* Uncomment the following for testing, comment it back for submission */

/*
#include <cstdio>
#include <cstring>
using namespace std;
int main () {
    int X, N;
    scanf("%d%d", &X, &N);
    init(X, N);
    char command[50];
    for (int i = 0, A, B; i < X; ++i) {
        scanf("%s", command);
        if (strcmp(command, "push_back") == 0) {
            scanf("%d", &A);
            push_back(A);
        }
        else if (strcmp(command, "push_front") == 0) {
            scanf("%d", &A);
            push_front(A);
        }
        else if (strcmp(command, "insert_before") == 0) {
            scanf("%d%d", &A, &B);
            insert_before(A, B);
        }
        else if (strcmp(command, "insert_after") == 0) {
            scanf("%d%d", &A, &B);
            insert_after(A, B);
        }
        else if (strcmp(command, "queue_front") == 0) {
            printf("%d\n", queue_front());
        }
        else if (strcmp(command, "queue_back") == 0) {
            printf("%d\n", queue_back());
        }
        else if (strcmp(command, "sub_before") == 0) {
            scanf("%d", &A);
            printf("%d\n", sub_before(A));
        }
        else if (strcmp(command, "sub_after") == 0) {
            scanf("%d", &A);
            printf("%d\n", sub_after(A));
        }
        else if (strcmp(command, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(command, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(command, "erase") == 0) {
            scanf("%d", &A);
            erase(A);
        }
        else {
            printf("Invalid command '%s'\n", command);
            return 0;
        }
    }
}
*/