#include <iostream>
#include <algorithm>

using namespace std; 

vector<int> bit1, bit2; 
/* Theo lý thuyết tính toán, ta quy ước bit1 tương đương với mảng diff của a => tổng của các diff từ 1 -> diff[i] chính là a[i]
   Tương tự, ta suy ra được là : sum[i] = sigma(n - j + 1) * diff[j] - (n - i) * sigma(diff[1 -> i])với j chạy từ 1 -> i 
   ------> bit2 được dùng để lưu phần đầu của mảng này

   Đọc thêm tại https://wiki.vnoi.info/algo/data-structures/fenwick
*/

void updatepoint(vector<int>& bit, int u, int v) { 
    int idx = u; 

    // Cả đoạn dưới này là dùng để cộng những ảnh hưởng của a[u] lên các tập prefix lớn hơn sau khi + thêm v 
    while (idx <= n) { //biên
        bit[idx] += v; // Cộng ảnh hưởng
        idx += (idx & (-idx)); //tìm tập 2^k tiếp theo bị ảnh hưởng
    }
}

void updaterange (int l, int r, int v) {
    updatepoint(bit1, l, v); //Khi ta thay đổi giá trị của cả 1 range, trong mảng diff chỉ 2 giá trị thay đổi đó là l và r + 1 
    updatepoint(bit1, r + 1, -v); //r + 1

    updatepoint(bit2, l, (n - l + 1) * v); 
    updatepoint(bit2, r + 1, -(n - r) * v); //tương tự nhưng là có nhân :v 
}

long long getsumonbit(vector<int>& bit, int u) {
    long long ans = 0; 

    // Đây là phần ngược lại của hàm updatepoint. Ở hàm update point, ta thêm giá trị v vào các hàm cha bị ảnh hưởng 
    // Còn ở hàm này, ta tính tổng từ 1 -> u dựa trên tập diff để tìm dc giá trị a[u]; 
    int idx = u; 

    while (idx > 0) { //biên
        ans += bit[idx]; 
        idx -= (idx & (-idx)); 
    }
    return ans; 
}

// Cái hàm này vui nè :v 
long long prefix(int u) {
    return getsumonbit(bit2, u) - getsumonbit(bit1, u) * (n - u); 
} 


int main() {

}
