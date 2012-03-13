#include "StdAfx.h"
#include <iostream>
#include "CL.h"

using namespace std;

V* CL::getBack()
{
	return back;
}

V* CL::getFront()
{
	return front;
}

void CL::setFront(double pr)
{
	V* temp;
	
	try
	{	
		temp=new V(pr);
	
	}catch(...)

	{
		cout<<"Error!"<<endl;
	}

	if(front)	//list not empty;
	{
		front->p=temp;
		temp->n=front;
		front=temp;
		front->p=NULL;
	}
	
	else	//list empty,
	{
		temp->n = temp->p = NULL;
		front = back = temp;	//new record is the first and the last element in the list 
	}
}
unsigned CL::getSize(void)
{
	return size;
}

void CL::push(double pr)
{
	V* temp;
	
	try
	{	
		temp=new V(pr);
	
	}catch(...)

	{
		cout<<"Error!"<<endl;
	}

	if(back)	//list not empty;
	{
		back->n = temp;
		temp->p = back;
		back = temp;
		back->n=NULL;
	}
	
	else	//list empty,
	{
		temp->n = temp->p = NULL;
		front = back = temp;	//new record is the first and the last element in the list 
	}
	
	size++;
}

int CL::pop( double& res ) 
{
	if (!back) return (int)0;
	
	res=front->v;
	
	if ( front == back)
	{
		delete front;
		front=back=NULL;
	}

	else
	{
		front = front->n;
		delete front->p;
		front->p=NULL;
	}
	return (int)1;
}

void CL::print( void )
{
	V* p = front;
	
	while( p )
	{
		cout<<p->v<<endl;
		p = p->n;
	}
}

void CL::revPrint(void)
{
	V* pr = back;

	while( pr )
	{
		cout<<pr->v<<endl;
		pr = pr->p;
	}

}

CL::CL()
{
	size=( int )0;
	front = back = NULL;
}
CL::CL( int n )
{
	double bf1,bf2;
	int i = (int)1;
	
	back = front = NULL;
	size=(int)0;

	cout << "1. ->";
	cin >> bf1;
	getchar();
	push( bf1 );

	while( i < n )
	{
		cout << (i+1)<<". ->";
		cin >> bf2;
		getchar ();
		
		if( bf2 < bf1 )
			cout << "Error! Value must be greater then " << bf1 << "!" << endl;
		
		else
		{
			push( bf2 );
			i++;
			bf1 = bf2;
		}
	}
}

CL::CL( CL& pr )
{
	V* temp = pr.getFront();
	size = pr.getSize();
	
	while( temp )
	{
		push(temp->v);
		temp = temp->n;
	}
}

CL::~CL(void)
{
	V* pr;

	while(front)
	{
		pr=front->n;
		front->p=front->n=NULL;
		delete front;
		
		front=pr;
	}
	front=back=NULL;
}

//=====cList======//

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

	pr=getBack();

	if(val>=pr->v)	//insert at the back;
	{
		push(val);
		
		return;
	}

	pr=getFront();

	if(val<=pr->v)	//insert at the front;
	{
		setFront(val);
		
		return;
	}
	

	try
	{	
		temp=new V(val);
	
	}catch(...)

	{
		cout<<"Error!"<<endl;
	}

	while( ( pr ) && ( val > pr->v ) )
		pr=pr->n;

	after=pr->p;

	after->n=temp;	//link new element with previous element;
	temp->p=after;

	temp->n=pr;	//link new element with next element;
	pr->p=temp;
}

void cList::insert(unsigned n,double* m)
{
	for(unsigned i=0;i<n;i++)
		insert( *(m+i) );
}
