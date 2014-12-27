#include <cstdio>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
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
void copyVector(int pi[], int n, vector<int> &vectorA)
{
	vectorA.push_back(0);
	for(int i=1; i<=n; i++){
		vectorA.push_back(pi[i]);
	}
}

void cetakVector(vector<int> vectorA, int n)
{
	for(int i=1; i<=n; i++){
		cout << vectorA[i];
	}
	cout << endl;
}

void iteratedGreedy (int pi[], int n)
{
	
}

int main ()
{
  int n, m;
  vector<int> phi;
  printf ("Please input the number of job(s) : ");
  scanf ("%d", &n);
  int ptime[n+1];
  for (int i=1; i<=n;i++)
  {
  	scanf("%d", ptime[i]);
  }
  copyVector(ptime, n, phi);
  cetakVector(phi, n);
  printf ("Please input the number of machine(s) : ");
  scanf ("%d", &m);
  
  printf("\n");
}
