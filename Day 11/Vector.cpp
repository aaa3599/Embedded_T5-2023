#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

typedef struct node
{
    int value;
    struct node *next;
}node;


int main(){
    // vector<int> array;
    list<int> array;
    // array.push_back(4);
    // array.push_back(8);
    // array.push_back(20);
    // array.push_back(15);

    // array.insert(array.begin()+2,77);

    // array.erase(array.begin()+2);
    
    auto data = 10.8;
    array.assign(8,5);

    
    // for (int i = 0; i < array.size(); i++)
    // {
    //     printf("%d\n",array[i]);
    // }
    
    
    for( int item : array)
        printf("%d  ",item);

    map<string, int> SinhVien;

    SinhVien["ID"]=101;
    SinhVien["LOP"]= 7;
    SinhVien["TUOI"]=12;

    for (auto item:SinhVien)
    {
        printf("\nKey: %s, value:%d, diachi:%p, size:%d",item.first.c_str(),item.second, &item, sizeof(item));
    }
    

    return 0;
}
