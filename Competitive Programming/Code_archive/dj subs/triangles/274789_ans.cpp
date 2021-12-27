// ans.cpp 1 Dec 17, 16:32:40 100 0 Judging completed in 4.259s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool T(int a, int b, int c){
    if (a+b<=c) return 0;
    if (a+c<=b) return 0;
    if (b+c<=a) return 0;
    return 1;
}
int main() {
    int N; cin >> N;
    int third, second, first; cin >> third >> second >> first;
    if (T(third, second, first)){
        cout << "YES\n"; return 0;
    }
    int A[] = {third, second, first};
    sort(A,A+3);
    third = A[0]; second = A[1]; first = A[2];
    for (int i = 3, a; i < N; ++i){
        cin >> a;
        if (a > first){
            third = second; second = first; first = a;
        }else if (a > second){
            third = second; second = a;
        }else if (a > third){
            third = a;
        }else if (T(third, second, a)){
            cout << "YES\n"; return 0;
        }
        if (T(third, second, first)){
            cout << "YES\n"; return 0;
        }
    }
    cout << "NO\n";
}