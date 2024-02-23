#include<iostream>
using namespace std;
int main(){
    int A,B, result,i;
    cin >> A >> B;
    
    if(A>B) { //더 작은 수를 a에 넣어두자.
        result = B; B = A; A = result;
    }
    //최대공약수 -> 최소공배수 순서로 출력
    for(i=1; i<=A; i++){
        if(A%i==0 && B%i==0) result = i;
    }
    cout << result << endl;

    result = 0; i = B;
    while(!result){
        if(i%B==0 && i%A==0) result = i;
        i++;
    }
    cout << result;
}