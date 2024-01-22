#include<stdio.h>
#include<iostream>
using namespace std;

class Array{
	private:
//	public:
		int *A;
		int size;
		int length=0;
		void swap(int *a1, int *a2);
	public:
		Array(int sz){
			size=sz;
			A=new int[size];
		}
		Array(){
			size=20;
			A=new int[size];
		}
		void Display();
		void append(int x);
		void Insert(int index, int x);
		int Delete(int index);
		int linearSearch(int key);
		int binarySearch(int key);
		int binarySearchR(int l, int h, int key);
		int get(int index);
		void set(int index, int x);
		int Sum();
		int Max();
		int Min();
		int Avg();
		int Sum(int n);
		void Reverse();
		bool isSorted();
		void negativeOnLeftside();
		void Merge(Array a2,Array *a3);
		void Union(Array a2,Array *a3);
		void Intersection(Array a2,Array *a3);
		void Difference(Array a2,Array *a3);
		~Array(){
			delete(A);
		}
};

void Array::Display(){
	for(int i=0;i<length;i++)
		printf("%d ",A[i]);
	cout<<endl;
}

void Array::append(int x){
	A[length++]=x;
}

void Array::Insert(int index, int x){
	if(index>=0 && index<=length){
		int i=length;
		for(;i>index;i--){
			A[i]=A[i-1];
		}
		A[index]=x;
		length++;
	}
}

int Array::Delete(int index){
	if(index>=0 && index<=length){
		int x=A[index];
		for(int i=index;i<length;i++){
			A[i]=A[i+1];
		}
		length--;
		return x;
	}
}

int Array::linearSearch(int key){
	for(int i=0;i<length;i++){
		if(key==A[i])
			return i;
	}
	return -1;
}

int Array::binarySearch(int key){
	int l=0,h=length-1,mid;
	while(l<=h){
		mid=(l+h)/2;
		if(key==A[mid])
			return mid;
		else if(key>A[mid])
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}

int Array::binarySearchR(int l, int h, int key){
 	int mid;
	while(l<=h){
	mid=(l+h)/2;
		if(key==A[mid])
			return mid;
		else if(key>A[mid])
			return binarySearchR(mid+1,h,key);
		else
			return binarySearchR(l,mid-1,key);
	}
	return -1;
}

int Array::get(int index){
	if(index>=0 && index<length){
		return A[index];
	}
	return -1;
}

void Array::set(int index, int x){
	if(index>=0 && index<length){
		A[index]=x;
	}
}

int Array::Sum(){
	int sum=0;
	for(int i=0;i<length;i++)
		sum+=A[i];
	return sum;
}

int Array::Max(){
	int max=A[0];
	for(int i=0;i<length;i++){
		if(max<A[i])
			max=A[i];
	}
	return max;
}

int Array::Min(){
	int min=A[0];
	for(int i=0;i<length;i++){
		if(min>A[i])
			min=A[i];
	}
	return min;
}

int Array::Avg(){
	return Sum()/length;
}

int Array::Sum(int n){
	if(n<=0){
		return 0;
	}
	return Sum(n-1)+A[n-1];
}

void Array::swap(int *a1, int *a2){
	int temp=*a1;
	*a1=*a2;
	*a2=temp;
}

void Array::Reverse(){
	int i=0,j=length-1;
	for(;i<j;i++,j--){
		swap(&A[i],&A[j]);
	}
}

bool Array::isSorted(){
	for(int i=0;i<length-1;i++){
		if(A[i]>A[i+1])
			return false;
	}
	return true;
}

void Array::negativeOnLeftside(){
	int i=0,j=length-1;
	while(i<j){
		if(A[i]>=0 && A[j]<0){
			swap(&A[i],&A[j]);
			i++,j--;
		}
		else if(A[i]<0)
			i++;
		else if(A[j]>=0)
			j--;
	}
}

void Array::Merge(Array a2,Array *a3){
	int i=0,j=0,k=0;
	while(i<length && j<a2.length){
		if(A[i] < a2.A[j]){
			a3->A[k++]=A[i++];
		}
		else{
			a3->A[k++]=a2.A[j++];
		}
	}
	for(;j<a2.length;j++)
		a3->A[k++]=a2.A[j];

	for(;i<length;i++)
		a3->A[k++]=A[i];
		
	a3->length=k;	
}

void Array::Union(Array a2,Array *a3){
	int i=0,j=0,k=0;
	while(i<length && j<a2.length){
		if(A[i] < a2.A[j]){
			a3->A[k++]=A[i++];
		}
		else if(A[i] > a2.A[j]){
			a3->A[k++]=a2.A[j++];
		}
		else{
			a3->A[k++]=a2.A[j++];i++;
		}
	}
	for(;j<a2.length;j++)
		a3->A[k++]=a2.A[j];

	for(;i<length;i++)
		a3->A[k++]=A[i];
	
	a3->length=k;	
}

void Array::Intersection(Array a2,Array *a3){
	int i=0,j=0,k=0;

	while(i<length && j<a2.length){
		if(A[i] < a2.A[j]){
			i++;
		}
		else if(A[i] > a2.A[j]){
			j++;
		}
		if(A[i] == a2.A[j]){
			a3->A[k++]=a2.A[j++];i++;
		}

	}
	
	a3->length=k;
}

void Array::Difference(Array a2, Array *a3){
	int i=0,j=0,k=0;

	while(i<length && j<a2.length){
		if(A[i] < a2.A[j])
			a3->A[k++]=A[i++];
		else if(A[i] > a2.A[j])
			j++;
		else{
			j++;i++;
		}
	}
	for(;i<length;i++)
		a3->A[k++]=A[i];
		
	a3->length=k;	
}

int main(){
	Array a1(10);
	Array a2(10);
	Array a3;
	a1.append(10);
	a1.append(20);
	a1.append(22);
	a2.append(11);
	a2.append(22);
	
	a1.Difference(a2,&a3);
	a3.Display();
	return 0;
}
