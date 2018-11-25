#include <stdio.h>

void insertionSort(int a[],int n)
{
	for(i=1;i<7;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j=j-1;	
		}
		a[j+1]=temp;

	}
	for(i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
}

void main()
{
	int i,j,temp;
	int a[7]={4,5,1,6,9,3,7};
	insertionSort(a,7);
}

