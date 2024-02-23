#include<iostream>
#include<vector>
using namespace std;
vector<int> v[20001];
int visited[20001] = {0,};
int K, V, E, possible;
void DFS(int now){
    if(!visited[now]) visited[now] = 1;

    int neighbor;
    for(int i=0; i<v[now].size(); i++){
        neighbor = v[now][i];
        if(!visited[neighbor]){ //색칠 안되어있음
            if(visited[now] == 1){
                visited[neighbor] = 2;
            }
            if(visited[now] == 2){
                visited[neighbor] = 1;
            }
            DFS(neighbor);
        }
        else{ // 색칠 되어있음
            if(visited[now] == visited[neighbor]){
                possible = 0;
                return;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int p1, p2;
    cin >> K;
    while(K--){
        possible = 1;
        cin >> V >> E;
        for(int i=0; i<E; i++){
            cin >> p1 >> p2;
            v[p1].push_back(p2);
            v[p2].push_back(p1);
        }
    
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                DFS(i);
                if(!possible) break;
            }
        }
        if(possible) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        for(int i=1; i<=V; i++){
            visited[i] = 0;
            v[i].clear();
        }

    }
}
