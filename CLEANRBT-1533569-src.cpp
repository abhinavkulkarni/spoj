#include <iostream>
#include <queue>

using namespace std;

int n, w, h, inc[11][11], d[20][20], answer, DP[1<<11][11];
char m[20][20];
pair<int, int> pt[11];


//inc[][] matrix represents incident matrix
//pt[] vecotr stores the coordinates of the dirty tiles as well as the origin

bool ok(int x, int y){return x<h && y<w && x>=0 && y>=0 && m[x][y]!='x';}

void BFS()
{
	int u, v, mv[][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	queue<int> q;
	for(int p=0; p<=n; p++)
	{
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				d[i][j]=99999;
		d[pt[p].first][pt[p].second]=0;
		q.push(pt[p].first);
		q.push(pt[p].second);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			v=q.front();	q.pop();
			for(int i=0; i<4; i++)
				if(ok(u+mv[i][0], v+mv[i][1]) && d[u+mv[i][0]][v+mv[i][1]]>d[u][v]+1)
				{
					d[u+mv[i][0]][v+mv[i][1]]=d[u][v]+1;
					q.push(u+mv[i][0]);
					q.push(v+mv[i][1]);
				}
		}
		for(int j=0; j<=n; j++)
			inc[p][j]=d[pt[j].first][pt[j].second];
	}
}

void ShortestRoute()
{
	int prev;
	n++;
	for(int i=0; i<(1<<n); i++)
		for(int j=0; j<n; j++)
		{
			DP[i][j]=99999;
			if(((1<<j)&i)==0)
				continue;
			prev=(1<<j)^i;
			if(prev==0)
			{
				DP[i][j]=0;
				continue;
			}
			for(int k=0; k<n; k++)					//inc[j][k] gives the shortest path length
				if(k!=j && DP[prev][k]+inc[j][k]<DP[i][j])	//between j and k
					DP[i][j]=DP[prev][k]+inc[j][k];
		}
	answer=DP[(1<<n)-1][n-1];					//Origin is (n-1)th point
}

int main()
{
	while(1)
	{
		cin>>w>>h;
		if(w==0 && h==0)
			break;
		n=0;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
			{
				cin>>m[i][j];
				if(m[i][j]=='*')
					pt[++n]=make_pair(i, j);	//I take the dirty tiles in the vector
				else if(m[i][j]=='o')			//from index 1 onwards
					pt[0]=make_pair(i, j);		//I take the origin at 0th index position
			}
		if(n==0)
			cout<<"0"<<endl;
		else
		{
			swap(pt[0], pt[n]);				//Origin position goes in the last position
			BFS();						//I do BFS for every dirty tile as well as
			ShortestRoute();				//the origin. So I get the matrix.
			if(answer==99999)
				cout<<"-1"<<endl;
			else
				cout<<answer<<endl;
		}
	}
	return 0;
}
