%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%%

input:
      expr '\n' { printf("Result = %d\n", $1); }
    ;

expr:
      expr '+' term { $$ = $1 + $3; }
    | expr '-' term { $$ = $1 - $3; }
    | term          { $$ = $1; }
    ;

term:
      term '*' factor { $$ = $1 * $3; }
    | term '/' factor { $$ = $1 / $3; }
    | factor          { $$ = $1; }
    ;

factor:
      NUMBER        { $$ = $1; }
    | '(' expr ')'  { $$ = $2; }
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    printf("-------------------------\n");
    printf("Name: Umesh Pariyar\nRoll No: 20\nLab No: 19\n");
    return 0;
}