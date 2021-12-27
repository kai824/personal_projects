// wires.cpp 23 Feb 19, 13:51:45 0 0 Compilation failed on AWS Oregon.
void wire(int n, int P, int order[]){
	//cout<<'\n';
	int vp=1,hp=1,nex=0;//one for vertical, one for horizontal
	while(vp<=n && hp<=n){
	    if(press(vp,hp)==0){
	        order[nex]=1;
	        hp++;
	        nex++;
	    }else{
	        order[nex]=0;
	        nex++;
	        vp++;
	    }
	}
	if(vp==n){
	    for(int x=hp;x<=n;x++){
	        order[nex]=1;//since horizontal
	        nex++;
	    }
	}else if(hp==n){
	    for(int x=vp;x<=n;x++){
	        order[nex]=0;//vertical stuff
	        nex++;
	    }
	}
	for(int x=0;x<2*n;x++){
		//cout<<order[x];
	}
	//cout<<'\n';
}