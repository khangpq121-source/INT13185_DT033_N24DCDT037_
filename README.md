# ĐỀ TÀI DT033: LIỆT KÊ TỔ HỢP CHẬP K CỦA N PHẦN TỬ

* **Họ và tên:** Võ Ngọc Minh Khang
* **MSSV:** N24DCDT037
* **Lớp:** D24CQDT01-N
* **Học phần:** Cấu trúc dữ liệu và giải thuật (INT13185 - Nhóm 03)
* **Giảng viên hướng dẫn:** Hồ Nhựt Minh
* **Mã đề:** DT033

---

## 1. Môi trường và Yêu cầu hệ thống
* **Ngôn ngữ:** C++ (chuẩn C++17 trở lên)
* **Trình biên dịch:** `g++` (GCC / MinGW / MSYS2) hoặc bất kỳ trình biên dịch C++17 nào
* Không sử dụng thư viện ngoài, chỉ dùng thư viện chuẩn (`<vector>`, `<iostream>`, `<algorithm>`, `<string>`, `<sstream>`).

---

## 2. Cấu trúc thư mục dự án
```text
DT033_CPP/
├── include/
│   └── DeTai.h               # Khai báo các hàm thuật toán sinh tổ hợp và kiểm chứng
├── src/
│   ├── DeTai.cpp             # Định nghĩa chi tiết các thuật toán
│   └── main.cpp              # Chương trình chính (chạy demo, nhập bàn phím, ví dụ)
├── test/
│   └── runtests.cpp          # Bộ kiểm thử tự động 12 ca kiểm thử độc lập
├── docs/
│   └── anh_ket_qua/          # Chứa 11 ảnh chụp màn hình minh chứng
├── README.md                 # Hướng dẫn biên dịch và chạy
└── .gitignore
```

---

## 3. Lệnh biên dịch (Compile)

Mở terminal hoặc PowerShell tại thư mục `DT033_CPP`:

```powershell
# Biên dịch chương trình chính:
g++ -O2 -std=c++17 -Iinclude src/DeTai.cpp src/main.cpp -o main.exe

# Biên dịch bộ kiểm thử tự động:
g++ -O2 -std=c++17 -Iinclude src/DeTai.cpp test/runtests.cpp -o runtests.exe
```

---

## 4. Lệnh chạy chương trình

### 4.1. Chạy Ví dụ 1 trên phiếu giao ($n = 4, k = 2$):
```powershell
.\main.exe --vd1
```

### 4.2. Chạy Ví dụ 2 trên phiếu giao ($n = 3, k = 0$):
```powershell
.\main.exe --vd2
```

### 4.3. Chạy chế độ nhập dữ liệu tương tác từ bàn phím:
```powershell
.\main.exe --input
```
Hoặc chạy trực tiếp `.\main.exe` để hiện menu tương tác.

### 4.4. Chạy toàn bộ 12 ca kiểm thử tự động:
```powershell
.\runtests.exe
```
Kết quả kiểm thử hiển thị chi tiết trạng thái `[PASS]` / `[FAIL]` cho từng ca kiểm thử và tỷ lệ hoàn thành.

