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

vector<int> iteratedGreedy (vector<int> phi, int n)
{
	 vector<int> phiB;
	 int temp;
	 copyVector(phi, n, phiB);
	 while(1){
	 	vector<int> phiD, phiR;
	 	copyVector(phiB, n, phiD);
	 	for(int i=0; i<d;i++){
	 		temp=rand()%phiD.size();
	 		phiR.push_back(phiD[temp]);
	 		phiD.erase(phiD.begin()+temp);
		 }
		 return phiD;
	 	if(1) break;
	 }
}


int main ()
{
	int n, m, temp;
	vector<int> phi, ptime;
	printf ("Please input the number of job(s) : ");
	cin >> n;
	printf ("Please input the number of machine(s) : ");
	scanf ("%d", &m);
	for (int i=0; i<(n*m);i++)
	{
		cin >> temp;
		ptime.push_back(temp);
	}
	cetakVector(iteratedGreedy(ptime, n));
	printf("\n");
	return 0;
}
