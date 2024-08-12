#include<stdio.h>
#include<iostream>
using namespace std;

void compare(char A[], char B[]){
	int i,j;
	for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++){
		if(A[i]!=B[j]){
			break;
		}
	}
	if(A[i]==B[j]){
		printf("Equal\n");
	}
	else if(A[i]<B[j]){
		printf("Less\n");
	}
	else{
		printf("Greater\n");
	}	
}

int main(){
	char A[] = "painter";
	char B[] = "painting";
	compare(A,B);
	compare(B,A);
	char C[] = "simran";
	char D[] = "simran";
	compare(C,D);
	return 0;
}
