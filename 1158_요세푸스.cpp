#include<iostream>
#include<queue>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    int cnt=0;
    //초기 세팅
    queue<int> q;
    for(int i=1; i<N+1; i++){
        q.push(i);
    }
    //K번째마다 꺼내기
    cout << "<";
    while(q.size() != 1){//마지막은 출력 형식 달라서.. size = 1인 상태로 만들어야겠는데 일단
        cnt++;
        if(cnt == K){   //K번째면 내보내야.
            cout << q.front() << ", ";
            q.pop();
            cnt = 0;
        }
        else{       //K번째가 아니면, 다시 queue에
            q.push(q.front());
            q.pop();
        }
    }
    //마지막 element
    cout << q.front() << ">";
    q.pop();
}