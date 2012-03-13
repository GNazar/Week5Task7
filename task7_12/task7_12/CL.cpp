#include "StdAfx.h"
#include <iostream>
#include "CL.h"

using namespace std;

V::V(double val)
{
	v=val;
	n=p=NULL;
}

V::V(void)
{
	v=0;
	n=p=NULL;
}

V::V(const V& pr)
{
	v=pr.v;
	p=pr.p;
	n=pr.n;
}

V::~V(void){}

//***************************//

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
	size++;
}

unsigned CL::getSize(void)
{
	return size;
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
	if(n>0)
	{

	cout << "1. ->";
	cin >> bf1;
	getchar();
	push( bf1 );	//add first element;

	while( i < n )
	{
		cout << (i+1)<<". ->";
		cin >> bf2;
		getchar ();
		
		if( bf2 < bf1 )	// new value less then last(not sorted);
			cout << "Error! Value must be greater then " << bf1 << "!" << endl;
		
		else
		{
			push( bf2 );
			i++;
			bf1 = bf2;	//set bf1 tolast value;
		}
	}
	}
}

CL::CL( CL& pr )
{
	V* temp = pr.getFront();
	size = pr.getSize();
	
	while( temp )
	{
		push(temp->v);	//add value at the end of list;
		temp = temp->n;
	}
}

CL::~CL(void)
{
	V* pr;

	while(front)
	{
		pr=front->n;
		delete front;
		
		front=pr;
	}
	front=back=NULL;
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



