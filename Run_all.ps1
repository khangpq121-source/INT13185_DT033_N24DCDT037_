# PowerShell script biên dịch và chạy kiểm thử tự động
Write-Host "=== DANG BIEN DICH CHUONG TRINH C++ ===" -ForegroundColor Cyan
g++ -O2 -std=c++17 -Iinclude src/DeTai.cpp src/main.cpp -o main.exe
g++ -O2 -std=c++17 -Iinclude src/DeTai.cpp test/runtests.cpp -o runtests.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "Bien dich thanh cong!`n" -ForegroundColor Green
    Write-Host "=== DANG CHAY BO KIEM THU TU DONG ===" -ForegroundColor Cyan
    .\runtests.exe
} else {
    Write-Host "Bien dich that bai!" -ForegroundColor Red
}

