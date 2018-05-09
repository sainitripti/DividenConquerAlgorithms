#include<iostream>
using namespace std;

struct Pair{
	int min;
	int max;
};

Pair minmax(int arr[],int l,int r);

int main(void){
	cout<<"\n Simultaneous Minimum Maximum Algorithm \n";
	
	cout<<"\n Enter size of array: ";
	int size;
	cin>>size;

	cout<<"\n Enter array elements: \n";
	int arr[50];

	for(int i=0;i<size;i++){
		cout<<" Element "<<i+1<<" : ";
		cin>>arr[i];
	}

	Pair result=minmax(arr,0,size-1);

	cout<<"\n Minimum element from array is : "<<result.min;
	cout<<"\n Maximum element from array is : "<<result.max<<endl;

}

Pair minmax(int arr[],int l,int r){
	Pair result;
	if(l>r){
		cout<<"\n Array does not exist";
		result.min=-1;
		result.max=-1;
	}
	else if(l==r){
		result.min=arr[l];
		result.max=arr[l];
	}
	else if(l==r-1){
		if(arr[l]<arr[r]){
			result.min=arr[l];
			result.max=arr[r];
		}
		else{
			result.min=arr[r];
			result.max=arr[l];
		}
	}
	else{
		Pair left,right;
		int mid=l+(r-l)/2;

		left=minmax(arr,l,mid);
		right=minmax(arr,mid+1,r);

		if(left.min<right.min){
			result.min=left.min;
		}
		else{
			result.min=right.min;
		}
		
		if(left.max>right.max){
			result.max=left.max;
		}
		else{
			result.max=right.max;
		}

	}

	return result;
}

