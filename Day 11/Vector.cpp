#include <iostream>
#include <vector>

using namespace std;



int main(){
    vector<int> array;
    // array.push_back(4);
    // array.push_back(8);
    // array.push_back(20);
    // array.push_back(15);

    // array.insert(array.begin()+2,77);

    // array.erase(array.begin()+2);
    auto data = 10.8;
    array.assign(8,5);

    int i;
    for (i = 0; i < array.size(); i++)
    {
        printf("%d\n",array[i]);
    }
    
    // int item;
    // for( int item : array)
    //     printf("%d\n",item);
    return 0;
}
