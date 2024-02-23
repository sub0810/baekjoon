#include <iostream>
#include <stack>

using namespace std;
int temp, num, arr[1000001];

int main() {
	stack<int> s;

	cin >> num;
    cin.ignore();
	for (int i=0; i<num; i++) cin >> arr[i];
	
    //시작
	s.push(arr[num-1]);	//가장 오른쪽에 있는 수는 stack에 push
	arr[num-1] = -1;		//가장 오른쪽의 있는 수는 오큰수가 없으므로 -1
	for (int i=num-2; i>=0; i--) {
		temp = arr[i];			//stack의 top과 비교할 숫자
        //스택에 값이 남아있다면, 그게 오큰수
        //스택에 값이 없다면, -1
		while(!s.empty() && temp >= s.top()) s.pop();

        if(s.empty()) arr[i] = -1;
        else arr[i] = s.top();

		s.push(temp);
	}

	for (int i=0; i<num; i++) cout << arr[i] << " ";
}