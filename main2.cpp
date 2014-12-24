#include <cstdio>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//array start from 1 to n
//test-case : mistic.heig-vd.ch/taillard/problemes.dir/ordonnancement.dir/flowshop.dir/tai50_20.txt

//rule to sort descending
bool desc (int a, int b)
{
	return (a > b);
}

//The FGH heuristic
//possible pair processing-time > machine
void createpi(int job[], int n)
{
	//sort descending
	sort (job, job+n, desc);
	
	//Select the next job and insert it in all possible positions in the partial sequence 
	//and keep the best one (i.e. minimum makespan) as the current partial sequence.
	
	
}

void localsearchinsertion (int pi[], int n)
{
  bool improve = 1;
  while (improve)
  {
    improve = 0;
    //remove a job k at random from pi (without repetition)
    for (int i=0; i<=n; i++)
   {
      
   }
  }
}

int main ()
{
  int n, m;
  printf ("Please input the number of job(s) : ");
  scanf ("%d", &n);
  int ptime[n+1];
  for (int i=1; i<=n;i++)
  {
  	scanf("%d", ptime[i]);
  }
  printf ("Please input the number of machine(s) : ");
  scanf ("%d", &m);
  
  printf("\n");
}
