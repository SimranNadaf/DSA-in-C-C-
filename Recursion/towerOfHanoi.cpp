#include<stdio.h>
#include<iostream>
using namespace std;

void TOH(int n, int a, int b, int c){						// time Complexity : O(2^n)
	if(n>0){
		TOH(n-1,a,c,b);
		printf("move from %d to %d\n",a,c);
		TOH(n-1,b,a,c);
	}
}

int main(){
	TOH(3,1,2,3);
	return 0;
}
