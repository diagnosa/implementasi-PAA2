#include <cstdio>
#include <utility>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//array start from 1 to n

struct setofjob
{
	vector<int>start;
	vector<int>finish;	
};


void generateinput(int n, setofjob *a)
{
	srand(time(NULL));
	for (int i=1; i<=n; i++)
	{
		a->start[i] = rand()%1000;
		a->finish[i] = a->start[i] + rand()%100;
		if (a->start[i]==a->finish[i]) a->finish[i]+= a->start[i]+rand();
	}
  /*for (int i=1; i<=n; i++)
  {
    arr[i] = i;
  }
  for (int i=1;i<=n;i++)
  {
  	int j=rand()%n+1;
  	swap (arr[i], arr[j]);	
  }*/
}

void localsearchinsertion (vector<int> &arr)
{
  bool improve = 1;
  while (improve)
  {
    improve = 0;
   // for (int i=0; i<=n; i++)
   // {
      
   // }
  }
}

int main ()
{
  setofjob set;
  int n, m;
  printf ("Please input the number of job(s) : ");
  scanf ("%d", &n);
  for(int i=0; i<=n; i++){
  	set.start.push_back(0);
  	set.finish.push_back(0);
  }
  printf ("Please input the number of machine(s) : ");
  scanf ("%d", &m);
  generateinput(n, &set);
  for (int i=1; i<=n;i++)
  {
    printf ("%d %d \n", set.start[i], set.finish[i]);
  }
  printf("\n");
}
