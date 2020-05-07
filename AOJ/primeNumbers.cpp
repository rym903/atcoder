#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template <class T>
void print(T& x){printf("%d\n", x);}
void printvec(vector<int> a){
    rep(i, a.size()-1){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size()-1]);
}


vector<int> primes(100000);
int num_prime = 0; 

bool IsPrime(int m){
    if(m<2) return false;
    if(m==2) return true;
    if(m%2==0) return false;

    double root_m = sqrt(m);

    for(int i=3; i<=root_m; i+=2){
        if(m%i==0) return false;
    }

    return true;
}

void updatePrimes(int st, int max_v){
    for(int i=st;i < max_v+1; i+=2){
        if(IsPrime(i)){
            num_prime++;
            primes[num_prime] = i;
            // printf("%dは素数 ", i);
        }
    }
}
 
int main()
{
    primes[0] = 0;
    primes[1] = 2;
    primes[2] = 3;
    num_prime = 2;
    updatePrimes(5, 1000000);
    int num, id;

    while(scanf("%d", &num) != EOF){
        auto it = lower_bound(primes.begin(), primes.begin()+num_prime, num);
        if(*it > num) it--;
        id = it - primes.begin();
        printf("%d\n", id);
    }
    return 0;
}