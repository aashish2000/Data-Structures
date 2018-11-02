#include <stdio.h>

void shell(int a[],int n)
{
	int i,j,k,temp;
	for(i=n/2;i>=0;i/=2)
	{
		for(j=i;j<n;j++)
		{
			temp=a[j];
			for(k=j;k>=i && a[k-i]>=temp;k=k-i)
			{
				a[k]=a[k-i];
			}
			a[k]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i] );
	}
}

int main()
{
	int a[5]={3,1,5,2,8};
	shell(a,5);
}