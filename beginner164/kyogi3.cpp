#include<cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i=0;i<n;i++){
        nums[i]=0;
    }

    int a;
    for(int i=0;i<n-1;i++){
        scanf("%d", &a);
        nums[a-1] += 1;
    }

    for(int i=0; i<n; i++){
        printf("%d\n", nums[i]);
    }

    return 0;
}