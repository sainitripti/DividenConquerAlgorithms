#include<iostream>
using namespace std;

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int mid,int r);
void print(int arr[],int size);

int main(void){

	cout<<"\n Merge Sort Algorithm \n";

	cout<<"\n Enter the size of unsorted array: ";
	int size;
	cin>>size;

	cout<<"\n Enter the elements of unsorted array: \n";
	int arr[50];
	for(int i=0;i<size;i++){
		cout<<" Element "<<i+1<<" : ";
		cin>>arr[i];
	}

	mergeSort(arr,0,size-1);

	cout<<"\n Sorted Array is: ";
	print(arr,size);
}

void mergeSort(int arr[],int l,int r){
	if(l<r){
		int mid=l+(r-l)/2;

		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge(int arr[],int l,int mid,int r){
	int size1,size2;
	size1=mid-l+1;
	size2=r-mid;

	int leftArr[30],rightArr[30];
	int i,j,k;

	for(i=0;i<size1;i++){
		leftArr[i]=arr[l+i];
	}

	for(j=0;j<size2;j++){
		rightArr[j]=arr[mid+1+j];
	}

	i=0;
	j=0;
	k=l;

	while(i<size1&&j<size2){
		if(leftArr[i]<rightArr[j]){
			arr[k++]=leftArr[i++];
		}
		else{
			arr[k++]=rightArr[j++];
		}
	}

	while(i<size1){
		arr[k++]=leftArr[i++];
	}

	while(j<size2){
		arr[k++]=rightArr[j++];
	}
}

void print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

