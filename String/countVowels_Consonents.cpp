#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	char A[]="how are you";
	int cvowel = 0;
	int cconsonent = 0;
	int i=0;
	for(;A[i]!='\0';i++){
		if((A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u') || (A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U')){
			cvowel++;			
		}
		else if((A[i] >= 65 && A[i] <=90) || (A[i] >=97 && A[i] <= 122)){
			cconsonent++;
		}
	}
	printf("Count of Vowels: %d\n",cvowel);
	printf("Count of Consonent: %d", cconsonent);
	return 0;
}
