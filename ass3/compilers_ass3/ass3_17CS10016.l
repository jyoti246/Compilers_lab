%{
#define _KEYWORD  10
#define _ID     11
#define _PUNC   12
#define _CONST_INT  13
#define _CONST_FLT  14
#define _CONST_ENUM  15
#define _CONST_CHAR  16
#define _STRING   17
#define _ESCAPE_SEQUENCE 18
#define _MCOMMENT 19
#define _SCOMMENT 20
#define _WS     21
%}


KEYWORD					"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"




DIGIT					[0-9]
NONZERO_DIGIT			[1-9]
NON_DIGIT				[_a-zA-Z]

IDENTIFIER				{NON_DIGIT}({NON_DIGIT}|{DIGIT})*



SIGN					[+-]
INTEGER_CONSTANT		0|{NONZERO_DIGIT}{DIGIT}*


digseq					{DIGIT}+
FRACT_PART				({digseq}?\.{digseq})|({digseq}\.)
EXP_PART				[eE]{SIGN}?{digseq}
FLOATING_CONSTANT		({FRACT_PART}{EXP_PART}?)|({digseq}{EXP_PART})




ENUMERATION_CONSTANT	{IDENTIFIER}




ESCAPE_SEQUENCE			\\['"?\\abfnrtv]

c_char					[^\'\\\n]
c_char_sequence			{c_char}+
CHARACTER_CONSTANT		\'{c_char_sequence}\'



s_char					[^\"\\\n]|{ESCAPE_SEQUENCE}
s_char_sequence			{s_char}+
STRING					\"{s_char_sequence}*\"



PUNCTUATOR				"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"




SINGLE_COMMENT 			[/][/].*
END_MULTI_C				[\*]+[/]
START_MULTI_C 			[/][\*]+
NON_STAR 				(([^\*]).*)
NON_FS 					([^/].*)
AVOID_MULTI_END 		(NON_STAR|([\*]{NON_FS}))
MULTI_COMMENT 			({START_MULTI_C}(([^\*])|((\*)+[^/\*]))*{END_MULTI_C})

ws						[ \t\n\v\f]



%%
{KEYWORD}				{return _KEYWORD;}
{IDENTIFIER}		    {return _ID;}
{INTEGER_CONSTANT}		{return _CONST_INT;}
{FLOATING_CONSTANT}		{return _CONST_FLT;}
{ENUMERATION_CONSTANT}	{return _CONST_ENUM;}
{CHARACTER_CONSTANT}	{return _CONST_CHAR;}
{ESCAPE_SEQUENCE}		{return _ESCAPE_SEQUENCE;}
{STRING}				{return _STRING;}
{PUNCTUATOR}			{return _PUNC;}
{MULTI_COMMENT}			{return _MCOMMENT;}
{SINGLE_COMMENT}		{return _SCOMMENT;}
{ws}					{return _WS;}
%%









