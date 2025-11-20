for(int j = 1; j <= num; ++j) {
        cout << j << '\n'; 
        for(int i = 1; i <= am; ++i) {
            if (a[i] <= j) { 
                ways[j] += ways[j - a[i]]; 
                ways[j] %= LOG;
                cout << a[i] << '\n'; 
                for(int k = 1; k <= num; ++k) {
                    cout << ways[k] << ' '; 
                }
                cout << '\n'; 

            }
            cout << '\n';   
        }
    } 
    cout << ways[num] % LOG; 



/* 
Lý giải về sự khác biệt giữa Coin Combiantion I và Coin Combination II 

Trong Coin Combination I : 
for 1 -> sum 
    for coin in coins  
        if ( a[i] < s) 
            ... 

=> Tất cả các hoán vị được sinh ra : Vì mình đang tính mọi trường hợp 
Khi t là vòng ngoài => xây t để thử tất cả các coin bước cuối cùng -=> tính luôn cả những chuỗi có lặp lại => Tính tất cả các trường hợp 
=> sinh full combo hoán vị 


Trong Coin Combination II : 
for coin in coins 
    for 1 -> sum 
        if (...) 

-> Không có hoán vị lặp : do không xử lý coin lặp lại ( tức nếu tổng 3, chỉ ghi nhận trường hợp 1 + 2, không thể ghi nhận trường hợp 1 + 1) 
Khi t là vòng trong -> xây t để thử với số coin tăng dần thì khớp ở đâu =>  thứ tự coin cố định => không thể xử lý coin lại, tương đuognư không có hoán vị ( không có 2 + 2 + 2 + 3 và 2 + 3 + 2 + 2 vì nếu đã xử lý 3 thì sẽ tiếp tục xử lý 4 chú không quay lại xử lý 2 _ 
=> Không tạo ra hoán vị 
*/
