#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "DeTai.h"

#ifdef _WIN32
#include <windows.h>
#endif

// Bộ kiểm thử tự động gồm 12 ca kiểm thử độc lập
// Bám sát yêu cầu phiếu giao DT033 và Rubric chấm điểm

struct TestCaseResult {
    std::string ma_ca;
    std::string mo_ta;
    bool dat;
};

std::vector<TestCaseResult> danh_sach_ket_qua;

void ghi_nhan_ca(const std::string& ma_ca, const std::string& mo_ta, bool ket_qua) {
    danh_sach_ket_qua.push_back({ma_ca, mo_ta, ket_qua});
    std::cout << "[" << (ket_qua ? "PASS" : "FAIL") << "] " << ma_ca << ": " << mo_ta << "\n";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::cout << "======================================================================\n";
    std::cout << "CHAY BO KIEM THU TU DONG (12 CA TEST DOC LAP) - DE TAI DT033\n";
    std::cout << "Sinh vien: Vo Ngoc Minh Khang - MSSV: N24DCDT037 - Lop: D24CQDT01-N\n";
    std::cout << "======================================================================\n\n";

    // Ca 1 (A01): Vi du 1 tren phieu giao - n = 4, k = 2
    {
        auto ds = liet_ke_to_hop(4, 2);
        std::vector<std::vector<int>> mong_doi = {
            {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}
        };
        bool ok = (ds == mong_doi) && (ds.size() == 6) && (dem_to_hop(4, 2) == 6);
        ghi_nhan_ca("A01_VD1", "Vi du 1 phieu giao: n=4, k=2 sinh dung 6 to hop", ok);
    }

    // Ca 2 (A02): Vi du 2 tren phieu giao - n = 3, k = 0
    {
        auto ds = liet_ke_to_hop(3, 0);
        bool ok = (ds.size() == 1) && (ds[0].empty()) && (dem_to_hop(3, 0) == 1);
        ghi_nhan_ca("A02_VD2", "Vi du 2 phieu giao: n=3, k=0 sinh dung 1 to hop rong [[]]", ok);
    }

    // Ca 3 (A03): n = 5, k = 3 (Vi du 3.2 giao trinh)
    {
        auto ds = liet_ke_to_hop(5, 3);
        bool ok = (ds.size() == 10) && (dem_to_hop(5, 3) == 10);
        // Kiem tra cau hinh dau va cuoi
        if (ok) {
            ok = (ds.front() == std::vector<int>{1, 2, 3}) && (ds.back() == std::vector<int>{3, 4, 5});
        }
        ghi_nhan_ca("A03_VD32", "Vi du 3.2 giao trinh: n=5, k=3 sinh dung 10 to hop", ok);
    }

    // Ca 4 (A04): Ca 5 phieu giao - n = 7, k = 3, sinh tiep tu [2, 4, 6] -> [2, 4, 7]
    {
        std::vector<int> x = {2, 4, 6};
        bool sinh_duoc = to_hop_tiep(x, 7, 3);
        std::vector<int> mong_doi = {2, 4, 7};
        bool ok = sinh_duoc && (x == mong_doi);
        ghi_nhan_ca("A04_TIEP", "Ca 5 phieu giao: n=7, k=3 tu [2, 4, 6] sinh tiep thanh [2, 4, 7]", ok);
    }

    // Ca 5 (A05): Ca 1 phieu giao - n = 1, k = 1
    {
        auto ds = liet_ke_to_hop(1, 1);
        std::vector<std::vector<int>> mong_doi = {{1}};
        bool ok = (ds == mong_doi) && (ds.size() == 1);
        ghi_nhan_ca("A05_BIEN1", "Ca 1 phieu giao: n=1, k=1 chi in [[1]], so luong = 1", ok);
    }

    // Ca 6 (A06): Ca 2 phieu giao - n = 5, k = 5 (k = n)
    {
        auto ds = liet_ke_to_hop(5, 5);
        std::vector<std::vector<int>> mong_doi = {{1, 2, 3, 4, 5}};
        bool ok = (ds == mong_doi) && (ds.size() == 1);
        ghi_nhan_ca("A06_BIEN2", "Ca 2 phieu giao: n=5, k=5 chi in [[1, 2, 3, 4, 5]], so luong = 1", ok);
    }

    // Ca 7 (A07): Ca 3 phieu giao - n = 5, k = 1
    {
        auto ds = liet_ke_to_hop(5, 1);
        std::vector<std::vector<int>> mong_doi = {{1}, {2}, {3}, {4}, {5}};
        bool ok = (ds == mong_doi) && (ds.size() == 5);
        ghi_nhan_ca("A07_BIEN3", "Ca 3 phieu giao: n=5, k=1 lan luot [1] den [5], so luong = 5", ok);
    }

    // Ca 8 (A08): Ca loi LOI01 - Kiem tra input khong hop le
    {
        bool caught = false;
        try {
            liet_ke_to_hop(3, 5); // k > n la loi
        } catch (const std::invalid_argument&) {
            caught = true;
        }
        ghi_nhan_ca("A08_LOI01", "Kiem tra du lieu vao sai (k > n): nem ngoai le hop le", caught);
    }

    // Ca 9 (A09): Truong hop bien n = 6, k = 0
    {
        auto ds = liet_ke_to_hop(6, 0);
        bool ok = (ds.size() == 1) && (ds[0].empty()) && (dem_to_hop(6, 0) == 1);
        ghi_nhan_ca("A09_RONG", "Kiem tra bien k=0 tren n=6: tra ve dung 1 to hop rong", ok);
    }

    // Ca 10 (A10): Kiem tra cau hinh cuoi cung [5, 6, 7] tren n=7, k=3 khong sinh tiep duoc
    {
        std::vector<int> x = {5, 6, 7};
        bool sinh_duoc = to_hop_tiep(x, 7, 3);
        bool ok = (!sinh_duoc) && (x == std::vector<int>{5, 6, 7});
        ghi_nhan_ca("A10_DUNG", "Kiem tra dieu kien dung: cau hinh cuoi [5, 6, 7] tra ve false", ok);
    }

    // Ca 11 (A11): Quy mo vua n = 10, k = 2 (C(10, 2) = 45) va kiem tra bat bien tang nghiem ngat
    {
        auto ds = liet_ke_to_hop(10, 2);
        bool ok = (ds.size() == 45) && (dem_to_hop(10, 2) == 45);
        // Kiem tra bat bien: moi to hop deu tang nghiem ngat va thu tu tu dien tang dan
        if (ok) {
            for (size_t i = 0; i < ds.size(); ++i) {
                if (ds[i][0] >= ds[i][1]) { ok = false; break; }
                if (i > 0 && ds[i - 1] >= ds[i]) { ok = false; break; }
            }
        }
        ghi_nhan_ca("A11_QUYMO", "Quy mo n=10, k=2: sinh dung 45 to hop va dam bao thu tu tu dien", ok);
    }

    // Ca 12 (A12): Yeu cau tuy chon - Loc to hop chua phan tu p = 3 tren n = 6, k = 3
    {
        auto ds = liet_ke_to_hop(6, 3); // Tong C(6, 3) = 20 to hop
        auto ds_chua_3 = loc_to_hop_chua_p(ds, 3);
        // So to hop chua 3 chinh bang C(5, 2) = 10
        bool ok = (ds.size() == 20) && (ds_chua_3.size() == 10);
        ghi_nhan_ca("A12_MOHUONG", "Yeu cau tuy chon: loc to hop chua phan tu p=3 cho ra dung 10 to hop", ok);
    }

    // Tong ket
    int so_dat = 0;
    for (const auto& r : danh_sach_ket_qua) {
        if (r.dat) so_dat++;
    }

    std::cout << "\n======================================================================\n";
    std::cout << "TONG KET KIEM THU: " << so_dat << " / " << danh_sach_ket_qua.size() << " CA DAT (PASS)\n";
    std::cout << "TY LE HOAN THANH: " << (so_dat * 100.0 / danh_sach_ket_qua.size()) << "%\n";
    std::cout << "======================================================================\n";

    return (so_dat == (int)danh_sach_ket_qua.size()) ? 0 : 1;
}

