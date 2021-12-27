// ans.cpp 16 Oct 17, 16:53:18 100 0.08 Judging completed in 4.593s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int cards;
struct md{
	int mv;//my value
	md *n,*fake;//next...
	md(int N) : mv(cards-N) {
		if(N==1){
			n=nullptr;
			
		}else{
			n=new md(N-1);
		}
        /*if (_s != _e) {
            l = new node(s, m);
            r = new node(m+1, e);
        }        */
    }
} *start;
md *e;
void init(int N){
	start=new md(N);
	e=start;
	while(e->n!=nullptr){//setting the end of the "deque"
		e=e->n;
	}
}
void push_front(int nv){
	md *x=new md(1);
	x->mv=nv;
	x->n=start;
	start=x;
}
void push_back(int nv){
	md *x=new md(1);
	x->mv=nv;
	e->n=x;
	x->n=nullptr;
	e=x;
}
/*void pop_back(){
	
}*/
void pop_front(){
	md *x=start;
	start=start->n;
	delete x;
}
void pop_second(){//pops the second element   :)
	md *x=start->n;
	start->n=start->n->n;
	delete x;
}
void output(int x){
	md *current=start;
	int y=0;
	while(current->n!=nullptr){
		if(x==-1)cout<<current->mv<<' ';
		if(y==x){
			cout<< current->mv <<' '<< current->n->mv <<' '<< current->n->n->mv;y++;break;
		}
		current=current->n;
		y++;
	}
	if(x==-1 || y==x)cout<<current->mv;
}
int main(){
	int k;string seq;
	cin>>cards>>k>>seq;
	init(cards);
	for(int x=0;x<seq.size();x++){
		if(seq[x]=='A'){
			push_back(start->mv);
			pop_front();
		}else if(seq[x]=='B'){
			push_back(start->n->mv);
			pop_second();
		}
	}
	output(k-1);
	return 0;
}