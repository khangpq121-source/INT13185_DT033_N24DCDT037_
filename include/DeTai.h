#ifndef DETAI_H
#define DETAI_H

#include <vector>
#include <string>

// ==============================================================================
// Đề tài DT033: Liệt kê tổ hợp chập k của n phần tử
// Sinh viên: Võ Ngọc Minh Khang - MSSV: N24DCDT037 - Lớp: D24CQDT01-N
// Học phần: Cấu trúc dữ liệu và giải thuật (INT13185 - Nhóm 03)
// ==============================================================================

/**
 * @brief Tính số tổ hợp C(n, k) độc lập bằng phương pháp số học để kiểm chứng.
 * @param n Tổng số phần tử (0 <= n <= 12)
 * @param k Số phần tử chọn (0 <= k <= n)
 * @return Số lượng tổ hợp chập k của n
 */
long long dem_to_hop(int n, int k);

/**
 * @brief Sinh cấu hình tổ hợp kế tiếp từ cấu hình hiện tại x theo thứ tự từ điển.
 *        Cấu hình x gồm k phần tử: 1 <= x[0] < x[1] < ... < x[k-1] <= n.
 * @param x Mảng tham chiếu lưu cấu hình hiện tại
 * @param n Tổng số phần tử
 * @param k Kích thước tổ hợp
 * @return true nếu sinh được cấu hình tiếp theo, false nếu x đã là cấu hình cuối cùng
 */
bool to_hop_tiep(std::vector<int>& x, int n, int k);

/**
 * @brief Liệt kê toàn bộ các tổ hợp chập k của n theo thứ tự từ điển.
 *        Đặc biệt xử lý: k = 0 trả về đúng một tổ hợp rỗng [[]].
 * @param n Tổng số phần tử
 * @param k Kích thước tổ hợp
 * @return Danh sách tất cả các tổ hợp
 */
std::vector<std::vector<int>> liet_ke_to_hop(int n, int k);

/**
 * @brief Chuyển một vector thành chuỗi dạng [1, 2, 3] hoặc []
 */
std::string to_string_to_hop(const std::vector<int>& x);

/**
 * @brief Hàm mở rộng tùy chọn: Lọc các tổ hợp có chứa phần tử p
 * @param ds Danh sách các tổ hợp đã sinh
 * @param p Giá trị phần tử cần lọc (1 <= p <= n)
 * @return Danh sách các tổ hợp có chứa p
 */
std::vector<std::vector<int>> loc_to_hop_chua_p(const std::vector<std::vector<int>>& ds, int p);

#endif // DETAI_H

