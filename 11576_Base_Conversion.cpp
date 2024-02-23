#include<iostream>
#include<stack>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    stack<long long> s;
    long long A,B,m,in,A_to_ten,ten_to_B;
    A_to_ten = 0, ten_to_B = 0;
    cin >> A >> B >> m;
    //A to ten
    for(int i=0; i<m; i++){
        cin >> in;
        A_to_ten = A_to_ten * A + in;
    }
    //ten to B
    while(A_to_ten/B != 0){
        ten_to_B = A_to_ten%B;
        s.push(ten_to_B);
        A_to_ten/=B;
    }
    s.push(A_to_ten);
    
    while(!s.empty()){
        cout << s.top() << " "; s.pop();
    }
}