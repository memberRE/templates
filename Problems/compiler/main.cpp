#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LexAla.h"
using namespace std;
int main()
{
    ifstream fin("testfile.txt");
    ofstream fout("output.txt");
    LexAnalyzer lexanaly(fin,fout);
    lexanaly.startAna();
    fin.close();
    fout.close();
}
