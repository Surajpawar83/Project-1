#include<iostream>
using namespace std;


// structure for SinglyLL,   SinglyCL,   Stack,    Queue :-

template <typename T>
struct node1
{
	T data;
	struct node1 *next;
};
//////////////////////////////////////////////////////////////////////////////////////////

// structure for DoublyLL and DoublyCL :-

template <typename T>
struct node2
{
    T data;
    struct node2 *next;
    struct node2 *prev;
};
//////////////////////////////////////////////////////////////////////////////////////////

//Declaration of Classes :-

template <class T>
class SinglyLL
{
private:
	node1 <T> * first;
	int size;
	
public:
	SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};
/////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
private:
	node1 <T> * first;
	node1 <T> * last;
	int size;

public:
	SinglyCL();
	void InsertFirst(T no);
	void InsertLast(T no);
	void InsertAtPos(T no, int ipos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int ipos);
	void Display();
	int Count();	
};
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
private:
	node2 <T> * first;
	int size;
	
public:
	DoublyLL();
	void InsertFirst(T no);
	void InsertLast(T no);
	void InsertAtPos(T no, int ipos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int ipos);
	void Display();
	int Count();
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
private:
    node2 <T> * first;
    node2 <T> * last;
    int size;
    
public:
	DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no , int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Stack
{
private:
    node1 <T> * first;
    int size;
    
public:
	Stack();
	void push(T);
	T pop();
	void Display();
	int Count();
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
private:
    node1 <T> * first;
    int size;
    
public:
    Queue();
	void Enqueue(T);
	T Dequeue();
	void Display();
	int Count();
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class Sorting
{
	private:
	T *p;
	int size;
	int i;
	
	public:
	Sorting();
	void Accept();
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void Display();
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL<T> :: SinglyLL()
	{
		first = NULL;
		size = 0;
	}
	
	template <class T>
	void SinglyLL<T> :: InsertFirst(T no)
	{
		node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn -> next = first;
			first = newn;
		}
		size++;
	}
	
	template <class T>
	void SinglyLL<T> :: InsertLast(T no)
	{
		node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			node1 <T> * temp = first;
			
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = newn;
		}
		size++;
	}
	
	template <class T>
	void SinglyLL<T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > (size + 1)))
		{
			return;
		}
		
		if(ipos == 1)
		{
			InsertFirst(no);
		}
		else if(ipos == (size + 1))
		{
			InsertLast(no);
		}
		else
		{
			node1 <T> * newn = new node1 <T>;
			
			newn -> data = no;
			newn -> next = NULL;
			
			node1 <T> * temp = first;
			
			for(int i = 1; i < (ipos - 1); i++)
			{
				temp = temp -> next;
			}
			
			newn -> next = temp -> next;
			temp-> next = newn;
			
			size++;
		}
	}
	
	template <class T>
	void SinglyLL<T> :: DeleteFirst()
	{
		node1 <T> * temp = first;
		
		if(first != NULL)
		{
			first = first -> next;
			delete temp;
			
			size--;
		}
	}
	
	template <class T>
	void SinglyLL<T> :: DeleteLast()
	{
		node1 <T> * temp = first;
		
		if(first == NULL)
		{
			return;
		}
		else if(first -> next == NULL)
		{
			delete first;
			first = NULL;
			size--;
		}
		else
		{
			while(temp -> next -> next != NULL)
			{
				temp = temp -> next;
			}
			delete temp -> next;
			temp -> next = NULL;
			size--;
		}
	}
	
	template <class T>
	void SinglyLL<T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))
		{
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{	
			node1 <T> * temp = first;
			node1 <T> * targated = NULL;
			
			for(int i = 1; i < (ipos - 1); i++)
			{
				temp = temp -> next;
			}
			targated = temp -> next;
			temp -> next = targated -> next;
			delete targated;
			
			size--;
			
		}
	}
	
	template <class T>
	void SinglyLL<T> :: Display()
	{
		node1 <T> * temp = first;
		
		while(temp != NULL)
		{
			cout <<"|"<<temp -> data<<"|-> ";
			temp = temp -> next;
		}
		cout<< "\n";
	}
	
	template <class T>
	int SinglyLL<T> :: Count()
	{
		return size;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL <T> :: SinglyCL()
	{
		first = NULL;
		last = NULL;
		size = 0;
	}
	
	template <class T>
	void SinglyCL <T> :: InsertFirst(T no)
	{
		node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn -> next = first;
			first = newn;
		}
		
		last -> next = first;
		
		size++;
	}
	
	template <class T>
	void SinglyCL <T> :: InsertLast(T no)
	{
		node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last -> next = newn;
			last = newn;
		}
		
		last -> next = first;
		
		size++;
	}
	
	template <class T>
	void SinglyCL <T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > (size + 1)))
		{
			return;
		}
		
		if(ipos == 1)
		{
			InsertFirst(no);
		}
		else if(ipos == (size + 1))
		{
			InsertLast(no);
		}
		else
		{
			node1 <T> * newn = new node1 <T>;
			
			newn -> data = no;
			newn -> next = NULL;
			
			node1 <T> * temp = first;
			
			for(int i = 1; i < (ipos - 1); i++)
			{
				temp = temp -> next;
			}
			
			newn -> next = temp -> next;
			temp-> next = newn;
			
			size++;
		}
	}
	
	template <class T>
	void SinglyCL <T> :: DeleteFirst()
	{
		if((first == NULL) && (last == NULL))
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first -> next;
			delete last -> next;
			last -> next = first;
		}
		
		size--;
	}
	
	template <class T>
	void SinglyCL <T> :: DeleteLast()
	{
		node1 <T> * temp = first;
		
		if((first == NULL) && (last == NULL))
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp -> next != last)
			{
				temp = temp -> next;
			}
			
			delete last;
			last = temp;
			
			last -> next = first;
		}
		
		size--;
	}
	
	template <class T>
	void SinglyCL <T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))
		{
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{	
			node1 <T> * temp = first;
			node1 <T> * targated = NULL;
			
			for(int i = 1; i < (ipos - 1); i++)
			{
				temp = temp -> next;
			}
			targated = temp -> next;
			temp -> next = targated -> next;
			delete targated;
			
			size--;
			
		}
	}
	
	template <class T>
	void SinglyCL <T> :: Display()
	{
		node1 <T> * temp = first;
		
		if((first == NULL) && (last == NULL))
		{
			return;
		}
		
		do
		{
			cout<<"|"<< temp -> data<<"|-> ";
			temp = temp -> next;
		}while(temp != last -> next);
		
		cout << "\n";
	}
	
	template <class T>
	int SinglyCL <T> :: Count()
	{
		return size;
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T> :: DoublyLL()
{
	first = NULL;
	size = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
	node2 <T> * newn = new node2 <T>;
		
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn -> next = first;
		first -> prev = newn;
		first = newn;
	}
	size++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
	node2 <T> * newn = new node2 <T>;
		
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node2 <T> * temp = first;
		
		for(int i = 1; i < size; i++)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
		newn -> prev = temp;	
	}
	size++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
	if((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == (size + 1))
	{
		InsertLast(no);
	}
	else
	{
		node2 <T> * newn = new node2 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		node2 <T> * temp = first;
		
		for(int i = 1; i <= (ipos - 2); i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		newn -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
		
		size++;
	}
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
	node2 <T> * temp = first;
	
	if(first == NULL)
	{
		return;
	}
	else
	{
		first = first -> next;
		first -> prev = NULL;
		delete temp;
		
		size--;
	}
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
	node2 <T> * temp = first;
	
	if(first == NULL)
	{
		return;
	}
	else if(first -> next == NULL)
	{
		delete first;
		first = NULL;
	}
	else
	{
		for(int i = 1; i < size; i++)
		{
			temp = temp -> next;
		}
		temp -> prev ->next = NULL;
		delete temp;
		
		size--;
	}
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{	
		node2 <T> * temp = first;
		
		for(int i = 1; i <= (ipos - 2); i++)
		{
			temp = temp -> next;
		}
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		size--;
	}
}

template <class T>
void DoublyLL<T> :: Display()
{
	node2 <T> * temp = first;
	
	while(temp != NULL)
	{
		cout<<"|"<<temp -> data<<"|-> ";
		temp = temp -> next;
	}
	cout<< "\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
	return size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL <T> :: DoublyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template <class T>
void DoublyCL <T> :: InsertFirst(T no)
{
    node2 <T> * newn = new node2 <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL <T> :: InsertLast(T no)
{
    node2 <T> * newn = new node2 <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template <class T>
void DoublyCL <T> :: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node2 <T> * newn= new node2 <T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        node2 <T> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template <class T>
void DoublyCL <T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class T>
void DoublyCL <T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template <class T>
void DoublyCL <T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        node2 <T> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}

template <class T>
void DoublyCL <T> :: Display()
{
    node2 <T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyCL <T> :: Count()
{
    return size;
}

////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack <T> :: Stack()
    {
        first = NULL;
        size = 0;
    }
    
	template <class T>
    void Stack <T> :: push(T no)
    {
        node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn -> next = first;
			first = newn;
		}
		size++;
     }
    
	template <class T>
    T Stack <T> :: pop()
    {
		T no;
		node1 <T> * temp = first;
		
		if(first == NULL)
		{
			cout<<"stack is empty\n";
			//return;
		}
		
		if(first -> next == NULL)
		{
			no = first -> data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first -> data;
			first = first -> next;
			delete temp;
		}
		
		size--;
		return no;
    }
    
	template <class T>
    void Stack <T> :: Display()
    {
		node1 <T> * temp = first;
		
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|"<<"\n";
			temp = temp -> next;
		}
		cout<<"\n";
	}
	
	template <class T>
    int Stack <T> :: Count()
    {
        return size;
    }
	
////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue <T> :: Queue()
    {
        first = NULL;
        size = 0;
    }
    
	template <class T>
    void Queue <T> :: Enqueue(T no)
    {
		node1 <T> * newn = new node1 <T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			node1 <T> * temp = first;
			
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = newn;	
		}
		
		size++;
    }
    
	template <class T>
    T Queue <T> ::Dequeue()
    {
		T no;
		node1 <T> * temp = first;
		
		if(first == NULL)
		{
			cout<<"Queue is empty\n";
			//return;
		}
		
		if(first -> next == NULL)
		{
			no = first -> data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first -> data;
			first = first -> next;
			delete temp;
		}
		
		size--;
		return no;
    }
    
	template <class T>
    void Queue <T> :: Display()
    {	
		node1 <T> * temp = first;
		
		for(int i = 1; i <= size; i++)
		{
			cout<<"|"<<temp->data<<"|-> ";
			temp = temp -> next;
		}
		cout<<"\n";
	}
    
	template <class T>
    int Queue <T> :: Count()
    {
        return size;
    }
	
////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Sorting <T> :: Sorting()
{
	p = new T;
	size = 0;
	i = 0;
}

template <class T>
void Sorting <T> :: Accept()
{	
	cout<<"Enter size of element"<<"\n";
	cin>>size;
	
	if(p == NULL)
	{
		return;
	}
	
	cout<<"Enter the elements"<<"\n";
	
	for(i = 0; i < size; i++)
	{
		cin>>p[i];
	}
}

template <class T>
void Sorting <T> :: BubbleSort()
{
	T *Arr = p;
	T temp;
	
	int j = 0;
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < (size - i - 1); j++)
		{
			if(Arr[j] > Arr[j+1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = temp;
			}
		}
	}
}

template <class T>
void Sorting <T> :: SelectionSort()
{
	T *Arr = p;
	T temp;
	
	int j = 0, minindex = 0;
	
	for(i = 0; i < size; i++)
	{
		minindex = i;
		
		for(j = i; j < size; j++)
		{
			if(Arr[minindex] > Arr[j])
			{
				minindex = j;
			}
		}
		temp = Arr[i];
		Arr[i] = Arr[minindex];
		Arr[minindex] = temp;
	}
}

template <class T>
void Sorting <T> :: InsertionSort()
{
	T *Arr = p;
	T key;
	
	int j = 0;
	
	for(i = 0; i < size; i++)
	{
		key = Arr[i];
		
		for(j = (i-1); (j >= 0) && (Arr[j] > key); j--)
		{
			Arr[j+1] = Arr[j];
		}
		Arr[j+1] = key;
	}
}

template <class T>
void Sorting <T> :: Display()
{	
	for(i = 0; i < size; i++)
	{
		cout<<p[i]<<"\n";
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
