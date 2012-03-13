#pragma once
#include "v.cpp"

class CL
{
	V* front;
	V* back;
	unsigned size;

public:
	V* getFront(void);
	void setFront(double);
	V* getBack(void);
	unsigned getSize(void);
	void push(double);
	int pop(double&);
	void print(void);
	void revPrint(void);
	CL(void);
	CL(int);
	CL(CL&);
	~CL(void);
};
class cList:public CL
{
public:

	cList(void);
	cList(int);
	cList( cList& );
	~cList();
	void insert( double );
	void insert( unsigned, double* );
	
};
