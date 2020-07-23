//Author: Beregi Bence Zsolt
//Date: 2020.02.29.
//Title: Polinom


#include <iostream>
#include <string>
#include "polinom.h"
#include "actions.h"


using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    bool globDoCon = true;
    while(globDoCon)
        {
        cout << "Hany polinomot szeretne megadni?: ";
        bool doContinue = true;
        int numberOfPol = checker(1, "min");
        vector<Pol*> pols;
        cout << "Adja meg a polinomt(okat) (Pl: 3x^2+2x+1 -> 3 2 1): ";
        for(int i = 0; i < numberOfPol; i++)
        {
            int start = 0;
            bool isLast = false;
            string input;
            getline(cin, input);
            try
            {
                vector<double> temp;
                while(isLast == false)
                    temp.push_back(stod(splitter(&start, input.substr(start), ' ', &isLast)));
                Pol* tmp = new Pol();
                tmp->addVec(temp);
                pols.push_back(tmp);

            }
            catch(...)
            {
                cout << "Hibas polinom. Probald ujra: ";
                i--;
            }
        }
        cout << "Lehetseges opciok:\n";
        if(numberOfPol < 2)
        {
            while(doContinue)
            {
                cout << "1. Kiiras\n2. Onmagaval valo osszeadas\n3. Onmagaval valo szorzas\n4. Helyetesitesi ertekkel valo szamolas\nValasztott opcio: ";
                int selected = checker(1, 4);
                switch(selected)
                {
                case 1:
                    pols[0]->out();
                    break;
                case 2:
                    pols[0]->sum(pols[0])->out();
                    break;
                case 3:
                    pols[0]->mult(pols[0])->out();
                    break;
                case 4:
                    {
                        cout << "Add meg a szamot amivel helyetesitsem az x-et: ";
                        string input;
                        double x = beX();
                        cout << "Az adott x-el a helyetesitesi ertek: " << pols[0]->calc(x) << endl;
                        break;
                    }
                }
                whatNext(&doContinue, &globDoCon);
            }
        }
        else
        {
            while(doContinue)
            {
                cout << "1. Kiiras\n2. Osszeadas\n3. Szorzas\n4. Helyetesitesi ertekkel valo szamolas\nValasztott opcio: ";
                int selected = checker(1, 4);
                switch(selected)
                {
                case 1:
                    polKi(pols);
                    break;
                case 2:
                    {
                        cout << "Melyik polinomokat szeretne osszeadni? (Space-el elvalasztva egymas utan. (Pl: 2 3 -> 2+3)): ";
                        vector<double> polsToSum = be(numberOfPol, pols);
                        Pol* sum = new Pol();
                        for(int i = 0; i < (int)polsToSum.size(); i++)
                            sum = sum->sum(pols[polsToSum[i] - 1]);
                        sum->out();
                        break;
                    }
                case 3:
                    {
                        cout << "Melyik polinomokat szeretne osszeszorozni? (Space-el elvalasztva egymas utan. (Pl: 2 3 -> 2+3)): ";
                        vector<double> polsToMul = be(numberOfPol, pols);
                        Pol* mul = new Pol();
                        for(int i = 0; i < (int)polsToMul.size(); i++)
                            mul = mul->mult(pols[polsToMul[i] - 1]);
                        mul->out();
                        break;
                    }
                case 4:
                    {
                        cout << "Melyik polinomoba(okba) szeretne behelyetesiteni?: ";
                        vector<double> polsToCal = be(numberOfPol, pols);
                        cout << "Mit szeretne behelyetesiteni?: ";
                        int x = beX();
                        for(int i = 0; i < (int)polsToCal.size(); i++)
                            cout << polsToCal[i] << ": helyetesitesi erteke " << x << "-el: " << pols[i]->calc(x) << endl;
                        break;
                    }
                }
                whatNext(&doContinue, &globDoCon);
            }
        }
    }
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("adding elements and vector to the Pol vector")
{
    Pol test;
    test.addEl(2);
    CHECK(test.getVals().at(0) == 2);
    Pol test2;
    vector<double> a = {1, 3.257, 5};
    test2.addVec(a);
    for(int i = 0; i < (int)a.size(); i++)
        CHECK(test2.getVals().at(i) == a.at(i));
}

TEST_CASE("summing pols")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({3, 2 ,1});
    vector<double> b({4, 5, 6});
    test_1.addVec(a);
    test_2.addVec(b);
    Pol* out = test_1.sum(&test_2);
    vector<double> c({7, 7, 7});
    CHECK(out->getVals() == c);
}

TEST_CASE("multiplying pols")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({3, 2 ,1});
    vector<double> b({4, 5, 6});
    test_1.addVec(a);
    test_2.addVec(b);
    Pol* out = test_1.mult(&test_2);
    vector<double> c({12, 23, 32, 17, 6});
    CHECK(out->getVals() == c);
}

TEST_CASE("calculating pol value with x")
{
    Pol test_1;
    vector<double> a({2, 5.2, 1.4, 6});
    test_1.addVec(a);
    double out = test_1.calc(4.2);
    CHECK(round(out * 1000) / 1000 == 251.784);
}

TEST_CASE("summing then multiplying polinom")
{
    Pol test_1, test_2, test_3;
    vector<double> a({3, 5, 6, 4});
    vector<double> b({2, 6, 2, 6, 1});
    vector<double> c({2, 1, 7, 12, 2});
    test_1.addVec(a);
    test_2.addVec(b);
    test_3.addVec(c);
    Pol* out = test_1.sum(&test_2);
    out = out->mult(&test_3);
    vector<double> d({4, 20, 37, 118, 183, 191, 193, 84, 10});
    CHECK(out->getVals() == d);
}

TEST_CASE("summing pols with 0 in it")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({3, 0, 0, 2, 1});
    vector<double> b({4, 0, 2, 5, 6});
    test_1.addVec(a);
    test_2.addVec(b);
    Pol* out = test_1.sum(&test_2);
    vector<double> c({7, 0, 2, 7, 7});
    CHECK(out->getVals() == c);
}

TEST_CASE("multiplying pols with 0 in it")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({3, 0, 3, 2 ,1});
    vector<double> b({4, 5, 6});
    test_1.addVec(a);
    test_2.addVec(b);
    Pol* out = test_1.mult(&test_2);
    vector<double> c({12, 15, 30, 23, 32, 17, 6});
    CHECK(out->getVals() == c);
}

TEST_CASE("calculating pol (with 0 in it) value with x")
{
    Pol test_1;
    vector<double> a({2, 5.2, 0, 1.4, 6});
    test_1.addVec(a);
    double out = test_1.calc(3.13);
    CHECK(round(out * 1000) / 1000 == 361.795);
}

TEST_CASE("summing then calculating with x")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({2, 5, 0, 2, 1.5, 0});
    vector<double> b({5, 7, 0, 2.5});
    test_1.addVec(a);
    test_2.addVec(b);
    double out = test_1.sum(&test_2)->calc(3.7);
    CHECK(round(out * 1000) /1000 == 2708.485);
}

TEST_CASE("multiplying then calculating with x")
{
    Pol test_1;
    Pol test_2;
    vector<double> a({2, 5, 0, 2, 1.5, 0});
    vector<double> b({5, 7, 0, 2.5});
    test_1.addVec(a);
    test_2.addVec(b);
    double out = test_1.mult(&test_2)->calc(2.43);
    CHECK(round(out * 1000) /1000 == 41521.898);
}
#endif
