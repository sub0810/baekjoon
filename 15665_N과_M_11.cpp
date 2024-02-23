#include<iostream>
using namespace std;
int N,M,tmp;
int arr[8] = {0,};
int input_num[8] = {0,};
int check[8] = {0,};
void dfs(int count);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> input_num[i];
    for(int i=0; i<N; i++){
        for(int j=1; j<N-i; j++){
            if(input_num[j-1] > input_num[j]){
                tmp = input_num[j-1];
                input_num[j-1] = input_num[j];
                input_num[j] = tmp;
            }
        }
    }
    dfs(0);
}

void dfs(int count){
    int dup_check[10001] = {0,};
    if(count == M){
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<N; i++){
        if(!dup_check[input_num[i]]){
            dup_check[input_num[i]] = 1;
            check[i]++;
            arr[count] = input_num[i];
            dfs(count+1);
            check[i]--;
        }
    }
}