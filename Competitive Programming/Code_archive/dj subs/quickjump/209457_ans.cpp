// ans.cpp 5 Jun 17, 22:07:59 0 0 Judging completed in 3.636s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
vector<ll> fibo={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,2269806340,4539612680,9079225360,18158450720,36316901440,72633802880,145267605760,290535211520,581070423040,1162140846080,2324281692160,4648563384320,9297126768640,18594253537280,37188507074560,74377014149120,148754028298240,297508056596480,595016113192960,1190032226385920,2380064452771840,4760128905543680,9520257811087360,19040515622174720,38081031244349440,76162062488698880,152324124977397760,304648249954795520,609296499909591040};
int main() {
    ll n,it=fibo.size()-1,ans=0;
    cin>>n;
    while(n>0){
        ans+=n/fibo[it];
        n%=fibo[it];
        it--;
    }
    ans=ans*3;
    if(ans<0)cout<<1/0;
    return 0;
}