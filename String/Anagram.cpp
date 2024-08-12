#include<stdio.h>
#include<iostream>
using namespace std;

void isAnagram(char a[], char b[]){
	char hash[26] = {0};
	int i;
	for(i=0;a[i]!='\0';i++){
		hash[a[i]-97]++;
	}
	for(i=0;b[i]!='\0';i++){
		hash[b[i]-97]--;
		if(hash[b[i]-97] < 0){
			break;
		}
	}
	if(b[i]=='\0'){
		printf("%s and %s are Anagram\n",a,b);
	}
	else{
		printf("%s and %s are not Anagram\n",a,b);
	}
}

int main(){
	char A[] = "medical";
	char B[] = "decimal";
	isAnagram(A,B);
	
	char C[] = "simran";
	char D[] = "nadaf";
	isAnagram(C,D);
	return 0;
}
