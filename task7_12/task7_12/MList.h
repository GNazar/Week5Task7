#pragma once
#include "CL.h"
#include <iostream>

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
