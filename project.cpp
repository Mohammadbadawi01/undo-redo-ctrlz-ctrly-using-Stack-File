#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
FILE* save;
int br = 0;

//mohammad badawi 18/4/2021 3 AM

struct stack
{
	void pop();
	void push(string h);
	string top();
	int empty();
private:
	string arr[100];
	int index = 0;

};
void stack::pop()
{
	if (!empty())
	{
		index--;

	}
}
void stack::push(string h)
{
	arr[index] = h;
	index++;
}
string stack::top()
{
	if (empty())
	{
		const char *xx = "x0x0";
		return xx;
	}
	else
	{
		return arr[index - 1];
	}
	
}
int stack::empty()
{
	return (index == 0);
}
void stackPrint(stack s) {
	
	if (s.empty()) { return; }
	string d;
	d = s.top();
	s.pop();
	stackPrint(s);

	const char* f = d.c_str();
	printf(f);
	printf("\n");

}
void stackPrint_in_file(stack s) {
	
	if (s.empty()) { return; }
	if ( br== 0)
	{
		save = fopen("output.txt", "w");
	}
	br++;
	string d = s.top();
	const char* j = d.c_str();
	s.pop();
	stackPrint_in_file(s);
	fputs(j, save);
	fputc('\n', save);
}

int main()
{
	stack my_data;
	stack save_delete;
	string str;
	while (1) {
	
		 printf("\n\033[31mmyCommand >  \033[0m");
		getline(cin, str);
		if (str == "quit") {
			
			printf("\033[32m result >\033[0m");
			printf("Good Bye!\n");
			br = 0;
			stackPrint_in_file(my_data);
			fclose(save);
			break;
		}
		else if (str == "print") {
			printf("\033[32m result >\033[0m");
			if (my_data.empty()) {
				printf("Empty\n");
			}
			else {
				printf("\n\n");
				stackPrint(my_data);
				printf("\n");
			}
		}
		else if (str=="undo") {
			printf("\033[32m result >\033[0m");
			if (my_data.empty())
			{
				printf("\nEmpty\n");
			}
			else
			{
				save_delete.push(my_data.top());
				my_data.pop();
				printf("\n\n");
				stackPrint(my_data);
			}
		}
		else if (str=="redo") {
			printf("\033[32m result >\033[0m");
			if (save_delete.empty())
			{
				printf("\nno data to redo\n");
			}
			else
			{
				my_data.push(save_delete.top());
				save_delete.pop();
				printf("\n\n");
				stackPrint(my_data);
			}
		}
		else if(str=="save")
		{
			printf("\033[32m result >\033[0m");
			if (my_data.empty()) { printf( "\nEmpty\n"); }
			else
			{
				 printf("\ndone save\n\n");
				 br = 0;
				 stackPrint_in_file(my_data);
				 fclose(save);
			}
		}
		else {

			my_data.push(str);
		}
	}
	
}
