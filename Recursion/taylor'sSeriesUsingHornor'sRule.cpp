#include<stdio.h>
#include<iostream>
using namespace std;

int e(int x,int n){
	static int s=1;
	if(n==0)
		return s;
	s=1+x/n*s;
	return e(x,n-1);
}

int eI(int x,int n){
	int s=1;
	for(;0<n;n--){
		s=1+x/n*s;
	}
	return s;
}
int main(){
	printf("%d ",e(5,5));
	printf("%d ",eI(5,5));
	return 0;
}
