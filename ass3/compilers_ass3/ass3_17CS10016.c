#include <stdio.h>
#define _KEYWORD  10
#define _ID   11
#define _PUNC   12
#define _CONST_INT  13
#define _CONST_FLT  14
#define _CONST_ENUM   15
#define _CONST_CHAR   16
#define _STRING   17
#define _ESCAPE_SEQUENCE 18
#define _MCOMMENT 19
#define _SCOMMENT 20
#define _WS   21


int yylex(void);
char *yytext;


int main()
{
  int token;
  while(token = yylex())
  {
    switch(token)
    {
      case _KEYWORD:
            printf("<KEYWORD, %d, %s>\n", token, yytext);
            break;

      case _ID:
            printf("<IDENTIFIER, %d, %s>\n", token, yytext);
            break;

      case _CONST_INT:
            printf("<INTEGER_CONSTANT, %d, %s>\n", token, yytext);
            break;

      case _PUNC:
            printf("<PUNCTUATOR, %d, %s>\n", token, yytext);
            break;

      case _CONST_FLT:
            printf("<FLOATING_CONSTANT, %d, %s>\n", token, yytext);
            break;

      case _CONST_ENUM :
            printf("<ENUMERATION_CONSTANT, %d, %s>\n", token, yytext);
            break;

      case _CONST_CHAR:
            printf("<CHARACTER_CONSTANT, %d, %s>\n", token, yytext);
            break;

      case _ESCAPE_SEQUENCE:
            printf("<ESCAPE_SEQUENCE, %d, %s>\n", token, yytext);
            break;


      case _STRING:
            printf("<STRING, %d, %s>\n", token, yytext);
            break;      

      case _MCOMMENT:
            printf("<MULTILINE_COMMENT, %d, %s>\n", token, yytext);
            break;

      case _SCOMMENT:
            printf("<SINGLELINE_COMMENT, %d, %s>\n", token, yytext);
            break;

      case _WS: printf("%s",yytext);

    }
  }
  return 0;
}