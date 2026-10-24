#include <iostream>
#include <string>
#include <vector>
#include "DeTai.h"

#ifdef _WIN32
#include <windows.h>
#endif

void chay_vi_du_1() {
    std::cout << "\n========================================\n";
    std::cout << "CHAY VI DU 1: n = 4, k = 2\n";
    std::cout << "========================================\n";
    int n = 4, k = 2;
    auto ds = liet_ke_to_hop(n, k);
    long long cnt = dem_to_hop(n, k);
    
    std::cout << "Du lieu vao: n = " << n << ", k = " << k << "\n";
    std::cout << "Ket qua chinh (danh sach to hop):\n[";
    for (size_t i = 0; i < ds.size(); ++i) {
        std::cout << to_string_to_hop(ds[i]);
        if (i + 1 < ds.size()) std::cout << ", ";
    }
    std::cout << "]\n";
    std::cout << "Tong so to hop sinh duoc: " << ds.size() << "\n";
    std::cout << "Kiem chung bang cong thuc C(4, 2) = " << cnt << "\n";
    std::cout << "Danh gia: " << (ds.size() == (size_t)cnt ? "KHOP HOAN TOAN (PASS)" : "SAI LECH (FAIL)") << "\n";
}

void chay_vi_du_2() {
    std::cout << "\n========================================\n";
    std::cout << "CHAY VI DU 2: n = 3, k = 0 (Truong hop bien to hop rong)\n";
    std::cout << "========================================\n";
    int n = 3, k = 0;
    auto ds = liet_ke_to_hop(n, k);
    long long cnt = dem_to_hop(n, k);
    
    std::cout << "Du lieu vao: n = " << n << ", k = " << k << "\n";
    std::cout << "Ket qua chinh (danh sach to hop):\n[";
    for (size_t i = 0; i < ds.size(); ++i) {
        std::cout << to_string_to_hop(ds[i]);
        if (i + 1 < ds.size()) std::cout << ", ";
    }
    std::cout << "]\n";
    std::cout << "Tong so to hop sinh duoc: " << ds.size() << "\n";
    std::cout << "Kiem chung bang cong thuc C(3, 0) = " << cnt << "\n";
    std::cout << "Danh gia: " << (ds.size() == 1 && ds[0].empty() ? "TO HOP RONG HOP LE (PASS)" : "FAIL") << "\n";
}

void nhap_tu_ban_phim() {
    std::cout << "\n========================================\n";
    std::cout << "NHAP DU LIEU TU BAN PHIM\n";
    std::cout << "========================================\n";
    int n, k;
    std::cout << "Nhap n (0 <= n <= 12): ";
    if (!(std::cin >> n)) return;
    std::cout << "Nhap k (0 <= k <= n): ";
    if (!(std::cin >> k)) return;
    
    try {
        auto ds = liet_ke_to_hop(n, k);
        long long cnt = dem_to_hop(n, k);
        std::cout << "\nKet qua sinh to hop (" << ds.size() << " cau hinh):\n";
        for (size_t i = 0; i < ds.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << to_string_to_hop(ds[i]) << "\n";
        }
        std::cout << "\nKiem chung ly thuyet C(" << n << ", " << k << ") = " << cnt << "\n";
        
        // Tùy chọn lọc phần tử p
        if (k > 0) {
            char chon;
            std::cout << "\nBan co muon loc to hop chua phan tu p khong? (y/n): ";
            std::cin >> chon;
            if (chon == 'y' || chon == 'Y') {
                int p;
                std::cout << "Nhap phan tu p (1 <= p <= " << n << "): ";
                std::cin >> p;
                auto ds_p = loc_to_hop_chua_p(ds, p);
                std::cout << "Cac to hop chua phan tu " << p << " (" << ds_p.size() << " to hop):\n";
                for (size_t i = 0; i < ds_p.size(); ++i) {
                    std::cout << "  " << (i + 1) << ". " << to_string_to_hop(ds_p[i]) << "\n";
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << "\n";
    }
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::cout << "========================================================\n";
    std::cout << "DE TAI DT033: LIET KE TO HOP CHAP K CUA N PHAN TU\n";
    std::cout << "Sinh vien: Vo Ngoc Minh Khang - MSSV: N24DCDT037\n";
    std::cout << "Lop: D24CQDT01-N - Hoc phan: INT13185 (Nhom 03)\n";
    std::cout << "========================================================\n";

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--vd1") {
            chay_vi_du_1();
            return 0;
        } else if (arg == "--vd2") {
            chay_vi_du_2();
            return 0;
        } else if (arg == "--input") {
            nhap_tu_ban_phim();
            return 0;
        }
    }

    // Nếu không có tham số dòng lệnh, chạy menu trực quan
    int lua_chon = 0;
    do {
        std::cout << "\nMENU CHUC NANG:\n";
        std::cout << "  1. Chay Vi du 1 tren phieu giao (n = 4, k = 2)\n";
        std::cout << "  2. Chay Vi du 2 tren phieu giao (n = 3, k = 0)\n";
        std::cout << "  3. Nhap n, k tu ban phim va kiem chung\n";
        std::cout << "  4. Thoat\n";
        std::cout << "Chon chuc nang (1-4): ";
        if (!(std::cin >> lua_chon)) break;

        switch (lua_chon) {
            case 1: chay_vi_du_1(); break;
            case 2: chay_vi_du_2(); break;
            case 3: nhap_tu_ban_phim(); break;
            case 4: std::cout << "Tam biet!\n"; break;
            default: std::cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lua_chon != 4);

    return 0;
}

