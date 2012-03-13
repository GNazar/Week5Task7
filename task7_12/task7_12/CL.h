#pragma once

class V
{
public:

	double v;
	V* n;
	V* p;

	V(double val);
	V(void);
	V(const V& pr);
	~V(void);
};

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
	CL(void);
	CL(int);
	CL(CL&);
	~CL(void);
	void push(double);
	int pop(double&);
	void print(void);
	void revPrint(void);
};
