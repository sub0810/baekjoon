#include<iostream>
using namespace std;
int N,M;
int arr[8] = {0,};
int check[8] = {0,};
void dfs(int count);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    dfs(0);
}

void dfs(int count){
    int print_possible = 1;
    if(count == M){
        for(int i=1; i<M; i++){
            if(arr[i] < arr[i-1]){
                print_possible = 0;
                break;
            }
        }

        if(print_possible){
            for(int i=0; i<M; i++) cout << arr[i] << " ";
            cout << "\n";
            return;
        }

    }
    for(int i=0; i<N; i++){
        if(!check[i]){
            check[i]++;
            arr[count] = i+1;
            dfs(count+1);
            check[i]--;
        }
    }
}