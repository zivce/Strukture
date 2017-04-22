#include "QueueAsArr.h"
#include "StekInt.h"
#include "StaticStack.h"
#include "StackLL.h"
#include "DQArr.h"


#include <string>
using namespace std;
void checkStatement(string a)
{
	Stek t(a.length());
	//najgori slucaj da su svi iz
	//azbuke {(,),{,},*,/,[,]}
	int i = 0;
	while (i < a.length())
	{
		if (a[i] == '(' || a[i] == '{'
			|| a[i] == '[')
		{
			t.push(a[i]);
		}
		else if (a[i] == '/' &&
			a[i + 1] == '*')
		{
			t.push(a[i]);
			
		}
		else if (a[i] == ')')
		{
			if (t.topElem() == '(')
			{
				t.pop(); i++;
				continue;
			}
			else {
				throw (i + 1);
			}

		}
		else if (a[i] == ']')
		{
			if (t.topElem() == '[')
			{
				t.pop(); i++;
				continue;
			}
			else {
				throw (i + 1);
			}
		}
		else if (a[i] == '}')
		{

			if (t.topElem() == '{')
			{
				t.pop();
				i++;
				continue;
			}
			else {
				throw (i + 1);
			}
		}

		else if (a[i] == '*' &&
			a[i + 1] == '/')
		{
			if (t.topElem() == '/')
			{
				t.pop(); i++;
				continue;
			}
			else {
				throw (i + 1);
			}
		}

		i++;
	}

	if (t.isEmpty())
		cout << "OK\n";
	else
		cout <<	"unmatched> " <<(char)t.topElem() << "\n";


}
int doTheMath(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
	else if (c == '/')
	{
		if (a == 0)
			throw "undefined";

		return b / a;
	}
	else
		cout << "undefined";
	return 0;
}

string addLarge(string a, string b)
{
	StekLL* stekA = new StekLL();
	StekLL* stekB = new StekLL();
	StekLL* stekRes = new StekLL();
	int carry = 0;

	//napunimo oba steka
	int i = 0;
	while (a[i] != '\0')
	{
		int cifra = a[i] - '0';
		stekA->addToHead(cifra);
		i++;
	}

	i = 0;
	while (b[i] != '\0')
	{
		int cifra = b[i] - '0';
		stekB->addToHead(cifra);
		i++;
	}

	while(!stekA->isEmpty() || !stekB->isEmpty())
	{ 

		int result = 
			stekA->deleteFromHead() 
			+ stekB->deleteFromHead()
			+ carry;

		carry = result / 10;//nosi carry tj 1 
		result = result % 10;

		stekRes->addToHead(result);
	
	}
	string res = "";
	while(!stekRes->isEmpty())
	{
		res += stekRes->deleteFromHead()+'0';
	}

	return res;
}

int calcPostfix(string a)
{
	StekI tmp(a.length());
	int i = 0;
	int op1 = 0;
	int op2 = 0;
	int res = 0;

	while (a[i] != '\0')
	{
		
		if (a[i] > '0' && a[i] < '9')
		{
			int cifraStek = a[i] - '0';

			//prev da li je cifra na steku
			//multidigit

			if (!tmp.isEmpty() && a[i-1]!=' ')
			{
				cifraStek = tmp.pop();
				cifraStek *= 10;
				cifraStek += a[i]-'0';

			}


			tmp.push(cifraStek);
			i++;
			continue;
		}
		else if (a[i] == '/' || a[i] == '+'
			|| a[i] == '*' || a[i] == '-')
		{
			op1 = tmp.pop();
			op2 = tmp.pop();
			tmp.push(doTheMath(op1,op2,a[i])); 
			i++;
			continue;
		}
		
		
		//ostali karakteri!
		i++;
	}


	return tmp.pop();
	
}

int calcPrefix(string a) {
	StekI tmp(a.length());

	int i = a.length() - 1;
	int op1 = 0;
	int op2 = 0;
	int res = 0;
	while (i >= 0)
	{
		if (a[i] > '0' && a[i] < '9')
		{
			int cifraStek = a[i] - '0';

			if (!tmp.isEmpty() && a[i + 1] != ' ')
			{
				cifraStek *= 10;
				cifraStek += tmp.pop();

			}
			tmp.push(cifraStek);
			i--;
			continue;
		}
		else if(a[i] == '+' || a[i] == '-' || 
			a[i] == '*' || a[i] == '/')
		{
			op1 = tmp.pop();
			op2 = tmp.pop();
			tmp.push(doTheMath(op1, op2, a[i]));
			i--;
			continue;
		}
		//ostali karakteri!
		i--;
	}


	return tmp.pop();



	}
/*
+ Deo za infix 2 postfix
*/
bool isOperator(char ch)
{//is it operator or not!
	return (
		ch == '^'
		|| ch == '+'
		|| ch == '-'
		|| ch == '*'
		|| ch == '/');
}


int opPriority(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '^')
		return 3;


}



string infix2postfix(string a)
{
	Stek tmp(a.length());

	string postfix = "";
	int i = 0;
	while (i < a.length())
	{
		if (a[i] == '(')

			tmp.push(a[i]);

		else if (isOperator(a[i]))
		{
			while (!tmp.isEmpty() && tmp.topElem() != '('
				&& opPriority(tmp.topElem()) > opPriority(a[i]))
			{
				//ako top ima veci prioritet izbaci sve do prve (
				postfix += tmp.topElem();
				tmp.pop();
			}
			
			tmp.push(a[i]);
		}
		else if (a[i] == ')')
		{
			while (!tmp.isEmpty() && tmp.topElem() != '(')
			{
				postfix += tmp.topElem();
				tmp.pop();
			}

			tmp.pop();
		}
		else if (a[i] == ';')
		{

			while (!tmp.isEmpty())
			{
				postfix += tmp.pop();
			}

		}
		else 
		{//operand
			postfix += a[i];
		}
		
		
		i++;

	}//end expression
	return postfix;
}

void main()
{
	try{
/*
	QAsArr t(10);
	t.enq(10);
	t.deq();
	t.enq(5);
	t.enq(10);
	t.enq(9); 
	t.enq(11);
	t.enq(53); 
	t.enq(4);
	cout <<"\n" << t << "\n";
	t.enq(6);
	t.enq(20);
	t.enq(32);
	cout <<"\n"<< t << "\n";
	t.deq();
	t.deq();
	cout << "\n"<<t  <<"\n";
	t.enq(40);
	t.enq(8);
	cout << t << " ";
	cout << t.getNumOfElems();
		checkStatement("(({a}k)t)/*+()");
		cout << addLarge("3232", "454111");
		cout << calcPostfix("5 6 + 7 * 11 /"); //==7
		cout << calcPrefix("/ 11 * 7 + 5 6"); // ==7
		cout << infix2postfix("((a+b)^c)/d;");
		*/

		DeqAsArr t(5);

		t.enq(4);
		t.enq(5);
		t.enqHead(3);
		t.enqHead(44);
		t.deqTail();
		cout << t;

		t.enq(3);

		//ne treba da se izvrsi!
		t.enqHead(2);

		cout << t;


	}
	catch (int a)
	{
		cout << "error at" << a;
	}

	catch (char* p)
	{
		cout << p;
	}
}