#include <stdio.h>
#include <stdlib.h>

int max_find(int *p,int n)
{
	int i,j,t;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			t=p[j];
			p[j]=p[j+1];
			p[j+1]=t;
		}
	}
	
	return p[n-1];
	
	
}

int *create_arr(n)
{
	int *p=(int *)(malloc (n*sizeof(int)));
	return p;
	
}

int main()
{
	int n,i,j,t;
	printf("Enter the length of the array ");
	scanf("%d",&n);
	
	int *p=create_arr(n);
	
	for (i=0;i<n;i++)
	{
		printf("Enter element number %d : ",i+1);
		scanf("%d",&p[i]);
	}
	
	printf("maximum element is : %d ",max_find(p,n));
	
	return 0;
}
