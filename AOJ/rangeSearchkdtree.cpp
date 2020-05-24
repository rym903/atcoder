#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
// #define BUGS
 
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

struct P {
    int x;
    int y;
    int id;
};

struct Node {
    P mid;
    Node *left;
    Node *right;
};

vector<P> a;
int N, Q;
int sx, sy, tx, ty;
Node *head;
vector<int> ans;

class axisSorter {
    int k;
public:
    axisSorter(int _k) : k(_k) {}
    double operator()(const P &a_, const P &b_) {
        if(k==0) return a_.x < b_.x;
        else return a_.y < b_.y;
    }
};

Node* buildKDtree(int l, int r, int depth){
    if(l>=r){
        return NULL;
    }

    sort(a.begin()+l, a.begin()+r, axisSorter(depth%2));
    int mid = (l+r)/2; // (l+r)/2 と同じ

    Node *node = new Node();
    node->mid = a[mid];
    // printf("depth=%d, mid=%d, mid.x = %d, mid.y = %d\n", depth, mid, node->mid.x, node->mid.y);
    node->left = buildKDtree(l, mid, depth+1);
    node->right = buildKDtree(mid+1, r, depth+1);
    return node;
}

void rangeSearch(Node* nd, int depth){
    // printf("Sdepth=%d, mid.x = %d, mid.y = %d, (%d, %d), (%d, %d)\n", depth, nd->mid.x, nd->mid.y, sx, sy, tx, ty);
    if(sx <= nd->mid.x && nd->mid.x <= tx && sy <= nd->mid.y && nd->mid.y <= ty){
        #ifdef BUGS
            printf("pushed!\n");
        #endif
        ans.push_back(nd->mid.id);
        if(nd->left != NULL) rangeSearch(nd->left, depth+1);
        if(nd->right != NULL) rangeSearch(nd->right, depth+1);
    }else if(depth%2==0){
        if(nd->mid.x < sx){
            if(nd->right != NULL) rangeSearch(nd->right, depth+1);
        }else if(tx < nd->mid.x){
            if(nd->left != NULL) rangeSearch(nd->left, depth+1);
        }else{
            if(nd->left != NULL) rangeSearch(nd->left, depth+1);
            if(nd->right != NULL) rangeSearch(nd->right, depth+1);
        }
    }else if(depth%2==1){
        if(nd->mid.y < sy){
            if(nd->right != NULL) rangeSearch(nd->right, depth+1);
        }else if(ty < nd->mid.y){
            if(nd->left != NULL) rangeSearch(nd->left, depth+1);
        }else{
            if(nd->left != NULL) rangeSearch(nd->left, depth+1);
            if(nd->right != NULL) rangeSearch(nd->right, depth+1);
        }
    }

    // printf("x=%d, y=%d, dpth=%d\n", nd->mid.x, nd->mid.y, depth);
}

int main()
{
    cin >> N;
    a.resize(N);
    rep(i, N){
        scanf("%d %d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    // sort(a.begin(), a.begin()+a.size(), axisSorter(1));
    // rep(i, N){
    //     printf("(%d, %d) ", a[i].x, a[i].y);
    // }
    // printf("\n");

    head = buildKDtree(0, N, 0);
    cin >> Q;
    rep(i, Q){
        cin >> sx >> tx >> sy >> ty;
        ans.clear();
        rangeSearch(head, 0);
        sort(ans.begin(), ans.end());
        rep(j, ans.size()){
            printf("%d\n",ans[j]);
        }
        printf("\n");
    }


    return 0;
}