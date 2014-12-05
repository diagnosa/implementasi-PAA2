#include <iostream>
using namespace std;

void randominput(int input[], int n)
{
	for (int i=0; i<n; i++)
	{
		input[i] = rand() % n +1;
	}
}

/*int PRTCTlj (int j, int v1, int v2, int p1j, int p2j) 
{
	int C1j = v1 + p1j + lj;
	return (2 * (max(v2,C1j)) + p2j);
}*/

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


int main() {
	int n;
	scanf("%d", &n);
	return 0;
}
