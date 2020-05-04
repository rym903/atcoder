#include<cstdio>
#include<cstdlib>
using namespace std;

// arrの中で最大のインデックスとその値を格納する
void max_residual(long arr[], int n, long max_iv[]){
    long item=0, value=-1;

    for(int i=0; i<n; i++){
        if(arr[i] > value){
            item = i;
            value = arr[i];
        }
    }

    max_iv[0] = item;
    max_iv[1] = value;
    arr[item] = 0;
    // printf("%ld, %ld\n", item, value);
}

// max_ivの子供が、一番幸福度が大きくなる所に移し、その幸福度を返す。
long ido(long max_iv[], bool is_filled[], long n){
    long item=max_iv[0], value=max_iv[1];
    long dist=-1, pos=-1;

    for(int i=0; i<n; i++){
        if(is_filled[i]) continue;
        
        if(abs(i-item) > dist){
            dist = abs(i-item);
            pos = i;
        }
    }
    is_filled[pos] = true;
    printf("幸福度%ldの、左から%ld番目の子が、左から%ldに移動(%ld)\n", value, item+1, pos+1, value*dist);
    return dist * value;
}

int main(){
    long n;
    scanf("%ld", &n);

    long happy[n];
    bool is_filled[n];
    for(int i=0;i<n;i++){
        scanf("%ld", &happy[i]);
        is_filled[i] = false;
    }

    long max_iv[2];

    int ans=0;
    for(int i=0; i<n; i++){
        max_residual(happy, n, max_iv);
        ans += ido(max_iv, is_filled, n);
        printf("合計値: %d\n", ans);
    }

    printf("%d\n", ans);

    return 0;
}