%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);
%}

%token LETTER DIGIT

%%

input:
      identifier '\n' { printf("Valid identifier\n"); }
    ;

identifier:
      LETTER rest
    ;

rest:
      rest LETTER
    | rest DIGIT
    | rest '_'
    |
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid identifier\n");
}

int main()
{   
    printf("Enter identifier: ");
    yyparse();
    printf("-------------------------\n");
    printf("Name: Umesh Pariyar\nRoll No: 20\nLab No: 20\n");
    return 0;
}