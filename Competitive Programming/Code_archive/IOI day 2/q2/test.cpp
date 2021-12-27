#include "dungeons.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> s,p,w,l,x,z,answer,a2;
int n=7,q=100;

int simp(int x,int z){
	while(x<n){
		if(z<s[x]){
			z+=p[x];
			x=l[x];
		}else{
			z+=s[x];
			x=w[x];
		}
	}
	return z;
}

int main(){
	s.resize(n);
	p.resize(n);
	w.resize(n);
	l.resize(n);
    x.resize(q);
    z.resize(q);
    answer.resize(q);
		a2.resize(q);


	while(true){
		s[0]=1+(rand()%100);
		for (int i = 1; i < n; i++) {
			s[i]=s[0];
		}
		for (int i = 0; i < n; i++) {
			p[i]=1+(rand()%7);
		}
		for (int i = 0; i < n; i++) {
			w[i]=i+1+(rand()%(n-i));
		}
		for (int i = 0; i < n; i++) {
			l[i]=(rand()%(n+1));
		}

// std::cerr<<"Done reading input\n";

    init(n, s, p, w, l);

		// cerr<<"Init function worked :)\n";
    for (int i = 0; i < q; i++) {
			x[i]=rand()%n;
			z[i]=1+(rand()%20);
				//cerr<<x[i]<<' '<<z[i]<<'\n';

			answer[i] = simulate(x[i], z[i]);
			a2[i]=simp(x[i],z[i]);
			if(answer[i]!=a2[i]){
				cout<<"YAY\n";
				ofstream out("tc.txt");
				out<<n<<' '<<1<<'\n';
				for(int i=0;i<n;i++)out<<s[i]<<' ';out<<'\n';
				for(int i=0;i<n;i++)out<<p[i]<<' ';out<<'\n';
				for(int i=0;i<n;i++)out<<w[i]<<' ';out<<'\n';
				for(int i=0;i<n;i++)out<<l[i]<<' ';out<<'\n';
				out<<x[i]<<' '<<z[i]<<'\n';
				out.close();
				cout<<answer[i]<<' '<<a2[i]<<'\n';
				return 0;
			}
    }
		//out.close();
	}
    return 0;
}
