#include<stdio.h>
#include<iostream>
using namespace std;

int factRecursive(int n){				// Time Complexity: O(n)   Space Complexity: O(n)
	if(n==0)
		return 1;
	return factRecursive(n-1)*n;
}

int factIterative(int n){			// Time Complexity: O(n)   Space Complexity: O(1)
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}

int main(){
	printf("%d ",factRecursive(5));
	printf("%d ",factIterative(5));
	return 0;
}
