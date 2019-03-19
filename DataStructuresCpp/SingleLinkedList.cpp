#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Node{

	int value;
	Node * next;
};

class LinkedList
{
private:
	Node * head;
	int size;
public:
	LinkedList()				//CONSTRUCTOR
	{
		head = NULL;
		size = 0;
	}
	~LinkedList()				//DESTRUCTOR
	{
		Node * temp = head;
		while(temp)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
	void push_front(int v)         //PUSHES TO FRONT OF LINKED LIST
	{
        Node * temp = new Node;
        temp->value = v;
		temp->next = head;
		head = temp;
		//delete temp;
		size++;
    }
	int pop_front()				//POPS FRONT AND RETURNS DATA
	{
		if(head == NULL)
			return int(NULL);
		else
		{
			int x;
			Node * temp;
			temp = head;
			head = head->next;
			x = temp->value;
			delete temp;
			size--;
			return x;
		}
	}
	void printAll()					//DISPLAYS THE LINKED LIST ELEMENTS
	{
		if(head == NULL)
			cout << "Linked List Empty" << endl;
		else
		{
			Node * temp = head;
			while(temp)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	Node * search(int v)    //CHECK NULL BEFORE USING THIS IN MAIN FUNCTION__RETURNS NODE IF FOUND
	{
	    Node * temp = head;
	    while(temp)
        {
            if(temp->value == v)
                return temp;
            else
                temp = temp->next;
        }
        return NULL;
	}
	Node * getElementAt(int index)  //CHECK NULL BEFORE USING THIS IN MAIN FUNCTION__RETURNS NODE IF FOUND
	{
	    if(index <0 || index >=size)
            return NULL;
	    Node * temp = head;
	    while(index)
        {
            temp = temp->next;
            index--;
        }
        return temp;
	}
	bool deleteAt(int index)		//DELETES BY INDEX
	{
	    if(index <0 || index >=size)
            return 0;
        if(head == NULL)
            return 0;
        if(index == 0)
        {
            pop_front();
            return 1;
        }

	    Node * temp = head;
	    Node *temp2 = NULL;
	    while(index)
        {
            temp2 = temp;
            temp = temp->next;
            index--;
        }
        temp2->next = temp2->next->next;
        delete temp;
        size--;
        return 1;
	}
	bool deleteValue(int val)		//DELETES BY VALUE
	{
	    if(head == NULL)
            return 0;
        Node * temp = head;
        Node * temp2 = NULL;
        while(temp)
        {
            if(temp->value == val)
            {
                if(temp2 == NULL)
                {
                    pop_front();
                    return 1;
                }
                temp2->next = temp2->next->next;
                delete temp;
                size--;
                return 1;
            }
            else
            {
                temp2 = temp;
                temp = temp->next;
            }
        }
        return 0;
	}
	void reverse()				//REVERSES THE LINKED LIST BY SWITCHING POINTER DIRECTION AND KEEPING NODES IN PLACE
	{
		if(head == NULL)
			return;
		if(head->next == NULL)
			return;

		Node * a = NULL;
		Node * b = head;
		Node * c = head->next;

		while(c!=NULL)
		{
			b->next = a;
			a = b;
			b = c;
			c = c->next;
		}
		head = b;
		b->next = a;
		//a = b;

	}
	void pairSwap()			//SWAP ELEMENTS OF LIST BY PAIRS   1 2 3 4 becomes 2 1 4 3
	{
	    Node * temp = head;
	    while(temp && temp->next)
	    {
	    	swap(&(temp->value), &(temp->next->value));
	    	temp = temp->next->next;
	    }
	}
	void lastToFront()			//BASICALLY POPS BACK AND PUSHES FRONT
	{
	    if(head==NULL)
	    	return;
	    if(head->next == NULL)
	    	return;
	    Node * temp = head;
	    Node * temp2 = head->next;
	    while(temp2->next)
	    {
	    	temp = temp2;
	    	temp2 = temp2->next;
	    }
	    int x = temp2->value;
	    temp->next = NULL;
	    push_front(x);
	}
    LinkedList createIntersection(LinkedList * l1, LinkedList * l2)   //RETURNS A LINKED LIST THAT IS THE INTERSECTION OF l1 and l2
    {
    	Node * temp1 = l1->head;
    	Node * temp2 = l2->head;
    	Node * temp3 = NULL;

    	LinkedList l3;

    	while(temp1 && temp2)
    	{
    		temp3 = l2->search(temp1->value);
    		if(temp3)
    		{
    			int x = temp1->value;
    			l3.push_front(x);
    			//l2.deleteValue(x);
    		}
    		temp1 = temp1->next;
    	}
    	if(l3.head)
    		l3.reverse();

    	return l3;
    }


};
int main()
{

}
	
