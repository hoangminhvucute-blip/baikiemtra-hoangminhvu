#include <iostream>
#include <string>
using namespace std;

// Câu 1: Đ?nh ngh?a c?u trúc Khách hàng
struct KhachHang
{
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTien;
};

// Câu 2: Hàm nh?p m?ng n khách hàng
void Nhap(KhachHang a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap khach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

// Câu 3: Hàm xu?t m?ng n khách hàng
void Xuat(KhachHang a[], int n)
{
    cout << "\n";
    cout << "==============================================================\n";
    cout << "                  DANH SACH KHACH HANG\n";
    cout << "==============================================================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien: " << a[i].tongTien << endl;
        cout << "--------------------------------------------------------------\n";
    }
}

// Câu 4: S?p x?p chèn tr?c ti?p (Insertion Sort)
// S?p x?p tăng d?n theo t?ng ti?n thanh toán
void InsertionSort(KhachHang a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int pos = i - 1;

        // Đưa các ph?n t? l?n hơn x sang ph?i
        while (pos >= 0 && a[pos].tongTien > x.tongTien)
        {
            a[pos + 1] = a[pos];
            pos--;
        }

        // Chèn x vào v? trí thích h?p
        a[pos + 1] = x;
    }
}

// Câu 5: T?m ki?m nh? phân
// T?m các khách hàng có t?ng ti?n b?ng X
void TimKiemNhiPhan(KhachHang a[], int n, double X)
{
    int left = 0;
    int right = n - 1;
    int viTri = -1;

    // T?m m?t v? trí có t?ng ti?n b?ng X
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].tongTien == X)
        {
            viTri = mid;
            break;
        }
        else if (a[mid].tongTien < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // Không t?m th?y
    if (viTri == -1)
    {
        cout << "\nKhong co khach hang nao co tong tien = " << X << endl;
        return;
    }

    // T?m sang trái đ? l?y các khách hàng trùng X
    int dau = viTri;
    while (dau > 0 && a[dau - 1].tongTien == X)
    {
        dau--;
    }

    // T?m sang ph?i đ? l?y các khách hàng trùng X
    int cuoi = viTri;
    while (cuoi < n - 1 && a[cuoi + 1].tongTien == X)
    {
        cuoi++;
    }

    // Xu?t các khách hàng t?m đư?c
    cout << "\nCAC KHACH HANG CO TONG TIEN = " << X << ":\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = dau; i <= cuoi; i++)
    {
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien: " << a[i].tongTien << endl;
        cout << "--------------------------------------------------------------\n";
    }
}

// Câu 6: Hàm chính
int main()
{
    int n;

    cout << "Nhap so luong khach hang n = ";
    cin >> n;

    KhachHang a[100];

    // Nh?p danh sách khách hàng
    Nhap(a, n);

    // Hi?n th? danh sách v?a nh?p
    cout << "\nDANH SACH KHACH HANG VUA NHAP:";
    Xuat(a, n);

    // S?p x?p tăng d?n theo t?ng ti?n
    InsertionSort(a, n);

    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN:";
    Xuat(a, n);

    // Nh?p X c?n t?m
    double X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;

    // T?m ki?m nh? phân
    TimKiemNhiPhan(a, n, X);

    return 0;
}
