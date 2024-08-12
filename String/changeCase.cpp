#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	char A[] = "WELCOME";
	
	// lower Case
	for(int i=0;A[i]!='\0';i++){
		A[i] += 32;
	}
	printf("Lower Case: %s\n", A);
	
	//Change Case
	char B[]="WeLCOme!!";
	for(int i=0;B[i]!='\0';i++){
		if(B[i]>=65 && B[i]<=90)
			B[i] += 32;
		else if(B[i]>=97 && B[i]<=122)
			B[i] -= 32;
	}
	printf("Change Case: %s", B);
	
	return 0;
}
