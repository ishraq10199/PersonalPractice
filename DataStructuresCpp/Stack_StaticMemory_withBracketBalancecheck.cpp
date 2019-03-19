#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#define MAX 1000

using namespace std;

class Stack
{
private:
	char s[MAX];
	int top;
	int size;
public:
	Stack()
	{
		top = -1;
		size = 0;
	}

	void push(char x)
	{
		size++;
		//cout << "Pushing " << x << " to s[" << (top+1) << "]" << endl;
		s[++top] = x;
	}

	char pop()
	{
		if(size==0)
        {
            cout << "Stack empty" << endl;
            return '\0';
        }

		int x = s[top--];
		size--;
		return x;
	}

	bool isEmpty()
	{
		if(size == 0)
			return 1;
		else
			return 0;
	}

	void printAll()
	{
		for(int i=top; i>=0; i--)
			cout << s[i] << endl;
	}

};

int main()
{
    bool flag = 1;
	Stack s1;
    int len;
	char c;
	char * temp;
	char * str;

	temp = new char [100];
	cin >> temp;

	str = new char [strlen(temp) + 1];
	strcpy(str, temp);

	delete [] temp;

	len = strlen(str);

	cout << str << endl;

	for(int i=0; i<len; i++)
    {
        if(flag==0)
        {
            cout << "UNBALANCED";
            break;
        }
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            s1.push(str[i]);
        else
        {
            if(s1.isEmpty()==1)
            {
                cout << "UNBALANCED" << endl;
                break;
            }

            c = str[i];

            switch(c)
            {
            case ')':
                if(s1.pop() == '(')
                    break;
                cout << "UNBALANCED";
                flag = 0;
                goto A;
            case '}':
                if(s1.pop() == '{')
                    break;
                cout << "UNBALANCED";
                flag = 0;
                goto A;
            case ']':
                if(s1.pop() == '[')
                    break;
                cout << "UNBALANCED";
                flag = 0;
                goto A;
            }
        }
    }
    if(s1.isEmpty()==0)
    {
        cout << "UNBALANCED";
        return 0;
    }
    cout << "BALANCED";
	//s1.printAll();
A:
//	cout << endl << endl;






	return 0;
}
