#include<stdio.h>
#include<iostream>
using namespace std;

int com(int n,int r){				
	if(r==0 | n==r) return 1;
	return com(n-1,r-1)+com(n-1,r);
}

int main(){
	printf("%d ",com(3,2));
	return 0;
}
