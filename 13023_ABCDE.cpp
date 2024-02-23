#include<iostream>
#include<vector>
using namespace std;
int N, M, p1,p2;
int visited[2000] = {0,};
vector<vector<int>> v(2000);
void find_friend(int now, int depth, vector<vector<int>> &v){
    int next;
    if(depth == 4){
        cout << 1;
        exit(0);
    }
    for(int j=0; j<v[now].size(); j++){
        next = v[now][j];
        if(!visited[next]){
            visited[next]++;
            find_friend(next,depth+1,v);
            visited[next]--;
        }
    }
}

int main(){
    cin >> N >> M;
    vector<vector<int>> v(N);

    for(int i=0; i<M; i++){
        cin >> p1 >> p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }
    for(int i=0; i<N; i++){
        visited[i]++;
        find_friend(i, 0, v);
        visited[i]--;
    }
    cout << 0;
}