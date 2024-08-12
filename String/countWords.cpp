#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	char A[]="How are you?";
	int word=1;
	int i;
	for(i=0;A[i]!='\0';i++){
		if(A[i]==' '){
			word++;
		}
	}
	printf("Words: %d",word);
	return 0;
}
