#include "LexAla.h"
#include <algorithm>
#include <cctype>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#define DEBUG
using namespace std;
//static string now_string = "";
static char now_ch = ' ';
static int integer_read;
static string str_read = "";
static string lower_str_read = "";
static int line_num = 1; // line number
static symType now_type;
static map<string, symType> str2type;
static map<symType, string> type2str;
// LexAnalyzer::LexAnalyzer(ifstream &ff_in)
// {
//     file_in = ff_in;
// }
ostream &operator<<(ostream &ofs, symType st)
{
    ofs << type2str[st];
    return ofs;
}
void LexAnalyzer::get_sym()
{
    //now_ch = file_in.get();
    // ensure now_ch has been written
    while (isspace(now_ch))
    {
        if (now_ch == '\n')
            line_num++;
        now_ch = file_in.get();
    }
    if (isdigit(now_ch))
    {
        now_type = INTCON;
        str_read.clear();
        lower_str_read.clear();
        integer_read = now_ch - '0';
        str_read.push_back(now_ch);
        while (isdigit(now_ch = file_in.get()))
        {
            integer_read = integer_read * 10 + now_ch - '0';
            str_read.push_back(now_ch);
        }
    }
    else if (isalpha(now_ch) || now_ch == '_')
    {
        str_read.clear();
        lower_str_read.clear();
        str_read.push_back(now_ch);
        lower_str_read.push_back(tolower(now_ch));
        while (isalnum(now_ch = file_in.get()) || now_ch == '_')
            str_read.push_back(now_ch), lower_str_read.push_back(tolower(now_ch));
        auto it = str2type.find(lower_str_read);
        if (it == str2type.end())
            now_type = IDENFR;
        else
            now_type = it->second;
    }
    else
    {
        str_read.clear();
        lower_str_read.clear();
        str_read.push_back(now_ch);
        char tem = 0;
        switch (now_ch)
        {
        case '+':
            now_type = PLUS;
            break;
        case '-':
            now_type = MINU;
            break;
        case '/':
            now_type = DIV;
            break;
        case '*':
            now_type = MULT;
            break;
        case '<':
            tem = file_in.peek();
            now_type = tem == '=' ? LEQ : LSS;
            break;
        case '>':
            tem = file_in.peek();
            now_type = tem == '=' ? GEQ : GRE;
            break;
        case '=':
            tem = file_in.peek();
            now_type = tem == '=' ? EQL : ASSIGN;
            break;
        case '!':
            tem = file_in.peek();
            now_type = tem == '=' ? NEQ : ILLEGAL;
            break;
        case ':':
            now_type = COLON;
            break;
        case ';':
            now_type = SEMICN;
            break;
        case ',':
            now_type = COMMA;
            break;
        case '(':
            now_type = LPARENT;
            break;
        case ')':
            now_type = RPARENT;
            break;
        case '[':
            now_type = LBRACK;
            break;
        case ']':
            now_type = RBRACK;
            break;
        case '{':
            now_type = LBRACE;
            break;
        case '}':
            now_type = RBRACE;
            break;
        case EOF:
            now_type = EOFTK;
            break;
        default:
            now_type = ILLEGAL;
        }
        if (tem == '=')
            str_read.push_back('='), file_in.get();
        now_ch = file_in.get();
    }
}

void LexAnalyzer::get_nex_char()
{
    str_read.clear();
    str_read.push_back(now_ch);
    now_ch = file_in.get();
    now_type = CHARCON;
    //跳过下一个单引号
    now_ch = file_in.get();
}

void LexAnalyzer::get_nex_string()
{
    str_read.clear();
    str_read.push_back(now_ch);
    now_type = STRCON;
    while ((now_ch = file_in.get()) != '\"')
    {
        if (now_ch == EOF) //貌似没必要
            break;
        str_read.push_back(now_ch);
    }
    now_ch = file_in.get();//跳过下一个双引号
}

inline void initStr2Type()
{
    str2type.insert({"const", CONSTTK});
    type2str.insert({CONSTTK, "CONSTTK"});
    str2type.insert({"int", INTTK});
    type2str.insert({INTTK, "INTTK"});
    str2type.insert({"char", CHARTK});
    type2str.insert({CHARTK, "CHARTK"});
    str2type.insert({"void", VOIDTK});
    type2str.insert({VOIDTK, "VOIDTK"});
    str2type.insert({"main", MAINTK});
    type2str.insert({MAINTK, "MAINTK"});
    str2type.insert({"if", IFTK});
    type2str.insert({IFTK, "IFTK"});
    str2type.insert({"else", ELSETK});
    type2str.insert({ELSETK, "ELSETK"});
    str2type.insert({"switch", SWITCHTK});
    type2str.insert({SWITCHTK, "SWITCHTK"});
    str2type.insert({"case", CASETK});
    type2str.insert({CASETK, "CASETK"});
    str2type.insert({"default", DEFAULTTK});
    type2str.insert({DEFAULTTK, "DEFAULTTK"});
    str2type.insert({"while", WHILETK});
    type2str.insert({WHILETK, "WHILETK"});
    str2type.insert({"for", FORTK});
    type2str.insert({FORTK, "FORTK"});
    str2type.insert({"scanf", SCANFTK});
    type2str.insert({SCANFTK, "SCANFTK"});
    str2type.insert({"printf", PRINTFTK});
    type2str.insert({PRINTFTK, "PRINTFTK"});
    str2type.insert({"return", RETURNTK});
    type2str.insert({RETURNTK, "RETURNTK"});

    type2str.insert({IDENFR, "IDENFR"});
    type2str.insert({INTCON, "INTCON"});
    type2str.insert({CHARCON, "CHARCON"});
    type2str.insert({STRCON, "STRCON"});
    type2str.insert({PLUS, "PLUS"});
    type2str.insert({MINU, "MINU"});
    type2str.insert({MULT, "MULT"});
    type2str.insert({DIV, "DIV"});
    type2str.insert({LSS, "LSS"});
    type2str.insert({LEQ, "LEQ"});
    type2str.insert({GRE, "GRE"});
    type2str.insert({GEQ, "GEQ"});
    type2str.insert({EQL, "EQL"});
    type2str.insert({NEQ, "NEQ"});
    type2str.insert({COLON, "COLON"});
    type2str.insert({ASSIGN, "ASSIGN"});
    type2str.insert({SEMICN, "SEMICN"});
    type2str.insert({COMMA, "COMMA"});
    type2str.insert({LPARENT, "LPARENT"});
    type2str.insert({RPARENT, "RPARENT"});
    type2str.insert({LBRACK, "LBRACK"});
    type2str.insert({RBRACK, "RBRACK"});
    type2str.insert({LBRACE, "LBRACE"});
    type2str.insert({RBRACE, "RBRACE"});
}
void LexAnalyzer::OUT()
{
    if (now_type == ILLEGAL || now_type == EOFTK)
        return;
#ifdef DEBUG
    cout << now_type << ' ' << str_read << endl;
#endif
    file_out << now_type << ' ' << str_read << endl;
}
void LexAnalyzer::startAna()
{
    initStr2Type();
    now_ch = file_in.get(); // 必须
    get_sym();
    while (now_type != EOFTK)
    {
        OUT();
        if (now_type == ILLEGAL)
        {
            if (str_read[0] == '\'')
            {
                get_nex_char();
                OUT();
            }
            else if (str_read[0] == '\"')
            {
                get_nex_string();
                OUT();
            }
        }
        get_sym();
    }
}
