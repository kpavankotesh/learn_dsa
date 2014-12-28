#include <stdio.h>

void print_r(int a[],int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void merge(int a[],int temp[], int start, int mid, int end) {
	int first_end,  second_start, temp_pos=0;
	first_end = mid;
	second_start = mid + 1;
	int size = end - start+1;
	while((start <= first_end) && (second_start <= end)){
		if (a[start]<=a[second_start])
		{
			temp[temp_pos] = a[start];
			start++;
		}
		else{
			temp[temp_pos] = a[second_start];
			second_start++;
		}
		temp_pos++;
	}
	while(start <= first_end){
		temp[temp_pos]=a[start];
		temp_pos++;
		start++;
	}
	while(second_start <= end){
		temp[temp_pos]=a[second_start];
		temp_pos++;
		second_start++;
	}
	int i;
	for (i = 0; i < size; ++i)
	{
		a[i] = temp[i];
	}
}

void mergesort(int a[], int temp[], int start, int end){
	if (end > start)
	{
		int mid = (start+end)/2;
		mergesort(a,temp,0,mid);
		mergesort(a,temp,mid+1,end);
		merge(a,temp, 0,mid, end);
	}
}

int main(){
	int i=0,n, a[100],temp_n, temp[100];
	printf("\nEnter the number of elements:\n");
	scanf("%d",&n);
	temp_n = n;
	printf("Enter the %d elements:\n", n);
	while(temp_n--){
		scanf("%d",&a[i++]); 
	} 

	mergesort(a,temp,0,n-1);
	printf("\nSorted Array:\n");
	print_r(a,n);
	return 0;
}
