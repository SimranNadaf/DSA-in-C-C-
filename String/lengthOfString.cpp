#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	char A[] = {'A','B','C'};
	char B[] = {65,66,67};
	char C[] = "ABC";
	printf("%s\n",A);
	printf("%s\n",B);
	printf("%s\n",C);
	int i;
	for(i=0;A[i]!='\0';i++){
	}
	printf("Length: %d",i);
	return 0;
}
