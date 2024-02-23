#include<iostream>
using namespace std;
typedef long long ll;
char inequality[10];    //x번째 부등호
int k;
int result[10];
int check[10] = {0,};
ll min_num = 9999999999;
ll max_num = -1;

void min_max_cal(int len);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k;
    for(int i=1; i<=k; i++) cin >> inequality[i];
    for(int i=9; i>=0; i--){
        result[0] = i;
        check[i]=1;
        min_max_cal(1);
        check[i]=0;
    }
    string max_result = to_string(max_num);
    string min_result = to_string(min_num);
    if(max_result.length() == k){
        max_result = "0" + max_result;
    }
    cout << max_result << "\n";
    if(min_result.length() == k){
        min_result = "0" + min_result;
    }
    cout << min_result << "\n";
}
//len 번째 index를 채울 차례
void min_max_cal(int len){
    if(len == k+1){
        ll tmp = 0;
        ll mul = 1;
        for(int i=k; i>=0; i--){
            tmp += mul * result[i];
            mul *= 10;
        }
        max_num = max(max_num, tmp);
        min_num = min(min_num, tmp);
    }
    else{
        int possible = 0;
        if(inequality[len] == '<'){
            for(int i=result[len-1]+1; i<=9; i++){
                if(!check[i]){
                    check[i]=1;
                    result[len] = i;
                    min_max_cal(len+1);
                    check[i]=0;
                    possible = 1;
                }
            }
            
        }
        else if(inequality[len] == '>'){
            for(int i=result[len-1]-1; i>=0; i--){
                if(!check[i]){
                    check[i]=1;
                    result[len] = i;
                    min_max_cal(len+1);
                    check[i]=0;
                    possible = 1;
                }
            }
        }
        if(!possible) return;
    }
}