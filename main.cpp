#include <iostream>
using namespace std;

int input[201];

void randominput(int n)
{
	for (int i=0; i<n; i++)
	{
		input[i] = rand() % n +1;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	randominput(n);
	return 0;
}
