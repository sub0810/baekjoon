#include<iostream>
using namespace std;

int check(char candy[51][51], int N);
int main(){
    char candy[51][51]={0,};
    char change;
    int i,j,N,tmp,maximum;
    maximum = -1;
    cin >> N;

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            cin >> candy[i][j];
        }
    }

    for(i=1; i<=N; i++){    //좌우로 변경
        for(j=2; j<=N; j++){
            if(candy[i][j] == candy[i][j-1]) continue;
            change = candy[i][j];
            candy[i][j] = candy[i][j-1];
            candy[i][j-1] = change;
            tmp = check(candy, N);
            maximum = max(maximum,tmp);
            change = candy[i][j];
            candy[i][j] = candy[i][j-1];
            candy[i][j-1] = change;
        }
    }
    for(j=1; j<=N; j++){    //상하로 변경
        for(i=2; i<=N; i++){
            if(candy[i][j] == candy[i-1][j]) continue;
            change = candy[i][j];
            candy[i][j] = candy[i-1][j];
            candy[i-1][j] = change;
            tmp = check(candy, N);
            maximum = max(maximum,tmp);
            change = candy[i][j];
            candy[i][j] = candy[i-1][j];
            candy[i-1][j] = change;
        }
    }

    cout << maximum;
}

int check(char candy[51][51], int N){
    int maximum,C,P,Z,Y,i,j;
    maximum = -1;
    for(i=1; i<=N; i++){    //가로 확인
        C = 0; P = 0; Z = 0; Y = 0;
        if(candy[i][1] == 'C') C++;
        else if(candy[i][1] == 'P') P++;
        else if(candy[i][1] == 'Z') Z++;
        else if(candy[i][1] == 'Y') Y++;
        for(j=2; j<=N; j++){
            if(candy[i][j-1] == candy[i][j]){
                if(candy[i][j] == 'C') C++;
                else if(candy[i][j] == 'P') P++;
                else if(candy[i][j] == 'Z') Z++;
                else if(candy[i][j] == 'Y') Y++;
            }
            else{ //이전이랑 다르면 원래 있던 값을 maximum과 비교
                if(candy[i][j] == 'C'){
                    if(maximum < C) maximum = C;
                    C = 1;
                }
                if(candy[i][j] == 'P'){
                    if(maximum < P) maximum = P;
                    P = 1;
                }
                if(candy[i][j] == 'Z'){
                    if(maximum < Z) maximum = Z;
                    Z = 1;
                }
                if(candy[i][j] == 'Y'){
                    if(maximum < Y) maximum = Y;
                    Y = 1;
                }
            }
        }
        if(maximum < C) maximum = C;
        if(maximum < P) maximum = P;
        if(maximum < Z) maximum = Z;
        if(maximum < Y) maximum = Y;
    }
    for(j=1; j<=N; j++){    //세로 확인
        C = 0; P = 0; Z = 0; Y = 0;
        if(candy[1][j] == 'C') C++;
        else if(candy[1][j] == 'P') P++;
        else if(candy[1][j] == 'Z') Z++;
        else if(candy[1][j] == 'Y') Y++;
        for(i=2; i<=N; i++){
            if(candy[i-1][j] == candy[i][j]){
                if(candy[i][j] == 'C') C++;
                else if(candy[i][j] == 'P') P++;
                else if(candy[i][j] == 'Z') Z++;
                else if(candy[i][j] == 'Y') Y++;
            }
            else{ //이전이랑 다르면 원래 있던 값을 maximum과 비교
                if(candy[i][j] == 'C'){
                    if(maximum < C) maximum = C;
                    C = 1;
                }
                if(candy[i][j] == 'P'){
                    if(maximum < P) maximum = P;
                    P = 1;
                }
                if(candy[i][j] == 'Z'){
                    if(maximum < Z) maximum = Z;
                    Z = 1;
                }
                if(candy[i][j] == 'Y'){
                    if(maximum < Y) maximum = Y;
                    Y = 1;
                }
            }
        }
        if(maximum < C) maximum = C;
        if(maximum < P) maximum = P;
        if(maximum < Z) maximum = Z;
        if(maximum < Y) maximum = Y;
    }
    return maximum;
}