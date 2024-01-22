#include<stdio.h>
#include<iostream>
using namespace std;

int fab(int n){							// Time complexity: O(2^n)
	if(n<=1)
		return n;
	return fab(n-2)+fab(n-1);
}

int fabI(int n){					// Time Complexity: O(n)
	int a=0;
	int b=1;
	int ans;
	if(n<=1) return n;
	for(int i=2;i<=n;i++){
		ans=a+b;
		a=b;
		b=ans;
	}
	return ans;
}

int main(){
	printf("%d ",fab(7));
	printf("%d ",fabI(7));
	return 0;
}
