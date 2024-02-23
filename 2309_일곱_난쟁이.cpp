#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height[9],i,j,sum;
    int check = 0;
    sum = 0;
    for(i=0; i<9; i++){
        cin >> height[i];
        sum += height[i];
    }
    //정렬 먼저
    sort(height,height+9);
    //2명 색출해내기
    for(i=1; i<9; i++){
        for(j=0; j<i; j++){
            if(sum-height[i]-height[j] == 100){
                for(int k=0; k<9; k++){
                    if(k==i || k==j) continue;
                    cout << height[k] << "\n";
                }
                check=1;
                break;
            }
        }
        if(check) break;
    }
}