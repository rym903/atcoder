#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    // printf("%d %d %d\n", n, m, s);

    int k = gcd<int, int>(21, 42);
    printf("%d\n", k);
    return 0;

}