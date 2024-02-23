#include<iostream>
using namespace std;
int N,M;
int arr[8] = {0,};
void dfs(int count);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    dfs(0);
}

void dfs(int count){
    if(count == M){
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<N; i++){
        arr[count] = i+1;
        dfs(count+1);
    }
}