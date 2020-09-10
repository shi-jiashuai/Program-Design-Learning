#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include "MyArray.h"
using namespace std;

void test01()
{
    MyArray arr;

    for (int i = 0; i < 10; i++)
    {
        arr.pushBack(i);
    }

    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr.getData(i) << endl;
    }

    MyArray arr2(arr);
    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2.getData(i) << endl;
    }

    arr.setData(0, 1000);

    cout << "arr 0号位置数据为： " << arr.getData(0) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr.getData(i) << endl;
    }

    cout << "数组容量为： " << arr.getCapcity() << endl;
    cout << "数组大小为： " << arr.getSize() << endl;

    //小任务： 利用[]方式去索引数组中的元素，可读可写
    cout << "---------------------" << endl;

    arr[0] = 10000;
    cout << arr[0] << endl;
}


class Solution {
public:
        vector<int> shuffle(vector<int>& nums, int n) {

        // 使用双指针法
        int halfSize = nums.size() * 0.5;
        //int* pointer1 = nums.begin();
        //int* pointer2 = &nums[halfSize];

        vector<int> ret;

        auto iterator1 = nums.begin();
        std::vector<int>::iterator iterator2 = iterator1 + halfSize;

        while (iterator2 < nums.end())
        {
            ret.push_back(*iterator1);
            ret.push_back(*iterator2);
            ++iterator1;
            ++iterator2;
        }

        return ret;
    }
};
int main() 
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}