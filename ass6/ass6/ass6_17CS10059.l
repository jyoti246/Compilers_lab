%{
#include "ass6_17CS10059_translator.h"
#include "y.tab.h"
%}

%option noyywrap

DIG 			[0-9]
ZERO			"0"
NZERODIG 		[1-9]
DECIMAL 		"."
IDEN_ND			[A-Za-z_]
IDEN 			({IDEN_ND}({IDEN_ND}|{DIG})*)
WS		[ \t\n]
SIGN 			[-+]
DIGS			{DIG}+
EXP_PART		([eE]{SIGN}?{DIGS})
C_INT 			(({NZERODIG}({DIG}*))|{ZERO}+)
C_FRACT 		(({DIGS}{DECIMAL})|({DIGS}?{DECIMAL}{DIGS}))
C_FLOAT			(({DIGS}{EXP_PART})|({C_FRACT}{EXP_PART}?))
C_ENUM 			{IDEN}
ESC_SEQ 		([\\][\'\"\?\\abfnrtv])
C_CHAR 			[^\'\\\n]|{ESC_SEQ}
C_CHAR_SEQ 		{C_CHAR}+
C_CHAR_CONST 	(\'{C_CHAR_SEQ}\')
CONST 			({C_INT}|{C_FLOAT}|{C_ENUM}|{C_CHAR_CONST})
S_CHAR 			[^\"\\\n]|{ESC_SEQ}
S_CHAR_SEQ 		{S_CHAR}+
C_STRING 		(\"{S_CHAR_SEQ}*\")
SINGLE_COMMENT 	[/][/].*
END_MULTI_C		[\*]+[/]
START_MULTI_C 	[/][\*]+
NON_STAR 		(([^\*]).*)
NON_FS 			([^/].*)
AVOID_MULTI_END (NON_STAR|([\*]{NON_FS}))
MULTI_COMMENT 	({START_MULTI_C}(([^\*])|((\*)+[^/\*]))*{END_MULTI_C})

%%
"auto"              {return AUTO;}
"enum"              {return ENUM;}
"restrict"          {return RESTRICT;}
"unsigned"          {return UNSIGNED;}
"break"             {return BREAK;}
"extern"            {return EXTERN;}
"return"            {return RETURN_KEYWORD;}
"_Bool"             {return BOOL;}
"continue"          {return CONTINUE;}
"if"                {return IF;}
"static"            {return STATIC;}
"_Complex"          {return COMPLEX;}
"default"           {return DEFAULT;}
"inline"            {return INLINE;}
"struct"            {return STRUCT;}
"_Imaginary"        {return IMAGINARY;}
"do"                {return DO;}
"int"               {return INT;}
"void"              {return VOID;}
"char"              {return CHAR;}
"for"              	{return FOR;}
"signed"            {return SIGNED;}
"while"             {return WHILE;}
"const"             {return CONST;}
"goto"              {return GOTO_KEYWORD;}
"sizeof"            {return SIZEOF;}
"case"              {return CASE;}
"float"             {return FLOAT;}
"short"             {return SHORT;}
"volatile"          {return VOLATILE;}
"switch"            {return SWITCH;}
"double"            {return DOUBLE;}
"long"              {return LONG;}
"typedef"           {return TYPEDEF;}
"else"              {return ELSE;}
"register"          {return REGISTER;}
"union"             {return UNION;}

"["                 {return '[';  }
"]"                 { return ']'; }
"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
"."                 { return '.'; }
"->"                { return POINTER; }
"++"                { return INCREMENT; }
"--"                { return DECREMENT; }
"&"                 { return '&'; }
"*"                 { return '*'; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"~"                 { return '~'; }
"!"                 { return '!'; }
"/"                 { return '/'; }
"%"                 { return '%'; }
"<<"                { return LEFT_SHIFT; }
">>"                { return RIGHT_SHIFT; }
"<"                 { return '<'; }
">"                 { return '>'; }
"<="                { return LESS_EQUALS; }
">="                { return GREATER_EQUALS; }
"=="                { return EQUALS; }
"!="                { return NOT_EQUALS; }
"^"                 { return '^'; }
"|"                 { return '|'; }
"&&"                { return AND_OP; }
"||"                { return OR_OP; }
"?"                 { return '?'; }
":"                 { return ':'; }
";"                 { return ';'; }
"..."               { return ELLIPSIS; }
"="                 { return '='; }
"*="                { return MULTIPLY_ASSIGN; }
"/="                { return DIVIDE_ASSIGN; }
"%="                { return MODULO_ASSIGN; }
"+="                { return ADD_ASSIGN; }
"-="                { return SUBTRACT_ASSIGN; }
"<<="               { return LEFT_SHIFT_ASSIGN; }
">>="               { return RIGHT_SHIFT_ASSIGN; }
"&="                { return AND_ASSIGN; }
"^="                { return XOR_ASSIGN; }
"|="                { return OR_ASSIGN; }
","                 { return ','; }
"#"                 { return '#'; }
{WS}								{; }

{IDEN}          															{yylval.str = new string(yytext);  return  ID;}
{C_INT}         															{yylval.intval = atoi(yytext); return  CONST_INT; }
{C_FLOAT}																 	    {yylval.floatval = atof(yytext); return  CONST_FLT;}
{C_ENUM}																    	{return  CONST_ENUM;}
{C_CHAR_CONST}																{yylval.charval = yytext[1]; return  CONST_CHAR; }
{C_STRING}   																  {yylval.str = new string(yytext);  return  STRING; }

{SINGLE_COMMENT}	 														{; }
{MULTI_COMMENT}	 															{; }

%%
