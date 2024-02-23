#include<iostream>
using namespace std;
int main(){
    int A,B, result,i,j,T;
    cin >> T;
    cin.ignore();
    while(T--){
        cin >> A >> B;
        if(A>B) { //더 작은 수를 a에 넣어두자.
            result = B; B = A; A = result;
        }
        result = 0; i = 1; j = B;
        while(!result){
            if(j%B==0 && j%A==0){
                result = j;
                break;
            }
            i++;
            j = B * i;
        }
        cout << result << endl;;
    }
}