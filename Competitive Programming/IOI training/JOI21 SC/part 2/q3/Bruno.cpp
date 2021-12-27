#include "Bruno.h"
#include <vector>
using namespace std;

namespace {
int right=0;
int left=1;
int down=2;
int up=3;
int stay=4;
} // namespace

vector<int> Bruno(int K, vector<int> value) {//k cells + value of length 9
  for(int j=0;j<9;j++)value[j]--;
  vector<int> res(K, 0);
  bool u1,b1;
  for (int i = 0; i < K; i++) {
    int a=value[0]&1,b=value[1]&1,c=value[2]&1;
    if(a==b && b==c && a==1)u1=1;
    else u1=0;
    a=value[6]&1,b=value[7]&1,c=value[8]&1;
    if(a==b && b==c && a==0)b1=1;
    else b1=0;
    if(u1 && b1){
      a=value[3]&1,b=value[4]&1,c=value[5]&1;
      if(a==b && b==c){
        if(a==1)res[i]=down;
        else res[i]=left;
      }else{
        if(a==1 && b==0 && c==0)res[i]=stay;
        else res[i]=right;
      }
    }else{
      if(u1)res[i]=down;
      if(b1)res[i]=up;
    }

    for(int j=0;j<9;j++)value[j]/=2;
  }
  return res;
}
