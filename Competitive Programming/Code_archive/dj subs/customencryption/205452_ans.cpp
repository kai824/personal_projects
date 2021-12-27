// ans.cpp 29 Apr 17, 21:56:38 0 1 Judging completed in 10.677s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
string stored;
int cs=0;//current shift
void loadCipher(string plaintext) {
	stored=plaintext;
}
void shift(int s) {
	int a;
	for(int x=0;x<stored.length();x++){
		a=(int)stored[x];
		a-=97;
		a+=13;
		a%=26;
		a+=97;
		stored[x]=(char)a;
	}
}
int getLetter(int position) {
	int a=(int)stored[position];
	a-=97;
	a%=26;
	return (((int)stored[position])-96);
}
int main(){
	int ans=0;
    string a;
    bool b=false;
    cin>>a;
    a=a+" ";
    for(int x=0;x<a.length();x++){
        if(b){
            b=false;
            if(isdigit(a[x])){
                for(int y=0;y<a[x]-'0';y++){
                    stored=stored+" ";
                    stored[stored.length()-1]=a[x-1];
                }
            }else{
                stored=stored+" ";
                stored[stored.length()-1]=a[x-1];
            }
        }
        if(a[x]=='!'){
            shift(13);
        }else if(isalpha(a[x])){
            b=true;
        }
    }
    for(int x=0;x<stored.length();x++){
    	ans+=getLetter(x);
    }
    cout<<ans;
    return 0;
}