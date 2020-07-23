#include <iostream>

using namespace std;

int main()
{
    int k;
    double s, a;
    cin >> a >> k;
    (a == 0) ? s = 0 : s = 1;
    while(k > 0)
    {
        if(k % 2 == 0)
        {
            s *= a;
            --k;
        }
        else
        {
            a *= a;
            k /= 2;
        }
    }
    cout << s;
    return 0;
}
