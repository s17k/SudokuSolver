#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 9;

int arr[N][N];

bool dasie(int i, int j, int k)
{
	for(int l=0;l<N;l++)
		if(arr[i][l] == k && l != j) return false;
	
	for(int l=0;l<N;l++)
		if(arr[l][j] == k && l != i) return false;
	for(int l=(i/3)*3;l<(i/3)*3+3;l++)
	{
		for(int t=(j/3)*3;t<(j/3)*3+3;t++)
		{
			if(arr[l][t] == k && (l != i or t != j)) return false;
		}
	}
	return true;
}

bool count(int i, int j)
{
	if(arr[i][j] != -1)
	{
		if(!dasie(i,j,arr[i][j])) return false;
		if(j+1 < N)
			if(count(i,j+1)) return true;
		if(j+1 >= N && i+1 < N)
			if(count(i+1,0)) return true;
		if(j+1 >= N && i+1 >= N) return true;
	}
	else
	{
		for(int k=1;k<=9;k++)
		{
			if(dasie(i,j,k))
			{
				arr[i][j] = k;
					if(j+1 < N)
				if(count(i,j+1)) return true;
				if(j+1 >= N && i+1 < N)
					if(count(i+1,0)) return true;
				if(j+1 >= N && i+1 >= N) return true;
			}
		}
		arr[i][j] = -1;
	}
	return false;
}


int main ()
{
	char c;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> c;
			if(c != '.')
				arr[i][j] = c-'0';
			else
				arr[i][j] = -1;
		}
	}
	if(count(0,0))
	{
		printf("TAK\n");
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
	}
	else
		printf("NIE\n");
}
