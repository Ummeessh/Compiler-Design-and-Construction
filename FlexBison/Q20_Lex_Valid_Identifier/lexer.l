%{
#include "parser.tab.h"
%}

%%

[a-zA-Z_]          { return LETTER; }
[0-9]              { return DIGIT; }
\n                 { return '\n'; }
[ \t]              ;
.                  { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}