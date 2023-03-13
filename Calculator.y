%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(char const *);

#define YYSTYPE union {
    int integer;
    char *str;
}

typedef struct {
    char *name;
    int n_args;
    double (*func)(double *);
} function;

function functions[] = {
    { "sin", 1, sin },
    { "cos", 1, cos },
    { "tan", 1, tan },
    { NULL, 0, NULL }
};

#define MAX_ARGS 10

double call_function(char *name, int n_args, double *args) {
    function *f = functions;
    while (f->name) {
        if (strcmp(f->name, name) == 0 && f->n_args == n_args) {
            return f->func(args);
        }
        f++;
    }
    yyerror("unknown function");
    return 0;
}

double evaluate(char *name, int n_args, double *args) {
    if (n_args > MAX_ARGS) {
        yyerror("too many arguments");
        return 0;
    }
    if (name) {
        return call_function(name, n_args, args);
    } else {
        return args[0];
    }
}

%}

%token INTEGER NAME
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN COMMA

%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc UMINUS

%%

input:  /* empty */
    | input line
    ;

line:
    '\n'
    | exp '\n' { printf("= %g\n", $1); }
    ;

exp:
    INTEGER                     { $$ = $1; }
    | NAME LPAREN arglist RPAREN { $$ = evaluate($1, $3, $4); }
    | exp PLUS exp              { $$ = $1 + $3; }
    | exp MINUS exp             { $$ = $1 - $3; }
    | exp TIMES exp             { $$ = $1 * $3; }
    | exp DIVIDE exp            { $$ = $1 / $3; }
    | MINUS exp %prec UMINUS    { $$ = -$2; }
    | LPAREN exp RPAREN         { $$ = $2; }
    ;

arglist:
    /* empty */
    | exp                        { $$ = 1; $1list[0] = $1; }
    | arglist COMMA exp          { if ($1 >= MAX_ARGS) { yyerror("too many arguments"); } else { $3list[$1++] = $3; } 

$$

