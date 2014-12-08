#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//array start from 1 to n

//generating random number
void randominput(int input[], int n)
{
	for (int i=1; i<=n; i++)
	{
		input[i] = rand() % n +1;
	}
}

//generating set of job
//a for start time and b for finish time
void jobset (int a[], int b[], int n)
{
	randominput (a, n);
	randominput (b, n);
	for (int i = 1; i<=n; i++)
	{
		if (a[i]==b[i])
		{
			b[i]+= rand() % (n/2);
		}
		
		if (a[i] > b[i])
		{
			swap (a[i], b[i]);
		}
	}
}

//priority rule (for comparisson)
int PRTCTlj (int j, int v1, int v2, int p1j, int p2j) 
{
	int C1j = v1 + p1j + lj;
	return (2 * (max(v2,C1j)) + p2j);
}

//iterated local search
int ILS (int n)
{
	int maxiter = 120, pert = 7;
	int iter = 1, cnt = 0, i = 1;
	for (iter = 1; iter <= maxiter; iter++)
	{
		for (i = 1; i<=n; i++)
		{
			
		}
	}
}

//iterated greedy local search
int IGRLS (int n)
{
	
}

int main() {
	int n;
	scanf("%d", &n);
	return 0;
}
