#include<stdio.h>
#include<iostream>
using namespace std;

void valide(char a[]){
	int i;
	for(i=0;a[i]!='\0';i++){
		if(!(a[i]>=65 && a[i]<=90) && !(a[i]>=97 && a[i]<=122) && !(a[i]>=48 && a[i]<=57)){
			break;
		}
	}
	if(a[i]=='\0'){
		printf("String is Valide\n");
	}
	else{
		printf("String is not Valide\n");
	}
}
int main(){
	char name[] = "Simran@123";
	valide(name);
	char name1[] = "Simran123";
	valide(name1);
	return 0;
}
