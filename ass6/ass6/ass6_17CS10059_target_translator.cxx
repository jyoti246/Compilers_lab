#include "ass6_17CS10059_translator.h"

extern Quad_Array Q_arr;
extern symboltable GT;
extern symboltable *sym;
extern symboltable *curr_sym;
extern type_inf *global_type;
extern int global_width;
extern vector<string> string_lits;
extern int yyparse();

int global_call_to_assembly = 0;

void create_calling_assembly(){
		global_call_to_assembly++;
}

void Code_Generator:: handle_strings()
{
		create_calling_assembly();
	  int global_string_count = 0;
    cout<<"\t.section\t.rodata\n";
    for(vector<string>::iterator it = string_lits.begin(); it != string_lits.end(); it++)
    {
				create_calling_assembly();
        cout<<global_string_start<<global_string_count++<<":\n";
        cout<<"\t.string "<<*it<<"\n";
    }
		create_calling_assembly();
}
void Code_Generator:: create_Function_Prologue()
{
		create_calling_assembly();
    stack_req = ((stack_size>>4)+1)<<4; //align with word boundary
    cout<<"\t.globl\t"<<function_name<<"\n";	//create a global function
    cout<<"\t.type\t"<<function_name<<", @function\n";	//declare that the function is a function
    cout<<function_name<<":\n";
    cout<<"\tpushq\t%rbp\n";
    cout<<"\tmovq\t%rsp, %rbp\n";
    cout<<"\tsubq\t$"<<stack_req<<",\t%rsp\n";	//allocate stack for local variables
		create_calling_assembly();
}

void Code_Generator:: create_Function_Epilogue()
{
		create_calling_assembly();
    cout << "\t" << "ret"<<endl;
		create_calling_assembly();
}

void Code_Generator:: handle_Globals()
{
		create_calling_assembly();
    symtab *p;
    int i;
    for(i = 0 ; i < (&GT)->no_of_entries; i++)
    {
        if((&GT)->sym_table[i].id[0] != 't')
        {
            //handle chars
            if((&GT)->sym_table[i].type.type_name.compare("char")==0)
            {
								create_calling_assembly();
                if((&GT)->sym_table[i].init_val == NULL)
                    cout<<"\t.comm\t"<<(&GT)->sym_table[i].id<<",1,1\n";
                else
                {
										create_calling_assembly();
                    cout << "\t.globl\t"<<(&GT)->sym_table[i].id<<"\n";
                    cout << "\t.data"<<endl;
                    cout << "\t.type\t"<<(&GT)->sym_table[i].id<<", @object"<<"\n";
                    cout << "\t.size\t"<<(&GT)->sym_table[i].id<<", 1"<<"\n";
                    cout << (&GT)->sym_table[i].id<< ":" << "\n";
                    cout << "\t.byte\t"<<(&GT)->sym_table[i].init_val->int_val<<"\n";
                }
            }
		  		if((&GT)->sym_table[i].type.type_name.compare("int")==0)
            {
								create_calling_assembly();
                if((&GT)->sym_table[i].init_val == NULL)
                    cout<<"\t.comm\t"<<(&GT)->sym_table[i].id<<",4,4\n";
                else
                {
										create_calling_assembly();
                    cout << "\t.globl\t"<<(&GT)->sym_table[i].id<<"\n";
                    cout << "\t.data"<<endl;
                    cout << "\t.align 4"<<endl;
                    cout << "\t.type\t"<<(&GT)->sym_table[i].id<<", @object"<<"\n";
                    cout << "\t.size\t"<<(&GT)->sym_table[i].id<<", 4"<<"\n";
                    cout << (&GT)->sym_table[i].id<< ":" << "\n";
                    cout << "\t.long\t"<<(&GT)->sym_table[i].init_val->int_val<<"\n";
										create_calling_assembly();
								}
            }
						create_calling_assembly();
        }

    }
}

string Code_Generator:: generate_GOTO_Labels()
{
    string t = ".L";
		create_calling_assembly();
    t = t + to_string(goto_label_count);
    goto_label_count++;
    return t;
		create_calling_assembly();
}

void Code_Generator:: set_GOTO_Labels_target()
{
		create_calling_assembly();
    for(vector<Quad>::iterator it = Q_arr.arr.begin(); it != Q_arr.arr.end(); it++)
    {
				create_calling_assembly();
        if(it->op >= IF_LESS && it->op <= GOTO)
        {
						create_calling_assembly();
            int backpatch_result = atoi(((*it).result).c_str());
            if(generate_goto.count(backpatch_result)==0)
            {
								create_calling_assembly();
                string label = generate_GOTO_Labels();
                generate_goto[backpatch_result] = label;
            }
						create_calling_assembly();
            (*it).result = generate_goto[backpatch_result];
        }
    }
}
void Code_Generator:: Map_TAC_to_Assembly()
{
		create_calling_assembly();
    int arg1_binding, arg2_binding, result_binding;
    arg1_binding = arg2_binding = result_binding = 0;   //make quad argument bindings
		create_calling_assembly();
    symtab *global_arg1, *global_arg2, *global_result;
		create_calling_assembly();
    symtab* curr_arg1 ;
    curr_arg1 = curr_sym->lookup(current_quad.arg_1);
    symtab* curr_arg2 ;
		create_calling_assembly();
    curr_arg2= curr_sym->lookup(current_quad.arg_2);
    symtab* curr_result;
		create_calling_assembly();
    curr_result = curr_sym->lookup(current_quad.result); //All are present in symboltable, so lookup will handle it fine
		create_calling_assembly();
    global_arg1 = NULL;
    global_arg2 = NULL;
    global_result = NULL;
		create_calling_assembly();
    for(int j = 0; j < (&GT)->no_of_entries; j++)
    {
				create_calling_assembly();
        if((&GT)->sym_table[j].id.compare(current_quad.arg_1)==0)
            global_arg1 = &((&GT)->sym_table[j]);
				create_calling_assembly();
    }

    for(int j = 0; j < (&GT)->no_of_entries; j++)
    {
				create_calling_assembly();
        if((&GT)->sym_table[j].id.compare(current_quad.arg_2)==0)
            global_arg2 = &((&GT)->sym_table[j]);
				create_calling_assembly();
		}

    for(int j = 0; j < (&GT)->no_of_entries; j++)
    {
				create_calling_assembly();
        if((&GT)->sym_table[j].id.compare(current_quad.result)==0)
            global_result = &((&GT)->sym_table[j]);
        else
        global_result = NULL;
				create_calling_assembly();
    }
		create_calling_assembly();
    string generator_arg1 = empty_string;
    string generator_arg2 = empty_string;
    string generator_result = empty_string;
    if(current_quad.result[0] <= '0' || current_quad.result[0] >= '9')
    {
				create_calling_assembly();
        if(global_result == NULL)
        {
						create_calling_assembly();
            result_binding = curr_result->offset;
	      		string bind = to_string(result_binding);
	          generator_result = bind + "(%rbp)";
        }
        else
            generator_result = current_quad.result;
    }
    if(current_quad.arg_1[0] <= '0' || current_quad.arg_1[0] >= '9')
    {
				create_calling_assembly();
        if(global_arg1 == NULL)
        {
						create_calling_assembly();
            arg1_binding = curr_arg1->offset;
	    			string bind = to_string(arg1_binding);
            generator_arg1 = bind + "(%rbp)";
						create_calling_assembly();
        }
        else
				{
					create_calling_assembly();
			    if(global_arg1->type.type_name.compare("function")==0)
			    {
						create_calling_assembly();
						func_type = 1;		//handle functions, particularly the library functions which were created
			    }
	    		else
          {
						create_calling_assembly();
						generator_arg1 = current_quad.arg_1;
					}
				}
    }

        if(current_quad.arg_2[0] <= '0' || current_quad.arg_2[0] >= '9')
        {
					create_calling_assembly();
	        if(global_arg2 == NULL)
	        {
	            arg2_binding = curr_arg2->offset;
		    			string bind = to_string(arg2_binding);
	            generator_arg2 = bind + "(%rbp)";
							create_calling_assembly();
					}
	        else
					{
							create_calling_assembly();
		    			generator_arg2 = current_quad.arg_2;
					}
			}

		if(current_quad.op == UNARY_MINUS)
    	{
				create_calling_assembly();
        cout << "\t" << "movq" << "\t" <<generator_arg1<< ",\t%rax" << endl;
        cout << "\t" << "negq\t %rax"<< endl;
        cout << "\t" << "movq" << "\t" << "%rax,\t" << generator_result << "\t"  << endl;
				create_calling_assembly();
		}

    else if(current_quad.op == COPY)
    {
			create_calling_assembly();
			if(func_type==1)
			{
					create_calling_assembly();
					cout<<"\tmovl\t%eax,\t"<<generator_result<<endl;
			    func_type = 0;
			}
			else
			{
				create_calling_assembly();
				if(current_quad.arg_1[0]>='0' && current_quad.arg_1[0]<='9')
				{
						create_calling_assembly();
				    cout<<"\tmovl\t$"<<current_quad.arg_1<<",\t"<<generator_result<<"\n";
				}
				else
				{
						create_calling_assembly();
				    cout<<"\tmovl\t"<<generator_arg1<<",\t%eax\n";
				    cout<<"\tmovl\t"<<"%eax,\t"<<generator_result<<"\n";
				}
			}
    }
    else if(current_quad.op == PLUS)
    {
				create_calling_assembly();
        if((current_quad.arg_2.compare("1"))==0)
        {
						create_calling_assembly();
            cout<< "\tmovl\t" <<generator_arg1<<",\t%edx\n";
            cout<< "\taddl\t$1,\t%edx\n";
            cout<< "\tmovl\t%edx,\t%eax\n";
            cout<< "\tmovl\t%eax,\t"<< generator_result<<"\n";
						create_calling_assembly();
				}
        else
        {
						create_calling_assembly();
            cout<<"\tmovl\t" <<generator_arg1<<",\t%edx\n";
            if(current_quad.arg_2[0]>='0' && current_quad.arg_2[0]<='9')
                cout<<"\tmovl\t$" <<current_quad.arg_2<<",\t%eax\n";
            else
                cout << "\tmovl\t" <<generator_arg2 << ",\t%eax\n";
            cout<<"\taddl\t %edx,\t%eax\n";
            cout<<"\tmovl\t %eax,\t"<<generator_result<<"\n";
						create_calling_assembly();
				}
    }

    else if(current_quad.op == MINUS)
    {
        if((current_quad.arg_2).compare("1")==0)
        {
						create_calling_assembly();
	          cout << "\tmovl\t" <<generator_arg1<< ",\t%edx\n";
            cout << "\tsubl\t$1,\t %edx\n";
            cout << "\tmovl\t %edx,\t %eax\n";
            cout << "\tmovl \t %eax,\t"  << generator_result<< "\n";
						create_calling_assembly();
				}
        else
        {
            //result = a - b
						create_calling_assembly();
            cout<< "\tmovl\t" <<generator_arg1<< ",\t%edx\n";
            cout<< "\tmovl\t" <<generator_arg2 << ",\t%eax\n";
            cout<< "\tsubl\t%eax,\t%edx\n";
            cout<< "\tmovl\t%edx,\t%eax\n";
            cout<< "\tmovl \t%eax,\t" << generator_result<<"\n";
        }
    }

    else if(current_quad.op==MULT)
    {
				create_calling_assembly();
        cout<< "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        if(current_quad.arg_2[0]>='0' && current_quad.arg_2[0]<='9')
            cout<< "\timull\t$" << current_quad.arg_2 << ",%eax\n";
        else
        {
            cout<< "\timull\t" <<generator_arg2 << ",%eax\n";
        }
        cout<< "\tmovl\t%eax,\t"<< generator_result<< "\n";
				create_calling_assembly();
    }

    else if(current_quad.op==DIVIDE)
    {
				create_calling_assembly();
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        cout << "\tmovl\t%eax,\t" << generator_result<< "\n";
				create_calling_assembly();
    }
    else if(current_quad.op==MODULO)
    {
				create_calling_assembly();
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        cout << "\tmovl\t%edx,\t"  << generator_result << "\n";
				create_calling_assembly();
    }
    else if(current_quad.op==IF_LESS)
    {
				create_calling_assembly();
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tjge\t.L" << goto_label_count <<"\n";
        cout << "\tjmp\t" <<current_quad.result <<"\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;
				create_calling_assembly();
    }
    else if(current_quad.op==IF_GREATER)
    {
        //  if a > b goto .L1
				create_calling_assembly();
				cout<< "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout<< "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
				//jump on less
				create_calling_assembly();
        cout<< "\tjle\t.L" << goto_label_count << "\n";
        cout<< "\tjmp\t" <<current_quad.result << "\n";
        cout<< ".L"<< goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;
				create_calling_assembly();
    }

    else if(current_quad.op==IF_IS_EQUAL)
    {
        //  if a == b goto L1
				create_calling_assembly();
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tjne\t.L" << goto_label_count << "\n";
        cout << "\tjmp\t" <<current_quad.result << "\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;
				create_calling_assembly();
    }

    else if(current_quad.op==IF_NOT_EQUAL)
    {
        //  if a != b goto .L1
				create_calling_assembly();
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tje\t.L" << goto_label_count << "\n";
        cout << "\tjmp\t" <<current_quad.result << "\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;
				create_calling_assembly();
    }

    else if(current_quad.op==IF_NOT_EXPRESSION)
    {
				create_calling_assembly();
				//if a==0 goto .L1
        cout<< "\tcmpl\t$0,\t"<<generator_arg1<< "\n";
        cout<< "\tjne\t.L"<< goto_label_count<<"\n";
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        cout<< ".L"<<goto_label_count<<" : \n";
        goto_label_count = goto_label_count + 1;
				create_calling_assembly();
		}
    else if(current_quad.op==IF_EXPRESSION)
    {
				//if a!= 0 goto .L1
				create_calling_assembly();
				cout<< "\tcmpl\t$0,\t"<<generator_arg1<< endl;
        cout<< "\tje\t.L"<< goto_label_count<<endl;
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        cout<< ".L" <<goto_label_count<<" : \n" ;
        goto_label_count++;
				create_calling_assembly();
    }
    else if(current_quad.op==GOTO)
    {
				create_calling_assembly();
        //goto .L1
        cout<<"\tjmp\t" <<current_quad.result<<"\n";
    }
    else if(current_quad.op == PARAM)
    {
				create_calling_assembly();
	      if(next_quad.result.compare("printInt")==0 || next_quad.result.compare("printStr")==0 || next_quad.result.compare("readInt")==0)
				{
			    if(current_quad.result[0]=='.')
			    {
						cout<<"\tmovq\t$"<<current_quad.result<<",\t%rdi\n";
			    }
			    else if(current_quad.result[0]>='0' && current_quad.result[0]<='9')
		            cout<<"\tmovq\t$"<<current_quad.result<<",\t%rdi\n";
          else
                cout<<"\tmovq\t"<<generator_result<<",\t%rdi\n";
          no_of_params++;
			create_calling_assembly();
		}
		else
		{
	     string s;
       std::vector<string> str1;
	     int flag = 0;
	     if(current_quad.result[0]>='0' && current_quad.result[0]<='9')
	     {
	        s = s + "\tmovq\t$" + current_quad.result + ",\t%rax\n";
	     }
	     else{
				 flag = 0;
				 for(int i=0;i<new_sym->no_of_entries;i++)
				 {
		     	if(current_quad.result.compare(new_sym->sym_table[i].id)==0 && new_sym->sym_table[i].type.array_type.compare("array")==0)
		     	{
						create_calling_assembly();
						//flag = 0;
		     		if(result_binding>0)
						{
							s = s + "\tmovq\t" + generator_result + ",\t%rax\n";flag = 1;}
						else
						{
							s = s + "\tleaq\t" + generator_result + ",\t%rax\n";flag = 1;}
		     		}
						create_calling_assembly();
			}
		 if(!flag)
                 	s = s + "\tmovq\t" + generator_result + ",\t%rax\n";
        	 str1.push_back(s);
        	 str1.push_back("\tpushq\t%rax\n");
        	 stack_of_parameters.push(str1);
					 create_calling_assembly();
	    }
	}
}

    else if(current_quad.op==CALL)
    {
			create_calling_assembly();
			if(current_quad.result.compare("printInt")==0 || current_quad.result.compare("printStr")==0 || current_quad.result.compare("readInt")==0)
			{
					 create_calling_assembly();
	   			 int num;
					 create_calling_assembly();
           num = atoi((current_quad.arg_1).c_str());
           num=num*4;
           cout << "\t" << "call\t"<<current_quad.result << endl;
           if(current_quad.arg_2 != "")
               cout << "\t" << "movq\t%rax,\t"<<generator_arg2<< endl;
			}
			else{
				create_calling_assembly();
				int num;
        num = atoi((current_quad.arg_1).c_str());
        num=num*8;
        while(stack_of_parameters.size() > 0)
        {
					create_calling_assembly();
            vector<string> str;
            str = stack_of_parameters.top();
            for(int i = 0; i<str.size(); i++)
            {
							create_calling_assembly();
                cout<<str[i];
            }
						create_calling_assembly();
	    stack_of_parameters.pop();    //pop from stack
        }
				create_calling_assembly();
        cout << "\tcall\t"<<current_quad.result << "\n";
        cout << "\taddq\t$"<<num<<",\t%rsp"<< "\n";
				cout<<"#--"<<current_quad.arg_2<<"\n";
        create_calling_assembly();
			}

    }

    else if(current_quad.op==RETURN)
    {
        if(current_quad.result.compare(empty_string)!=0)
        	cout<<"\tmovq\t"<<generator_result<< ",\t%rax"<< endl;
					cout <<"\tleave\n\tret\n";
	    create_calling_assembly();
			no_of_params = 0;
    }
    else if(current_quad.op==DEREFERENCE)
    {
        // a = *p
				create_calling_assembly();
				cout<<"\tmovq\t"<<generator_arg1<<",\t%rax\n";
        cout<<"\tmovl\t(%rax),\t %ecx\n";
        cout<<"\tmovl\t%ecx,\t"<<generator_result<<"\n";
				create_calling_assembly();
		}

    else if(current_quad.op==REFERENCE)
    {
        //p = &a
				create_calling_assembly();
        cout<<"\tleaq\t"<<generator_arg1<<",\t%rax\n";
        cout<<"\tmovq\t%rax,\t"<<generator_result<<"\n";
				create_calling_assembly();
		}
    else if(current_quad.op==ARRAY_ACCESS)
    {
			create_calling_assembly();
      //b = a[i]
			if(arg1_binding>0)		//required for passing array as parameters
			{
				create_calling_assembly();
				cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
				cout<<"\tmovq\t"<<arg1_binding<<"(%rbp),\t%rdi\n";
				cout<<"\taddq\t%rdi,\t%rdx\n";
				cout<<"\tmovl\t(%rdx),\t%eax\n";
				cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
			}
			else
			{
				create_calling_assembly();
				cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx"<< endl;
				cout<<"\tmovl\t"<<arg1_binding<<"(%rbp,%rdx,1),\t%eax\n";
				cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
			}
			create_calling_assembly();
    }

    else if(current_quad.op==ARRAY_DEREFERENCE)
    {
			create_calling_assembly();
			  //a[i] = b
			if(result_binding>0)		//required for passing array as parameters
			{
				cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
				cout<<"\tmovl\t"<<generator_arg1<<",\t%eax\n";
				cout<<"\tmovq\t"<<result_binding<<"(%rbp),\t%rdi\n";
				cout<<"\taddq\t%rdi,\t%rdx\n";

				cout<<"\tmovl\t%eax,\t(%rdx)\n";
			}
			else{
				create_calling_assembly();
		        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
		        cout<<"\tmovslq\t"<<generator_arg1<<",\t%rax\n";
		        cout<<"\tmovq\t%rax,\t"<<result_binding<<"(%rbp,%rdx,1)\n";
			}
		 }
		 create_calling_assembly();
}

void Code_Generator:: Bind_Memory_Record()
{

    handle_strings();
    handle_Globals();
    set_GOTO_Labels_target();
		create_calling_assembly();
    int quad_size = Q_arr.arr.size();
    for(int i = 0; i < quad_size; i++)
    {
			//print the quads for reference
			cout<<"  # "; Q_arr.arr[i].print();
			create_calling_assembly();
        if(generate_goto.count(i)>0)
        {
            cout<<generate_goto[i]<<":\n";
        }
				create_calling_assembly();
        current_quad = Q_arr.arr[i];	//update current quad
				if(i<quad_size-1)
					next_quad = Q_arr.arr[i+1];	//update next quad
        if(Q_arr.arr[i].op == _FUNCTION_START)
        {
					create_calling_assembly();
            if(Q_arr.arr[i+1].op != _FUNCTION_END)
            {
								ptr_type=0;
								create_calling_assembly();
                symtab *p=NULL;
                for(int j = 0; j < (&GT)->no_of_entries; j++)
                {
										create_calling_assembly();
										if(((&GT)->sym_table[j].id).compare(Q_arr.arr[i].result)==0)
                        p = &((&GT)->sym_table[j]);
                }
								create_calling_assembly();
                function_name = Q_arr.arr[i].result;
                row = p;
								create_calling_assembly();
                create_calling_assembly();
                new_sym = p->nested_table;
                curr_sym = new_sym;
                flag_parameter = 1;
                int total_count;
								create_calling_assembly();
                total_count =  row->type.no_of_params;
                create_calling_assembly();
								for(int j = 0; j < total_count; j++)
								{
								    new_sym->sym_table[j].offset = memory;
								    memory = memory + 8;
								    cout<<"#--param_offset:"<<memory<<"\n";
								}
								create_calling_assembly();
								memory_bind_ebp = 0;
                for(int j = total_count; j < new_sym->no_of_entries; j++)
                {
									create_calling_assembly();
								    if(new_sym->sym_table[j].id.compare("retVal")==0)
								    {
											create_calling_assembly();
								    }
                    if(new_sym->sym_table[j].id.compare("retVal"))
                    {
											create_calling_assembly();
                        memory_bind_ebp = memory_bind_ebp - new_sym->sym_table[j].size;
                        new_sym->sym_table[j].offset = memory_bind_ebp;
												cout<<"#--loacl var offset: "<<new_sym->sym_table[j].size<<" "<<new_sym->sym_table[j].offset<<"\n";
                    }
                }
								create_calling_assembly();
                cout<<"#"<<memory_bind_ebp<<endl;
                stack_size = memory_bind_ebp*(-1) + memory;
								for(int j = 0; j< new_sym->no_of_entries; j++)
								{
									create_calling_assembly();
									if(new_sym->sym_table[j].id.compare(current_quad.result)==0||!new_sym->sym_table[j].id.compare(current_quad.arg_1)==0
						                       ||!new_sym->sym_table[j].id.compare(current_quad.arg_2)==0)
									{
										if(new_sym->sym_table[j].type.pointer_type.compare("ptr")==0)
											ptr_type = 1;
											create_calling_assembly();
										cout<<"##ptr"<<new_sym->sym_table[j].id<<endl;
									}
								}
								create_calling_assembly();
                create_Function_Prologue();
            }
            else
            {
							create_calling_assembly();
                i++;
								no_of_params = 0;
								memory = 16;
								memory_bind_ebp = 0;
                continue;
            }
        }
        else if(Q_arr.arr[i].op == _FUNCTION_END)
        {
					create_calling_assembly();
            sym = &GT;
            curr_sym = &GT;
	    			cout<<"\tleave\n\tret\n";
            cout << "\t.size\t"<<function_name<<",\t.-"<<function_name<<endl;
	    			function_name = "";
            no_of_params = 0;
	    			memory = 16;
	    			memory_bind_ebp = 0;
	    			continue;
        }

        if(function_name.compare(empty_string))
        {
					create_calling_assembly();
            Map_TAC_to_Assembly();
        }
    }
		create_calling_assembly();
}

int main(int argc, char *argv[])
{
    bool failure = yyparse();
    int arr_size = Q_arr.arr.size();
    string output_file = "a.out";
    if(argc==2) output_file = string(argv[1]);
    string quad_file = "ass6_17CS10059_quads" + output_file + ".out";
    ofstream outf1(quad_file.c_str());
    streambuf *coutbuf1 = cout.rdbuf();
    cout.rdbuf(outf1.rdbuf());
    cout<<"********************Printing Quads**********************\n";
	cout<<"--------------------------------------------------------\n";
    cout<<"|                         Quads                        |\n";
    cout<<"--------------------------------------------------------\n";
	int i = 0;
	int j = 0;
    while(i<arr_size)
    {
        if (Q_arr.arr[i].result.length() > 0){
            cout<<j<<" : ";
            Q_arr.arr[i].print();
            j++;
		}
        i++;
    }
	create_calling_assembly();
	cout<<"--------------------------------------------------------------\n";
    cout<<" 									Symbol Table (ST.gbl)											 \n";
	cout<<"--------------------------------------------------------------\n";
	symboltable *g = &GT;
    g->print();
    cout<<"-------------------------------------------------------------\n";
	create_calling_assembly();
    for(int i = 0; i< g->no_of_entries; i++)
    {
        if(g->sym_table[i].nested_table != NULL)
        {
            cout<<"--------------------------------------------------------------\n";
				    cout<<"          Symbol Table of " << g->sym_table[i].id <<"		    \n";
						cout<<"--------------------------------------------------------------\n";
						g->sym_table[i].nested_table->print();
						cout<<"-------------------------------------------------------------\n";
        }
    }
		cout<<"--------------------------------------------------------\n";
    cout<<"|                  Compilation Result                  |\n";
    cout<<"--------------------------------------------------------\n";
    if(failure)
        cout << "Compilation Failure  :-( !!\n";
    else
        cout << "Compilation Success  ^_^ !!\n";
    cout<<"--------------------------------------------------------\n";
		create_calling_assembly();
    cout.rdbuf(coutbuf1);
		create_calling_assembly();
    string tmp = "ass6_17CS10059_" + output_file + ".s";
    ofstream outfile(tmp.c_str());
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());
    curr_sym = sym;
    Code_Generator c;
    c.Bind_Memory_Record();
		create_calling_assembly();
    cout.rdbuf(coutbuf);
    return 0;
}
