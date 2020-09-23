int isAlpha(int c) {
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'))?1:0;
}

int isNumber(int c) {
	return (c>='0' && c<='9')?1:0;
}

int isSpace(int c) {
    return (c==' ' || c=='\n' || c=='\r' || c=='\t')?1:0;
}
