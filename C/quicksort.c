#include<stdio.h>

void quicksort(int A[], int low, int high){
	int pivot;
	if(low<high){
		pivot= partition(A, low, high);
		quicksort(A, low, pivot-1);
		quicksort(A, pivot+1, high);
	}
}

void swap(int A[], int left, int right){
	int temp;
	temp = A[left];
	A[left]= A[right];
	A[right] = temp;
}

int partition(int A[], int low, int high){
	int left, right, pivot_element;
	pivot_element=A[low];
	left = low;
	right = high;
	while(left<right){
		while(A[left]<=pivot_element)	left++;
		while(A[right]>pivot_element)	right--;
		if(left<right)
			swap(A, left, right);
	}
	A[low]=A[right];
	A[right]= pivot_element;
	return right;
}

int main(){
	int i,n;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int A[n+1];
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	quicksort(A, 0, n-1);
	for(i=0;i<n;i++){
		printf("%d \t",A[i]);
	}
	printf("\n");
	return 0;	
}
