#include<cstdio>
#include<cstdlib>

#define T int

void swap(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}


void InsertSort(T* array,int n)
{
	T i,j,temp;
	for(i=1;i<n;i++){
		j=i;
		temp=array[i];
		while(j>0&&temp<array[j-1]){
			array[j]=array[j-1];
			j--;
		}
		array[j]=temp;
	}
}

T partition(T* array,T lo,T hi)
{
	swap(array[lo],array[lo+rand()%(hi-lo+1)]);

	T pivot=array[lo];

	T mi=lo;
	
	for(int k=lo+1;k<=hi;k++)
		if(array[k]<pivot)
			swap(array[++mi],array[k]);
	
	swap(array[lo],array[mi]);
	
	return mi;


}

/*T partition(T* array,T lo, T hi)
{
	swap(array[lo],array[lo+rand()%(hi-lo+1)]);

	T pivot=array[lo];
	while(lo<hi){
		while((lo<hi)&&(pivot<=array[hi]))
			hi--;
		array[lo]=array[hi];
		while((lo<hi)&&(array[lo]<=pivot))
			lo++;
		array[hi]=array[lo];
	}
	array[lo]=pivot;
	return lo;
}
*/
void quickSort(T* array,T lo,T hi)
{
	if(hi-lo<2) return;

	T mi=partition(array,lo,hi-1);
	
	quickSort(array,lo,mi);
	
	quickSort(array,mi+1,hi);
}

void QuickSort(T* array,T n)
{
	quickSort(array,0,n);
}

void merge(T* array,T lo,T mi,T hi)
{
	T* A=array+lo;
	T lb=mi-lo;
	T* B=new T[lb];
	for(T i=0;i<lb;B[i]=A[i++]);
	T lc=hi-mi;
	T* C=array+mi;
	for(T i=0,j=0,k=0;(j<lb)||(k<lc);){
		if((j<lb)&&(!(k<lc)||(B[j]<=C[k])))
			A[i++]=B[j++];
		if((k<lc)&&(!(j<lb)||(C[k]<B[j])))
			A[i++]=C[k++];
	}
	delete []B;

}

void mergeSort(T* array,T lo,T hi)
{
	if(hi-lo<2) return;
	T mi=(lo+hi)/2;
	mergeSort(array,lo,mi);
	mergeSort(array,mi,hi);
	merge(array,lo,mi,hi);
}

void shellSort(T* array,T n)
{
	int s[]={1,2,3,5,8,13,21,34,55,89,144};
	int k,i=0;
	while(s[++i]<n);
	k=i-2;
	for(int t=k;t>0;t--){
		int a=0,b=0;
		int B[1000][1000];
		
	}
}


void main()
{
	T a[]={3,4,8,7,5,6,9,12,11};
	//InsertSort(a,7);
	//QuickSort(a,7);
	mergeSort(a,0,9);
	T i;
	for(i=0;i<9;i++)
		printf("%d  ",a[i]);
	system("PAUSE");
	return;
}
