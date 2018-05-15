#include<iostream>
#include<fstream>
using namespace std;

int A[100][100];
int visit[7];
bool cycle = false;
void DFS(int u)
{
	visit[u] = 1;
	int n = A[u][1];
	for(int i = 2; i < n+2; i++)
	{
		int v = A[u][i];
		if(visit[v] == 0 )
			DFS(v);
		else if(visit[v] == 1 )
			cycle  = true;
		visit[u] = 2;
	}
}

int main()
{
	int i, j;
	ifstream ifs("graph2.txt");
	while(!ifs.eof())
	{
		ifs>>A[i][0]>>A[i][1];
		if(ifs.eof())
		{
			break;
		}
		int n = A[i][1];
		cout<<A[i][0]<<" "<<A[i][1]<<" ";
		for(j = 2 ; j < n+2 ; j++)
		{
			ifs>>A[i][j];
			
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
		i++;
	}
	for(int u = 0; u < 7;u++)
	{
		if(visit[i] == 0)
			DFS(u);
	}
	if(cycle)
		cout<<"Do thi co chu trinh!"<<endl;
	else 
		cout<<"Do thi khong co chu trinh!"<<endl;
		
	ifs.close();	
}
