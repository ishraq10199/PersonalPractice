#include <iostream>

//LINKED LIST HAS DUPLICATE FUNCTION
/*
Question 1: First input -> test case;
	rest of the input is [OPERATION] [DATA]
						 [OPERATION] [DATA]
					     [OPERATION] [DATA]
	Operation 1 == INSERT; Operation 2 == RETRIEVE
	
	if retrieved values match with a queue, it is a queue
	if retrieved values match with a stack, it is a stack
	if retrieved values match with none of the above, its neither a stack, nor a queue

Question 2: LinkedList with functions: 	init()
										push_front()
										display()
										dispose()
										duplicate()

NOTES:  QUESTION 1 is contained within a function '__void question1()__'


*/

using namespace std;

struct Node
{
	int val;
	Node * next;
};

class LinkedList
{
private:
	Node * head;
public:
	void init()
	{
		head = NULL;
	}
	void push_front(int v)         //FOR QUEUE AND STACK
	{
        Node * temp = new Node;
        temp->val = v;
		temp->next = head;
		head = temp;
    }
	int pop_front()				//PFOR ONLY STACK
	{
		if(head == NULL)
			return -1;
		else
		{
			int x;
			Node * temp;
			temp = head;
			head = head->next;
			x = temp->val;
			delete temp;
			return x;
		}
	}
	int pop_back()
	{
		if(head == NULL)
			return -1;
		else if(head->next == NULL)
		{
			int x = head->val;
			delete head;
			head = NULL;
			return x;
		}
		else
		{
			int x;
			Node * temp = head->next;
			Node * temp2 = head;
			Node * temp3;
			while(temp)
			{
				temp3 = temp2;
				temp2 = temp2->next;
				temp = temp->next;     //temp3 is second last Node, temp2 is last Node
			}
			x = temp2->val;
			temp3->next = NULL;
			delete temp2;
			return x;
		}
	}
	void duplicate()
	{
		Node * temp = head;
		Node * temp2;
		while(temp)
		{
			temp2 = new Node;
			temp2->val = temp->val;
			temp2->next = temp->next;
			temp->next = temp2;
			temp = temp->next->next;
		}

	}
	void display()
	{
		if(head == NULL)
		{
			cout << "NO ELEMENTS";
			return;
		}
		Node * temp = head;
		while(temp)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;

	}
	void dispose()
	{
		Node * temp;
		while(head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

class Queue
{
private:
	LinkedList l1;
public:
	Queue()
	{
		l1.init();
	}
	~Queue()
	{
		l1.dispose();
	}
	void enqueue(int n)
	{
		l1.push_front(n);
	}
	int dequeue()
	{
		int x = l1.pop_back();
		return x;
	}
};

class Stack
{
private:
	LinkedList l1;
public:
	Stack()
	{
		l1.init();
	}
	~Stack()
	{
		l1.dispose();
	}
	void push(int n)
	{
		l1.push_front(n);
	}
	int pop()
	{
		int x = l1.pop_front();
		return x;
	}
};

void question1()
{
	bool isQueue = 1, isStack = 1;
	Queue q;
	Stack s;

	int n;
	cin >> n;

	int * a = new int[n]; // array of operations, 1 -> insert, 2-> retrieve
	int * b = new int[n];  // array of data (inserted or retrieved)

	for(int i=0; i<n; i++)
		cin >> a[i] >> b[i];
	
	for(int i=0; i<n; i++)
	{
		if(a[i]==1)
		{
			q.enqueue(b[i]);
			s.push(b[i]);
		}
		if(a[i]==2)
		{
			if(b[i]!=q.dequeue())
				isQueue = 0;      //if expected element doesn't match with the dequeued int, its not a queue
			if(b[i]!=s.pop())
				isStack = 0;		//if expected element doesn't match with the popped int, its not a stack
		}
	}

	if(isQueue && isStack)
		cout << endl << "Both of them";
	if(isQueue && !isStack)
		cout << endl << "It's a Queue";
	if(!isQueue && isStack)
		cout << endl << "It's a Stack";
	if(!isQueue && !isStack)
		cout << endl << "None of them";

}

int main()
{
	
	question1();


	return 0;
}
