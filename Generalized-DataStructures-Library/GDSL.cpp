//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Generalized Data Structure Library (GDSL).
// File        :  GDSL.cpp
// Description :  This project is a C++ library of generic data structures that provides object
//                oriented implementations of both linear & non-linear data structures.
// Author      :  Ishwari Pravin Jadhav
// Date        :  14/09/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// ----------------------------------- Queue ------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class       : QueueX
// Description : Generic implementation of Queue
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct Queuenode
{
    T data;                                             // Data of generic type
    struct Queuenode<T> * next;                         // Pointer to the next node
};

template<class T>
class QueueX
{
    private:
    struct Queuenode<T> *first;                        // Pointer to the first node (front)
    int iCount;                                        // Stores number of elements in Queue

    public:
    QueueX();
    ~QueueX();
    void Enqueue(T);
    T Dequeue();
    void Display();
    int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	QueueX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class QueueX.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~QueueX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Destructor of class QueueX.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
QueueX<T> :: ~QueueX()
{
    struct Queuenode<T> * temp = NULL;

    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Enqueue
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Adds a new element at the rear (end) of the Queue.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void QueueX<T> :: Enqueue(T no)
{
    struct Queuenode<T> * temp = NULL;
    struct Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Dequeue
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Removes an element from the front of the Queue.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T QueueX<T> :: Dequeue()
{
    struct Queuenode<T> *temp = NULL;
    T value = 0;

    if(first == NULL)
    {
        cout<<"Unable to remove as Queue is empty\n";
        return T();
    }
    else 
    {
        temp = first;
        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements in the Queue.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> * temp = NULL;

    temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the total number of elements in the Queue.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int QueueX<T> :: Count()
{
    return iCount;
}

// ----------------------------------- Stack ------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class       : StackX
// Description : Generic implementation of Stack
// Author      : Ishwari Pravin Jadhav
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;                                                  // Data of generic type
    struct Stacknode<T> * next;                              // Pointer to the next node
};

template<class T>
class StackX
{
    private:
    struct Stacknode<T> *first;                              // Pointer to the first node (front)
    int iCount;                                              // Stores number of elements in Stack

    public:
    StackX();
    ~StackX();
    void Push(T);
    T Pop();
    void Display();
    int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	StackX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class StackX.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~StackX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Destructor of class StackX.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
StackX<T> :: ~StackX()
{
    struct Stacknode<T> * temp = NULL;

    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Push
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new element onto the top of the Stack.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Push(T no)
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Pop
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Removes and returns the top element from the Stack.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T StackX<T> :: Pop()
{
    struct Stacknode<T> *temp = NULL;
    T value = 0;

    if(first == NULL)
    {
        cout<<"Unable to remove as Stack is empty\n";
        return T();
    }
    else 
    {
        temp = first;
        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements in the Stack.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> * temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the total number of elements in the Stack.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

// ------------------------- Singly Linear Linked List -------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class :       SinglyLL
// Description : Generic Implementation of Singly Linear linked list.
// Author :      Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct SinglyLLnode
{
    T data;                                                               // Stores value of the node
    struct SinglyLLnode<T> *next;                                         // Pointer to the next node
};

template<class T>
class SinglyLL
{
    private:
    struct SinglyLLnode<T> * first;                                      // Head pointer of linked list
    int iCount;                                                          // Count of total nodes

    public:
    // Constructor / Destructor
    SinglyLL();
    ~SinglyLL();

    // Generic linked list operations
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOccurence(T);
    int SearchLastOccurence(T);
    int SearchAllOccurence(T);
    T Addition();
    T LargestElement();
    T SmallestElement();
    T SecMaximum();

    // Integer-only functions (Works only if T = int)
    void DisplayPerfect();
    void DisplayPrime();
    T AdditionEven();
    void SumDigit();
    void Reverse();
    void DisplayPalindrome();
    void DisplayProduct();
    void DisplaySmall();
    void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class Singly Linear Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyLL<T> :: SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~SinglyLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Destructor of class Singly Linear Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyLL<T> :: ~SinglyLL()
{
    struct SinglyLLnode<T>* temp = NULL;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// ------------------------------- Generic Functions -------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the beginning of the Singly Linear 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SinglyLLnode<T> * newn = NULL;

    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the end of the Singly Linear 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct SinglyLLnode<T> * temp = NULL;
    struct SinglyLLnode<T> * newn = NULL;

    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements of Singly Linear linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: Display()
{
    struct SinglyLLnode<T> * temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the number of nodes in the Singly Linear Linked
//                              List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the first node of the Singly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct SinglyLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    iCount--;
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the last node of the Singly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct SinglyLLnode<T> * temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no,int pos
//	Description             :   Inserts a new node at the specified position in Singly 
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertAtPos(T no,int pos)
{
    struct SinglyLLnode<T> * temp = NULL;
    struct SinglyLLnode<T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invaid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next;
        }

        newn = new struct SinglyLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int pos
//	Description             :   Deletes a node from the specified position in Singly 
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyLLnode<T> * temp = NULL;
    int iCnt = 0;
    struct SinglyLLnode<T> * target = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invaid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchFirstOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the first occurrence of an element in the
//                              Singly Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: SearchFirstOccurence(T no)
{
    struct SinglyLLnode<T> * temp = NULL;

    int iPos = 1;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return iPos;
        }
        iPos++;
        temp = temp -> next;
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchLastOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the last occurrence of an element in the 
//                              Singly Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: SearchLastOccurence(T no)
{
    struct SinglyLLnode<T> * temp = NULL;

    int iPos = 1;
    int iLastPos = -1;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }
        iPos++;
        temp = temp -> next;
    }
    return iLastPos;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchAllOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Counts total occurrences of an element in the Singly
//                              Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: SearchAllOccurence(T no)
{
    struct SinglyLLnode<T> * temp = NULL;

    int iCountOcc = 0;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iCountOcc++;
        }
        temp = temp->next;
    }
    return iCountOcc;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Addition
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of all elements present in the Singly
//                              Linear Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyLL<T> :: Addition()
{
    struct SinglyLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    while(temp != NULL)
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }
    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LargestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the largest element from the Singly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyLL<T> :: LargestElement()
{
    struct SinglyLLnode<T> * temp = NULL;

    temp = first;
    T iLargest = temp->data;

    while(temp != NULL)
    {
        if((temp->data) > iLargest)
        {
            iLargest = temp->data;
        }
        temp = temp -> next;
    }
    return iLargest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SmallestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the smallest element from the Singly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyLL<T> :: SmallestElement()
{
    struct SinglyLLnode<T> * temp = NULL;

    temp = first;
    T iSmallest = temp->data;

    while(temp != NULL)
    {
        if((temp->data) < iSmallest)
        {
            iSmallest = temp->data;
        }
        temp = temp -> next;
    }
    return iSmallest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SecMaximum
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the second Maximum element from the Singly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyLL<T> :: SecMaximum()
{
   struct SinglyLLnode<T> * temp = NULL;

   temp = first;
   T iMax1 = temp->data;
   T iMax2 = temp->data;

   while(temp != NULL)
   {
        if((temp->data) > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if(((temp->data) > iMax2) && ((temp->data) != iMax1))
        {
            iMax2 = temp->data;
        }
        temp = temp -> next;
   }
   return iMax2;
}

// -------------------------- Integer-Specific Functions ---------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPerfect
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all perfect numbers from the singly linear 
//                              linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplayPerfect()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iCnt = 0;
    int iSum = 0;
    temp = first;
    
    cout<<"Perfect numbers in Linked List are:";

    while(temp != NULL)
    {
        iSum = 0;

        for(iCnt = 1;iCnt < temp->data;iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPrime
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all prime numbers from the singly linear linked 
//                              list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplayPrime()
{
    struct SinglyLLnode<T> * temp = NULL;

    int i = 0;
    int iPrime = 0;
    temp = first;

    cout<<"Prime numbers in Linked List are:";

    while(temp != NULL)
    {
        iPrime = 0;

        for(i = 1;i <= temp->data;i++)
        {
            if((temp->data % i) == 0)
            {
                iPrime++;
            }
        }
        if(iPrime == 2)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AdditionEven
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates and returns the sum of all the even elements 
//                              present in the Singly Linear Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyLL<T> :: AdditionEven()
{
    struct SinglyLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iSum = iSum + (temp->data);
        }
        temp = temp->next;
    }
    return iSum;   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SumDigit
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of its digits for each integer element
//                              in Singly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: SumDigit()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iSum = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Addition of Digits of Element from linked list are:";

    while(temp != NULL)
    {
        iSum = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Reverse
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Reverses each integer element from Singly Linear Linked
//                              List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: Reverse()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iRev = 0;
    temp = first;

    cout<<"Reversed each Element of linked list are:";

    while(temp != NULL)
    {
        iRev = 0;
        int iTemp = temp->data;

        while(iTemp != 0)
        {
            iRev = (iRev * 10) + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        cout<<"|"<<iRev<<"| -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPalindrome
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays palindrome elements present in the Singly 
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplayPalindrome()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iRev = 0;
    int iNo = 0;
    temp = first;

    cout<<"Palindrome elements from linked list are:";

    while(temp != NULL)
    {
        iRev = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev  = (iRev * 10) + iDigit;
            iNo = iNo / 10;

        }
        if(iRev == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayProduct
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays product of digits of each element in Singly Linear
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplayProduct()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iProduct = 1;
    int iNo = 0;
    temp = first;

    cout<<"Product of digits of each element in Linked list:";

    while(temp != NULL)
    {
        iNo = temp->data;
        iProduct = 1;

        if(iNo == 0)
        {
            cout<<"1\t";
        }
        else
        {
            while(iNo != 0)
            {
                iDigit = iNo % 10;
                if(iDigit != 0)
                {
                    iProduct = iProduct * iDigit;
                }
                iNo = iNo / 10;
            }
            cout<<iProduct<<"\t";
        }
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplaySmall
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the smallest digit from each integer element 
//                              of the Singly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplaySmall()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iSmall = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Smallest digits of all digits of all element from linked list:";

    while(temp != NULL)
    {
        iSmall = 9;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iSmall)
            {
                iSmall = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iSmall<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayLarge
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the largest digit from each integer element 
//                              of the Singly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DisplayLarge()
{
    struct SinglyLLnode<T> * temp = NULL;

    int iLarge = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Largest digits of all digits of all element from linked list:";

    while(temp != NULL)
    {
        iLarge = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iLarge<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

// ------------------------- Singly Circular Linked List -------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class :       SinglyCLL
// Description : Generic Implementation of Singly Circular linked list
// Author :      Ishwari Pravin Jadhav
//
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct SinglyCLLnode
{
    T data;                                                        // Stores value of the node
    struct SinglyCLLnode<T> *next;                                 // Pointer to the next node
};

template<class T>
class SinglyCLL
{
    private:
    struct SinglyCLLnode<T> * first;                                // Head pointer of linked list
    struct SinglyCLLnode<T> * last;                                 // Tail pointer of linked list
    int iCount;                                                     // Count of total nodes

    public:
    // Constructor / Destructor
    SinglyCLL();
    ~SinglyCLL();

    // Generic linked list operations
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOccurence(T);
    int SearchLastOccurence(T);
    int SearchAllOccurence(T);
    T Addition();
    T LargestElement();
    T SmallestElement();
    T SecMaximum();

    // Integer-only functions (Works only if T = int)
    void DisplayPerfect();
    void DisplayPrime();
    T AdditionEven();
    void SumDigit();
    void Reverse();
    void DisplayPalindrome();
    void DisplayProduct();
    void DisplaySmall();
    void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyCLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class Singly Circular Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~SinglyCLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Destructor of class Singly Circular Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCLL<T> :: ~SinglyCLL()
{
    struct SinglyCLLnode<T>* temp = NULL;

    if (first != NULL)
    {
        last->next = NULL;

        while (first != NULL)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
    }
    first = NULL;
    last = NULL;
}

// ------------------------------- Generic Functions -------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the beginning of the Singly Circular 
//                              Linked List.
//	Returns					:   void
//
/////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the end of the Singly Circular 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the first node of the Singly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteFirst()
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
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the last node of the Singly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

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
        temp = first;

        while(temp->next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;

        last->next = first;
    }   
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements of Singly Circular linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: Display()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = NULL;

    temp = first;

    do
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    } while(temp != first);
    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the number of nodes in the Singly Circular Linked
//                              List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int pos
//	Description             :   Deletes a node from the specified position in Singly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    int i = 0;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invalid Position";
        return;
    }
    
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1;i++)
        {
            temp = temp-> next;
        }
        target = temp->next;
        temp->next = target -> next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no,int pos
//	Description             :   Inserts a new node at the specified position in Singly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;
    int i = 0;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid Position";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1;i < pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchFirstOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the first occurrence of an element in the
//                              Singly Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: SearchFirstOccurence(T no)
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iPos = 1;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            return iPos;
        }
        temp = temp -> next;
        iPos++;
    }while(temp != first);

    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchLastOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the last occurrence of an element in the 
//                              Singly Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: SearchLastOccurence(T no)
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iPos = 1;
    int iLastPos = -1;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }
        temp = temp -> next;
        iPos++;
    }while(temp != first);

    return iLastPos;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchAllOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Counts total occurrences of an element in the Singly
//                              Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: SearchAllOccurence(T no)
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iCountOcc = 0;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            iCountOcc++;
        }
        temp = temp->next;
    }while(temp != first);

    return iCountOcc;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Addition
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of all elements present in the Singly
//                              Circular Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyCLL<T> :: Addition()
{
    struct SinglyCLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    do
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }while(temp != first);

    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LargestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the largest element from the Singly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyCLL<T> :: LargestElement()
{
    struct SinglyCLLnode<T> * temp = NULL;

    temp = first;
    T iLargest = temp->data;

    do
    {
        if((temp->data) > iLargest)
        {
            iLargest = temp->data;
        }
        temp = temp -> next;
    }while(temp != first);

    return iLargest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SmallestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the smallest element from the Singly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyCLL<T> :: SmallestElement()
{
    struct SinglyCLLnode<T> * temp = NULL;

    temp = first;
    T iSmallest = temp->data;

    do
    {
        if((temp->data) < iSmallest)
        {
            iSmallest = temp->data;
        }
        temp = temp -> next;
    }while(temp != first);

    return iSmallest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SecMaximum
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the second Maximum element from the Singly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyCLL<T> :: SecMaximum()
{
   struct SinglyCLLnode<T> * temp = NULL;

   temp = first;
   T iMax1 = temp->data;
   T iMax2 = temp->data;

   do
   {
        if((temp->data) > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if(((temp->data) > iMax2) && ((temp->data) != iMax1))
        {
            iMax2 = temp->data;
        }
        temp = temp -> next;
   }while(temp != first);

   return iMax2;
}

// -------------------------- Integer-Specific Functions ---------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPerfect
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all perfect numbers from the singly Circular 
//                              linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplayPerfect()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iCnt = 0;
    int iSum = 0;
    temp = first;
    
    cout<<"Perfect numbers in Linked List are:";

    do
    {
        iSum = 0;

        for(iCnt = 1;iCnt < temp->data;iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPrime
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all prime numbers from the singly Circular linked 
//                              list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplayPrime()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int i = 0;
    int iPrime = 0;
    temp = first;

    cout<<"Prime numbers in Linked List are:";

    do
    {
        iPrime = 0;

        for(i = 1;i <= temp->data;i++)
        {
            if((temp->data % i) == 0)
            {
                iPrime++;
            }
        }
        if(iPrime == 2)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AdditionEven
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates and returns the sum of all the even elements 
//                              present in the Singly Circular Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T SinglyCLL<T> :: AdditionEven()
{
    struct SinglyCLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    do
    {
        if((temp->data) % 2 == 0)
        {
            iSum = iSum + (temp->data);
        }
        temp = temp->next;
    }while(temp != first);

    return iSum;   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SumDigit
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of its digits for each integer element
//                              in Singly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: SumDigit()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iSum = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Addition of Digits of Element from linked list are:";

    do
    {
        iSum = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Reverse
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Reverses each integer element from Singly Circular Linked
//                              List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: Reverse()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iRev = 0;
    temp = first;

    cout<<"Reversed each Element of linked list are:";

    do
    {
        iRev = 0;
        int iTemp = temp->data;

        while(iTemp != 0)
        {
            iRev = (iRev * 10) + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        cout<<"|"<<iRev<<"| -> ";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPalindrome
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays palindrome elements present in the Singly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplayPalindrome()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iRev = 0;
    int iNo = 0;
    temp = first;

    cout<<"Palindrome elements from linked list are:";

    do
    {
        iRev = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev  = (iRev * 10) + iDigit;
            iNo = iNo / 10;

        }
        if(iRev == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayProduct
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays product of digits of each element in Singly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplayProduct()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iProduct = 1;
    int iNo = 0;
    temp = first;

    cout<<"Product of digits of each element in Linked list:";

    do
    {
        iNo = temp->data;
        iProduct = 1;

        if(iNo == 0)
        {
            cout<<"1\t";
        }
        else
        {
            while(iNo != 0)
            {
                iDigit = iNo % 10;
                if(iDigit != 0)
                {
                    iProduct = iProduct * iDigit;
                }
                iNo = iNo / 10;
            }
            cout<<iProduct<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplaySmall
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the smallest digit from each integer element 
//                              of the Singly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplaySmall()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iSmall = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Smallest digits of all digits of all element from linked list:";

    do
    {
        iSmall = 9;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iSmall)
            {
                iSmall = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iSmall<<" ";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayLarge
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the largest digit from each integer element 
//                              of the Singly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DisplayLarge()
{
    struct SinglyCLLnode<T> * temp = NULL;

    int iLarge = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Largest digits of all digits of all element from linked list:";

    do
    {
        iLarge = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iLarge<<" ";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

// ------------------------- Doubly Linear Linked List -------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class :       DoublyLL
// Description : Generic Implementation of Doubly linear linked list
// Author :      Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct DoublyLLnode
{
    T data;                                                        // Stores value of the node
    struct DoublyLLnode<T> *next;                                  // Pointer to the next node
    struct DoublyLLnode<T> *prev;                                  // Pointer to the previous node
};

template<class T>
class DoublyLL
{
    private:
    struct DoublyLLnode<T> * first;                                // Head pointer of linked list
    int iCount;                                                    // Count of total nodes

    public:
    // Constructor / Destructor
    DoublyLL();
    ~DoublyLL();

    // Generic linked list operations
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOccurence(T);
    int SearchLastOccurence(T);
    int SearchAllOccurence(T);
    T Addition();
    T LargestElement();
    T SmallestElement();
    T SecMaximum();

    // Integer-only functions (Works only if T = int)
    void DisplayPerfect();
    void DisplayPrime();
    T AdditionEven();
    void SumDigit();
    void Reverse();
    void DisplayPalindrome();
    void DisplayProduct();
    void DisplaySmall();
    void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   NONE
//	Description             :   This is Constructor of class Doubly Linear Linked List.
//	Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLL<T> :: DoublyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~DoublyLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   NONE
//	Description             :   This is Destructor of class Doubly Linear Linked List.
//	Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLL<T> :: ~DoublyLL()
{
    struct DoublyLLnode<T>* temp = NULL;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// ------------------------------- Generic Functions -------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the beginning of the Doubly Linear 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the end of the Doubly Linear 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DoublyLLnode<T> * temp = NULL;
    struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements of Doubly Linear linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> * temp = NULL;

    temp = first;

    cout<<"NULL<->";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|<->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the number of nodes in the Doubly Linear Linked
//                              List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the first node of the Doubly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        first->prev = NULL;
    }
    iCount--;
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the last node of the Doubly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DoublyLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else 
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    iCount--;
    cout<<"\n";   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no,int pos
//	Description             :   Inserts a new node at the specified position in Doubly 
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos)
{
    struct DoublyLLnode<T> * temp = NULL;
    int iCnt = 0;
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyLLnode<T> * newn = new struct DoublyLLnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;
        for(iCnt = 1;iCnt < pos - 1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    iCount++;
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int pos
//	Description             :   Deletes a node from the specified position in Doubly 
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyLLnode<T> * temp = NULL;
    int iCnt = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp = first;
        for(iCnt = 1;iCnt < pos - 1;iCnt++)
        {
            temp = temp->next;
        }

        struct DoublyLLnode<T>* target = temp->next;
        temp->next = target->next;
        if(target->next != NULL)
        {
            target->next->prev = temp;
        }
        delete target;
    }
    iCount--;
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchFirstOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the first occurrence of an element in the
//                              Doubly Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> :: SearchFirstOccurence(T no)
{
    struct DoublyLLnode<T> * temp = NULL;

    int iPos = 1;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return iPos;
        }
        iPos++;
        temp = temp -> next;
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchLastOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the last occurrence of an element in the 
//                              Doubly Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> :: SearchLastOccurence(T no)
{
    struct DoublyLLnode<T> * temp = NULL;

    int iPos = 1;
    int iLastPos = -1;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }
        iPos++;
        temp = temp -> next;
    }
    return iLastPos;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchAllOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Counts total occurrences of an element in the Doubly
//                              Linear Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> :: SearchAllOccurence(T no)
{
    struct DoublyLLnode<T> * temp = NULL;

    int iCountOcc = 0;
    temp = first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iCountOcc++;
        }
        temp = temp->next;
    }
    return iCountOcc;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Addition
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of all elements present in the Doubly
//                              Linear Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyLL<T> :: Addition()
{
    struct DoublyLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    while(temp != NULL)
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }
    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LargestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the largest element from the Doubly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyLL<T> :: LargestElement()
{
    struct DoublyLLnode<T> * temp = NULL;

    temp = first;
    T iLargest = temp->data;

    while(temp != NULL)
    {
        if((temp->data) > iLargest)
        {
            iLargest = temp->data;
        }
        temp = temp -> next;
    }
    return iLargest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SmallestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the smallest element from the Doubly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyLL<T> :: SmallestElement()
{
    struct DoublyLLnode<T> * temp = NULL;

    temp = first;
    T iSmallest = temp->data;

    while(temp != NULL)
    {
        if((temp->data) < iSmallest)
        {
            iSmallest = temp->data;
        }
        temp = temp -> next;
    }
    return iSmallest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SecMaximum
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the second Maximum element from the Doubly Linear
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyLL<T> :: SecMaximum()
{
   struct DoublyLLnode<T> * temp = NULL;

   temp = first;
   T iMax1 = temp->data;
   T iMax2 = temp->data;

   while(temp != NULL)
   {
        if((temp->data) > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if(((temp->data) > iMax2) && ((temp->data) != iMax1))
        {
            iMax2 = temp->data;
        }
        temp = temp -> next;
   }
   return iMax2;
}

// -------------------------- Integer-Specific Functions ---------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPerfect
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all perfect numbers from the Doubly linear 
//                              linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplayPerfect()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iCnt = 0;
    int iSum = 0;
    temp = first;
    
    cout<<"Perfect numbers in Linked List are:";

    while(temp != NULL)
    {
        iSum = 0;

        for(iCnt = 1;iCnt < temp->data;iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPrime
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all prime numbers from the Doubly linear linked 
//                              list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplayPrime()
{
    struct DoublyLLnode<T> * temp = NULL;

    int i = 0;
    int iPrime = 0;
    temp = first;

    cout<<"Prime numbers in Linked List are:";

    while(temp != NULL)
    {
        iPrime = 0;

        for(i = 1;i <= temp->data;i++)
        {
            if((temp->data % i) == 0)
            {
                iPrime++;
            }
        }
        if(iPrime == 2)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AdditionEven
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates and returns the sum of all the even elements 
//                              present in the Doubly Linear Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyLL<T> :: AdditionEven()
{
    struct DoublyLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iSum = iSum + (temp->data);
        }
        temp = temp->next;
    }
    return iSum;   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SumDigit
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of its digits for each integer element
//                              in Doubly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: SumDigit()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iSum = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Addition of Digits of Element from linked list are:";

    while(temp != NULL)
    {
        iSum = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Reverse
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Reverses each integer element from Doubly Linear Linked
//                              List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: Reverse()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iRev = 0;
    temp = first;

    cout<<"Reversed each Element of linked list are:";

    while(temp != NULL)
    {
        iRev = 0;
        int iTemp = temp->data;

        while(iTemp != 0)
        {
            iRev = (iRev * 10) + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        cout<<"|"<<iRev<<"| -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPalindrome
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays palindrome elements present in the Doubly
//                              Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplayPalindrome()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iRev = 0;
    int iNo = 0;
    temp = first;

    cout<<"Palindrome elements from linked list are:";

    while(temp != NULL)
    {
        iRev = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev  = (iRev * 10) + iDigit;
            iNo = iNo / 10;

        }
        if(iRev == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayProduct
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays product of digits of each element in Doubly Linear
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplayProduct()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iProduct = 1;
    int iNo = 0;
    temp = first;

    cout<<"Product of digits of each element in Linked list:";

    while(temp != NULL)
    {
        iNo = temp->data;
        iProduct = 1;

        if(iNo == 0)
        {
            cout<<"1\t";
        }
        else
        {
            while(iNo != 0)
            {
                iDigit = iNo % 10;
                if(iDigit != 0)
                {
                    iProduct = iProduct * iDigit;
                }
                iNo = iNo / 10;
            }
            cout<<iProduct<<"\t";
        }
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplaySmall
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the smallest digit from each integer element 
//                              of the Doubly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplaySmall()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iSmall = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Smallest digits of all digits of all element from linked list:";

    while(temp != NULL)
    {
        iSmall = 9;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iSmall)
            {
                iSmall = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iSmall<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayLarge
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the largest digit from each integer element 
//                              of the Doubly Linear Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DisplayLarge()
{
    struct DoublyLLnode<T> * temp = NULL;

    int iLarge = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Largest digits of all digits of all element from linked list:";

    while(temp != NULL)
    {
        iLarge = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iLarge<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

// ------------------------- Doubly Circular Linked List -------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class :       DoublyCLL
// Description : Generic Implementation of Doubly Circular linked list
// Author :      Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct DoublyCLLnode
{
    T data;                                                   // Stores value of the node
    struct DoublyCLLnode<T> *next;                            // Pointer to the next node
    struct DoublyCLLnode<T> *prev;                            // Pointer to the previous node
};

template<class T>
class DoublyCLL
{
    private:
    struct DoublyCLLnode<T> * first;                           // Head pointer of linked list
    struct DoublyCLLnode<T> * last;                            // Tail pointer of linked list
    int iCount;                                                // Count of total nodes

    public:
    // Constructor / Destructor
    DoublyCLL();
    ~DoublyCLL();

    // Generic linked list operations
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOccurence(T);
    int SearchLastOccurence(T);
    int SearchAllOccurence(T);
    T Addition();
    T LargestElement();
    T SmallestElement();
    T SecMaximum();

    // Integer-only functions (Works only if T = int)
    void DisplayPerfect();
    void DisplayPrime();
    T AdditionEven();
    void SumDigit();
    void Reverse();
    void DisplayPalindrome();
    void DisplayProduct();
    void DisplaySmall();
    void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyCLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class Doubly Circular Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructors\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~DoublyCLL
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Destructor of class Doubly Circular Linked List.
//	Returns					:   None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCLL<T> :: ~DoublyCLL()
{
    struct DoublyCLLnode<T>* temp = NULL;

    if (first != NULL)
    {
        last->next = NULL;

        while (first != NULL)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
    }
    first = NULL;
    last = NULL;
}

// ------------------------------- Generic Functions -------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the beginning of the Doubly Circular 
//                              Linked List.
//	Returns					:   void
//
/////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Inserts a new node at the end of the Doubly Circular 
//                              Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)       
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;

    }
    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements of Doubly Circular linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the Linked list are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LL is empty";
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while(temp != first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the number of nodes in the Doubly Circular Linked
//                              List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the first node of the Doubly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
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
        first = first->next;
        delete(first->prev);

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Deletes the last node of the Doubly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    { 
        delete last;

        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no,int pos
//	Description             :   Inserts a new node at the specified position in Doubly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;
    struct DoublyCLLnode<T> * newn = NULL;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        temp = first;

        for(iCnt = 1;iCnt < pos - 1;iCnt++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int pos
//	Description             :   Deletes a node from the specified position in Doubly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1;iCnt < pos - 1;iCnt++)
        {
            temp = temp ->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchFirstOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the first occurrence of an element in the
//                              Doubly Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: SearchFirstOccurence(T no)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iPos = 1;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            return iPos;
        }
        temp = temp -> next;
        iPos++;
    }while(temp != first);

    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchLastOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches for the last occurrence of an element in the 
//                              Doubly Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: SearchLastOccurence(T no)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iPos = 1;
    int iLastPos = -1;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            iLastPos = iPos;
        }
        temp = temp -> next;
        iPos++;
    }while(temp != first);

    return iLastPos;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchAllOccurence
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Counts total occurrences of an element in the Doubly
//                              Circular Linked List.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: SearchAllOccurence(T no)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCountOcc = 0;
    temp = first;

    do
    {
        if(temp->data == no)
        {
            iCountOcc++;
        }
        temp = temp->next;
    }while(temp != first);

    return iCountOcc;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Addition
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of all elements present in the Doubly
//                              Circular Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyCLL<T> :: Addition()
{
    struct DoublyCLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    do
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }while(temp != first);

    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LargestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the largest element from the Doubly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyCLL<T> :: LargestElement()
{
    struct DoublyCLLnode<T> * temp = NULL;

    temp = first;
    T iLargest = temp->data;

    do
    {
        if((temp->data) > iLargest)
        {
            iLargest = temp->data;
        }
        temp = temp -> next;
    }while(temp != first);

    return iLargest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SmallestElement
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the smallest element from the Doubly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyCLL<T> :: SmallestElement()
{
    struct DoublyCLLnode<T> * temp = NULL;

    temp = first;
    T iSmallest = temp->data;

    do
    {
        if((temp->data) < iSmallest)
        {
            iSmallest = temp->data;
        }
        temp = temp -> next;
    }while(temp != first);

    return iSmallest;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SecMaximum
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Returns the second Maximum element from the Doubly Circular
//                              Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyCLL<T> :: SecMaximum()
{
   struct DoublyCLLnode<T> * temp = NULL;

   temp = first;
   T iMax1 = temp->data;
   T iMax2 = temp->data;

   do
   {
        if((temp->data) > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if(((temp->data) > iMax2) && ((temp->data) != iMax1))
        {
            iMax2 = temp->data;
        }
        temp = temp -> next;
   }while(temp != first);

   return iMax2;
}

// -------------------------- Integer-Specific Functions ---------------------------------

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPerfect
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all perfect numbers from the Doubly Circular 
//                              linked list.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplayPerfect()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;
    int iSum = 0;
    temp = first;
    
    cout<<"Perfect numbers in Linked List are:";

    do
    {
        iSum = 0;

        for(iCnt = 1;iCnt < temp->data;iCnt++)
        {
            if((temp->data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }
        if(iSum == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPrime
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all prime numbers from the Doubly Circular linked 
//                              list.
//	Returns					:   void
//
/////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplayPrime()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int i = 0;
    int iPrime = 0;
    temp = first;

    cout<<"Prime numbers in Linked List are:";

    do
    {
        iPrime = 0;

        for(i = 1;i <= temp->data;i++)
        {
            if((temp->data % i) == 0)
            {
                iPrime++;
            }
        }
        if(iPrime == 2)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AdditionEven
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates and returns the sum of all the even elements 
//                              present in the Doubly Circular Linked List.
//	Returns					:   T
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T DoublyCLL<T> :: AdditionEven()
{
    struct DoublyCLLnode<T> * temp = NULL;

    T iSum = 0;
    temp = first;

    do
    {
        if((temp->data) % 2 == 0)
        {
            iSum = iSum + (temp->data);
        }
        temp = temp->next;
    }while(temp != first);

    return iSum;   
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SumDigit
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Calculates the sum of its digits for each integer element
//                              in Doubly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: SumDigit()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iSum = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Addition of Digits of Element from linked list are:";

    do
    {
        iSum = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<"\t";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Reverse
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Reverses each integer element from Doubly Circular Linked
//                              List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: Reverse()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iRev = 0;
    temp = first;

    cout<<"Reversed each Element of linked list are:";

    do
    {
        iRev = 0;
        int iTemp = temp->data;

        while(iTemp != 0)
        {
            iRev = (iRev * 10) + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        cout<<"|"<<iRev<<"| -> ";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayPalindrome
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays palindrome elements present in the Doubly 
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplayPalindrome()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iRev = 0;
    int iNo = 0;
    temp = first;

    cout<<"Palindrome elements from linked list are:";

    do
    {
        iRev = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev  = (iRev * 10) + iDigit;
            iNo = iNo / 10;

        }
        if(iRev == temp->data)
        {
            cout<<temp->data<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayProduct
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays product of digits of each element in Doubly
//                              Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplayProduct()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iDigit = 0;
    int iProduct = 1;
    int iNo = 0;
    temp = first;

    cout<<"Product of digits of each element in Linked list:";

    do
    {
        iNo = temp->data;
        iProduct = 1;

        if(iNo == 0)
        {
            cout<<"1\t";
        }
        else
        {
            while(iNo != 0)
            {
                iDigit = iNo % 10;
                if(iDigit != 0)
                {
                    iProduct = iProduct * iDigit;
                }
                iNo = iNo / 10;
            }
            cout<<iProduct<<"\t";
        }
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplaySmall
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the smallest digit from each integer element 
//                              of the Doubly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplaySmall()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iSmall = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Smallest digits of all digits of all element from linked list:";

    do
    {
        iSmall = 9;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iSmall)
            {
                iSmall = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iSmall<<" ";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DisplayLarge
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays the largest digit from each integer element 
//                              of the Doubly Circular Linked List.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DisplayLarge()
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iLarge = 0;
    int iDigit = 0;
    int iNo = 0;
    temp = first;

    cout<<"Largest digits of all digits of all element from linked list:";

    do
    {
        iLarge = 0;
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iLarge)
            {
                iLarge = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iLarge<<" ";
        temp = temp -> next;
    }while(temp != first);

    cout<<"\n";
}

// ----------------------------- Binary Search Tree -----------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class       : BST
// Description : Generic Implementation of Binary search tree
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct BSTnode
{
    T data;                                        // Data of generic type
    struct BSTnode<T> * lchild;                    // Pointer to left child node
    struct BSTnode<T> * rchild;                    // Pointer to right child node
};

template<class T>
class BST
{
    private:
    struct BSTnode<T> * first;                     // Pointer to root node of BST

    // Recursive helper functions for traversals and counting
    void InorderX(BSTnode<T> *root);
    void PreorderX(BSTnode<T> *root);
    void PostorderX(BSTnode<T> *root);
    int CountX(BSTnode<T> *root);
    int CountLeafNodesX(BSTnode<T> *root);
    int CountParentNodesX(BSTnode<T> *root);

    public:
    // Constructor / Destructor
    BST();

    void Insert(T);
    void Inorder();
    void Preorder();
    void Postorder();
    bool Search(T);
    int Count();
    int CountLeafNodes();
    int CountParentNodes();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BST
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is Constructor of class BST.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
BST<T> :: BST()
{
    first = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Insert
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int no
//	Description             :   This function inserts a new node in the BST according 
//                              to BST rules.
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Insert(T no)
{
    struct BSTnode<T> * newn = new BSTnode<T>;
    struct BSTnode<T> * temp = NULL;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(no == temp->data)
            {
                cout << "Duplicate element : Unable to insert node\n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Inorder
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays nodes in Inorder (Left, Root, Right).
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Inorder()
{
    InorderX(first);
}

template<class T>
void BST<T> :: InorderX(BSTnode<T> *root)
{
    if(root != NULL)
    {
        InorderX(root->lchild);
        cout << root->data << "\t";
        InorderX(root->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Preorder
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays nodes in Preorder (Root, Left, Right).
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Preorder()
{
    PreorderX(first);
}

template<class T>
void BST<T> :: PreorderX(BSTnode<T> *root)
{
    if(root != NULL)
    {
        cout<<root->data<<"\t";
        PreorderX(root->lchild);
        PreorderX(root->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Postorder
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays nodes in Postorder (Left, Right, Root).
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Postorder()
{
    PostorderX(first);
}

template<class T>
void BST<T> :: PostorderX(BSTnode<T> *root)
{
    if(root != NULL)
    {
        PostorderX(root->lchild);
        PostorderX(root->rchild);
        cout<<root->data<<"\t";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Search
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int no
//	Description             :   Searches an element in BST & displays its time complexity.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool BST<T> :: Search(T no)
{
    bool bFlag = false;
    int TimeComplexity = 0;
    struct BSTnode<T> * temp = first;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
        TimeComplexity++;
    }

    cout << "TimeComplexity of search is : " << TimeComplexity << "\n";
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Counts total number of nodes in BST.
//	Returns					:   int
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: Count()
{
    return CountX(first);
    cout<<"\n";
}

template<class T>
int BST<T> :: CountX(BSTnode<T> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + CountX(root->lchild) + CountX(root->rchild);
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountLeafNodes
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Counts total number of leaf nodes in BST.
//	Returns					:   int
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: CountLeafNodes()
{
    return CountLeafNodesX(first);
    cout<<"\n";
}

template<class T>
int BST<T> :: CountLeafNodesX(BSTnode<T> *root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }

    return CountLeafNodesX(root->lchild) + CountLeafNodesX(root->rchild);
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountParentNodes
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Counts total number of parent nodes in BST.
//	Returns					:   int
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: CountParentNodes()
{
    return CountParentNodesX(first);
    cout<<"\n";
}

template<class T>
int BST<T> :: CountParentNodesX(BSTnode<T> *root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->lchild != NULL || root->rchild != NULL)
    {
        return 1 + CountParentNodesX(root->lchild) + CountParentNodesX(root->rchild);
    }
    return 0;
}

// ----------------------------- Sorting Algorithm -----------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class       : Sorting (ArrayX)
// Description : Generic Implementation of Sorting algorithm.
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
    public:
        T *Arr;                                           // Array of elements 
        int iSize;                                        // Size of array 
        bool Sorted;                                      // Array sorted flag
    
        //Constructor / Destructor
        ArrayX(int);
        ~ArrayX();

        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ArrayX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int no
//	Description             :   This is the constructor of class ArrayX.
//	Returns					:   None
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayX<T> :: ArrayX(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~ArrayX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is the destructor of class ArrayX.
//	Returns					:   None
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Accepts elements from user and checks if already sorted.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i = 0;                         

    for(i = 0; i < iSize;i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays array elements.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSort
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Sorts array using simple Bubble Sort.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: BubbleSort()
{
    int i = 0, j = 0;
    T temp;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; i < iSize ; i++)
    {
        for(j = 0; j < iSize - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"Data after Pass : "<<i+1<<"\n";

        Display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSortEfficient
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Optimized Bubble Sort using flag for early stopping.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    int i = 0, j = 0;
    T temp;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; (i < iSize && bFlag == true) ; i++)
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout<<"Data after Pass : "<<i+1<<"\n";

        Display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SelectionSort
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Sorts array using Selection Sort.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0 ; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertionSort
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Sorts array using Insertion Sort.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayX<T> :: InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

// ----------------------------- Searching Algorithm -----------------------------------

///////////////////////////////////////////////////////////////////////////////////////
//
// Class       : Searching (ArrayX)
// Description : Generic Implementation of Searching algorithm.
// Author      : Ishwari Pravin Jadhav
//
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayXX
{
    public:
        T *Arr;                                             // Array of elements
        int iSize;                                          // Size of array
        bool Sorted;                                        // Array sorted flag

        //Constructor / Destructor
        ArrayXX(int no);
        ~ArrayXX();

        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BiDirectionalSearch(T);
        bool BinarySearchInc(T);
        bool BinarySearchDec(T);
        bool BinarySearchEfficientInc(T);
        bool BinarySearchEfficientDec(T);
        bool CheckSortedInc();
        bool CheckSortedDec();
};

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ArrayX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   int no
//	Description             :   This is the constructor of class ArrayX.
//	Returns					:   None
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayXX<T> :: ArrayXX(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~ArrayX
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   This is the destructor of class ArrayX.
//	Returns					:   None
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
ArrayXX<T> :: ~ArrayXX()
{
    delete []Arr;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Accepts array elements from the user.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayXX<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    
    int i =0;                      

    for(i = 0; i < iSize;i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))     
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Displays all elements of the array.
//	Returns					:   void
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void ArrayXX<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LinearSearch
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Performs linear search on the array.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: LinearSearch(T no)    
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)                 
    {
        cout<<"Data is sorted\n";

        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BiDirectionalSearch
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Searches from both ends simultaneously.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: BiDirectionalSearch(T no)
{
    int iStart = 0;
    int iEnd = 0;

    bool bFlag = false;

    for(iStart = 0, iEnd = iSize-1 ; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchInc
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Performs binary search assuming ascending order.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: BinarySearchInc(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    } 

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchDec
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Performs binary search assuming descending order.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: BinarySearchDec(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])    
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientInc
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Performs optimized binary search for ascending array.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: BinarySearchEfficientInc(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)
    {
        cout<<"Data is not sorted\n";
        
        return LinearSearch(no);
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }   

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientDec
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   T no
//	Description             :   Performs optimized binary search for descending array.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: BinarySearchEfficientDec(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedInc
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Checks whether the array is sorted in ascending order.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: CheckSortedInc()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedDec
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   None
//	Description             :   Checks whether the array is sorted in descending order.
//	Returns					:   bool
//
////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool ArrayXX<T> :: CheckSortedDec()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	main
//	Function Date			:	14/09/2025
//	Function Author			:	Ishwari Pravin Jadhav
//	Parameters				:   NONE
//	Description             :   This is the entry point function of the program.
//	Returns					:   int
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<"------------------------- Queue Data Structure -------------------------------\n";

    // --------------------------- INT --------------------------------
    cout<<"--- Integer Queue ---\n";
    QueueX<int> Queueiobj;
    int Queueinum, QueueIntn;
    cout<<"How many integers to insert at first? ";
    cin>>QueueIntn;
    for(int i = 0; i < QueueIntn; i++)
    {
        cout<<"Enter integer value to enqueue: ";
        cin>>Queueinum;
        Queueiobj.Enqueue(Queueinum);
    }
    cout<<"Elements of Integer Queue:\n";
    Queueiobj.Display();
    cout<<"Count of elements: "<<Queueiobj.Count()<<"\n";
    cout<<"Removed element: "<<Queueiobj.Dequeue()<<"\n";
    cout<<"Elements after Dequeue:\n";
    Queueiobj.Display();
    cout<<"Count after Dequeue: "<<Queueiobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    // --------------------------- FLOAT --------------------------------
    cout<<"--- Float Queue ---\n";
    QueueX<float> Queuefobj;
    float Queuefnum;
    int QueueFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>QueueFloatn;
    for(int i = 0; i < QueueFloatn; i++)
    {
        cout<<"Enter float value to enqueue: ";
        cin>>Queuefnum;
        Queuefobj.Enqueue(Queuefnum);
    }
    cout<<"Elements of Float Queue:\n";
    Queuefobj.Display();
    cout<<"Count of elements: "<<Queuefobj.Count()<<"\n";
    cout<<"Removed element: "<<Queuefobj.Dequeue()<<"\n";
    cout<<"Elements after Dequeue:\n";
    Queuefobj.Display();
    cout<<"Count after Dequeue: "<<Queuefobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    // --------------------------- DOUBLE --------------------------------
    cout<<"--- Double Queue ---\n";
    QueueX<double> Queuedobj;
    double Queuednum;
    int QueueDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>QueueDoublen;
    for(int i = 0; i < QueueDoublen; i++)
    {
        cout<<"Enter double value to enqueue: ";
        cin>>Queuednum;
        Queuedobj.Enqueue(Queuednum);
    }
    cout<<"Elements of Double Queue:\n";
    Queuedobj.Display();
    cout<<"Count of elements: "<<Queuedobj.Count()<<"\n";
    cout<<"Removed element: "<<Queuedobj.Dequeue()<<"\n";
    cout<<"Elements after Dequeue:\n";
    Queuedobj.Display();
    cout<<"Count after Dequeue: "<<Queuedobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Queue ---\n";
    QueueX<char> Queuecobj;
    char Queuech;
    int QueueCharn;
    cout<<"How many char to insert at first? ";
    cin>>QueueCharn;
    for(int i = 0; i < QueueCharn; i++)
    {
        cout<<"Enter character to enqueue: ";
        cin>>Queuech;
        Queuecobj.Enqueue(Queuech);
    }
    cout<<"Elements of Character Queue:\n";
    Queuecobj.Display();
    cout<<"Count of elements: "<<Queuecobj.Count()<<"\n";
    cout<<"Removed element: "<<Queuecobj.Dequeue()<<"\n";
    cout<<"Elements after Dequeue:\n";
    Queuecobj.Display();
    cout<<"Count after Dequeue: "<<Queuecobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"------------------------- Stack Data Structure -------------------------------\n";

    // --------------------------- INT --------------------------------
    cout<<"--- Integer Stack ---\n";
    StackX<int> StackXiobj;
    int StackXinum, StackIntn;
    cout<<"How many integers to insert at first? ";
    cin>>StackIntn;
    for(int i = 0; i < StackIntn; i++)
    {
        cout<<"Enter integer value to push: ";
        cin>>StackXinum;
        StackXiobj.Push(StackXinum);
    }
    cout<<"Elements of Integer Stack:\n";
    StackXiobj.Display();
    cout<<"Count of elements: "<<StackXiobj.Count()<<"\n";
    cout<<"Popped element: "<<StackXiobj.Pop()<<"\n";
    cout<<"Elements after Pop:\n";
    StackXiobj.Display();
    cout<<"Count after Pop: "<<StackXiobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    // --------------------------- FLOAT --------------------------------
    cout<<"--- Float Stack ---\n";
    StackX<float> StackXfobj;
    float StackXfnum;
    int StackFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>StackFloatn;
    for(int i = 0; i < StackFloatn; i++)
    {
        cout<<"Enter float value to push: ";
        cin>>StackXfnum;
        StackXfobj.Push(StackXfnum);
    }
    cout<<"Elements of Float Stack:\n";
    StackXfobj.Display();
    cout<<"Count of elements: "<<StackXfobj.Count()<<"\n";
    cout<<"Popped element: "<<StackXfobj.Pop()<<"\n";
    cout<<"Elements after Pop:\n";
    StackXfobj.Display();
    cout<<"Count after Pop: "<<StackXfobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";


    // --------------------------- DOUBLE --------------------------------
    cout<<"--- Double Stack ---\n";
    StackX<double> StackXdobj;
    double StackXdnum;
    int StackDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>StackDoublen;
    for(int i = 0; i < StackDoublen; i++)
    {
        cout<<"Enter double value to push: ";
        cin>>StackXdnum;
        StackXdobj.Push(StackXdnum);
    }
    cout<<"Elements of Double Stack:\n";
    StackXdobj.Display();
    cout<<"Count of elements: "<<StackXdobj.Count()<<"\n";
    cout<<"Popped element: "<<StackXdobj.Pop()<<"\n";
    cout<<"Elements after Pop:\n";
    StackXdobj.Display();
    cout<<"Count after Pop: "<<StackXdobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Stack ---\n";
    StackX<char> StackXcobj;
    char StackXch;
    int StackCharn;
    cout<<"How many char to insert at first? ";
    cin>>StackCharn;
    for(int i = 0; i < StackCharn; i++)
    {
        cout<<"Enter character to push: ";
        cin>>StackXch;
        StackXcobj.Push(StackXch);
    }
    cout<<"Elements of Character Stack:\n";
    StackXcobj.Display();
    cout<<"Count of elements: "<<StackXcobj.Count()<<"\n";
    cout<<"Popped element: "<<StackXcobj.Pop()<<"\n";
    cout<<"Elements after Pop:\n";
    StackXcobj.Display();
    cout<<"Count after Pop: "<<StackXcobj.Count()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"------------------------- Singly Linear Linked List -------------------------------\n\n";

    // --------------------------- INT --------------------------------
    cout<<"--- Integer Linked List ---\n";
    SinglyLL<int> SinglyLLiobj;
    int SinglyLLinum, SinglyLLIntn;
    cout<<"How many integers to insert at first? ";
    cin>>SinglyLLIntn;
    for(int i = 0; i < SinglyLLIntn; i++)
    {
        cout<<"Enter integer to insert at first: ";
        cin>>SinglyLLinum;
        SinglyLLiobj.InsertFirst(SinglyLLinum);
    }
    cout<<"How many integers to insert at last? ";
    cin>>SinglyLLIntn;
    for(int i = 0; i < SinglyLLIntn; i++)
    {
        cout<<"Enter integer to insert at last: ";
        cin>>SinglyLLinum;
        SinglyLLiobj.InsertLast(SinglyLLinum);
    }
    SinglyLLiobj.Display();
    cout<< "Count: "<<SinglyLLiobj.Count()<<"\n";
    cout<< "Sum: "<<SinglyLLiobj.Addition()<<"\n";
    cout<< "Largest: "<<SinglyLLiobj.LargestElement()<<"\n";
    cout<< "Smallest: "<<SinglyLLiobj.SmallestElement()<<"\n";
    cout<< "Second Max: "<<SinglyLLiobj.SecMaximum()<<"\n";
    cout<< "Even Sum: "<<SinglyLLiobj.AdditionEven()<<"\n";
    SinglyLLiobj.DisplayPrime();
    cout<<"\n";
    SinglyLLiobj.DisplayPerfect();
    cout<<"\n";
    SinglyLLiobj.SumDigit();
    cout<<"\n";
    SinglyLLiobj.DisplayPalindrome();
    cout<<"\n";
    SinglyLLiobj.DisplayProduct();
    cout<<"\n";
    SinglyLLiobj.DisplaySmall();
    cout<<"\n";
    SinglyLLiobj.DisplayLarge();
    cout<<"\n";
    cout << "---------------------------------------------\n\n";

    // --------------------------- FLOAT --------------------------------
    cout<<"--- Float Linked List ---\n";
    SinglyLL<float> SinglyLLfobj;
    float SinglyLLfnum;
    int SinglyLLFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>SinglyLLFloatn;
    for(int i = 0; i < SinglyLLFloatn; i++)
    {
        cout<<"Enter float to insert at first: ";
        cin>>SinglyLLfnum;
        SinglyLLfobj.InsertFirst(SinglyLLfnum);
    }
    cout<<"How many floats to insert at last? ";
    cin>>SinglyLLFloatn;
    for(int i = 0; i < SinglyLLFloatn; i++)
    {
        cout<<"Enter float to insert at last: ";
        cin>>SinglyLLfnum;
        SinglyLLfobj.InsertLast(SinglyLLfnum);
    }
    SinglyLLfobj.Display();
    cout<<"Count: "<<SinglyLLfobj.Count()<<"\n";
    cout<<"Sum: "<<SinglyLLfobj.Addition()<<"\n";
    cout<<"Largest: "<<SinglyLLfobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<SinglyLLfobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<SinglyLLfobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE --------------------------------
    cout<<"--- Double Linked List ---\n";
    SinglyLL<double> SinglyLLdobj;
    double SinglyLLdnum;
    int SinglyLLDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>SinglyLLDoublen;
    for(int i = 0; i < SinglyLLDoublen; i++)
    {
        cout<<"Enter double to insert at first: ";
        cin>>SinglyLLdnum;
        SinglyLLdobj.InsertFirst(SinglyLLdnum);
    }
    cout<<"How many doubles to insert at last? ";
    cin>>SinglyLLDoublen;
    for(int i = 0; i < SinglyLLDoublen; i++)
    {
        cout<<"Enter double to insert at last: ";
        cin>>SinglyLLdnum;
        SinglyLLdobj.InsertLast(SinglyLLdnum);
    }
    SinglyLLdobj.Display();
    cout<<"Count: "<<SinglyLLdobj.Count()<<"\n";
    cout<<"Sum: "<<SinglyLLdobj.Addition()<<"\n";
    cout<<"Largest: "<<SinglyLLdobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<SinglyLLdobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<SinglyLLdobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Linked List ---\n";
    SinglyLL<char> SinglyLLcobj;
    char SinglyLLch;
    int SinglyLLCharn;
    cout<<"How many chars to insert at first? ";
    cin>>SinglyLLCharn;
    for(int i = 0; i < SinglyLLCharn; i++)
    {
        cout<<"Enter char to insert at first: ";
        cin>>SinglyLLch;
        SinglyLLcobj.InsertFirst(SinglyLLch);
    }
    cout<<"How many chars to insert at last? ";
    cin>>SinglyLLCharn;
    for(int i = 0; i < SinglyLLCharn; i++)
    {
        cout<<"Enter char to insert at last: ";
        cin>>SinglyLLch;
        SinglyLLcobj.InsertLast(SinglyLLch);
    }
    SinglyLLcobj.Display();
    cout<<"Count: " <<SinglyLLcobj.Count()<<"\n";
    cout<<"Largest char: "<<SinglyLLcobj.LargestElement()<<"\n";
    cout<<"Smallest char: "<<SinglyLLcobj.SmallestElement()<<"\n";
    cout<<"Second Max char: "<<SinglyLLcobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"------------------------- Singly Circular Linked List -------------------------------\n\n";

    // --------------------------- INT --------------------------------
    cout<<"--- Integer Linked List ---\n";
    SinglyCLL<int> SinglyCLLiobj;
    int SinglyCLLinum, SinglyCLLIntn;
    cout<<"How many integers to insert at first? ";
    cin>>SinglyCLLIntn;
    for(int i = 0; i < SinglyCLLIntn; i++)
    {
        cout<<"Enter integer to insert at first: ";
        cin>>SinglyCLLinum;
        SinglyCLLiobj.InsertFirst(SinglyCLLinum);
    }
    cout<<"How many integers to insert at last? ";
    cin>>SinglyCLLIntn;
    for(int i = 0; i < SinglyCLLIntn; i++)
    {
        cout<<"Enter integer to insert at last: ";
        cin>>SinglyCLLinum;
        SinglyCLLiobj.InsertLast(SinglyCLLinum);
    }
    SinglyCLLiobj.Display();
    cout<< "Count: "<<SinglyCLLiobj.Count()<<"\n";
    cout<< "Sum: "<<SinglyCLLiobj.Addition()<<"\n";
    cout<< "Largest: "<<SinglyCLLiobj.LargestElement()<<"\n";
    cout<< "Smallest: "<<SinglyCLLiobj.SmallestElement()<<"\n";
    cout<< "Second Max: "<<SinglyCLLiobj.SecMaximum()<<"\n";
    cout<< "Even Sum: "<<SinglyCLLiobj.AdditionEven()<<"\n";
    SinglyCLLiobj.DisplayPrime();
    cout<<"\n";
    SinglyCLLiobj.DisplayPerfect();
    cout<<"\n";
    SinglyCLLiobj.SumDigit();
    cout<<"\n";
    SinglyCLLiobj.DisplayPalindrome();
    cout<<"\n";
    SinglyCLLiobj.DisplayProduct();
    cout<<"\n";
    SinglyCLLiobj.DisplaySmall();
    cout<<"\n";
    SinglyCLLiobj.DisplayLarge();
    cout<<"\n";
    cout << "---------------------------------------------\n\n";

    // --------------------------- FLOAT --------------------------------
    cout<<"--- Float Linked List ---\n";
    SinglyCLL<float> SinglyCLLfobj;
    float SinglyCLLfnum;
    int SinglyCLLFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>SinglyCLLFloatn;
    for(int i = 0; i < SinglyCLLFloatn; i++)
    {
        cout<<"Enter float to insert at first: ";
        cin>>SinglyCLLfnum;
        SinglyCLLfobj.InsertFirst(SinglyCLLfnum);
    }
    cout<<"How many floats to insert at last? ";
    cin>>SinglyCLLFloatn;
    for(int i = 0; i < SinglyCLLFloatn; i++)
    {
        cout<<"Enter float to insert at last: ";
        cin>>SinglyCLLfnum;
        SinglyCLLfobj.InsertLast(SinglyCLLfnum);
    }
    SinglyCLLfobj.Display();
    cout<<"Count: "<<SinglyCLLfobj.Count()<<"\n";
    cout<<"Sum: "<<SinglyCLLfobj.Addition()<<"\n";
    cout<<"Largest: "<<SinglyCLLfobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<SinglyCLLfobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<SinglyCLLfobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE --------------------------------
    cout<<"--- Double Linked List ---\n";
    SinglyCLL<double> SinglyCLLdobj;
    double SinglyCLLdnum;
    int SinglyCLLDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>SinglyCLLDoublen;
    for(int i = 0; i < SinglyCLLDoublen; i++)
    {
        cout<<"Enter double to insert at first: ";
        cin>>SinglyCLLdnum;
        SinglyCLLdobj.InsertFirst(SinglyCLLdnum);
    }
    cout<<"How many doubles to insert at last? ";
    cin>>SinglyCLLDoublen;
    for(int i = 0; i < SinglyCLLDoublen; i++)
    {
        cout<<"Enter double to insert at last: ";
        cin>>SinglyCLLdnum;
        SinglyCLLdobj.InsertLast(SinglyCLLdnum);
    }
    SinglyCLLdobj.Display();
    cout<<"Count: "<<SinglyCLLdobj.Count()<<"\n";
    cout<<"Sum: "<<SinglyCLLdobj.Addition()<<"\n";
    cout<<"Largest: "<<SinglyCLLdobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<SinglyCLLdobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<SinglyCLLdobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Linked List ---\n";
    SinglyCLL<char> SinglyCLLcobj;
    char SinglyCLLch;
    int SinglyCLLCharn;
    cout<<"How many chars to insert at first? ";
    cin>>SinglyCLLCharn;
    for(int i = 0; i < SinglyCLLCharn; i++)
    {
        cout<<"Enter char to insert at first: ";
        cin>>SinglyCLLch;
        SinglyCLLcobj.InsertFirst(SinglyCLLch);
    }
    cout<<"How many chars to insert at last? ";
    cin>>SinglyCLLCharn;
    for(int i = 0; i < SinglyCLLCharn; i++)
    {
        cout<<"Enter char to insert at last: ";
        cin>>SinglyCLLch;
        SinglyCLLcobj.InsertLast(SinglyCLLch);
    }
    SinglyCLLcobj.Display();
    cout<<"Count: " <<SinglyCLLcobj.Count()<<"\n";
    cout<<"Largest char: "<<SinglyCLLcobj.LargestElement()<<"\n";
    cout<<"Smallest char: "<<SinglyCLLcobj.SmallestElement()<<"\n";
    cout<<"Second Max char: "<<SinglyCLLcobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"------------------------- Doubly Linear Linked List -------------------------------\n\n";

    // --------------------------- INT --------------------------------
    cout<<"--- Integer Linked List ---\n";
    DoublyLL<int> DoublyLLiobj;
    int DoublyLLinum, DoublyLLIntn;
    cout<<"How many integers to insert at first? ";
    cin>>DoublyLLIntn;
    for(int i = 0; i < DoublyLLIntn; i++)
    {
        cout<<"Enter integer to insert at first: ";
        cin>>DoublyLLinum;
        DoublyLLiobj.InsertFirst(DoublyLLinum);
    }
    cout<<"How many integers to insert at last? ";
    cin>>DoublyLLIntn;
    for(int i = 0; i < DoublyLLIntn; i++)
    {
        cout<<"Enter integer to insert at last: ";
        cin>>DoublyLLinum;
        DoublyLLiobj.InsertLast(DoublyLLinum);
    }
    DoublyLLiobj.Display();
    cout<< "Count: "<<DoublyLLiobj.Count()<<"\n";
    cout<< "Sum: "<<DoublyLLiobj.Addition()<<"\n";
    cout<< "Largest: "<<DoublyLLiobj.LargestElement()<<"\n";
    cout<< "Smallest: "<<DoublyLLiobj.SmallestElement()<<"\n";
    cout<< "Second Max: "<<DoublyLLiobj.SecMaximum()<<"\n";
    cout<< "Even Sum: "<<DoublyLLiobj.AdditionEven()<<"\n";
    DoublyLLiobj.DisplayPrime();
    cout<<"\n";
    DoublyLLiobj.DisplayPerfect();
    cout<<"\n";
    DoublyLLiobj.SumDigit();
    cout<<"\n";
    DoublyLLiobj.DisplayPalindrome();
    cout<<"\n";
    DoublyLLiobj.DisplayProduct();
    cout<<"\n";
    DoublyLLiobj.DisplaySmall();
    cout<<"\n";
    DoublyLLiobj.DisplayLarge();
    cout<<"\n";
    cout << "---------------------------------------------\n\n";

    // --------------------------- FLOAT --------------------------------
    cout<<"--- Float Linked List ---\n";
    DoublyLL<float> DoublyLLfobj;
    float DoublyLLfnum;
    int DoublyLLFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>DoublyLLFloatn;
    for(int i = 0; i < DoublyLLFloatn; i++)
    {
        cout<<"Enter float to insert at first: ";
        cin>>DoublyLLfnum;
        DoublyLLfobj.InsertFirst(DoublyLLfnum);
    }
    cout<<"How many floats to insert at last? ";
    cin>>DoublyLLFloatn;
    for(int i = 0; i < DoublyLLFloatn; i++)
    {
        cout<<"Enter float to insert at last: ";
        cin>>DoublyLLfnum;
        DoublyLLfobj.InsertLast(DoublyLLfnum);
    }
    DoublyLLfobj.Display();
    cout<<"Count: "<<DoublyLLfobj.Count()<<"\n";
    cout<<"Sum: "<<DoublyLLfobj.Addition()<<"\n";
    cout<<"Largest: "<<DoublyLLfobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<DoublyLLfobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<DoublyLLfobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE --------------------------------
    cout<<"--- Double Linked List ---\n";
    DoublyLL<double> DoublyLLdobj;
    double DoublyLLdnum;
    int DoublyLLDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>DoublyLLDoublen;
    for(int i = 0; i < DoublyLLDoublen; i++)
    {
        cout<<"Enter double to insert at first: ";
        cin>>DoublyLLdnum;
        DoublyLLdobj.InsertFirst(DoublyLLdnum);
    }
    cout<<"How many doubles to insert at last? ";
    cin>>DoublyLLDoublen;
    for(int i = 0; i < DoublyLLDoublen; i++)
    {
        cout<<"Enter double to insert at last: ";
        cin>>DoublyLLdnum;
        DoublyLLdobj.InsertLast(DoublyLLdnum);
    }
    DoublyLLdobj.Display();
    cout<<"Count: "<<DoublyLLdobj.Count()<<"\n";
    cout<<"Sum: "<<DoublyLLdobj.Addition()<<"\n";
    cout<<"Largest: "<<DoublyLLdobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<DoublyLLdobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<DoublyLLdobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Linked List ---\n";
    DoublyLL<char> DoublyLLcobj;
    char DoublyLLch;
    int DoublyLLCharn;
    cout<<"How many chars to insert at first? ";
    cin>>DoublyLLCharn;
    for(int i = 0; i < DoublyLLCharn; i++)
    {
        cout<<"Enter char to insert at first: ";
        cin>>DoublyLLch;
        DoublyLLcobj.InsertFirst(DoublyLLch);
    }
    cout<<"How many chars to insert at last? ";
    cin>>DoublyLLCharn;
    for(int i = 0; i < DoublyLLCharn; i++)
    {
        cout<<"Enter char to insert at last: ";
        cin>>DoublyLLch;
        DoublyLLcobj.InsertLast(DoublyLLch);
    }
    DoublyLLcobj.Display();
    cout<<"Count: " <<DoublyLLcobj.Count()<<"\n";
    cout<<"Largest char: "<<DoublyLLcobj.LargestElement()<<"\n";
    cout<<"Smallest char: "<<DoublyLLcobj.SmallestElement()<<"\n";
    cout<<"Second Max char: "<<DoublyLLcobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"------------------------- Doubly Circular Linked List -------------------------------\n\n";

    // --------------------------- INT --------------------------------
    cout<< "--- Integer Linked List ---\n";
    DoublyCLL<int> DoublyCLLiobj;
    int DoublyCLLinum, DoublyCLLIntn;
    cout<<"How many integers to insert at first? ";
    cin>>DoublyCLLIntn;
    for(int i = 0; i < DoublyCLLIntn; i++)
    {
        cout<<"Enter integer to insert at first: ";
        cin>>DoublyCLLinum;
        DoublyCLLiobj.InsertFirst(DoublyCLLinum);
    }
    cout<<"How many integers to insert at last? ";
    cin>>DoublyCLLIntn;
    for(int i = 0; i < DoublyCLLIntn; i++)
    {
        cout<<"Enter integer to insert at last: ";
        cin>>DoublyCLLinum;
        DoublyCLLiobj.InsertLast(DoublyCLLinum);
    }
    DoublyCLLiobj.Display();
    cout<< "Count: "<<DoublyCLLiobj.Count()<<"\n";
    cout<< "Sum: "<<DoublyCLLiobj.Addition()<<"\n";
    cout<< "Largest: "<<DoublyCLLiobj.LargestElement()<<"\n";
    cout<< "Smallest: "<<DoublyCLLiobj.SmallestElement()<<"\n";
    cout<< "Second Max: "<<DoublyCLLiobj.SecMaximum()<<"\n";
    cout<< "Even Sum: "<<DoublyCLLiobj.AdditionEven()<<"\n";
    DoublyCLLiobj.DisplayPrime();
    cout<<"\n";
    DoublyCLLiobj.DisplayPerfect();
    cout<<"\n";
    DoublyCLLiobj.SumDigit();
    cout<<"\n";
    DoublyCLLiobj.DisplayPalindrome();
    cout<<"\n";
    DoublyCLLiobj.DisplayProduct();
    cout<<"\n";
    DoublyCLLiobj.DisplaySmall();
    cout<<"\n";
    DoublyCLLiobj.DisplayLarge();
    cout<<"\n";
    cout << "---------------------------------------------\n\n";

    // --------------------------- FLOAT --------------------------------
    cout<< "--- Float Linked List ---\n";
    DoublyCLL<float> DoublyCLLfobj;
    float DoublyCLLfnum;
    int DoublyCLLFloatn;
    cout<<"How many floats to insert at first? ";
    cin>>DoublyCLLFloatn;
    for(int i = 0; i < DoublyCLLFloatn; i++)
    {
        cout<<"Enter float to insert at first: ";
        cin>>DoublyCLLfnum;
        DoublyCLLfobj.InsertFirst(DoublyCLLfnum);
    }
    cout<<"How many floats to insert at last? ";
    cin>>DoublyCLLFloatn;
    for(int i = 0; i < DoublyCLLFloatn; i++)
    {
        cout<<"Enter float to insert at last: ";
        cin>>DoublyCLLfnum;
        DoublyCLLfobj.InsertLast(DoublyCLLfnum);
    }
    DoublyCLLfobj.Display();
    cout<<"Count: "<<DoublyCLLfobj.Count()<<"\n";
    cout<<"Sum: "<<DoublyCLLfobj.Addition()<<"\n";
    cout<<"Largest: "<<DoublyCLLfobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<DoublyCLLfobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<DoublyCLLfobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE --------------------------------
    cout<< "--- Double Linked List ---\n";
    DoublyCLL<double> DoublyCLLdobj;
    double DoublyCLLdnum;
    int DoublyCLLDoublen;
    cout<<"How many doubles to insert at first? ";
    cin>>DoublyCLLDoublen;
    for(int i = 0; i < DoublyCLLDoublen; i++)
    {
        cout<<"Enter double to insert at first: ";
        cin>>DoublyCLLdnum;
        DoublyCLLdobj.InsertFirst(DoublyCLLdnum);
    }
    cout<<"How many doubles to insert at last? ";
    cin>>DoublyCLLDoublen;
    for(int i = 0; i < DoublyCLLDoublen; i++)
    {
        cout<<"Enter double to insert at last: ";
        cin>>DoublyCLLdnum;
        DoublyCLLdobj.InsertLast(DoublyCLLdnum);
    }
    DoublyCLLdobj.Display();
    cout<<"Count: "<<DoublyCLLdobj.Count()<<"\n";
    cout<<"Sum: "<<DoublyCLLdobj.Addition()<<"\n";
    cout<<"Largest: "<<DoublyCLLdobj.LargestElement()<<"\n";
    cout<<"Smallest: "<<DoublyCLLdobj.SmallestElement()<<"\n";
    cout<<"Second Max: "<<DoublyCLLdobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR --------------------------------
    cout<<"--- Character Linked List ---\n";
    DoublyCLL<char> DoublyCLLcobj;
    char DoublyCLLch;
    int DoublyCLLCharn;
    cout<<"How many chars to insert at first? ";
    cin>>DoublyCLLCharn;
    for(int i = 0; i < DoublyCLLCharn; i++)
    {
        cout<<"Enter char to insert at first: ";
        cin>>DoublyCLLch;
        DoublyCLLcobj.InsertFirst(DoublyCLLch);
    }
    cout<<"How many chars to insert at last? ";
    cin>>DoublyCLLCharn;
    for(int i = 0; i < DoublyCLLCharn; i++)
    {
        cout<<"Enter char to insert at last: ";
        cin>>DoublyCLLch;
        DoublyCLLcobj.InsertLast(DoublyCLLch);
    }
    DoublyCLLcobj.Display();
    cout<<"Count: " <<DoublyCLLcobj.Count()<<"\n";
    cout<<"Largest char: "<<DoublyCLLcobj.LargestElement()<<"\n";
    cout<<"Smallest char: "<<DoublyCLLcobj.SmallestElement()<<"\n";
    cout<<"Second Max char: "<<DoublyCLLcobj.SecMaximum()<<"\n";
    cout<<"---------------------------------------------\n";

    cout<<"----------------------------- Binary Search Tree -----------------------------------\n\n";

    // --------------------------- INT --------------------------------
    BST<int> BSTiobj;
    cout<<"--- Insertion Operation (int) ---\n";
    int BSTinum, BSTIntn;
    cout<<"How many integers to insert? ";
    cin>>BSTIntn;
    for(int i = 0; i < BSTIntn; i++)
    {
        cout<<"Enter integer to insert: ";
        cin>>BSTinum;
        BSTiobj.Insert(BSTinum);
    }
    cout << "Elements inserted successfully...\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Traversal Operation (int) ---\n";
    cout<<"Inorder Traversal (LNR)   : ";
    BSTiobj.Inorder();
    cout<<"\n";
    cout<<"Preorder Traversal (NLR)  : ";
    BSTiobj.Preorder();
    cout<<"\n";
    cout<<"Postorder Traversal (LRN) : ";
    BSTiobj.Postorder();
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Searching Operation (int) ---\n";
    cout<<"Enter integer to search: ";
    cin>>BSTinum;
    bool bRet = BSTiobj.Search(BSTinum);
    if(bRet)
    {
        cout<<BSTinum<<" is present in BST.\n";
    }
    else
    {
        cout<<BSTinum<<"is not present in BST.\n";
    }
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Counting Operation (int) ---\n";
    cout<<"Total number of nodes         : "<<BSTiobj.Count()<<"\n";
    cout<<"Total number of leaf nodes    : "<<BSTiobj.CountLeafNodes()<<"\n";
    cout<<"Total number of parent nodes  : "<<BSTiobj.CountParentNodes()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- FLOAT --------------------------------
    BST<float> BSTfobj;
    cout<<"--- Insertion Operation (float) ---\n";
    float BSTfnum;
    int BSTFloatn;
    cout<<"How many floats to insert? ";
    cin>>BSTFloatn;
    for(int i = 0; i < BSTFloatn; i++)
    {
        cout<<"Enter float to insert: ";
        cin>>BSTfnum;
        BSTfobj.Insert(BSTfnum);
    }
    cout<<"Elements inserted successfully...\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Traversal Operation (float) ---\n";
    cout<<"Inorder Traversal (LNR)   : ";
    BSTfobj.Inorder();
    cout<<"\n";
    cout<<"Preorder Traversal (NLR)  : ";
    BSTfobj.Preorder();
    cout<<"\n";
    cout<<"Postorder Traversal (LRN) : ";
    BSTfobj.Postorder();
    cout<<"\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Searching Operation (float) ---\n";
    cout<<"Enter float to search: ";
    cin>>BSTfnum;
    bRet = BSTfobj.Search(BSTfnum);
    if(bRet)
    {
        cout<<BSTfnum<<" is present in BST.\n";
    }
    else
    {
        cout<<BSTfnum<<" is not present in BST.\n";
    }
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Counting Operation (float) ---\n";
    cout<<"Total number of nodes         : "<<BSTfobj.Count()<<"\n";
    cout<<"Total number of leaf nodes    : "<<BSTfobj.CountLeafNodes()<<"\n";
    cout<<"Total number of parent nodes  : "<<BSTfobj.CountParentNodes()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE --------------------------------
    BST<double> BSTdobj;
    cout<<"--- Insertion Operation (double) ---\n";
    double BSTdnum;
    int BSTDoublen;
    cout<<"How many doubles to insert? ";
    cin>>BSTDoublen;
    for(int i = 0; i < BSTDoublen; i++)
    {
        cout<<"Enter double to insert: ";
        cin>>BSTdnum;
        BSTdobj.Insert(BSTdnum);
    }
    cout<<"Elements inserted successfully...\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Traversal Operation (double) ---\n";
    cout<<"Inorder Traversal (LNR)   : ";
    BSTdobj.Inorder();
    cout<<"\n";
    cout<<"Preorder Traversal (NLR)  : ";
    BSTdobj.Preorder();
    cout<<"\n";
    cout<<"Postorder Traversal (LRN) : ";
    BSTdobj.Postorder();
    cout<<"\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Searching Operation (double) ---\n";
    cout<<"Enter double to search: ";
    cin>>BSTdnum;
    bRet = BSTdobj.Search(BSTdnum);
    if(bRet)
    {
        cout<<BSTdnum<<" is present in BST.\n";
    }
    else
    {
        cout<<BSTdnum<<" is not present in BST.\n";
    }
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Counting Operation (double) ---\n";
    cout<<"Total number of nodes         : "<<BSTdobj.Count()<<"\n";
    cout<<"Total number of leaf nodes    : "<<BSTdobj.CountLeafNodes()<<"\n";
    cout<<"Total number of parent nodes  : "<<BSTdobj.CountParentNodes()<<"\n";
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR --------------------------------
    BST<char> BSTcobj;
    cout<<"--- Insertion Operation (char) ---\n";
    char BSTch;
    int BSTCharn;
    cout<<"How many chars to insert? ";
    cin>>BSTCharn;
    for(int i = 0; i < BSTCharn; i++)
    {
        cout<<"Enter char to insert: ";
        cin>>BSTch;
        BSTcobj.Insert(BSTch);
    }
    cout<<"Elements inserted successfully...\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Traversal Operation (char) ---\n";
    cout<<"Inorder Traversal (LNR)   : ";
    BSTcobj.Inorder();
    cout<<"\n";
    cout<<"Preorder Traversal (NLR)  : ";
    BSTcobj.Preorder();
    cout<<"\n";
    cout<<"Postorder Traversal (LRN) : ";
    BSTcobj.Postorder();
    cout<<"\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Searching Operation (char) ---\n";
    cout<<"Enter char to search: ";
    cin>>BSTch;
    bRet = BSTcobj.Search(BSTch);
    if(bRet)
    {
        cout<<BSTch<<" is present in BST.\n";
    }
    else
    {
        cout<<BSTch<<" is not present in BST.\n";
    }
    cout<<"---------------------------------------------\n\n";

    cout<<"--- Counting Operation (char) ---\n";
    cout<<"Total number of nodes         : "<<BSTcobj.Count()<<"\n";
    cout<<"Total number of leaf nodes    : "<<BSTcobj.CountLeafNodes()<<"\n";
    cout<<"Total number of parent nodes  : "<<BSTcobj.CountParentNodes()<<"\n";
    cout<<"---------------------------------------------\n\n";

    cout<<"----------------------------- Sorting Algorithm -----------------------------------\n\n";

    // --------------------------- INT ---------------------------------
    cout<<"--- Integer Sorting ---\n";
    int SortIntn;
    cout<<"Enter number of integers: ";
    cin>>SortIntn;
    ArrayX<int> Sortiobj(SortIntn);
    Sortiobj.Accept();
    Sortiobj.Display();
    Sortiobj.BubbleSortEfficient();
    Sortiobj.Display();
    cout<<"---------------------------------------------\n\n";

    // --------------------------- FLOAT -------------------------------
    cout<<"--- Float Sorting ---\n";
    int SortFloatn;
    cout<<"Enter number of floats: ";
    cin>>SortFloatn;
    ArrayX<float> Sortfobj(SortFloatn);
    Sortfobj.Accept();
    Sortfobj.Display();
    Sortfobj.SelectionSort();
    Sortfobj.Display();
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE -------------------------------
    cout<<"--- Double Sorting ---\n";
    int SortDoublen;
    cout<<"Enter number of doubles: ";
    cin>>SortDoublen;
    ArrayX<double> Sortdobj(SortDoublen);
    Sortdobj.Accept();
    Sortdobj.Display();
    Sortdobj.InsertionSort();
    Sortdobj.Display();
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR -------------------------------
    cout<<"--- Character Sorting ---\n";
    int SortCharn;
    cout<<"Enter number of characters: ";
    cin>>SortCharn;
    ArrayX<char> Sortcobj(SortCharn);
    Sortcobj.Accept();
    Sortcobj.Display();
    Sortcobj.BubbleSort();
    Sortcobj.Display();
    cout<<"---------------------------------------------\n\n";

    cout<<"----------------------------- Searching Algorithm -----------------------------------\n\n";

    // --------------------------- INT ---------------------------------
    cout<<"--- Integer Searching ---\n";
    int SearchIntn;
    cout<<"Enter number of integers: ";
    cin>>SearchIntn;
    ArrayXX<int> searchiobj(SearchIntn);
    searchiobj.Accept();
    searchiobj.Display();
    int Searchinum;
    cout<<"Enter integer to search: ";
    cin>>Searchinum;
    if(searchiobj.LinearSearch(Searchinum))
    {
        cout<<Searchinum<<" is Found in the array.\n";
    }
    else
    {
        cout<<Searchinum<<" is Not Found in the array.\n";
    }
    cout<<"---------------------------------------------\n\n";

    // --------------------------- FLOAT ---------------------------------
    cout<<"--- Float Searching ---\n";
    int SearchFloatn;
    cout<<"Enter number of floats: ";
    cin>>SearchFloatn;
    ArrayXX<float> searchfobj(SearchFloatn);
    searchfobj.Accept();
    searchfobj.Display();
    float searchfnum;
    cout<<"Enter float to search: ";
    cin>>searchfnum;
    if(searchfobj.LinearSearch(searchfnum))
    {
        cout<<searchfnum<<" is Found in the array.\n";
    }
    else
    {
        cout<<searchfnum<<" is Not Found in the array.\n";
    }
    cout<<"---------------------------------------------\n\n";

    // --------------------------- DOUBLE ---------------------------------
    cout<<"--- Double Searching ---\n";
    int SearchDoublen;
    cout<<"Enter number of doubles: ";
    cin>>SearchDoublen;
    ArrayXX<double> searchdobj(SearchDoublen);
    searchdobj.Accept();
    searchdobj.Display();
    double searchdnum;
    cout<<"Enter double to search: ";
    cin>>searchdnum;
    if(searchdobj.LinearSearch(searchdnum))
    {
        cout<<searchdnum<<" is Found in the array.\n";
    }
    else
    {
        cout<<searchdnum<<" is Not Found in the array.\n";
    }
    cout<<"---------------------------------------------\n\n";

    // --------------------------- CHAR ---------------------------------
    cout<<"--- Character Searching ---\n";
    int SearchCharn;
    cout<<"Enter number of characters: ";
    cin>>SearchCharn;
    ArrayXX<char> searchcobj(SearchCharn);
    searchcobj.Accept();
    searchcobj.Display();
    char searchch;
    cout<<"Enter character to search: ";
    cin>>searchch;
    if(searchcobj.LinearSearch(searchch))
    {
        cout<<searchch<<" is Found in the array.\n";
    }
    else
    {
        cout<<searchch<<" is Not Found in the array.\n";
    }
    cout<<"---------------------------------------------\n\n";

    return 0;
}