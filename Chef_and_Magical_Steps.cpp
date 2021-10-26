#include <bits/stdc++.h>
using namespace std;
int dp[10000001];
bool prime[10000001];

void SieveOfEratosthenes(int n =10000001)
{
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        
        if (prime[p] == true)
        {
           
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
}
void solve(int x, int y){
    int count = 0;
    while(x<y){
        if(prime[x+2]){
            x+=2;
        }
        else x++;

        count++;
    }
    cout << count  <<endl;

    
}

int main(){
SieveOfEratosthenes();

int t ; cin>>t;
while(t--){
    int x ,y;
    cin >> x >> y;
    solve(x , y);

}


return 0;
}