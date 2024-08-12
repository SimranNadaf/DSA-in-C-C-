#include<stdio.h>
#include<iostream>
using namespace std;
template<class T>
class Array{
	private:
		T *A;
		int size;
		int length=0;
		void swap(T *a1, T *a2);
	public:
		Array(int sz){
			size=sz;
			A=new T[size];
		}
		Array(){
			size=20;
			A=new T[size];
		}
		void Display();
		void append(T x);
		void Insert(int index, T x);
		T Delete(int index);
		T linearSearch(T key);
		T binarySearch(T key);
		T binarySearchR(int l, int h, T key);
		T get(int index);
		void set(int index, T x);
		T Sum();
		T Max();
		T Min();
		T Avg();
		T Sum(int n);
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
template<class T>
void Array<T>::Display(){
	for(int i=0;i<length;i++)
		cout<<A[i]<<"\t";
	cout<<endl;
}
template<class T>
void Array<T>::append(T x){
	A[length++]=x;
}
template<class T>
void Array<T>::Insert(int index, T x){
	if(index>=0 && index<=length){
		int i=length;
		for(;i>index;i--){
			A[i]=A[i-1];
		}
		A[index]=x;
		length++;
	}
}
template<class T>
T Array<T>::Delete(int index){
	if(index>=0 && index<=length){
		int x=A[index];
		for(int i=index;i<length;i++){
			A[i]=A[i+1];
		}
		length--;
		return x;
	}
}
template<class T>
T Array<T>::linearSearch(T key){
	for(int i=0;i<length;i++){
		if(key==A[i])
			return i;
	}
	return -1;
}
template<class T>
T Array<T>::binarySearch(T key){
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
template<class T>
T Array<T>::binarySearchR(int l, int h, T key){
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
template<class T>
T Array<T>::get(int index){
	if(index>=0 && index<length){
		return A[index];
	}
	return -1;
}
template<class T>
void Array<T>::set(int index, T x){
	if(index>=0 && index<length){
		A[index]=x;
	}
}
template<class T>
T Array<T>::Sum(){
	int sum=0;
	for(int i=0;i<length;i++)
		sum+=A[i];
	return sum;
}
template<class T>
T Array<T>::Max(){
	int max=A[0];
	for(int i=0;i<length;i++){
		if(max<A[i])
			max=A[i];
	}
	return max;
}
template<class T>
T Array<T>::Min(){
	int min=A[0];
	for(int i=0;i<length;i++){
		if(min>A[i])
			min=A[i];
	}
	return min;
}
template<class T>
T Array<T>::Avg(){
	return Sum()/length;
}
template<class T>
T Array<T>::Sum(int n){
	if(n<=0){
		return 0;
	}
	return Sum(n-1)+A[n-1];
}
template<class T>
void Array<T>::swap(T *a1, T *a2){
	T temp=*a1;
	*a1=*a2;
	*a2=temp;
}
template<class T>
void Array<T>::Reverse(){
	int i=0,j=length-1;
	for(;i<j;i++,j--){
		swap(&A[i],&A[j]);
	}
}
template<class T>
bool Array<T>::isSorted(){
	for(int i=0;i<length-1;i++){
		if(A[i]>A[i+1])
			return false;
	}
	return true;
}
template<class T>
void Array<T>::negativeOnLeftside(){
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
template<class T>
void Array<T>::Merge(Array a2,Array *a3){
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
template<class T>
void Array<T>::Union(Array a2,Array *a3){
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
template<class T>
void Array<T>::Intersection(Array a2,Array *a3){
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
template<class T>
void Array<T>::Difference(Array a2, Array *a3){
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
	Array<int> a1(10);
	Array<int> a2(10);
	Array<int> a3;
	a1.append(10);
	a1.append(20);
	a1.append(22);
	a2.append(11);
	a2.append(22);
	
	a1.Difference(a2,&a3);
	a3.Display();
	
	Array<char> a4(10);
	a4.append('a');
	a4.append('b');
	a4.Display();
	
	Array<float> a5(10);
	a5.append(10.23);
	a5.append(2.55);
	a5.Display();
	return 0;
}
