#include <stdio.h>
#include "calculator.tab.h"

int main() {
    yyparse();
    return 0;
}

void yyerror(char const *s) {
    fprintf(stderr, "Error: %s\n", s);
}
