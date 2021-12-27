// judgequeue.cpp 13 Oct 17, 23:40:40 0 3.17 Judging completed in 9.694s on AWS Oregon.
#include "judgequeue.h"
#include<bits/stdc++.h>
using namespace std;
deque<int> judge;
int limit=10000000;
/* Initialize function */
void init (int X, int N) {
    
}

/* Update functions */
void push_front (int subID) {
    if(subID>limit)while(true){}
}
void push_back (int subID) {
    if(subID>limit)while(true){}
}
void insert_before (int subID, int ref) {
    if(subID>limit)while(true){}
}
void insert_after (int subID, int ref) {
    if(subID>limit)while(true){}
}

/* Access functions */
int queue_front() {
    return 0;
}
int queue_back() {
    return 0;
}
int sub_before (int ref) {
    return 0;
}
int sub_after (int ref) {
    return 0;
}

/* Modify functions */
void pop_front() {
}
void pop_back() {
}
void erase (int subID) {
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