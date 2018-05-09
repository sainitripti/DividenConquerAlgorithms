#include<iostream>
using namespace std;

void quickSort(int arr[],int l,int r);
int partition(int arr[],int l,int r);
void swap(int *a,int *b);
void print(int arr[],int size);

int main(void){

	cout<<"\n Quick Sort Algorithm \n";

	cout<<"\n Enter the size of unsorted array: ";
	int size;
	cin>>size;

	cout<<"\n Enter the elements of unsorted array: \n";
	int arr[50];
	for(int i=0;i<size;i++){
		cout<<" Element "<<i+1<<" : ";
		cin>>arr[i];
	}

	quickSort(arr,0,size-1);

	cout<<"\n Sorted Array is: ";
	print(arr,size);
}

void quickSort(int arr[],int l,int r){
	if(l<r){
		int pivot=partition(arr,l,r);

		quickSort(arr,l,pivot-1);
		quickSort(arr,pivot+1,r);
	}
}

int partition(int arr[],int l,int r){
	int pivotValue=arr[r];
	int i=l-1,j=l;

	while(j<r){
		if(arr[j]<pivotValue){
			i++;
			swap(&arr[i],&arr[j]);
		}
		j++;
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

