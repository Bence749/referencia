//Author: Beregi Bence Zsolt
//Date: 2020.04.05.
//Title: Anglers

#include <iostream>
#include "contest.h"
#include "angler.h"

using namespace std;

bool first_search(const string &name, Contest &e)
{
    ContestEnor t(name);
    bool l = false;
    for(t.first(); !t.end(); t.next())
    {
        l = t.current().weight != 1000;
        if( e.weight > t.current().weight )
            e = t.current();
    }
    return l;
}

bool second_search(const string &name)
{
    AnglerEnor t(name);
    bool l = true;
    for( t.first(); l && !t.end(); t.next() )
        l = t.current().atleastTwo;
    if( t.end() ) l = t.current().atleastTwo;
    return l;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Enter the name of the input file: ";
    string file;
    cin >> file;

    //First task
    try
    {
        Contest e;
        if(first_search(file, e))
            cout << e.weight << "kg is the weight of the easiest carp and it got caught by " << e.angler << " on the " << e.contest << " contest." << endl;
        else
            cout << "No one caught a carp." << endl;
    }
    catch(ContestEnor::FileError err)
    {
        cerr << "Can't find the input file: " << file << endl;
    }

    //Second task
    try
    {
        if(second_search(file))
            cout << "The statement is true!";
        else
            cout << "The statement is false!";
    }
    catch(ContestEnor::FileError err)
    {
        cerr << "Can't find the input file: " << file << endl;
    }
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//First task testes
TEST_CASE("first task empty file", "t0.txt")
{
    Contest e;
    CHECK_FALSE(first_search("t0.txt", e));
}

TEST_CASE("first task 1 angler, true", "t1.txt")
{
    Contest e;
    CHECK(first_search("t1.txt", e));
    CHECK(e.angler == "PISTIBA");
}

TEST_CASE("first task 1 angler, false", "t2.txt")
{
    Contest e;
    CHECK_FALSE(first_search("t2.txt", e));
}

TEST_CASE("first task more anglers, first one has the lightest carp", "t3.txt") {
    Contest e;
    CHECK(first_search("t3.txt", e));
    CHECK((e.angler=="IMIBA" && e.contest=="Tiszato0610" && e.weight==12)==TRUE);
}

TEST_CASE("first task more anglers, fourth one has the lightest carp", "t4.txt") {
    Contest e;
    CHECK(first_search("t4.txt", e));
    CHECK((e.angler=="JANIBA" && e.contest=="Kiliti0512" && e.weight==45)==TRUE);
}

TEST_CASE("first task more anglers, last one has the lightest carp", "t5.txt") {
    Contest e;
    CHECK(first_search("t5.txt", e));
    CHECK((e.angler=="ZOLIBA" && e.contest=="Szeged0807" && e.weight==32)==TRUE);
}

TEST_CASE("first task more anglers, no one caught a carp", "t6.txt") {
    Contest e;
    CHECK_FALSE(first_search("t6.txt", e));
}

TEST_CASE("no catch", "t7.txt") {
    ContestEnor tt("t7.txt");
    tt.first();
    CHECK(tt.current().weight == 1000);
}

TEST_CASE("1 catch, and its weight is 44", "t8.txt") {
    ContestEnor tt("t8.txt");
    tt.first();
    CHECK(tt.current().weight == 44);
}

TEST_CASE("three catches, and the lightes carp is moving from the first place to last with two catfish/line", "t9-11.txt") {
    for(int i = 9; i <= 11; i++)
    {
        ContestEnor t("t" + std::to_string(i) + ".txt");
        t.first();
        CHECK(t.current().weight == 34);
    }
}

TEST_CASE("three catches, and the lightes carp is moving from the first place to last with one catfish/line", "t12-15.txt") {
    for(int i = 12; i <= 15; i++)
    {
        ContestEnor t("t" + std::to_string(i) + ".txt");
        t.first();
        CHECK(t.current().weight == 34);
    }
}

//Second task testes
TEST_CASE("second task empty file", "t0.txt")
{
    CHECK_FALSE(second_search("t0.txt"));
}

TEST_CASE("1 angler, false", "t1-2.txt")
{
    CHECK_FALSE(second_search("t1.txt"));
    CHECK_FALSE(second_search("t2.txt"));
}

TEST_CASE("2 anglers, false", "t20.txt")
{
    CHECK_FALSE(second_search("t20.txt"));
}

TEST_CASE("2 anglers, true", "t21.txt")
{
    CHECK(second_search("t21.txt"));
}

TEST_CASE("3 anglers, false, because one of them the was only at one contest", "t3.txt")
{
    CHECK_FALSE(second_search("t3.txt"));
}

TEST_CASE("3 anglers, false, because one of them didn't catch carp", "t22.txt")
{
    CHECK_FALSE(second_search("t22.txt"));
}

TEST_CASE("3 anglers, true", "t23.txt")
{
    CHECK(second_search("t23.txt"));
}

TEST_CASE("no contest", "t0.txt")
{
    AnglerEnor t("t0.txt");
    t.first();
    CHECK_FALSE(t.current().atleastTwo);
}

TEST_CASE("1 angler, true", "t24.txt")
{
    AnglerEnor t("t24.txt");
    t.first();
    CHECK(t.current().atleastTwo);
}
TEST_CASE("1 angler, false; enortest", "t1.txt")
{
    AnglerEnor t("t1.txt");
    t.first();
    CHECK_FALSE(t.current().atleastTwo);
}

TEST_CASE("2 anglers, first true, second false", "t25.txt")
{
    AnglerEnor t("t25.txt");
    t.first();
    CHECK(t.current().atleastTwo);
    t.next();
    CHECK_FALSE(t.current().atleastTwo);
}

TEST_CASE("2 anglers, first false, second true", "t26.txt")
{
    CHECK_FALSE(second_search("t26.txt"));
}

TEST_CASE("2 anglers, first false, second true; enortest", "t26.txt")
{
    AnglerEnor t("t26.txt");
    t.first();
    CHECK_FALSE(t.current().atleastTwo);
    t.next();
    CHECK(t.current().atleastTwo);
}
#endif
