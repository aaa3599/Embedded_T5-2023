#include <iostream>
#include <string>

using namespace std;

// class SinhVien{
//     public:
//         SinhVien(int tuoi =5, int lop = 6); //contructor
//         void hienThi(); // method
//         // void themThongTin(int tuoi, int lop);
//     private:
//         int tuoi;      // property
//         int lop;
// };

class DoiTuong
{
public:
    void setThongTin(string ten, int tuoi);
    void hienThi(); // method
    // void themThongTin(int tuoi, int lop);
protected:
    int Tuoi; // property
    string Ten;
};

void DoiTuong::hienThi()
{
    cout << "Day la class DoiTuong\n";
    cout << "Ten: " << Ten << endl;
    cout << "Tuoi: " << Tuoi << endl;
}

void DoiTuong::setThongTin(string ten, int tuoi)
{
    Ten = ten;
    Tuoi = tuoi;
}

// SinhVien::SinhVien(int tuoi, int lop){
//     SinhVien::tuoi = tuoi;
//     SinhVien::lop = lop;
// }

class SinhVien : public DoiTuong
{
public:
    void setThongTin(string ten, int tuoi, long mssv);
    void hienThi();

private:
    int MSSV;
};

void SinhVien::setThongTin(string ten, int tuoi, long mssv)
{
    Ten = ten;
    Tuoi = tuoi;
    MSSV = mssv;
}

void SinhVien::hienThi()
{
    cout << "Day la class SinhVien\n";
    cout << "Ten: " << Ten << endl;
    cout << "Tuoi: " << Tuoi << endl;
    cout << "MSSV: " << MSSV << endl;
}

int main()
{
    // cout << "Hello world\n";
    // int i=0;
    // cout << "Nhap vao i:";
    // cin >> i;
    // cout << "i = " << i << endl;

    // SinhVien sv(17,6);    //object

    // sv.themThongTin(16,7);

    // sv.hienThi();
    DoiTuong dt;

    dt.setThongTin("Anh", 23);
    dt.hienThi();

    SinhVien sv;
    sv.setThongTin("Anh", 23, 20181319);
    sv.hienThi();

    return 0;
}
