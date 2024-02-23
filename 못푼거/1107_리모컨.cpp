#include<iostream>
using namespace std;
int check(int num, int broken[11]);
int main(){
    int N, M, i, len, tmp,mul2;
    int v1,v2,v3,v4,v5,v6,num;
    int is_first_zero = 1;
    int broken[11] = {0,};
    int cnt[6];
    int min_num = 500000;
    int mul1 = 1;
    cin >> N >> M;
    string possible = "";
    string Num = to_string(N);
    len = Num.length();

    for(i=1; i<=M; i++){
        cin >> tmp;
        broken[tmp]++;
    }

    if(M == 10){    //M이 10이면 그냥 +,-로 가는 수밖에..
        tmp = (N > 100)?N-100:100-N;
        cout << tmp;
        return 0;
    }
//---------------------------------------
    //숫자 쳐서 옮기기
    tmp = 0;
    for(i=0; i<len; i++) mul1*=10;
    mul2 = mul1;
    for(i=0; i<len; i++){
        mul1/=10;
        cnt[i] = check(Num[i]-'0',broken);
        tmp += cnt[i] * mul1;
        tmp ++;
        //cout << cnt[i] * pow(10,len-1-i) << " - " << tmp << endl;
    
    }
    min_num = min(min_num,tmp);

    //100에서부터 +,-로 움직이기
    tmp = (N > 100)?N-100:100-N;
    min_num = min(min_num,tmp);
        
    //가능한 모든 경우로 브루트포스?
    //이걸 어떻게 해야 할 지를 모르겠네

    //for(i=0; i<len; i++) cout << i << " : " << cnt[i] << endl;
    cout << min_num;

}
int check(int num, int broken[11]){
    int diff, min_num;
    min_num = 100;
    for(int i=0; i<10; i++){
        if(!broken[i]){
            diff = (i > num)? i-num : num-i;
            if(diff < min_num) min_num = diff;
        }
    }
    return min_num;
}