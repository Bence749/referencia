#include <iostream>

using namespace std;

int main()
{
    int pNum;
    cin >> pNum;
    int fromTo[pNum][2];
    for(int i = 0; i < pNum; i++)
        cin >> fromTo[i][0] >> fromTo[i][1];

    int meets[pNum] = {0};
    for(int i = 0; i < pNum; i++)
        for(int j = 0; j < i; j++)
            if(fromTo[i][0] <= fromTo[j][1] && fromTo[i][1] >= fromTo[j][0])
            {
                meets[i]++;
                meets[j]++;
            }

    int maxMeets = 0;
    int maxMeetsInd = 0;
    for(int i = 0; i < pNum; i++)
        if(meets[i] > maxMeets)
        {
            maxMeets = meets[i];
            maxMeetsInd = i;
        }

    cout << maxMeetsInd + 1 << endl << maxMeets << endl;
    return 0;
}
