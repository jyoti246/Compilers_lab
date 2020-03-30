#include "ass6_17CS10059_translator.h"
#include <bits/stdc++.h>
using namespace std;
#include "y.tab.h"

void increment(int &a){
	a = a + 1;
	return ;
}
int emits = 0;
int backpatches = 0;
int temp_var = 0;

void assign_op(Quad &q, opcodeType op){
	q.op = op;
}

void assign_result(Quad &q, string result){
	q.result = result;
}

void assign_arg1(Quad &q, string arg1){
	q.arg_1 = arg1;
}

void assign_arg2(Quad &q, string arg2){
	q.arg_2 = arg2;
}


void Quad_Array :: emit(opcodeType op, string result, string arg_1, string arg_2)
{
	Quad q;
	assign_op(q, op);
	assign_result(q, result);
	assign_arg1(q, arg_1);
	assign_arg2(q, arg_2);
	//pushback the quad q to the array of quads ,vector actually
	arr.push_back(q);
	//after emit gets completed, increment global quad_array index pointer
	increment(index);
}

void Quad_Array :: emit(opcodeType op, string result, int num)
{
	Quad q;
	assign_op(q, op);
	assign_result(q, result);
	string s = to_string(num);
	assign_arg1(q, s);
	arr.push_back(q);
	increment(index);
}

void Quad_Array :: emit(opcodeType op, string result, float float_num)
{
	Quad q;
	assign_op(q, op);
	assign_result(q, result);
	string s = to_string(float_num);
	assign_arg1(q, s);
	arr.push_back(q);
	increment(index);
}

void Quad_Array :: emit(opcodeType op, string result, char char_const)
{
	Quad q;
	assign_op(q, op);
	assign_result(q, result);
	string s = "";
	s = s + char_const;
	assign_arg1(q, s);
	arr.push_back(q);
	increment(index);
}

void Quad_Array :: backpatch(list<int> bp_list, int i)
{
	string s = to_string(i);
	increment(backpatches);
	for(int it : bp_list)
	{
		arr[it].result = s;
	}
}

/*
Functions for converting types .
We change e2 to e1.
*/

void Quad_Array :: convI2F(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name == "float")
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "float";
		increment(emits);
		emit(I2F, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convI2C(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name == "char")
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "char";
		increment(emits);
		emit(I2C, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convC2F(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name == "float")
		return;
	else
	{
		e1 = e2;
		increment(emits);
		e1->type.type_name = "float";
		emit(C2F, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convC2I(exp_attr *e1, exp_attr *e2)
{
	if(e2->type.type_name == "int")
		return;
	else
	{
		e1 = e2;
		increment(emits);
		e1->type.type_name = "int";
		emit(C2I, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convF2I(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name == "int")
		return;
	else
	{
		e1 = e2;
		increment(emits);
		e1->type.type_name = "int";
		emit(F2I, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convF2C(exp_attr * e1, exp_attr *e2)
{
	if(e2->type.type_name == "char")
		return;
	else
	{
		e1 = e2;
		e1->type.type_name = "char";
		increment(emits);
		emit(F2C, e1->loc, e2->loc, "");
	}
}

void Quad_Array :: convInt2Bool(exp_attr *exp)
{
	type_inf bool_type;
	bool_type.type_name = "bool";
	if(exp->type.type_name == "bool")
		return;
	if(exp->type.type_name == "int")
	{
		backpatch(exp->truelist, index);
		backpatch(exp->falselist,index);
		exp->falselist = makelist(index);
		increment(emits);
		emit(IF_NOT_EXPRESSION,"",exp->loc,"");
		exp->truelist = makelist(index);
		increment(emits);
		emit(GOTO,"","","");
	}
	exp->type.type_name = "bool";
}


void Quad :: print()
{

	if(op >= UNARY_PLUS && op <= NOT)
	{
		cout << result << " =";
		switch(op)
		{
			case COMPLEMENT:
				cout << " ";
				cout<<"~";
				break;
			case NOT:
				cout << " ";
				cout<<"!";
				break;
			case UNARY_PLUS:
				cout << " ";
				cout<<"+";
				break;
			case UNARY_MINUS:
				cout << " ";
				cout<<"-";
				break;
		}
		cout << arg_1 << endl;
	}
	if(op >= IF_LESS && op <= IF_NOT_EXPRESSION)
	{
		cout<<"if "<<arg_1;
		switch(op)
		{
			case IF_LESS:
				cout << " ";
				cout<<"< ";
				break;

			case IF_GREATER:
				cout << " ";
				cout<<"> ";
				break;
			case IF_LESS_EQUAL:
				cout << " ";
				cout<<"<= ";
				break;
			case IF_GREATER_EQUAL:
				cout << " ";
				cout<<">= ";
				break;
			case IF_IS_EQUAL:
				cout << " ";
				cout<<"== ";
				break;
			case IF_NOT_EQUAL:
				cout << " ";
				cout<<"!= ";
				break;
			case IF_EXPRESSION:
				cout << " ";
				cout<<"!= 0 ";
				break;
			case IF_NOT_EXPRESSION:
				cout << " ";
				cout<<"== 0 ";
				break;
		}
		cout << arg_2 << " goto " << result << endl;
	}
	if(op >= PLUS && op <=GREATER_EQUAL)
	{
		if(result.compare("") == 0)
			cout << arg_1;
		else
			cout << result << " = " << arg_1;

		switch(op)
		{
        case PLUS:
			cout << " ";
			cout << "+";
			break;
        case MINUS:
        	cout << " ";
			cout << "-";
			break;
        case MULT:
        	cout << " ";
			cout << "*";
			break;
        case DIVIDE:
			cout << " ";
			cout<<"/";
			break;
		case AND:
			cout << " ";
			cout<<"&";
			break;
        case MODULO:
			cout << " ";
			cout<<"%";
			break;
        case SHIFT_LEFT:
        	cout << " ";
			cout<<"<<";
			break;
        case SHIFT_RIGHT:
        	cout << " ";
			cout<<">>";
			break;
        case XOR:
        	cout << " ";
			cout<<"^";
			break;
        case OR:
        	cout << " ";
			cout<<"|";
			break;
        case LOGICAL_AND:
        	cout << " ";
			cout<<"&&";
			break;
        case LOGICAL_OR:
        	cout << " ";
			cout<<"||";
			break;
        case LESS:
			cout << " ";
			cout<<"<";
			break;
        case GREATER:
			cout << " ";
			cout<<">";
			break;
        case IS_EQUAL:
			cout<<"==";
			cout << " ";
			break;
        case NOT_EQUAL:
			cout<<"!=";
			cout << " ";
			break;
        case LESS_EQUAL:
			cout<<"<=";
			cout << " ";
			break;
        case GREATER_EQUAL:
			cout<<">=";
			cout << " ";
			break;
		}
		cout << " " << arg_2 << endl;
	}
	if (op >= C2I && op <= F2I)
	{
		cout<<result<<" =";
		switch(op)
		{
			case C2I :
				cout << " ";
				cout<<" Char2Int(" <<arg_1<<")" <<endl;
				break;
            case C2F :
            	cout << " ";
            	cout<<" Char2Float(" <<arg_1<<")" <<endl;
            	break;
            case I2C :
            	cout << " ";
            	cout<<" Int2Char("<<arg_1<<")"<<endl;
            	break;
            case F2C :
            	cout << " ";
            	cout<<" Float2Char("<<arg_1<<")"<<endl;
            	break;
            case I2F :
            	cout << " ";
            	cout<<" Int2Float("<<arg_1<<")"<<endl;
            	break;
            case F2I :
            	cout << " ";
            	cout<<" Float2Int("<<arg_1<<")"<<endl;
            	break;
		}
	}
	if (op == PARAM)
	{
		cout << "";
		cout<<"param "<<result<<"\n";
	}
	if (op == RETURN)
	{
		cout << "";
		cout<<"return "<<result<<"\n";
	}
	if (op == RETURN_VOID)
	{
		cout << "";
		cout<<"return\n";
	}
	if (op == _FUNCTION_START)
	{
		cout << "";
		cout<<"function "<<result<<" start\n";
	}
	if (op == _FUNCTION_END)
	{
		cout << "";
		cout<<"function "<<result<<" end\n";
	}
	if(op == GOTO)
	{
		cout << "";
		cout<<"goto "<<result<<"\n";
	}
	if (op == COPY)
	{
		cout << "";
		cout<<result<<" = "<<arg_1<<"\n";
	}
	if (op == ARRAY_ACCESS)
	{
		cout << "";
		cout<<result<<" = "<<arg_1<<"["<<arg_2<<"]\n";
	}
	if (op == ARRAY_DEREFERENCE)
	{
		cout << "";
		cout<<result<<"["<<arg_2<<"] = "<<arg_1 << "\n";
	}
	if(op == CALL)
	{
		cout << "";
		cout<<"call "<<result<<" "<<arg_1<<"\n";
	}
}

symtab* symboltable :: lookup(string s, string type, int pc)
{
	symtab *sp = sym_table;
	while (sp < &sym_table[MAX])
	{
		if(!sp->id.empty() && (sp->id == s))
		{
			return sp;
		}
		if(sp->id.empty())
		{
			sp = new symtab;
			sp->id = s;
			//include type
			type_inf t;
			t.type_name = type;
			int t_size = 0;
			if(pc == 0)
			{
    			if(type == "int")
    				t_size = 4;
    			else if(type == "float")
    				t_size = 8;
    			else if(type == "char")
    				t_size = 1;
    			else if((type == "function") || (type == "void"))
    				t_size = 0;
    			t.size = t_size;
    			sp->offset = offset;
    			sp->type = t;
    			sp->size = t_size;
    			sp->nested_table = NULL;
    			offset = offset + t_size;
    			sym_table[no_of_entries] = *sp;
    			increment(no_of_entries);
    			break;
		    }
    		else if (pc > 0)
    		{
					sp->size = 8;
					sp->type.type_name = type;
					cout<<type<<"\n";
					//sp->type.pointer_type = "ptr";

					//sp->type.array_type = "array";
					sp->pointer_count = pc;
					sp->offset = offset;
					sp->init_val = NULL;

					offset += 8;
					sym_table[no_of_entries] = *sp;
					increment(no_of_entries);
					break;
    		}
		}
		sp++;
	}
	return sp;
}

string symboltable :: gentemp(type_inf type)
{
	//maintain counts generated
	static int temporary_count = 0;
	string s = "t";
	s = s + to_string(temporary_count);
	increment(temporary_count);
	sym_table[no_of_entries].id = s;
	sym_table[no_of_entries].type = type;
	int t_size = 0;
	if(type.type_name  == "int")
		t_size = 4;
	else if(type.type_name  == "float")
		t_size = 8;
	else if(type.type_name == "char" )
		t_size = 1;
	else if((type.type_name == "function") || (type.type_name == "void"))
		t_size = 0;

	sym_table[no_of_entries].size = t_size;
	sym_table[no_of_entries].init_val = NULL;
	increment(temp_var);
	sym_table[no_of_entries].offset = offset;
	assert(temp_var == temporary_count);
	sym_table[no_of_entries].nested_table = NULL;
	offset = offset + t_size;
	increment(no_of_entries);
	return s;
}

void symboltable:: print()
{
	int i = 0;
	cout<<"Name\tType\t\tSize\tOffset\nInitVal\t";
	cout<<"---------------------------------------\n";
	while (i < no_of_entries)
	{
		int flag = 0;
		cout<<sym_table[i].id<<"\t";
		if(sym_table[i].pointer_count == 0 && sym_table[i].type.array_type.compare("array")!=0)
		{
			if(sym_table[i].type.type_name == "int")
				cout<<"int\t";
			else if(sym_table[i].type.type_name == "char")
				cout<<"char\t";
			else if(sym_table[i].type.type_name == "float")
				cout<<"float\t";
			else if(sym_table[i].type.type_name == "void")
				cout<<"void\t";
			else if(sym_table[i].type.type_name == "function")
				{cout<<"function\t";cout<<sym_table[i].type.no_of_params<<"\t";}
		}
		else if(sym_table[i].type.pointer_type == "ptr")
		{
			sym_table[i].size = 8;
			for (int j = 0; j < sym_table[i].pointer_count; ++j)
			{
				cout<<"*";
			}
			cout<<"\t";
		}

		else if(sym_table[i].type.array_type == "array")
		{
			cout<<sym_table[i].type.type_name;
			if(sym_table[i].type.idx!=0 && sym_table[i].type.type_name!="")
				{cout<<" ["<<sym_table[i].type.idx<<"]";flag = 1;}
			else
				for (int j = 0; j < sym_table[i].type.array_list.size(); ++j)
				{
					cout<<"["<<sym_table[i].type.array_list[j]<<"]";
				}
			cout<<"\t";
		}
		if(flag)
			{cout<<"\t"<<sym_table[i].size*sym_table[i].type.idx<<"\t";sym_table[i].size = sym_table[i].size*sym_table[i].type.idx;}
		if(!flag)
			cout<<"\t"<<sym_table[i].size<<"\t";
    if(i>=1)
		    sym_table[i].offset = sym_table[i-1].offset + sym_table[i-1].size;
		cout<<sym_table[i].offset<<"\t";

		if(sym_table[i].init_val == NULL)
			cout<<"NULL";
		else
		{
			if(sym_table[i].type.type_name == "int")
			{
				cout<<sym_table[i].init_val->int_val;
			}
			if(sym_table[i].type.type_name == "char")
			{
				cout<<sym_table[i].init_val->char_val;
			}
			if(sym_table[i].type.type_name == "float")
			{
				cout<<sym_table[i].init_val->float_val;
			}
		}
		cout << "\n";
		i++;
	}
}
list<int> makelist(int index)
{
    list<int> temp;
    temp.push_back(index);
    return temp;
}

list<int> merge(list<int> a, list<int> b)
{
    a.merge(b);
    return a;
}
