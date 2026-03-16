#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int P[301][301];
int W[301];
bool visited[301];


int prim(){
	int sum=0;
	for(int i=1;i<=N;i++){
		int index=-1;

		//현재 노드 선택
		for(int j=1;j<=N;j++){
			if(!visited[j]&&(index==-1||W[j]<W[index])){
				index=j;
			}
		}

		visited[index]=true;
		sum+=W[index];

		for(int j=1;j<=N;j++){
			if(!visited[j]){
				W[j]=min(W[j],P[index][j]); // 현재 위치에->j 의 cost와 원래 j의 cost 비교
			}
		}
	}
	return sum;		
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>W[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>P[i][j];
		}
	}

	cout<<prim();

}