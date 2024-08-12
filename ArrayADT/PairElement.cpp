#include<stdio.h>
#include<iostream>
using namespace std;

void pairElement(int a[], int n,int k){			// pair Element, O(n^2)
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]+a[j]==k){
				printf("Pair Elements is: %d, %d\n",a[i],a[j]);
			}
		}
	}
	printf("Pair Elements Not Found\n");
}

void pairElementWithHashing(int a[], int n, int k, int max){		// pair Element with hashing
							//  TC: O(n)	SC: O(n)
	int temp[max]={0};
	for(int i=0;i<n;i++){
		if(temp[k-a[i]]!=0){
			printf("Pair Elements is %d, %d\n",a[i],k-a[i]);
		}
		else{
			temp[a[i]]=1;
		}
	}
	printf("Pair Elements Not Found\n");
}

int main(){
	int a[5]={10,20,6,2,1};
//	pairElement(a,5,9);
	pairElementWithHashing(a,5,10,20);
	return 0;
}
