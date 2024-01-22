#include<stdio.h>
#include<iostream>
using namespace std;

int e(int x, int n){
	static int p=1,f=1;
	int r;
	if(n==0)
		return 1;
	r=e(x,n-1);
	p=p*x;
	f=f*n;
	return r+p/f;
}

int main(){
	printf("%d ",e(5,5));
	return 0;
}
