#include<stdio.h>
#include<iostream>
using namespace std;

void palindrome(char a[]){
	int i;
	for(i=0;a[i]!='\0';i++){
	}
	i--;
	int j;
	for(j=0;j<i;j++,i--){
		if(a[j] != a[i]){
			break;
		}
	}
	if(a[j]!=a[i]){
		printf("%s String is not Palindrome\n",a);
	}
	else{
		printf("%s String is Palindrome\n",a);
	}
}
int main(){
	char A[] = "madam";
	char B[] = "hello";
	palindrome(A);
	palindrome(B);
	return 0;
}
