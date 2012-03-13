#include "StdAfx.h"
#include "MList.h"

using namespace std;

cList::cList():CL()
{}

cList::cList(int n):CL(n)
{}

cList::cList(cList& c):CL(c)	//copy constructor;
{}

cList::~cList()
{}

void cList::insert(double val)
{
	V* temp;
	V* pr;
	V* after;

	pr=getFront();

	if( ( pr==NULL ) || ( val<=pr->v ) )	//insert at the front;
	{
		setFront(val);
		
		return;
	}

	pr=getBack();
	
	if(val>=pr->v)	//insert at the back;
	{
		push(val);
		
		return;
	}

	pr=getFront();
	
	try
	{	
		temp=new V(val);
	
	}catch(...)

	{
		cout<<"Error!"<<endl;
	}

	while( ( pr ) && ( val > pr->v ) )	//find position
		pr=pr->n;

	after=pr->p;

	after->n=temp;	//link new element with previous element;
	temp->p=after;

	temp->n=pr;	//link new element with next element;
	pr->p=temp;
}


void cList::insert(unsigned n,double* m)//insert array ;
{
	for(unsigned i=0;i<n;i++)
		insert( *(m+i) );
}

