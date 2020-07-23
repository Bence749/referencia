#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "polinom.h"

int checker(int x, std::string select);
int checker(int x, int y);
std::string splitter(int *start, std::string str, char delimetter, bool *x);
void whatNext(bool *x, bool *y);
void polKi(std::vector<Pol*> x);
std::vector<double> be(int x, std::vector<Pol*> y);
double beX();

#endif // ACTIONS_H_INCLUDED
