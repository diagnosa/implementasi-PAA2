#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;

//array start from 1 to n


void generateinput(int n, int arr[])
{
  for (int i=1; i<=n; i++)
  {
    arr[i] = i;
  }
  for (int i=1;i<=n;i++)
  {
  	int j=rand()%n+1;
  	swap (arr[i], arr[j]);	
  }
}

void localsearchinsertion (int arr[])
{
  bool improve = 1;
  while (improve)
  {
    improve = 0;
    for (int i=0; i<=n; i++)
    {
      
    }
  }
}

int main ()
{
  int n;
  scanf ("%d", &n);
  int setofjob[n+1];
  generateinput(n, setofjob);
  for (int i=1; i<=n;i++)
  {
    printf ("%d ", setofjob[i]);
  }
  printf("\n");
}
