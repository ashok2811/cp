#include <bits/stdc++.h>

using namespace std;

long long gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b , a%b);
}

int main(){
    int a = 5, b = 6;
    cout << gcd(a ,b) << " Hello" <<  endl;
}

