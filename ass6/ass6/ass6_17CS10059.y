%{
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
extern int yylex();
void yyerror(string s);
extern int yydebug;
extern int yyparse();

#include "ass6_17CS10059_translator.h"

Quad_Array Q_arr;
symboltable GT;
symboltable *sym = &GT;
symboltable *curr_sym = sym;
type_inf *global_type;
int global_width;

vector<string> string_lits;
int literal_count = 0;

int keep_count = 0;

void increase_k(){
    keep_count++;
}

%}

%union {
  int intval;
  float floatval;
  char charval;
  string *str;
  exp_attr *expr_attr;
  declaration *decclist;
  init_dec_list *init_dec_list_;
  type_inf *type_;
  func_def *func_def_;
  func_list *func_list_;
}


%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token FLOAT FOR GOTO_KEYWORD IF INLINE INT LONG REGISTER RESTRICT RETURN_KEYWORD SHORT SIGNED SIZEOF STATIC STRUCT SWITCH
%token TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY
%token POINTER INCREMENT DECREMENT LEFT_SHIFT RIGHT_SHIFT LESS_EQUALS GREATER_EQUALS EQUALS NOT_EQUALS
%token AND_OP OR_OP ELLIPSIS MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN
%token LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SCOMMENT MCOMMENT

%token <str> ID
%token <intval> CONST_INT
%token CONST_ENUM
%token <floatval> CONST_FLT
%token <str> STRING
%token <charval> CONST_CHAR

%type<expr_attr> primary_expression
%type<expr_attr> postfix_expression
%type<expr_attr> unary_expression
%type<charval> unary_operator
%type<expr_attr> cast_expression
%type<expr_attr> multiplicative_expression
%type<expr_attr> additive_expression
%type<expr_attr> shift_expression
%type<expr_attr> relational_expression
%type<expr_attr> equality_expression
%type<expr_attr> AND_expression
%type<expr_attr> exclusive_OR_expression
%type<expr_attr> inclusive_OR_expression
%type<expr_attr> logical_AND_expression
%type<expr_attr> logical_OR_expression
%type<expr_attr> conditional_expression
%type<expr_attr> assignment_expression
%type<expr_attr> assignment_expression_opt
%type<expr_attr> assignment_operator
%type<expr_attr> expression
%type<expr_attr> constant_expression
%type<expr_attr> declaration
%type<type_> declaration_specifiers
%type<init_dec_list_> init_declarator_list
%type<decclist> init_declarator
%type<decclist> direct_declarator
%type<type_> type_specifier
%type<type_> specifier_qualifier_list
%type<decclist> declarator
%type<expr_attr> initializer
%type<decclist> initializer_list
%type<type_> type_name
%type<type_> pointer
%type<func_list_> parameter_list
%type<func_list_> parameter_type_list
%type<func_list_> parameter_type_list_opt
%type<func_def_> parameter_declaration
%type<expr_attr> jump_statement
%type<expr_attr> compound_statement
%type<expr_attr> block_item
%type<expr_attr> block_item_list
%type<expr_attr> selection_statement
%type<expr_attr> iteration_statement
%type<expr_attr> M
%type<expr_attr> N
%type<expr_attr> statement
%type<expr_attr> expression_statement
%type<func_list_> argument_expression_list
%type<expr_attr> expression_opt
%type<decclist> function_definition

%start translation_unit


%%

// Rules start here

M:   {
    $$ = new exp_attr;
    $$->instr = Q_arr.index;};

N:   {
    $$ = new exp_attr;
    $$->nextlist = makelist(Q_arr.index);
    Q_arr.emit(GOTO,"","","");
};


primary_expression:             ID {
                                    $$ = new exp_attr;
                                    string t = (*($1));
                                    increase_k();
                                    symtab *h = curr_sym->lookup(t);
                                    $$->loc = t;
                                    increase_k();
                                    /* h -> nested_table = NULL; */
                                } |
                                CONST_INT {
                                    $$ = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "int";
                                    opcodeType op = COPY;
                                    increase_k();
                                    $$->loc = curr_sym->gentemp(type);
                                    increase_k();
                                    Q_arr.emit(op,$$->loc, $1);
                                    init_value *init = new init_value;
                                    increase_k();
                                    init->int_val = $1;
                                    increase_k();
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    $$->is_pointer_type = 0;
                                } |
                                CONST_FLT {
                                    increase_k();
                                    $$ = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "float";
                                    opcodeType op = COPY;
                                    increase_k();
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,$$->loc, $1);
                                    increase_k();
                                    init_value *init = new init_value;
                                    init->int_val = $1;
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    increase_k();
                                    $$->is_pointer_type = 0;
                                } |
                                CONST_CHAR {
                                    increase_k();
                                    $$ = new exp_attr;
                                    type_inf type;
                                    increase_k();
                                    type.type_name = "char";
                                    opcodeType op = COPY;
                                    increase_k();
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,$$->loc, $1);
                                    init_value *init = new init_value;
                                    init->int_val = $1;
                                    increase_k();
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    $$->is_pointer_type = 0;
                                    increase_k();
                                } |
                                STRING {
                                    $$ = new exp_attr;
                                    string s = ".LC";
                                    string temp = to_string(literal_count);
                                    s = s + temp;
                                    $$->loc = s;
                                    literal_count++;
                                    string_lits.push_back(*$1);
                                } |
                                '(' expression ')' {
                                    $$ = $2;
                                    increase_k();
                               };

enumeration_constant:           ID {};

postfix_expression :            primary_expression {
                                    $$ = $1;
                                    increase_k();
                                } |
                                postfix_expression '[' expression ']'
                                {
                                    increase_k();
                                    type_inf t = curr_sym->lookup($1->loc)->type;
                                	string s;
                                    type_inf t1;
                                    t1.type_name = "int";
                                	int idx;
                                	string s1;
                                	idx = t.idx;
                                	s = curr_sym->gentemp(t1);
                                        Q_arr.emit(COPY, s, 0);
                                        $1 -> inner = new string(s);    //temporary for inner dimension
                                	s = *($1->inner);
                                	s1 = to_string(idx);

                                    Q_arr.emit(MULT, s, s, s1);
                                    Q_arr.emit(PLUS, s, s, $3->loc);
                                    Q_arr.emit(MULT, s, s, string("4"));
                                    $$ = $1;
                                } |
                                postfix_expression '(' ')' {
                                } |
                                postfix_expression '(' argument_expression_list ')' {
                                    increase_k();
                                    string f = $1->loc;
                                    increase_k();
                                    symboltable *fsym = GT.lookup(f)->nested_table;
                                    func_list *flist = ($3);
                                    list<func_def*>::iterator it;
                                    increase_k();
                                    int c = 0;
                                    for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++)
                                    {
                                        func_def *f = *it;
                                        c++;
                                        Q_arr.emit(PARAM, f->param_name,"","");
                                    }
                                    increase_k();
                                    string s = to_string(c);
                                    Q_arr.emit(CALL,f,s,"");
                                    increase_k();
                                } |
                                postfix_expression '.' ID {
                                }|
                                postfix_expression POINTER ID {
                                } |
                                postfix_expression INCREMENT {
                                    $$ = new exp_attr;
                                    increase_k();
                                    string s = $1->loc;
                                    symtab * f = curr_sym->lookup($1->loc);
                                    $$->loc = curr_sym->gentemp(f->type);
                                    increase_k();
                                    if(f->type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(f->type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        Q_arr.emit(COPY, $$->loc, temp, "");
                                        Q_arr.emit(PLUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, $1->loc, temp, *($1->inner));
                                    }
                                    else
                                    {
                                        Q_arr.emit(COPY, $$->loc, $1->loc, "");
                                        Q_arr.emit(PLUS, $1->loc, $1->loc, "1");
                                    }
                                    increase_k();
                                } |
                                postfix_expression DECREMENT {
                                    $$ = new exp_attr;
                                    increase_k();
                                    string s = $1->loc;
                                    symtab * f = curr_sym->lookup($1->loc);
                                    increase_k();
                                    $$->loc = curr_sym->gentemp(f->type);
                                    if(f->type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(f->type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        Q_arr.emit(COPY, $$->loc, temp, "");
                                        Q_arr.emit(MINUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, $1->loc, temp, *($1->inner));
                                    }
                                    else
                                    {
                                        Q_arr.emit(COPY, $$->loc, $1->loc, "");
                                        Q_arr.emit(MINUS, $1->loc, $1->loc, "1");
                                    }
                                    increase_k();
                                } |
                                '(' type_name ')' '{' initializer_list '}' {
                                }|
                                '(' type_name ')' '{' initializer_list ',' '}' {
                                };

argument_expression_list:       assignment_expression {
                                    func_def *f = new func_def;
                                    increase_k();
                                    f->param_name = $1->loc;
                                    $$ = new func_list;
                                    increase_k();
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    $$->func_def_list.push_back(f);
                                    increase_k();
                                }|
                                argument_expression_list ',' assignment_expression {
                                    increase_k();
                                    func_def *f = new func_def;
                                    f->param_name = $3->loc;
                                    $$ = new func_list;
                                    increase_k();
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    $$->func_def_list.push_back(f);
                                    increase_k();
                                };

unary_expression:               postfix_expression {
                                }|
                                INCREMENT unary_expression {
                                    opcodeType op;
                                    op = PLUS;
                                    increase_k();
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup($2->loc)->type;
                                    if(type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $2->loc, *($2->inner));
                                        Q_arr.emit(PLUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, $2->loc, temp, *($2->inner));
                                    }
                                    else
                                        Q_arr.emit(op, $$->loc, $2->loc, "1");
                                    type = curr_sym->lookup($2->loc)->type;
                                    $$->loc = curr_sym->gentemp(type);
                                    op = COPY;
                                    increase_k();
                                    Q_arr.emit(op, $2->loc, $$->loc, "");
                                }|
                                DECREMENT unary_expression {
                                    opcodeType op;
                                    op = MINUS;
                                    increase_k();
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup($2->loc)->type;
                                    $$->loc = curr_sym->gentemp(type);
                                    if(type.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $2->loc, *($2->inner));
                                        Q_arr.emit(MINUS, temp, temp, "1");
                                        Q_arr.emit(ARRAY_DEREFERENCE, $2->loc, temp, *($2->inner));
                                    }
                                    else
                                        Q_arr.emit(op, $$->loc, $2->loc, "1");
                                    type = curr_sym->lookup($2->loc)->type;
                                    $$->loc = curr_sym->gentemp(type);
                                    op = COPY;
                                    increase_k();
                                    Q_arr.emit(op, $2->loc, $$->loc, "");
                                }|
                                unary_operator cast_expression {
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type.type_name = string("int");
                                    if($1 == '-')
                                    {
                                        increase_k();
                                        $$ = new exp_attr;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(UNARY_MINUS,$$->loc,$2->loc,"");
                                    }
                                    else if($1 == '&')
                                    {
                                        increase_k();
                                        $$ = new exp_attr;
                                	    type.pointer_type = "ptr";
                                	    type.pointer_count = 1;
                                	    type.size = 8;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(REFERENCE,$$->loc,$2->loc,"");
                                    }
                                    else if($1 == '*')
                                    {
                                        increase_k();
                                        $$ = new exp_attr;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(DEREFERENCE,$$->loc,$2->loc,"");
                                    }
                                    else
                                    {
                                        increase_k();
                                        $$ = $2;
                                    }
                                }|
                                SIZEOF unary_expression {
                                }|
                                SIZEOF '(' type_name ')' {
                                };

unary_operator  :               '&' {
                                    $$ = '&';
                                }|
                                '*' {
                                    $$ = '*';
                                }|
                                '+' {
                                    $$ = '+';
                                }|
                                '-' {
                                    $$ = '-';
                                }|
                                '~' {
                                    $$ = '~';
                                }|
                                '!' {
                                    $$ = '!';
                                };

cast_expression :               unary_expression {
                                }|
                                '(' type_name ')' cast_expression {
                                };

multiplicative_expression:      cast_expression {
                                    /* $$ = $1; */
                                    increase_k();
                                }|
                                multiplicative_expression '*' cast_expression {
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        increase_k();
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,$3);
                                        increase_k();
                                        type.type_name = type1.type_name;
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MULT, $$->loc, $1->loc, $3->loc);
                                    increase_k();
                                }|
                                multiplicative_expression '/' cast_expression {
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        increase_k();
                                        Q_arr.convI2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(DIVIDE, $$->loc, $1->loc, $3->loc);
                                }|
                                multiplicative_expression '%' cast_expression {
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MODULO, $$->loc, $1->loc, $3->loc);
                                };

additive_expression :           multiplicative_expression {
                                    /* $$ = $1; */
                                }|
                                additive_expression '+' multiplicative_expression {
                                    $$ = new exp_attr;
                                    increase_k();
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convI2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        increase_k();
                                        Q_arr.convI2F(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2F(e,$3);
                                        type.type_name = type1.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,$1);
                                        type.type_name = type2.type_name;
                                        increase_k();
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(PLUS, $$->loc, $1->loc, $3->loc);
                                }|
                                additive_expression '-' multiplicative_expression {
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    int flag = 0;
                                    increase_k();
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    increase_k();
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convI2F(e,$3);
                                        type.type_name = type1.type_name;
                                        increase_k();
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convI2F(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    increase_k();
                                    if(type1.type_name.compare("float")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2F(e,$3);
                                        type.type_name = type1.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("float")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type2;
                                        Q_arr.convC2F(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        increase_k();
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        increase_k();
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        increase_k();
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        increase_k();
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;
                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MINUS, $$->loc, $1->loc, $3->loc);
                                };

shift_expression:               additive_expression {
                                    /* $$ = $1; */
                                }|
                                shift_expression LEFT_SHIFT additive_expression {
                                    $$ = new exp_attr;
                                    /* type_inf type1;
                                    type1 = curr_sym->lookup($3->loc)->type; */
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }
                                    int flag = 0;
                                    increase_k();
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {
                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("float") == 0)
                                        {
                                            increase_k();
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convF2I(e,$3);
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,$3);
                                        }
                                    }
                                    type1.type_name = "int";
                                    $$->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_LEFT, $$->loc, $1->loc, $3->loc);
                                }|
                                shift_expression RIGHT_SHIFT additive_expression {
                                    $$ = new exp_attr;
                                    /* type_inf type1;
                                    increase_k();
                                    type1 = curr_sym->lookup($3->loc)->type; */
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }
                                    int flag = 0;
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {
                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("float") == 0)
                                        {
                                            increase_k();
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            increase_k();
                                            Q_arr.convF2I(e,$3);
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            increase_k();
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            increase_k();
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,$3);
                                        }
                                    }
                                    type1.type_name = "int";
                                    $$->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_RIGHT, $$->loc, $1->loc, $3->loc);
                                };

relational_expression:          shift_expression {
                                    /* $$ = $1; */
                                }|
                                relational_expression '<' shift_expression {
                                    // copy pasted part of the code
                                    // the purpose of the code is to check for array accesses and make temporaries
                                    // for such accesses
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    increase_k();
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression '>' shift_expression {
                                    // the copy pasted part of the code
                                    // the purpose of the code is to generate temporaries for array accesses
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    increase_k();
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER, "", $1->loc, $3->loc);
                                    increase_k();
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression LESS_EQUALS shift_expression {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    increase_k();
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    increase_k();
                                    Q_arr.emit(IF_LESS_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression GREATER_EQUALS shift_expression {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    increase_k();
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    increase_k();
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                };

equality_expression:            relational_expression {
                                    /* $$ = $1; */
                                }|
                                equality_expression EQUALS relational_expression {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    increase_k();
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_IS_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                equality_expression NOT_EQUALS relational_expression {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    increase_k();
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    increase_k();
                                    Q_arr.emit(IF_NOT_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                };

AND_expression :                equality_expression {
                                }|
                                AND_expression '&' equality_expression {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    increase_k();
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    increase_k();
                                    Q_arr.emit(LOGICAL_AND, $$->loc, $1->loc, $3->loc);
                                };

exclusive_OR_expression:        AND_expression {
                                }|
                                exclusive_OR_expression '^' AND_expression {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    increase_k();
                                    type_inf t;
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(XOR, $$->loc, $1->loc, $3->loc);
                                };

inclusive_OR_expression:        exclusive_OR_expression {
                                }|
                                inclusive_OR_expression '|' exclusive_OR_expression {

                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    $$ = new exp_attr;
                                    increase_k();
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    type_inf t;
                                    increase_k();
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(OR, $$->loc, $1->loc, $3->loc);
                                };

logical_AND_expression:         inclusive_OR_expression {
                                };|
                                logical_AND_expression N AND_OP M inclusive_OR_expression N {

                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($5->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
                                        $5->loc = temp;
                                        $5->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    type_inf type;
                                    increase_k();
                                    type.type_name = "bool";
                                    $$ = new exp_attr;
                                    $$->type = type;
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($1);
                                    //N required to prevent fall-through
                                    increase_k();
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($5);
                                    increase_k();
                                    //as mentioned in the slide
                                    Q_arr.backpatch($1->truelist, $4->instr);
                                    $$->truelist = $5->truelist;
                                    $$->falselist = merge($1->falselist, $5->falselist);
                                };

logical_OR_expression:          logical_AND_expression {
                                };|
                                logical_OR_expression N OR_OP M logical_AND_expression N {

                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($5->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
                                        $5->loc = temp;
                                        $5->type.array_type = ""; //check
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
                                        $1->loc = temp;
                                        $1->type.array_type = ""; //check
                                    }

                                    type_inf type;
                                    type.type_name = "bool";
                                    $$ = new exp_attr;
                                    $$->type = type;
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($1);
                                    increase_k();
                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($5);
                                    increase_k();
                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch($1->falselist, $4->instr);
                                    $$->falselist = $5->falselist;
                                    $$->truelist = merge($1->truelist, $5->truelist);
                                };

/*It is assumed that type of expression and conditional expression are same*/
conditional_expression:         logical_OR_expression {
                                };|
                                logical_OR_expression N '?' M expression N ':' M conditional_expression {
                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup($5->loc)->type;
                                    type2 = curr_sym->lookup($9->loc)->type;

                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $9->loc, *($9->inner));
                                        $9->loc = temp;
                                        $9->type.array_type = ""; //check
                                    }
                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        string temp = curr_sym->gentemp(type1);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
                                        $5->loc = temp;
                                        $5->type.array_type = ""; //check
                                    }
                                    $$ = new exp_attr;
                                    list<int> I;
                                    type_inf type;
                                    type = curr_sym->lookup($5->loc)->type;
                                    increase_k();
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(COPY, $$->loc, $9->loc,"");
                                    I = makelist(Q_arr.index);
                                    Q_arr.emit(GOTO,"","","");
                                    increase_k();
                                    // for the second N
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);
                                    increase_k();
                                    Q_arr.emit(COPY, $$->loc, $5->loc, "");
                                    I = merge(I, makelist(Q_arr.index));
                                    Q_arr.emit(GOTO,"", "", "");
                                    increase_k();
                                    // for the first N
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);
                                    increase_k();
                                    Q_arr.convInt2Bool($1);
                                    increase_k();
                                    // the standard stuff from the slides
                                    Q_arr.backpatch($1->truelist, $4->instr);
                                    Q_arr.backpatch($1->falselist, $8->instr);
                                    Q_arr.backpatch(I, Q_arr.index);
                                };

assignment_operator:            '=' {
                                    increase_k();
                                }|
                                MULTIPLY_ASSIGN {
                                    increase_k();
                                }|
                                DIVIDE_ASSIGN {
                                    increase_k();
                                }|
                                MODULO_ASSIGN {
                                    increase_k();
                                }|
                                ADD_ASSIGN  {
                                    increase_k();
                                }|
                                SUBTRACT_ASSIGN {
                                    increase_k();
                                }|
                                LEFT_SHIFT_ASSIGN {
                                    increase_k();
                                }|
                                RIGHT_SHIFT_ASSIGN {
                                    increase_k();
                                }|
                                AND_ASSIGN {
                                    increase_k();
                                }|
                                XOR_ASSIGN {
                                    increase_k();
                                }|
                                OR_ASSIGN {
                                    increase_k();
                                };

assignment_expression:          conditional_expression {
                                    increase_k();
                                }|
                                unary_expression assignment_operator assignment_expression {
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    increase_k();
                                    if(type2.array_type.compare("array") == 0)
                                    {
                                        increase_k();
                                        string temp = curr_sym->gentemp(type2);
                                        Q_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
                                        $3->loc = temp;
                                        $3->type.array_type = ""; //check
                                        increase_k();
                                    }

                                    if(type1.array_type.compare("array") == 0)
                                    {
                                        increase_k();
                                        Q_arr.emit(ARRAY_DEREFERENCE, $1->loc, $3->loc, *($1->inner));
                                    }
                                    else
                                        Q_arr.emit(COPY, $1->loc, $3->loc, "");
                                    $$ = $1;
                                    increase_k();
                                };

/*A constant value of this expression exists*/
constant_expression:            conditional_expression {
                                    increase_k();
                                };

expression :                    assignment_expression {
                                    $$ = $1;
                                    increase_k();
                                }|
                                expression ',' assignment_expression {
                                    increase_k();
                                };

/*Declarations*/
declaration:                    declaration_specifiers ';'{
                                    increase_k();
                                }
                                | declaration_specifiers init_declarator_list ';'
                                {
                                    increase_k();
                                    init_dec_list *new_dec = new init_dec_list;
                                    new_dec = $2;
                                    int size = 0;
                                    increase_k();
                                    type_inf *type = $1;
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("float")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    increase_k();
                                    list<declaration*>::iterator it;
                                    for(it = $2->dec_list.begin(); it != $2->dec_list.end(); it++)
                                    {
                                        increase_k();
                                        declaration *new_dec = *it;
                                        if(new_dec->type!=NULL){
                                        if(new_dec->type->type_name.compare("function")==0)
                                        {
                                            string name = new_dec->dec_name;
                                            //cout<<name<<"\n";
                                            curr_sym = &GT;
                                            Q_arr.emit(_FUNCTION_END,name,"","");
                                            //write an emit
                                            increase_k();
                                        }
                                        increase_k();
                                        symtab *ret, *f;
                                        symboltable *nest;
                                        if(new_dec->type->type_name.compare("function")==0)
                                        {
                                            f = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            nest = f->nested_table;
                                            ret = nest->lookup("retVal", type->type_name, new_dec->pointer_count);
                                            f->offset = curr_sym->offset;
                                            increase_k();
                                            f->size = size;
                                            f->init_val = NULL;
                                            continue;
                                        }
                                	}
                                        increase_k();

                                        symtab *f1 = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                        increase_k();
                                        f1->nested_table = NULL;
                                        increase_k();
                                        //condition for id
                                        if(new_dec->alist == vector<int>() && new_dec->pointer_count == 0)
                                        {
                                            f1->offset = curr_sym->offset;
                                            increase_k();
                                            //f1->offset = f1->offset + size;
                                            f1->type = *type;
                                            f1 = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            increase_k();
                                            if(new_dec->init != NULL)
                                            {
                                                increase_k();
                                                string x = new_dec->init->loc;
                                                Q_arr.emit(COPY, new_dec->dec_name, x, "");
                                                f1->init_val = curr_sym->lookup(x,f1->type.type_name)->init_val;
                                            }
                                            else
                                                new_dec->init = NULL;
                                        }

                                        else if(new_dec -> pointer_count > 0)
                                        {
                                            increase_k();
                                            symtab *sp;
                                            for(sp = curr_sym->sym_table; sp < &curr_sym->sym_table[curr_sym->no_of_entries]; sp++)
                                            {
                                                increase_k();
                                                if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                                                {
                                                    increase_k();
                                                    sp->offset = curr_sym->offset-4;
                                                    sp->pointer_count = new_dec->pointer_count;
                                                    sp->type = *type;
                                                    sp->type.pointer_type = "ptr";
                                                    sp->size = 4;
                                                    increase_k();
                                                }
                                            }
                                        }
                                        else if(new_dec->alist!=vector<int>())
                                        {
                                            symtab *sp;
                                            increase_k();
                                            for(sp = curr_sym->sym_table; sp < &curr_sym->sym_table[curr_sym->no_of_entries]; sp++)
                                            {
                                                increase_k();
                                                if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                                                {
                                                    int temp_size = size;
                                                    sp->offset = curr_sym->offset-4;
                                                    sp->type = *type;
                                                    increase_k();
                            			            sp->type.type_name = type->type_name;
                                                    sp->type.array_type = "array";
                                                    increase_k();
                                                    sp->type.pointer_type = "";
                            			            for(int i = 0; i < new_dec->alist.size(); i++)
                                                    {
                                                        increase_k();
                                                        sp->type.array_list.push_back(new_dec->alist[i]);
                                                    }

                                                    for (int i = 0; i < sp->type.array_list.size(); ++i)
                                                    {
                                                        increase_k();
                                                        temp_size = temp_size * sp->type.array_list[i];
                                                    }
                                                    increase_k();
                                                    sp->size = temp_size;
                                                    curr_sym->offset = curr_sym->offset + temp_size;
                                                }
                                            }
                                        }
                                    }
                                };

declaration_specifiers:         storage_class_specifier declaration_specifiers {
                                    increase_k();
                                }|
                                storage_class_specifier{
                                    increase_k();
                                }|
                                type_specifier{
                                    $$ = $1;
                                    increase_k();
                                }|
                                type_specifier declaration_specifiers {
                                    increase_k();
                                }|
                                type_qualifier declaration_specifiers {
                                    increase_k();
                                }|
                                function_specifier declaration_specifiers {
                                    increase_k();
                                }|
                                type_qualifier{
                                    increase_k();
                                }|
                                function_specifier{
                                    increase_k();
                                };

/*  I have made a change here .. please note if not working */
/* declaration_specifiers_opt:     declaration_specifiers {
                                }|
                                /*epsilon {} ;*/

init_declarator_list:           init_declarator {
                                    increase_k();
                                    $$ = new init_dec_list;
                                    $$->dec_list.push_back($1);
                                }|
                                init_declarator_list ',' init_declarator {
                                    $1->dec_list.push_back($3);
                                    $$ = $1;
                                    increase_k();
                                };

init_declarator:                declarator {
                                    increase_k();
                                    $$ = $1;
                                    $$->init = NULL;
                                }|
                                declarator '=' initializer {
                                    $$ = $1;
                                    $$->init = $3;
                                    increase_k();
                                };

storage_class_specifier:        EXTERN {
                                    increase_k();
                                }|
                                STATIC {
                                    increase_k();
                                }|
                                AUTO {
                                    increase_k();
                                }|
                                REGISTER {
                                    increase_k();
                                };

type_specifier:                 VOID {
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("void");
                                    $$->next = NULL;
                                }|
                                CHAR {
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("char");
                                    $$->next = NULL;
                                }|
                                SHORT {
                                    increase_k();
                                }|
                                INT {
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("int");
                                    $$->next = NULL;
                                }|
                                LONG {
                                    increase_k();
                                }|
                                FLOAT {
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("float");
                                    $$->next = NULL;
                                }|
                                DOUBLE {
                                    increase_k();
                                }|
                                SIGNED {
                                    increase_k();
                                }|
                                UNSIGNED {
                                    increase_k();
                                }|
                                BOOL {
                                    increase_k();
                                }|
                                COMPLEX {
                                    increase_k();
                                }|
                                IMAGINARY {
                                    increase_k();
                                }|
                                enum_specifier {
                                    increase_k();
                                };

specifier_qualifier_list:       type_specifier specifier_qualifier_list_opt {
                                    $$ = $1;
                                    increase_k();
                                }|
                                type_qualifier specifier_qualifier_list_opt {
                                    increase_k();
                                };

specifier_qualifier_list_opt:   specifier_qualifier_list {
                                    increase_k();
                                }|
                                /*epsilon*/ {
                                    increase_k();
                                };

enum_specifier:                 ENUM ID_opt '{' enumerator_list '}' {
                                }|
                                ENUM ID_opt '{' enumerator_list ',' '}' {
                                }|
                                ENUM ID {
                                };

ID_opt:                         ID {
                                    increase_k();
                                }|
                                /*epsilon*/ {
                                    increase_k();
                                };

enumerator_list:                enumerator {
                                    increase_k();
                                }|
                                enumerator_list ',' enumerator {
                                    increase_k();
                                };

enumerator:                     CONST_ENUM {
                                }|
                                CONST_ENUM '=' constant_expression {
                                };

type_qualifier:                 CONST {
                                    increase_k();
                                }|
                                RESTRICT {
                                    increase_k();
                                }|
                                VOLATILE {
                                    increase_k();
                                };

function_specifier:             INLINE {
                                    increase_k();
                                };

declarator :                    pointer direct_declarator {
                                    $$ = $2;
                                    increase_k();
                                    $$->pointer_count = $1->pointer_count;
                                }|
                                direct_declarator{
                                    $$ = $1;
                                    $$->pointer_count = 0;
                                    increase_k();
                                };

pointer_opt:                    pointer {
                                    increase_k();
                                }|
                                /*epsilon*/{
                                    increase_k();
                                };

direct_declarator:              ID {
                                    increase_k();
                                    $$ = new declaration;
                                    $$->dec_name = *($1);
                                }
                                | '(' declarator ')'
                                {
                                    increase_k();
                                    $$ = $2;
                                }
                                | direct_declarator '[' type_qualifier_list_opt assignment_expression_opt ']'
                                {
                                    increase_k();
                                    $$ = $1;
                            	    int idx = curr_sym->lookup($4->loc)->init_val->int_val;
                            	    $$->alist.push_back(idx);
                            	}
                                | direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']'
                                {
                                    increase_k();
                                }
                                | direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
                                {
                                    increase_k();
                                }
                                | direct_declarator '[' type_qualifier_list_opt '*' ']'
                                {
                                    increase_k();
                                }
                                | direct_declarator '(' parameter_type_list_opt')'
                                {
                                    increase_k();
                                    list<func_def*> l = $3->func_def_list;
                                    increase_k();
                                    symboltable *new_sym = new symboltable;
                                    $$ = $1;
                                    string name = $$->dec_name;
                                    increase_k();
                                    $$->type = new type_inf;
                                    $$->type->type_name = string("function");
                                    $$->type->no_of_params = l.size();
                                    symtab *func_lookup = sym->lookup($$->dec_name, $$->type->type_name);
                            		for(int i=0; i < sym->no_of_entries; i++)
                                   		{
                                            increase_k();
                            	    	if(sym->sym_table[i].id.compare($$->dec_name)==0)
                            	    	{
                            				sym->sym_table[i].type.type_name = "function";
                            				sym->sym_table[i].type.no_of_params = l.size();
                            	    	}
                                    }
                                    func_lookup -> nested_table = new_sym;
                                    increase_k();
                                    list<func_def*>::iterator it;
                                    for(it = l.begin(); it != l.end(); it++)
                                    {
                                        func_def *temp = *it;
                                        new_sym -> lookup(temp->param_name, temp->type->type_name);
                            	    for(int i = 0; i<new_sym->no_of_entries; i++)
                            	    {
                            		if(new_sym->sym_table[i].id.compare(temp->param_name)==0)
                            		{
                            			if(temp->type->array_type.compare("array")==0){
                            				new_sym->sym_table[i].type.array_type = "array";
                            				new_sym->sym_table[i].type.idx = temp->type->idx;
                            				}
                            		}
                            	    }
                                    }
                                    increase_k();
                                    symtab *sp;
                                    for(sp = sym->sym_table; sp < &sym->sym_table[sym->no_of_entries]; sp++)
                                    {
                                        if(!sp->id.empty() && !sp->id.compare($$->dec_name))
                                        {
                                            sp->nested_table = new_sym;
                                        }
                                    }
                                    curr_sym = new_sym;
                                    Q_arr.emit(_FUNCTION_START, name,"","");
                                }
                                | direct_declarator '(' identifier_list')' {
                                    increase_k();
                                };
assignment_expression_opt:      assignment_expression {
                                    increase_k();
                                }|
                                ;
type_qualifier_list_opt:        type_qualifier_list {
                                    increase_k();
                                }|
                                ;

pointer:                        '*'{
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("ptr");
                                    $$->next = NULL;
                                    $$->pointer_type = string("ptr");
                                    $$->pointer_count = 1;
                                }
                                | '*' type_qualifier_list{
                                    increase_k();
                                }
                                | '*' pointer
                                {
                                    increase_k();
                                    $$ = new type_inf;
                                    $$->type_name = string("ptr");
                                    $$->next = NULL;
                                    $$->pointer_type = string("ptr");
                                    $$->pointer_count = $2->pointer_count + 1;
                                    increase_k();
                                }
                                | '*' type_qualifier_list pointer
                                {
                                    increase_k();
                                };
type_qualifier_list:            type_qualifier {
                                    increase_k();
                                }
                                | type_qualifier_list type_qualifier {
                                    increase_k();
                                };
parameter_type_list_opt:        parameter_type_list
                                |{
                                    increase_k();
                                    $$ = new func_list;
                                };
parameter_type_list:            parameter_list {
                                    increase_k();
                                    $$ = new func_list;
                                    $$ = $1;
                                }
                                | parameter_list ',' ELLIPSIS
                                {
                                    increase_k();
                                };
parameter_list:                 parameter_declaration
                                {
                                    increase_k();
                                    $$ = new func_list;
                                    $$->func_def_list.push_back($1);
                                }
                                | parameter_list ',' parameter_declaration
                                {
                                    increase_k();
                                    $1->func_def_list.push_back($3);
                                    $$ = $1;
                                };
parameter_declaration:          declaration_specifiers declarator {
                                    $$ = new func_def;
                                    $$->type = $1;
                                    increase_k();
                                    if($2->alist.size()>0)
                                    {$$->type->array_type = "array";$$->type->idx = $2->alist[0];$$->type->type_name = $1->type_name;
                                    }
                                    for(int i=0; i<curr_sym->no_of_entries; i++)
                                    {
                                        increase_k();
                                    if(curr_sym->sym_table[i].id.compare($2->dec_name)==0)
                                    {
                                    if($2->type->array_type.compare("array")==0 || curr_sym->sym_table[i].type.array_type.compare("array")==0)
                                    {
                                    	curr_sym->sym_table[i].type.array_type = "array";
                                    	$$->type->array_type = "array";
                                    }
                                    }
                                    }
                                    $$->param_name = $2->dec_name;
                                    increase_k();
                                }
                                | declaration_specifiers{
                                    increase_k();
                                };

identifier_list:                 ID {
                                    increase_k();
                                }
                                | identifier_list ',' ID
                                {
                                    increase_k();
                                };

type_name:                  specifier_qualifier_list{
                                increase_k();
                                $$ = $1;
                            };

initializer:                assignment_expression {
                                $$ = $1;
                                increase_k();
                            }
                            | '{' initializer_list '}'
                            {
                                increase_k();
                            }
                            | '{' initializer_list ',' '}'
                            {
                                increase_k();
                            };

initializer_list:               initializer
                                {
                                    increase_k();
                                }
                                | designation initializer
                                {
                                    increase_k();
                                }
                                | initializer_list ',' initializer
                                {
                                    increase_k();
                                }
                                | initializer_list ',' designation initializer
                                {
                                    increase_k();
                                };

designation:                    designator_list '=' {
                                    increase_k();
                                };

designator_list:                designator{
                                    increase_k();
                                }
                                | designator_list designator{
                                    increase_k();
                                };

designator:                     '[' constant_expression ']'{
                                    increase_k();
                                }
                                | '.' ID{
                                    increase_k();
                                };

/*Statements*/
statement:                      labeled_statement {
                                    increase_k();
                                }|
                                compound_statement {
                                    increase_k();
                                }|
                                expression_statement {
                                    increase_k();
                                }|
                                selection_statement {
                                    increase_k();
                                }|
                                iteration_statement {
                                    increase_k();
                                }|
                                jump_statement {
                                    increase_k();
                                };

labeled_statement:              ID ':' statement {
                                    increase_k();
                                }|
                                CASE constant_expression ':' statement {
                                    increase_k();
                                }|
                                DEFAULT ':' statement {
                                    increase_k();
                                };

compound_statement:             '{' '}' {
                                    increase_k();
                                }|
                                '{' block_item_list '}' {
                                    $$ = $2;
                                    increase_k();
                                };

block_item_list:                block_item {
                                    increase_k();
                                    $$ = $1;
                                    Q_arr.backpatch($1->nextlist, Q_arr.index);
                                }|
                                block_item_list M block_item {
                                    $$ = new exp_attr;
                                    $$->nextlist = $3->nextlist;
                                    Q_arr.backpatch($1->nextlist, $2->instr);
                                    increase_k();
                                };

block_item:                     declaration {
                                    increase_k();
                                    $$ = new exp_attr;
                                }|
                                statement {
                                    increase_k();
                                };

expression_statement:           expression_opt ';'{
                                    $$ = $1;
                                    increase_k();
                                };

expression_opt:                 expression {
                                    $$ = $1;
                                    increase_k();
                                }|
                                /*Epslion*/ {
                                    $$ = new exp_attr;
                                };

selection_statement:            IF '(' expression N ')' M statement N ELSE M statement N {
                                    $$ = new exp_attr;
                                    Q_arr.backpatch($4->nextlist , Q_arr.index);
                                    Q_arr.convInt2Bool($3);
                                    increase_k();
                                    $$->nextlist = merge($7->nextlist, $8->nextlist);
                                    Q_arr.backpatch($3->truelist, $6->instr);
                                    Q_arr.backpatch($3->falselist, $10->instr);
                                    $$->nextlist = merge($$->nextlist, $11->nextlist);
                                    $$->nextlist = merge($$->nextlist, $12->nextlist);
                                    increase_k();
                                }|
                                IF '(' expression N ')' M statement N {
                                    $$ = new exp_attr;
                                    increase_k();
                                    Q_arr.backpatch($4->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($3);
                                    increase_k();
                                    Q_arr.backpatch($3->truelist, $6->instr);
                                    increase_k();
                                    $$->nextlist = merge($8->nextlist, $7->nextlist);
                                    $$->nextlist = merge($$->nextlist, $3->falselist);
                                }|
                                SWITCH '(' expression ')' statement {
                                    increase_k();
                                };

iteration_statement:            WHILE M '('  expression N ')' M statement {
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),$2->instr);
                                    increase_k();
                                    Q_arr.backpatch($5->nextlist,Q_arr.index);
                                    Q_arr.convInt2Bool($4);
                                    increase_k();
                                    $$ = new exp_attr;
                                    Q_arr.backpatch($8->nextlist, $2->instr);
                                    Q_arr.backpatch($4->truelist, $7->instr);
                                    $$->nextlist = $4->falselist;
                                }|
                                DO M statement M WHILE '(' expression ')' ';' {
                                    $$ = new exp_attr;
                                    Q_arr.convInt2Bool($7);
                                    Q_arr.backpatch($3->nextlist, $4->instr);
                                    Q_arr.backpatch($7->truelist, $2->instr);
                                    $$->nextlist = $7->falselist;
                                    increase_k();
                                }|
                                FOR '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement {
                                    $$ = new exp_attr;
                                    increase_k();
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),$9->instr);
                                    Q_arr.backpatch($7->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($6);
                                    increase_k();
                                    Q_arr.backpatch($11->nextlist,$5->instr);
                                    Q_arr.backpatch($6->truelist,$13->instr);
                                    Q_arr.backpatch($14->nextlist,$9->instr);
                                    increase_k();
                                    $$->nextlist = $6->falselist;
                                }|
                                FOR '(' declaration expression_opt ';' expression_opt ')' statement {
                                    // Not to be produced, as per assignment
                                };

jump_statement:                 GOTO_KEYWORD ID ';' {
                                    increase_k();
                                }|
                                CONTINUE ';' {
                                    increase_k();
                                }|
                                BREAK ';' {
                                    increase_k();
                                }|
                                RETURN_KEYWORD ';' {
                                    increase_k();
                                    $$ = new exp_attr;
                                    if(curr_sym->lookup("retVal")->type.type_name.compare("void")==0)
                                    {
                                        increase_k();
                                        Q_arr.emit(RETURN_VOID,"","","");
                                    }
                                }|
                                RETURN_KEYWORD expression ';' {
                                    $$ = new exp_attr;
                                    increase_k();
                                    type_inf type1, type2, type3;
                                    type1 = curr_sym->lookup("retVal")->type;
                                    type2 = curr_sym->lookup($2->loc)->type;
                                    for(int i=0; i<sym->no_of_entries;i++)
                                	{
                                        increase_k();
                                		if(sym->sym_table[i].id.compare($2->loc)==0)
                                			type3 = sym->sym_table[i].type;
                                	}
                                	if(type3.type_name.compare("function")==0)
                                	{
                                        increase_k();
                                		string t = curr_sym->gentemp(type1);
                                		Q_arr.emit(COPY, t, $2->loc, "");
                                		Q_arr.emit(RETURN,t,"","");
                                	}
                                	else if(type1.type_name == type2.type_name)
                                    {
                                        increase_k();
                                        Q_arr.emit(RETURN, $2->loc, "", "");
                                    }
                                };

/*External Definitions*/
translation_unit:               external_declaration {
                                    increase_k();
                                }|
                                translation_unit external_declaration {
                                    increase_k();
                                };

external_declaration:           function_definition {
                                    increase_k();
                                }|
                                declaration {
                                    increase_k();
                                };

function_definition:            declaration_specifiers declarator declaration_list compound_statement{
                                    increase_k();
                                }
                                | declaration_specifiers declarator compound_statement
                                {
                                    increase_k();
                                    declaration *new_dec = $2;
                                    int size = 0;
                                    type_inf *type = $1;
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("float")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    if(type->type_name.compare("void")==0) size = 0;
                                    symboltable *gt = &GT;
                                    Q_arr.emit(_FUNCTION_END,new_dec->dec_name,"","");
                                    symtab *func = gt->lookup($2->dec_name);
                                    if(func->nested_table != NULL)
                                    {
                                        increase_k();
                                        if($2->pointer_count>0)
                                            type->pointer_type = "ptr";
                                        symtab *ret = func->nested_table->lookup("retVal", type->type_name, $2->pointer_count);
                                        increase_k();
                                        if($2->pointer_count>0)
                                        {
                                            increase_k();
                                            ret->pointer_count = $2->pointer_count;
                                            ret->type.pointer_type = "ptr";
                                        }
                                        ret->offset = curr_sym->offset;
                                        ret->size = size;
                                        ret->init_val = NULL;
                                    }
                                    curr_sym = gt;
                                    $$ = $2;
                                };

declaration_list:               declaration {
                                }|
                                declaration_list declaration {
                                };

%%

void yyerror(string s){
    cout << "ERROR OCCURED : " << s << endl;
}
