#include<iostream>
using namespace std;
void perm(int num[], int depth, int n, int r);
void swap(int num[], int i, int j);
int main(){
    int num[] = {1,2,3,4,5,6,7,8};
    int N,M;
    cin >> N >> M;
    perm(num,0,N,M);
}
void perm(int num[], int depth, int n, int r){
    int i;
    if(depth == r){
        for(i=0; i<r; i++) cout << num[i] << " ";
        cout << "\n";
        return;
    }
    for(i=depth; i<n; i++){
        swap(num, i, depth);
        perm(num, depth+1, n, r);
        swap(num, i, depth);
    }
}
void swap(int num[], int i, int j){
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
}