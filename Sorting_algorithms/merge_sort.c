#include <stdio.h>
void merge(int arr[], int l, int m , int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
//	creating a temporary array
	int L[n1],R[n2];
//	copying to the temporary array
	for (i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	for (j=0;j<n2;j++){
		R[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
//	merge the temporary array
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
//	copy the remaining data to the temp array
	while (i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while (j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int arr[],int L,int R){
//	sort the array
	if (L<R){
		int m=L+(R-L)/2;
		mergesort(arr,L,m);
		mergesort(arr,m+1,R);
//		calling the merge function
		merge(arr,L,m,R);
	}
}
void print(int arr[], int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[]={1,0,9,3,7,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,size-1);	
	print(arr,size);
}