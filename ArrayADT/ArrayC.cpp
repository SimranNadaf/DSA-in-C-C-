#include<stdio.h>
#include<iostream>
using namespace std;

struct Array{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr){
	for(int i=0;i<arr.length;i++)
		printf("%d ",arr.A[i]);
	printf("\n\n");
}

void append(struct Array *arr, int x){
	arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int index, int x){
	if(index>=0 && index<=arr->length){
		int i=arr->length;
		for(;i>index;i--){
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=x;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index){
	if(index>=0 && index<=arr->length){
		int x=arr->A[index];
		for(int i=index;i<arr->length;i++){
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
		return x;
	}
}

int linearSearch(struct Array *arr, int key){
	for(int i=0;i<arr->length;i++){
		if(key==arr->A[i])
			return i;
	}
	return -1;
}

int binarySearch(struct Array arr, int key){
	int l=0,h=arr.length-1,mid;
	while(l<=h){
		mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key>arr.A[mid])
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}

int binarySearchR(struct Array arr, int l, int h, int key){
 	int mid;
	while(l<=h){
	mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key>arr.A[mid])
			return binarySearchR(arr,mid+1,h,key);
		else
			return binarySearchR(arr,l,mid-1,key);
	}
	return -1;
}

int get(struct Array arr, int index){
	if(index>=0 && index<arr.length){
		return arr.A[index];
	}
	return -1;
}

void set(struct Array *arr, int index, int x){
	if(index>=0 && index<arr->length){
		arr->A[index]=x;
	}
}

int Sum(struct Array arr){
	int sum=0;
	for(int i=0;i<arr.length;i++)
		sum+=arr.A[i];
	return sum;
}

int Max(struct Array arr){
	int max=arr.A[0];
	for(int i=0;i<arr.length;i++){
		if(max<arr.A[i])
			max=arr.A[i];
	}
	return max;
}

int Min(struct Array arr){
	int min=arr.A[0];
	for(int i=0;i<arr.length;i++){
		if(min>arr.A[i])
			min=arr.A[i];
	}
	return min;
}

int Avg(struct Array arr){
	return Sum(arr)/arr.length;
}

int Sum(struct Array arr, int n){
	if(n<=0){
		return 0;
	}
	return Sum(arr, n-1)+arr.A[n-1];
}

void swap(int *a1, int *a2){
	int temp=*a1;
	*a1=*a2;
	*a2=temp;
}

void Reverse(struct Array *arr){
	int i=0,j=arr->length-1;
	for(;i<j;i++,j--){
		swap(&arr->A[i],&arr->A[j]);
	}
}

bool isSorted(struct Array arr){
	for(int i=0;i<arr.length-1;i++){
		if(arr.A[i]>arr.A[i+1])
			return false;
	}
	return true;
}

void negativeOnLeftside(struct Array *arr){
	int i=0,j=arr->length-1;
	while(i<j){
		if(arr->A[i]>=0 && arr->A[j]<0){
			swap(arr->A[i],arr->A[j]);
			i++,j--;
		}
		else if(arr->A[i]<0)
			i++;
		else if(arr->A[j]>=0)
			j--;
	}
}

struct Array Merge(struct Array arr1, struct Array arr2){
	int i=0,j=0,k=0;
	struct Array arr3;
	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i] < arr2.A[j]){
			arr3.A[k++]=arr1.A[i++];
		}
		else{
			arr3.A[k++]=arr2.A[j++];
		}
	}
	for(;j<arr2.length;j++)
		arr3.A[k++]=arr2.A[j];

	for(;i<arr1.length;i++)
		arr3.A[k++]=arr1.A[i];
		
	arr3.length=k;
	
	return arr3;	
}

struct Array Union(struct Array arr1, struct Array arr2){
	int i=0,j=0,k=0;
	struct Array arr3;
	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i] < arr2.A[j]){
			arr3.A[k++]=arr1.A[i++];
		}
		else if(arr1.A[i] > arr2.A[j]){
			arr3.A[k++]=arr2.A[j++];
		}
		else{
			arr3.A[k++]=arr2.A[j++];i++;
		}
	}
	for(;j<arr2.length;j++)
		arr3.A[k++]=arr2.A[j];

	for(;i<arr1.length;i++)
		arr3.A[k++]=arr1.A[i];
	
	arr3.length=k;
	return arr3;	
}

struct Array Intersection(struct Array arr1, struct Array arr2){
	int i=0,j=0,k=0;
	struct Array arr3;

	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i] < arr2.A[j]){
			i++;
		}
		else if(arr1.A[i] > arr2.A[j]){
			j++;
		}
		if(arr1.A[i] == arr2.A[j]){
			arr3.A[k++]=arr2.A[j++];i++;
		}

	}
	
	arr3.length=k;
	return arr3;	
}

struct Array Difference(struct Array arr1, struct Array arr2){
	int i=0,j=0,k=0;
	struct Array arr3;

	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i] < arr2.A[j])
			arr3.A[k++]=arr1.A[i++];
		else if(arr1.A[i] > arr2.A[j])
			j++;
		else{
			j++;i++;
		}
	}
	for(;i<arr1.length;i++)
		arr3.A[k++]=arr1.A[i];
		
	arr3.length=k;
	return arr3;	
}

int main(){
	struct Array arr1;
	int s;
	int c;
	int f;
	int x,index;
	cout<<"Enter Size of Array: ";
	cin>>s;
	arr1.size=s;
	arr1.A=(int *)malloc(sizeof(int)*s);

	do{
	cout<<"1. Insert Element"<<endl;
	cout<<"2. Delete Element"<<endl;
	cout<<"3. Search Element"<<endl;
	cout<<"4. Display"<<endl;
	cout<<"5. Sum"<<endl;
	cout<<"6. Max"<<endl;
	cout<<"7. Min"<<endl;
	cout<<"8. Average"<<endl;
	cout<<"9. Exit"<<endl;
	cout<<"Enter Your Choice: ";
	cin>>c;
	switch(c){
		case 1:
			cout<<"Enter the element: ";
			cin>>x;
			append(&arr1,x);
			break;
		case 2:
			cout<<"Enter the index: ";
			cin>>index;
			Delete(&arr1,index);
			break;
		case 3:
			cout<<"Enter the Element: ";
			cin>>index;
			f=linearSearch(&arr1,index);
			if(f>=0)
				printf("Element Found At %d \n",f);
			else
				printf("Element Not Fount\n");
			break;
		case 4:
			Display(arr1);
			break;
		case 5:
			printf("Sum: %d \n",Sum(arr1));
			break;
		case 6:
			printf("Max: %d\n",Max(arr1));
			break;
		case 7:
			printf("Min: %d\n",Min(arr1));
			break;
		case 8:
			printf("Average: %d\n",Avg(arr1));
			break;
	}
	}while(c<9);
	
	return 0;
}
