enum symbol {
    NONE,
    IDENFR, INTCON, CHARCON, STRCON,
    CONSTTK, INTTK, CHARTK, VOIDTK,
    MAINTK, IFTK, ELSETK, SWITCHTK,
    CASETK, DEFAULTTK, WHILETK, FORTK,
    SCANFTK, PRINTFTK, RETURNTK, PLUS,
    MINU, MULT, DIV, LSS, LEQ, GRE, GEQ,
    EQL, NEQ, COLON, ASSIGN, SEMICN,
    COMMA, LPARENT, RPARENT, LBRACK,
    RBRACK, LBRACE, RBRACE
};

const char* reservedWord[15]={
    "const", "int", "char", "void",
    "main", "if", "else", "switch",
    "case", "default", "while", "for",
    "scanf", "printf", "return"
};
