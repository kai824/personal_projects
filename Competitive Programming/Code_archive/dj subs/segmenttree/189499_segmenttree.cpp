// segmenttree.cpp 10 Feb 17, 22:49:42 0 0.17 Judging completed in 4.681s on AWS Ireland.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
struct node {
	int left, right, mid, value;
	node *left_child, *right_child;
	
	node(int _left, int _right){
		
		left = _left;
		right = _right;
		mid = (_left + _right) / 2;
		value = 0;
		
		if (left != right) {
			left_child = new node(left, mid);
			right_child = new node(mid+1, right);
		}
	}
	
	void update(int pos, int newval){
		if(left == right){
			value = newval;
		}
		else{
			if(pos <= mid) left_child -> update(pos, newval);
			else right_child -> update(pos, newval);
			value = min(left_child -> value, right_child -> value);
		}
	}
	
	int query(int qleft, int qright){
		if(qleft == left && qright == right) return value;
		else if(qright <= mid) return left_child -> query(qleft, qright);
		else if(qleft > mid) return right_child -> query(qleft, qright);
		else{
			return min(
				left_child -> query(qleft, mid),
				right_child -> query(mid + 1, qright)
			);
		}
	}
  
};
node *root;
void init(int N) {
    root=new node(1, N);
}

void update(int P, int V) {
    root->update(P,V);
}

int query(int A, int B) {
    return (root->query(A,B));
}