#include<stdio.h>
#include<iostream>
using namespace std;

// Compare with other letter: TC = O(n^2)
void duplicate(char a[]){
	for(int i=0;a[i]!='\0';i++){
		for(int j=i+1;a[j]!='\0';j++){
			if(a[i] == a[j]){
				printf("%c",a[i]);
				a[j] = 0;
			}
		}
	}
}

// Use Hashtable as counting
void duplicateHash(char a[]){
	int hash[26]={0};
	for(int i=0;a[i]!='\0';i++){
		hash[a[i]-97]++;
	}
	for(int i=0;i<26;i++){
		if(hash[i]>1){
			printf("%c count: %d\n",i+97,hash[i]);
		}
	}
}

// Using masking(ANDing)& and merging(ORing)|
void duplicateBit(char a[]){
	long int h=0;
	int i;
	int x;
	for(i=0;a[i]!='\0';i++){
		x=1;
		x = x << a[i]-97;
		if((h & x) != 0){
			printf("duplacate: %c\n",a[i]);
		}
		else{
			h = x | h;
		}
	}
}

int main(){
	char A[] = "finding";
	duplicateBit(A);
	return 0;
}
