#include<fstream>
#include <iomanip>
#include<iostream>
#include<string>
using namespace std;
enum symType{
    IDENFR,//标识符
    INTCON,//整型 量
    CHARCON,//字符常量
    STRCON,//字符串
    CONSTTK,//const
    INTTK,//int
    CHARTK,//char
    VOIDTK,//
    MAINTK,
    IFTK,
    ELSETK,
    SWITCHTK,
    CASETK,
    DEFAULTTK,
    WHILETK,
    FORTK,
    SCANFTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    MULT,
    DIV,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    COLON,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    EOFTK,
    ILLEGAL
};



class LexAnalyzer
{
public:
    void get_sym();
    void get_nex_char();
    void get_nex_string();
    void startAna();
    void OUT();
    ifstream &file_in;
    ofstream &file_out;
    LexAnalyzer (ifstream &ff_in,ofstream & ff_out) : file_in(ff_in),file_out(ff_out) {}
private:

};
