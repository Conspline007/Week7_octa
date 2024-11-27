#include <stdio.h>

struct emp
{
	unsigned int empno : 5; unsigned int dept_number : 7 ; unsigned int sal:30 ;
	struct DOB
	{
		int d:6; int m:4; int y :20;
	}s2;	
}s1; 

int main()
{
	s1.empno=10;
	s1.dept_number =20;
	s1.sal=200000;
	s1.s2.d=31;
	s1.s2.m=5;
	s1.s2.y=2024;
	
	printf("%d.%d.%d",s1.s2.d,s1.s2.m,s1.s2.y);
	
}
