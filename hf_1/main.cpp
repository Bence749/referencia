#include <iostream>
#include <vector>

using namespace std;

void load(vector<int>* x)
{
    for(int i = 1; i <= 1000; i++) x->push_back(i);
}

bool isEven(int x)
{
    if(x % 2 == 0)
        return true;
    return false;
}
int main()
{
    vector<int> nums;
    load(&nums);
    int sumOfEven = 0;
    for(unsigned i = 0; i < nums.size(); i++)
        if(isEven(nums.at(i)))
            sumOfEven += nums.at(i);
    cout << sumOfEven;
    return 0;
}
