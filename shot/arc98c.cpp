#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    /* 入力受け取り */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    /* しゃくとり法 */
    long long res = 0;
    int right = 0;
    int sum = 0; // AND 和
    for (int left = 0; left < n; ++left) {
        cout << sum << endl;
        while (right < n && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            ++right;
        }
        res += right - left;
        if (left == right) ++right;
        else {
            sum -= a[left]; // a[left] を削除 (sum ^= a[left] でも OK)
        }
    }
    
    cout << res << endl;
}