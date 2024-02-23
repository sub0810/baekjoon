#include<iostream>
using namespace std;
char sign_matrix[11][11];
int result[11]; //1~10 index 사용
int result_sum[11] = {0,};
int n;
void guess(int len);
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            cin >> sign_matrix[i][j];
        }
    }
    guess(1);

}
void guess(int len){ //len : 이번에 채워야할 칸
    int possible;
    int tmp;
    if(len == n+1){
        //출력
        cout << result[1];
        for(int i=2; i<=n; i++) cout << " " << result[i];
        exit(0);
    }
    else{
        if(sign_matrix[len][len] == '+'){
            for(int i=0; i<=10; i++){ //숫자 탐색 
                possible = 1;
                for(int j=0; j<len; j++){
                    tmp = result_sum[len-1]-result_sum[j]+i;
                    //세 가지 경우에 모두 해당하지 않으면 이 숫자 skip
                    if(!((tmp == 0 && sign_matrix[j+1][len] == '0')||(tmp > 0 && sign_matrix[j+1][len] == '+')||(tmp < 0 && sign_matrix[j+1][len] == '-'))){
                        possible = 0;
                        break;
                    }
                }
                if(possible){
                    result[len] = i;
                    result_sum[len] = result_sum[len-1]+result[len];
                    guess(len+1);
                }
            }
        }
        else if(sign_matrix[len][len] == '-'){
            for(int i=0; i<=10; i++){ //숫자 탐색
                possible = 1;
                //조건 따지기
                for(int j=0; j<len; j++){
                    tmp = result_sum[len-1]-result_sum[j]-i;
                    //세 가지 경우에 모두 해당하지 않으면? 
                    if(!((tmp == 0 && sign_matrix[j+1][len] == '0')||(tmp > 0 && sign_matrix[j+1][len] == '+')||(tmp < 0 && sign_matrix[j+1][len] == '-'))) possible = 0;
                }
                if(possible){
                    result[len] = -i;
                    result_sum[len] = result_sum[len-1]+result[len];
                    guess(len+1);
                }
            }
        }
    }
}