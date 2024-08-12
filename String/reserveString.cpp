#include<stdio.h>
#include<iostream>
using namespace std;

// with extra space
void reverse(char a[]){
	int i=0;
	for(;a[i]!='\0';i++){
	}
	char b[i];
	i--;
	for(int j=0;a[j]!='\0';j++,i--){
		b[j] = a[i];
	}
	printf("Reverse of %s is %s\n",a,b);
}

// without extra space
void reverse2(char a[]){
	int i=0;
	for(;a[i]!='\0';i++){
	}
	i--;
	for(int j=0;j<i;j++,i--){
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	printf("Reverse: %s\n",a);
}

int main(){
	char A[]="Simran";
	reverse(A);
	reverse2(A);
	return 0;
}
