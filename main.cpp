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

//---------------------------------------global variable-------------------------------------------------------
int d=3;
int m, n;
unsigned int seed;
typedef pair<int, int> node;
vector< vector<node> > p;

//-----------------------------------------Cmax ----------------------------------------------------------------

int cmax (vector <int> arr)
{
	//total completion time
	int temp, selisih;
	vector<int> machine;
	for(int i=0; i<m; i++){
		machine.push_back(0);
	}
	for(int i=0; i<n; i++){
		temp=arr[i];
		machine[0]+=(p[0][temp]).first;
		for(int j=1; j<m; j++){
			if(machine[j-1]<=machine[j]){
				machine[j]+=(p[j][temp]).first;
			}
			else{
				selisih=machine[j-1]-machine[j];
				machine[j]=machine[j]+selisih+(p[j][temp]).first;
			}
		}
	}
	return machine[m-1];
}

//--------------------------------------------------------------------------------------------------------------
void copyVector(vector<node> asal, int n, vector<node> &tujuan)
{
	for(int i=0; i<n; i++){
		tujuan.push_back(asal[i]);
	}
}

void cetakVector(vector<node> vectorA)
{
	for(int i=0; i<vectorA.size(); i++){
		cout << vectorA[i].second << " ";
	}
	cout << endl;
}

vector<node> LocalSearch_Insertion(vector<node> phi, int n)
{
	srand(seed);
	bool improve = 1;
	int k;
	node temp;
	vector <node> phiA;
	while (improve == 1)
	{
		copyVector (phi, n, phiA);
		improve = 0;
		for (int i=0; i < n; i++)
		{
			k=rand()%phiA.size();
			temp = phiA[k];
			phiA.erase(phiA.begin()+k);
			k = rand()%phiA.size();
			phiA.insert(phiA.begin()+k, temp);
			if (cmax(phiA) < cmax(phi))
			{
				copyVector(phiA, n, phi);
				improve = 1;
			}
		}
	}
	return phi;
}

vector<node> iteratedGreedy (vector<node> phi, int n)
{
	srand(seed);
	vector<node> phiB;
	int k;
	copyVector(phi, n, phiB);
	while(1){
		vector<node> phiD, phiR;
		copyVector(phiB, n, phiD);
		//destruction phase
		for(int i=0; i<d; i++){
			k=rand()%phiD.size();
			phiR.push_back(phiD[k]);
			phiD.erase(phiD.begin()+k);
		 }
		 //construction phase
		 for(int i=0; i<d; i++){
		 	k=rand()%phiD.size();
		 	phiD.insert(phiD.begin()+k, phiR[i]);
		 }
		 return phiD;
		if(1) break;
	}
}


int main ()
{
	node temp;
	vector<node> phi;
	printf ("Please input the number of job(s) : ");
	cin >> n;
	for(int i=0;i<n;i++){
		temp.first=0;
		temp.second=i+1;
		phi.push_back(temp);
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
			cin >> (phi[j]).first;
		}
		p.push_back(phi);
	}
	cout << endl << "Final Result :" << endl;
	//cetakVector(iteratedGreedy(p[0], n));
	printf("\n");
	return 0;
}
