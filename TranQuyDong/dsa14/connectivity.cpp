#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;

int num;
int n;
stack<int> stacker,stack2;
int  A[100][100];
int index[100], lowlink[100];
void DFS(int v)
{
	index[v] = ++num;
	lowlink[v] = index[v];
	stacker.push(v);
	for(int w = 0; w < n; w++)
	{
		if(A[v][w] == 1)
		{
			if(index[w] == 0)
			{
				DFS(w);
				lowlink[v] = min(lowlink[v], lowlink[w]);
			}
			else	
			
				lowlink[v] = min(lowlink[v], index[w]);
		}
	}
}

int main()
{
	int s;
	ifstream ifs("graph1.txt");
	ifs>>n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ifs>> A[i][j];
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	ifs.close();
	ofstream ofs("output1.txt");
		cin>>s;
	cout<<"s = "<<s<<endl;
	ofs<<"s = ";
	ofs<<s<<endl;
	DFS(s);
	int w;
	do
	{
		w = stacker.top();
		if(lowlink[w] == lowlink[s])
			stack2.push(w);
		stacker.pop();
	}
	while(w!=s);
	while(!stack2.empty())
	{
		int w = stack2.top();
		ofs<<w<<" ";
		cout<<w<<" ";
		stack2.pop();
	}
	ofs.close();
	return 0;
}
