#include<iostream>
#include<stdio.h>
using namespace std;

int sumOfNaturalNoRecursive(int num){				// Time Complexity: O(n)   // Space Complexity: O(n)
	if(num==1)
		return 1;
	return sumOfNaturalNoRecursive(num-1)+num;
}

int sumOfNaturalNoIterative(int num){				// Time Complexity: O(n)   // Space Complexity: O(1)
	int ans=0;
	for(int i=1;i<=num;i++){
		ans+=i;
	}
	return ans;
}

int sumOfNaturalNoFormula(int num){					// Time Complexity: O(1)   // Space Complexity: O(1)
	return num*(num+1)/2;
}

int main(){
	printf("%d ",sumOfNaturalNoRecursive(5));
	printf("%d ",sumOfNaturalNoIterative(5));
	printf("%d ",sumOfNaturalNoFormula(5));
	return 0;
}
