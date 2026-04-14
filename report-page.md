# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu
Mục tiêu của bài lab là hiểu và cài đặt cách tính entropy để đo độ ngẫu nhiên của dữ liệu, đồng thời áp dụng thuật toán Euclid mở rộng để tìm nghịch đảo modulo. Qua đó, giúp sinh viên liên hệ giữa lý thuyết mật mã và lập trình thực tế.

## 2. Cách làm
- Đọc hiểu chương trình entropy mẫu.
- Bổ sung hàm tính redundancy.
- Hoàn thiện hàm mod_inverse().
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Entropy và redundancy
| Input | Entropy | Redundancy | Nhận xét |
|---|---:|---:|---|
| aaaa | 0 |8  |  Entropy = 0 → chuỗi không có tính ngẫu nhiên, tất cả ký tự đều giống nhau.
                  Redundancy = 8 → mức dư thừa tối đa, vì không có thông tin mới được tạo ra.
                  Điều này cho thấy dữ liệu hoàn toàn có thể dự đoán trước và không mang nhiều giá trị thông tin.|
| abcd |2  | 6 | Entropy = 2 → chuỗi có mức độ ngẫu nhiên cao, các ký tự xuất hiện với xác suất bằng nhau.
                 Redundancy = 6 → vẫn còn dư thừa do bảng chữ cái giả định là 256 ký tự.
                 Đây là trường hợp phân bố đều, nên entropy đạt giá trị cao hơn so với chuỗi lặp. |
| hello world | 2.84535 | 5.15465 | Entropy ≈ 2.85 → chuỗi có mức độ ngẫu nhiên trung bình, có cả ký tự lặp và ký tự khác nhau.
                                    Redundancy ≈ 5.15 → vẫn tồn tại độ dư thừa đáng kể do một số ký tự xuất hiện nhiều lần (như l, o).
                                    Đây là dạng dữ liệu thực tế, không hoàn toàn ngẫu nhiên nhưng cũng không quá lặp. |

### 3.2 Modulo inverse
| a | m | Kết quả mong đợi | Kết quả chương trình |
|---:|---:|---|---|
| 3 | 7 | 5 | 5 |
| 10 | 17 | 12 |  12|
| 6 | 9 | Không tồn tại | không tồn tại |

## 4. Kết luận
Qua bài lab, em hiểu cách tính entropy để đo mức độ ngẫu nhiên của dữ liệu và cách sử dụng thuật toán Euclid mở rộng để tìm nghịch đảo modulo trong mật mã học. Đồng thời, em cũng nắm được cách triển khai các công thức toán học thành chương trình C++.

Khó khăn lớn nhất:
Khó khăn lớn nhất là hiểu rõ ý nghĩa của công thức (đặc biệt là entropy và điều kiện tồn tại nghịch đảo modulo) và xử lý lỗi khi chương trình cho kết quả sai dù thuật toán có vẻ đúng.

Điều giúp em hiểu rõ hơn:
Việc tự chạy nhiều test case khác nhau và kiểm tra lại kết quả bằng tay đã giúp em hiểu rõ hơn bản chất của entropy và cách hoạt động của modulo inverse.
