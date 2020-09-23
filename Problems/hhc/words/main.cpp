#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"symbol.h"
#include"function.h"
using namespace std;
void retrack();
void error();
void init();
void isReservedWord();
void getSymbol();


static char input[1000];
static int end;
static FILE* in;
static FILE* output;

static enum symbol word_symbol;

void retrack(){
    if(feof(in)) return;
    fseek(in,-1,1);
}

void error(){ // need retrack()?
    return;
}

void init(){
    end=0 ;
    word_symbol=NONE;
}

void isReservedWord(){
    char letterInput[1000];
    int i;
    for (i=0;i<end;i++) {
        letterInput[i]=tolower(input[i]);
    }
    letterInput[i]='\0';
    for (i=0;i<15;i++) {
        if (strcmp(letterInput,reservedWord[i])==0){
            word_symbol=(enum symbol)i+5;
        }
    }
}

void getSymbol(){
    char c;
    c=fgetc(in);
    init();
    while(isSpace(c)) {
        c=fgetc(in);
    }
    input[end++]=c;
    if (isAlpha(c) || c=='_') {
        while (isAlpha(c) || c=='_' || isNumber(c)) {
            c=fgetc(in);
            input[end++]=c;
        }
        end--;
        retrack();
        word_symbol=IDENFR;
        isReservedWord();
    }
    else if (isNumber(c)) {
        while (isNumber(c)) {
            c=fgetc(in);
            input[end++]=c;
        }
        end--;
        retrack();
        word_symbol=INTCON;
    }
    else if(c=='\''){
        end--;  //delete the ' in input
        c=fgetc(in);
        input[end++]=c;
        c=fgetc(in);
        if (c!='\'') error();
        word_symbol=CHARCON;
    }
    else if(c=='\"'){
        end--;  //delete the " in input
        while((c=fgetc(in))!='\"') {
            input[end++]=c;
        }
        word_symbol=STRCON;
    }
    else if(c=='+') word_symbol=PLUS;
    else if(c=='-') word_symbol=MINU;
    else if(c=='*') word_symbol=MULT;
    else if(c=='/') word_symbol=DIV;
    else if(c==':') word_symbol=COLON;
    else if(c==';') word_symbol=SEMICN;
    else if(c==',') word_symbol=COMMA;
    else if(c=='(') word_symbol=LPARENT;
    else if(c==')') word_symbol=RPARENT;
    else if(c=='[') word_symbol=LBRACK;
    else if(c==']') word_symbol=RBRACK;
    else if(c=='{') word_symbol=LBRACE;
    else if(c=='}') word_symbol=RBRACE;
    else if(c=='<'){
        c=fgetc(in);
        if (c=='=') {
            input[end++]=c;
            word_symbol=LEQ;
        } else {
            retrack();
            word_symbol=LSS;
        }
    }
    else if(c=='>') {
        c=fgetc(in);
        if (c=='=') {
            input[end++]=c;
            word_symbol=GEQ;
        } else {
            retrack();
            word_symbol=GRE;
        }
    }
    else if(c=='=') {
    c=fgetc(in);
        if (c=='=') {
            input[end++]=c;
            word_symbol=EQL;
        } else {
            retrack();
            word_symbol=ASSIGN;
        }
    }
    else if(c=='!') {
        c=fgetc(in);
        if (c=='=') {
            input[end++]=c;
            word_symbol=NEQ;
        } else error();
    }
    else error();
}

void printout(){
    switch(word_symbol){
        case IDENFR:{fprintf(output,"IDENFR"); break;}
        case INTCON:{fprintf(output,"INTCON"); break;}
        case CHARCON:{fprintf(output,"CHARCON"); break;}
        case STRCON:{fprintf(output,"STRCON"); break;}
        case CONSTTK:{fprintf(output,"CONSTTK"); break;}
        case INTTK:{fprintf(output,"INTTK"); break;}
        case CHARTK:{fprintf(output,"CHARTK"); break;}
        case VOIDTK:{fprintf(output,"VOIDTK"); break;}
        case MAINTK:{fprintf(output,"MAINTK"); break;}
        case IFTK:{fprintf(output,"IFTK"); break;}
        case ELSETK:{fprintf(output,"ELSETK"); break;}
        case SWITCHTK:{fprintf(output,"SWITCHTK"); break;}
        case CASETK:{fprintf(output,"CASETK"); break;}
        case DEFAULTTK:{fprintf(output,"DEFAULTTK"); break;}
        case WHILETK:{fprintf(output,"WHILETK"); break;}
        case FORTK:{fprintf(output,"FORTK"); break;}
        case SCANFTK:{fprintf(output,"SCANFTK"); break;}
        case PRINTFTK:{fprintf(output,"PRINTFTK"); break;}
        case RETURNTK:{fprintf(output,"RETURNTK"); break;}
        case PLUS:{fprintf(output,"PLUS"); break;}
        case MINU:{fprintf(output,"MINU"); break;}
        case MULT:{fprintf(output,"MULT"); break;}
        case DIV:{fprintf(output,"DIV"); break;}
        case LSS:{fprintf(output,"LSS"); break;}
        case LEQ:{fprintf(output,"LEQ"); break;}
        case GRE:{fprintf(output,"GRE"); break;}
        case GEQ:{fprintf(output,"GEQ"); break;}
        case EQL:{fprintf(output,"EQL"); break;}
        case NEQ:{fprintf(output,"NEQ"); break;}
        case COLON:{fprintf(output,"COLON"); break;}
        case ASSIGN:{fprintf(output,"ASSIGN"); break;}
        case SEMICN:{fprintf(output,"SEMICN"); break;}
        case COMMA:{fprintf(output,"COMMA"); break;}
        case LPARENT:{fprintf(output,"LPARENT"); break;}
        case RPARENT:{fprintf(output,"RPARENT"); break;}
        case LBRACK:{fprintf(output,"LBRACK"); break;}
        case RBRACK:{fprintf(output,"RBRACK"); break;}
        case LBRACE:{fprintf(output,"LBRACE"); break;}
        case RBRACE:{fprintf(output,"RBRACE"); break;}
    }
    if (word_symbol!=NONE){
        int i;
        fprintf(output," ");
        for (i=0;i<end;i++)
            fprintf(output,"%c",input[i]);
        fprintf(output,"\n");
    }
}

int main()
{
    if ((in=fopen("testfile.txt","r"))==0) {
        fprintf(output,"not find testfile!");
    }
    output=fopen("output.txt","w");
    end=0;

    char c=0;
    while((c=fgetc(in))!=EOF) {
        retrack();
        getSymbol();
        printout();
    }

    fclose(in);
    fclose(output);
    return 0;
}
