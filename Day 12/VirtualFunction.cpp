#include<stdio.h>

class SinhVien
{
private:
    /* data */
public:
    virtual char *test(){                   //overload
        return (char*)"Hello world\n";
    }
    void display(){
        printf("test: %s\n",test());
    }
};

class DoiTuong: public SinhVien{
public:
    char *test(){
        return (char*)"This is test\n"; //override
    }
};

int main(){
    SinhVien sv;
    sv.display();
    DoiTuong td;
    td.display();
    return 0;
}

