// judgequeue.cpp 12 Nov 18, 23:29:28 100 3.68 Judging completed in 13.677s on AWS Oregon.
#include "judgequeue.h"
#include<bits/stdc++.h>
using namespace std;

list<int> q;
list<int>::iterator its[1000005];
/* Initialize function */
void init (int X, int N) {}

/* Update functions */
void push_front (int subID) {
    q.push_front(subID);
    its[subID]=q.begin();
}
void push_back (int subID) {
    q.push_back(subID);
    its[subID]=q.end();
    its[subID]--;
}
void insert_before (int subID, int ref) {
    its[subID]=q.insert(its[ref],subID);
}
void insert_after (int subID, int ref) {
    list<int>::iterator tmp=its[ref];
    tmp++;
    its[subID]=q.insert(tmp,subID);
}

/* Access functions */
int queue_front() {
    return q.front();
}
int queue_back() {
    return q.back();
}
int sub_before (int ref) {
    list<int>::iterator tmp=its[ref];
    tmp--;
    return *tmp;
}
int sub_after (int ref) {
    list<int>::iterator tmp=its[ref];
    tmp++;
    return *tmp;
}

/* Modify functions */
void pop_front() {
    q.pop_front();
}
void pop_back() {
    q.pop_back();
}
void erase (int subID) {
    q.erase(its[subID]);
}