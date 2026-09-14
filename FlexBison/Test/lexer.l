%{
#include "parser.tab.h"
%}

%%

[0-9]+      { return NUMBER; }
[+]         { return PLUS; }
[*]         { return MULT; }
[(]         { return '('; }
[)]         { return ')'; }
[ \t\n]     ;
.           { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}