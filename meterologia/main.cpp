/*
  Készítette: Beregi Bence Zsolt
  Neptun: DQK6TE
  E-mail: beregi.bence@hotmail.com
  Feladat: „ProgAlap beadandó feladatok” téma „Az átlag kisebb a minimum és maximum átlagánál” feladat
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

double splitter(int *start, string str, char delimetter)
{
    *start += str.find(delimetter) + 1;
    str = str.substr(0, str.find(delimetter));
    int output = atoi(str.c_str());
    return output;
}

int numberOfNotNull(int *array, int size)
{
    int output = 0;
    for(int i = 0; i < size; i++)
        if(array[i] != 0) output++;
    return output;
}

void clearCin()
{
    cin.clear();
    cin.ignore(256,'\n');
}

int main()
{
    int N, M;
    cerr << "Please set number of settlements, and the number of days. (Like this: 'number of settlements' 'number of days'): " << endl;
    cin >> N >> M;
    while(N < 1 || N > 1000 || M < 1 || M > 1000 || cin.fail())
    {
        cin.fail() == true ? cerr << "Bad input. Check and try again: " : cerr << "One of the values was out of bound. Check and try again: ";
        clearCin();
        cin >> N >> M;
    }
    int out[N];
    double weather[N][M];
    double avg[N];
    int maxarr[M], minarr[M];
    string input;
    getline(cin, input);
    for(int i = 0; i < N; i++)
    {
        double dailySum = 0;
        int start = 0;
        int startCheck = -1;
        cerr << "Give me the measured values of settlement " << i+1 << ": ";
        getline(cin, input);
        for(int j = 0; j < M; j++)
        {
            int isIt = splitter(&start, input.substr(start), ' ');
            if(startCheck == start && j != M-1)
            {
                cerr << "Not enough value. Check and try again.\n";
                i--;
                break;
            }else if(j == M-1 && startCheck != start)
            {
                cerr << "Too many values. Check and try again.\n";
                i--;
                break;
            }
            startCheck = start;
            if(isIt >= -50 && isIt <= 50 && !(cin.fail()))
            {
                weather[i][j] = isIt;
                dailySum += isIt;
            }
            else
            {
                cin.fail() == true ? cerr << "Bad input. Check and try again.\n": cerr << "One of the values was out of bound.\n";
                cin.clear();
                i--;
                break;
            }
            if(maxarr[i] < isIt || j == 0) maxarr[i] = isIt;
            if(minarr[i] > isIt || j == 0) minarr[i] = isIt;
        }
        avg[i] = dailySum / M;
        if(abs(avg[i] - maxarr[i]) > abs(avg[i] - minarr[i]))
            out[i] = i+1;
        else
            out[i] = 0;
    }
    cerr << "Result: ";
    cout << numberOfNotNull(out, N);
    for(int i = 0; i < N; i++)
        if(out[i] != 0) cout << " " << out[i];

    return 0;
}
