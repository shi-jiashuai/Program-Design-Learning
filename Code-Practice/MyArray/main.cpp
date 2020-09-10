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

    cout << "arr 0��λ������Ϊ�� " << arr.getData(0) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr.getData(i) << endl;
    }

    cout << "��������Ϊ�� " << arr.getCapcity() << endl;
    cout << "�����СΪ�� " << arr.getSize() << endl;

    //С���� ����[]��ʽȥ���������е�Ԫ�أ��ɶ���д
    cout << "---------------------" << endl;

    arr[0] = 10000;
    cout << arr[0] << endl;
}


class Solution {
public:
        vector<int> shuffle(vector<int>& nums, int n) {

        // ʹ��˫ָ�뷨
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