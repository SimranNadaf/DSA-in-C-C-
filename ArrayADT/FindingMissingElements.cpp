#include<stdio.h>
#include<iostream>
using namespace std;

void findMissingSingleElement1(int a[], int n){			// first Natural Number
	int sum=0,s=0;										// single Element, sorted array
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	n++;
	s=n*(n+1)/2;
	printf("Missing Element %d\n",s-sum);
}

void findMissingSingleElement2(int a[], int n){			// not first natural no.
	int diff=a[0]-0;									// single element, sorted array
	for(int i=0;i<n;i++){
		if(a[i]-i!=diff){
			printf("Missing Element %d \n",diff+i);
			break;
		}
	}
}

void findMissingMultipleElement(int a[], int n){		// not first natural no.
	int diff=a[0]-0;									// multiple elements, sorted array
	for(int i=0;i<n;i++){
		if(a[i]-i!=diff){
			while(diff<a[i]-i){
				printf("%d \n",diff+i);
				diff++;
			}
		}
	}
}

int main(){
	int a[]={1,2,3,4,5,6,8,9,10,11};
	findMissingSingleElement1(a,10);
	
	int b[]={6,7,8,9,10,12,13,14,15,16};
	findMissingSingleElement2(b,10);
	
	int c[]={6,7,8,11,12,15,16,17,18,19};
	findMissingMultipleElement(c,10);
	return 0;
}
