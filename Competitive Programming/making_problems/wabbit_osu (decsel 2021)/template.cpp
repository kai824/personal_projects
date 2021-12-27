#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32//to allow for local testing on windows computers...
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

void readInt(int &v) {
  v = 0;
  char ch = getchar_unlocked();
  for (; ch < '0' || ch > '9'; ch = getchar_unlocked());
  for (; '0' <= ch && ch <= '9'; ch = getchar_unlocked())
    v = (v << 3) + (v << 1) + (ch & 15);
}
void readBinaryString(string &s){
  s="";
  char c;
  while(c=getchar_unlocked() && (c=='0' || c=='1') )s+=c;
}
void outputInt(int o){
  string s=to_string(o);
  for(char c:s)putchar_unlocked(c);
}
void outputChar(char c){
  putchar_unlocked(c);
}
int32_t main(){
  int N;
  readInt(N);
  string S;
  readBinaryString(S);

  //code here...

  for(int i=1;i<=N;i++){
    outputInt(1);
    if(i<n)outputChar(' ');
  }

  return 0;
}
/*

*/
