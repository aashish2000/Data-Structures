#include <stdio.h>
#include <stdlib.h>

int largest(int a[],int n)
{
	int i;
	int max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return(max);
}

void radsort(int a[],int n)
{
	int bucket[10][10],bucket_count[10],j,rem=0,div=1,x,y,large;
	large=largest(a,n);
	int nop=0,i=0	;
	for(i=large;i>0;i=i/10)
	{
		nop++;
	}
	for(i=0;i<nop;i++)
	{
		for(j=0;j<10;j++)
		{
			bucket_count[j]=0;
		}
		for(j=0;j<n;j++)
		{
			rem=(a[j]/div)%10;
			bucket[rem][bucket_count[rem]]=a[j];
			bucket_count[rem]+=1;
		}
		j=0;
		for(x=0;x<10;x++)
		{
			for(y=0;y<bucket_count[x];y++)
			{
				a[j]=bucket[x][y];
				j++;
			}
		}
		div*=10;
	}
	printf("Sorted list:\n");
	for(x=0;x<n;x++)
	{
		printf("%d ",a[x]);
	}


}
void main()
{
	int a[4]={78,9,90,56};
	printf("Before Sort:\n");
	int i;
	for(i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int n=4;
	radsort(a,n);

}