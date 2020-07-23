#include <stdio.h>
#include <stdlib.h>

#define bigger(a, b) (a >= b) ? a : b

int main()
{
    int K, B, N, L;
    scanf("%d %d %d %d", &K, &N, &B, &L);
    int hol[N], mennyit[N];
    int maxB = B;
    int eleg = N+1;
    int kevesebb = 0;
    int prevB = B, moreB = 0;
    int meddig = (float)(B / L) * 100, must = 0, tanked = 0, calcB = B;
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &hol[i], &mennyit[i]);
        if((K - hol[i]) / 100 * L > B)
            eleg = i+1;
        if(i > 0)
            B -= ((hol[i] - hol[i-1]) / 100) * L;
        else
            B -= hol[i] / 100 * L;
        B += mennyit[i];
        if(prevB > B)
            moreB = i+1;
        prevB = B;
        maxB = bigger(maxB, B);
    }
    if(meddig < K)
        while(K - tanked >= meddig)
        {
            int i;
            for(i = N-1; meddig < hol[i] - tanked; i--);
            calcB -= (float)((hol[i] - tanked) / 100) * L;
            calcB += mennyit[i];
            meddig = (float)(calcB / L) * 100;
            tanked = hol[i];
            must++;
        }
    B -= ((K - hol[N-1]) / 100) * L;
    printf("%d\n%d\n%d\n%d\n%d", B, maxB, eleg, moreB, must);
    return 0;
}
