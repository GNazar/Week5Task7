#include "StdAfx.h"
#pragma once

class V
{
public:
	double v;
	V* n;
	V* p;


	double* value(void)
	{
		return &v;
	}

	V* next(void)
	{
		return n;
	}

	V* prev(void)
	{
		return p;
	}

	V(double val)
	{
		v=val;
		n=p=NULL;
	}
	V(void)
	{
		v=0;
		n=p=NULL;
	}
	V(const V& pr)
	{
		v=pr.v;
		p=pr.p;
		n=pr.n;
	}
	~V(void){}
};
