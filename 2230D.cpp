#include <bits/stdc++.h>

using namespace std; 
/* 
ban dau : s = dp[0] = 1; 
Goi dp[i][j] la so mang co dang [L, i] va co tap cuoi cung la j 
-> Khi tien hoa sang i + 1, ans += dp[i][j] truoc 

Khi gap i : 
TH1 : a[i] = b[i] 
-> dp[i][a[i]] += dp[i - 1][a[i] - 1] 
Tuc la noi i-1 co tap cuoi la a[i] - 1 vao a[i] -> tong khong thay doi 
Tu than no la 1 doan moi -> Neu arr[i] = 1 -> ++dp[1] Neu #1 thi ++dp[0] -> s++; 
Luu y : i > 1 do neu i = 1 thi khi a[i] > 1 <-> ++dp[0] (da lam ban dau) khi a[i] = 1 <-> khong co gi thay doi, s = 1 san :V noi chung bang bat cu cach nao thi s cung bang 1 nen truong hop bang 1 khong quan trong cho lam :V 

TH2 : a[i] # b[i] 
Lai giai thich cho i > 1 
Neu arr[i] = 1 thi s -= dp[0] = 0 -> Dung dieu kien 
Neu arr[i] > 1 && brr[i] > 1 -> dp[0] = 1 va cac dp con lai bang 0 -> dung dieu kien 

Vi sao dp[0] = 1 ? Vi tai thoi diem ban dau ton tai 1 doan [0, 0] ma A va B deu chua xem tap nao 

https://codeforces.com/contest/2230/problem/D
*/

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int t; cin >> t; 

    while (t--) {
        int n; cin >> n; 

        long long ans = 0LL; 

        vector<int> arr(n + 1, 0), brr(n + 1, 0);

        for(int i = 1; i <= n; ++i) cin >> arr[i]; 
        for(int i = 1; i <= n; ++i) cin >> brr[i]; 

        vector<long long> dp(n + 1, 0); 

        long long s = 1LL; 
        dp[0] = 1; 
        for(int i = 1; i <= n; ++i) { 
            if (arr[i] == brr[i]) {
                dp[arr[i]] += dp[arr[i] - 1]; 
                dp[arr[i] - 1] = 0; 

                if (i > 1) {
                    if (arr[i] > 1) ++dp[0]; 
                    else 
                        ++dp[1];
                    ++s; 
                }
            }

            else {
                s -= dp[arr[i] - 1] + dp[brr[i] - 1]; 
                dp[arr[i] - 1] = dp[brr[i] - 1] = 0; 

                if (i > 1 && arr[i] != 1 && brr[i] != 1) {
                    ++dp[0]; 
                    ++s; 
                }
            }
            ans += s; 
        }
        cout << ans << '\n'; 
    }
}
