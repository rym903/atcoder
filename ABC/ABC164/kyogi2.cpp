#include<cstdio>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int a;
    for(int i=0; i<m; i++){
        scanf("%d", &a);
        n -= a;
        if(n<0){
            n = -1;
            break;
        }
    }
    printf("%d\n", n);
    return 0;
}