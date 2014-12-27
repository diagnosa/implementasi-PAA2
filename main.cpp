#include <cstdio>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

//array start from 0 to n-1
//test-case : mistic.heig-vd.ch/taillard/problemes.dir/ordonnancement.dir/flowshop.dir/tai50_20.txt

//-----------------------------------------Cmax ----------------------------------------------------------------

int cmax (vector <int> arr)
{
	//total completion time
	int sum = 0;
	for (int i=0; i<arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum;
}

//---------------------------------------global variable-------------------------------------------------------
int d=3;
unsigned int seed;
vector< vector<int> > p;
//--------------------------------------------------------------------------------------------------------------
void copyVector(vector<int> asal, int n, vector<int> &tujuan)
{
	for(int i=0; i<n; i++){
		tujuan.push_back(asal[i]);
	}
}

void cetakVector(vector<int> vectorA)
{
	for(int i=0; i<vectorA.size(); i++){
		cout << vectorA[i] << " ";
	}
	cout << endl;
}

vector<int> LocalSearch_Insertion(vector<int> phi)
{
	srand(seed);
}

vector<int> iteratedGreedy (vector<int> phi, int n)
{
	srand(seed);
	vector<int> phiB;
	int temp;
	copyVector(phi, n, phiB);
	while(1){
	vector<int> phiD, phiR;
	copyVector(phiB, n, phiD);
	//destruction phase
	for(int i=0; i<d; i++){
		temp=rand()%phiD.size();
		phiR.push_back(phiD[temp]);
		phiD.erase(phiD.begin()+temp);
	 }
	 //construction phase
	 for(int i=0; i<d; i++){
	 	temp=rand()%phiD.size();
	 }
	 return phiD;
	if(1) break;
	}
}


int main ()
{
	int n, m, temp;
	vector<int> phi;
	printf ("Please input the number of job(s) : ");
	cin >> n;
	for(int i=0;i<n;i++){
		phi.push_back(0);
	}
	printf ("Please input the number of machine(s) : ");
	cin >> m;
	cout << "Please input initial seed :";
	cin >> seed;
	for (int i=0; i<m;i++)
	{
		cout << "Please input processing time job for machine number : " << i+1 << endl;
		for(int j=0; j<n ; j++)
		{
			cin >> phi[j];
		}
		p.push_back(phi);
	}
	//cetakVector(iteratedGreedy(ptime, n));
	printf("\n");
	return 0;
}
