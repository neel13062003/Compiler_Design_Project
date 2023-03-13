%{
#include "calculator.tab.h"
%}

DIGIT       [0-9]
LETTER      [a-zA-Z]
WS          [ \t\r\n]

%%

{DIGIT}+        { yylval = atoi(yytext); return INTEGER; }
{LETTER}+       { yylval.str = strdup(yytext); return NAME; }
{WS}+           ; /* ignore whitespace */
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
","             { return COMMA; }
.               { printf("Unknown token: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}
