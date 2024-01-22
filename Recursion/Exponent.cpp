#include<stdio.h>
#include<iostream>
using namespace std;

int pow(int m, int n){     			// time complexity: O(n)    space complexity: O(n)
	if(n==0)
		return 1;
	return pow(m,n-1)*m;
}

int pow2(int m, int n){				// time complexity: O(n/2)    space complexity: O(n)		
	if(n==0)
	return 1;
	if(n%2==0){
		return pow2(m*m,n/2);
	}
	else{
		return m*pow2(m*m,(n-1)/2);
	}
}

int main(){
	printf("%d ",pow(5,3));
	printf("%d ",pow2(5,3));
	return 0;
}
