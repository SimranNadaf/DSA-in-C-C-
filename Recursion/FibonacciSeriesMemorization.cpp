#include<stdio.h>
#include<iostream>
using namespace std;

int f[10];

int fab(int n){
	if(n<=1) return n;
	if(!f[n-1]) f[n-1]=fab(n-1);
	if(!f[n-2]) f[n-2]=fab(n-2);
	return f[n-2]+f[n-1];
}

int main(){
	printf("%d ",fab(7));
	return 0;
}
