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
vector<node> sumJob;

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
//-----------------------------------------NEH_heuristic----------------------------------------------------------------
bool rule (node a, node b) {
	return (a > b);
}

vector<int> NEH_heuristic(vector<int> phi)
{
	vector<int> urutan;
	int min, temp, indeksMinim;
	sort (sumJob.begin(), sumJob.end(), rule);
	temp = sumJob[0].second;
	urutan.push_back(temp);
	for(int i=1; i<n;i++)
	{
		temp = sumJob[i].second;
		urutan.push_back(temp);
		min=cmax(urutan);
		urutan.pop_back();
		indeksMinim=i;
		for(int j=0; j<i; j++)
		{
			urutan.insert(urutan.begin()+j, temp);
			if(min<cmax(urutan)){
				indeksMinim=j;
			}
			urutan.erase(urutan.begin()+j);
		}
		urutan.insert(urutan.begin()+indeksMinim, temp);
	}
	return urutan;
}
int main()
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
	for (int i=0; i<m;i++)
	{
		cout << "Please input processing time job for machine number : " << i+1 << endl;
		for(int j=0; j<n ; j++)
		{
			cin >> (phi[j]).first;
		}
		p.push_back(phi);
	}
	int a;
	vector<int> urutan;
	for(int i=0;i<n;i++){
		urutan.push_back(i);
	}
	vector<int> hasil;
	copyVector(NEH_heuristic(urutan), n, hasil);
	cout << cmax(hasil) << endl;
	cetakVector(hasil);
	return 0;
}
