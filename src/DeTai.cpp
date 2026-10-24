#include "DeTai.h"
#include <sstream>
#include <algorithm>
#include <stdexcept>

long long dem_to_hop(int n, int k) {
    if (k < 0 || k > n || n < 0) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    int k_rut_gon = std::min(k, n - k);
    long long ans = 1;
    for (int i = 1; i <= k_rut_gon; ++i) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

bool to_hop_tiep(std::vector<int>& x, int n, int k) {
    if (k == 0) {
        return false;
    }
    
    // Tìm vị trí i từ phải sang trái sao cho x[i] < n - k + (i + 1)
    // Lưu ý: trong C++ chỉ số mảng từ 0 đến k - 1
    // Tại chỉ số i (0-based), giá trị cực đại là: n - k + (i + 1)
    int i = k - 1;
    while (i >= 0 && x[i] == n - k + (i + 1)) {
        --i;
    }
    
    // Nếu không tìm thấy, tức mọi phần tử đã đạt giá trị cực đại -> cấu hình cuối cùng
    if (i < 0) {
        return false;
    }
    
    // Tăng x[i] lên 1 đơn vị
    ++x[i];
    
    // Đặt lại các phần tử phía sau theo quy tắc: x[j] = x[j - 1] + 1
    for (int j = i + 1; j < k; ++j) {
        x[j] = x[j - 1] + 1;
    }
    
    return true;
}

std::vector<std::vector<int>> liet_ke_to_hop(int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        throw std::invalid_argument("Dữ liệu vào không hợp lệ: yêu cầu 0 <= k <= n và n >= 0.");
    }
    
    std::vector<std::vector<int>> ket_qua;
    
    // Trường hợp biên k = 0: quy ước có đúng một tổ hợp rỗng
    if (k == 0) {
        ket_qua.push_back(std::vector<int>()); // [[]]
        return ket_qua;
    }
    
    // Cấu hình ban đầu: [1, 2, ..., k]
    std::vector<int> x(k);
    for (int i = 0; i < k; ++i) {
        x[i] = i + 1;
    }
    
    ket_qua.push_back(x);
    
    // Lặp sinh kế tiếp cho đến cấu hình cuối cùng
    while (to_hop_tiep(x, n, k)) {
        ket_qua.push_back(x);
    }
    
    return ket_qua;
}

std::string to_string_to_hop(const std::vector<int>& x) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < x.size(); ++i) {
        oss << x[i];
        if (i + 1 < x.size()) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

std::vector<std::vector<int>> loc_to_hop_chua_p(const std::vector<std::vector<int>>& ds, int p) {
    std::vector<std::vector<int>> ket_qua;
    for (const auto& to_hop : ds) {
        if (std::find(to_hop.begin(), to_hop.end(), p) != to_hop.end()) {
            ket_qua.push_back(to_hop);
        }
    }
    return ket_qua;
}

