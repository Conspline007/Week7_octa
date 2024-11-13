#include <stdio.h>
int avg_arr(int *p,int n)
{
	int sum=0,i;
	for (i=0;i<n;i++)
	{
		sum+=*(p+i);
	}
	return sum/n;
}


int main()
{
	int n,i;
	printf("Enter the length of the array ");
	scanf("%d",&n);
	int a[n];
	
	for (i=0;i<n;i++)
	{
		printf("Enter element number %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf(" The average of given array is %d ",avg_arr(a,n));
	return 0;
}
