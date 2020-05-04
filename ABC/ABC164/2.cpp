#define FOR(i, a, b) for(int i=a; i<b; i++)
#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<cstdlib>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    while(true){
        c -= b;
        if(c<=0){
            printf("Yes\n");
            break;
        }
        a -= d;
        if(a<=0){
            printf("No\n");
            break;
        }
    }

    return 0;
}