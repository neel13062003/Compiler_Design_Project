#ifndef CALCULATOR_TAB_H
#define CALCULATOR_TAB_H

#include <math.h>

extern "C" {
    int yyparse(void);
    void yyerror(char const *);
}

#endif
