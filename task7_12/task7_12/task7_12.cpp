/*
12.	З введених дійсних чисел, відсортованих за зростанням значень, сформувати двонапрям лений список. 
Роздрукувати створений список в обох напрямках. Розробити функцію, яка вводить у список новий елемент, 
зберігаючи його впорядкованість. 
На основі цієї  функції доповнити список 4-а новими числами.
*/


#include "stdafx.h"
#include "CL.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const unsigned N=4;
	int n;
	double *m;
	double res=0;

	cout<<"Enter number of elements->";
	
	do
	{
		cin>>n;

		if(n<0) 
			cout<<"Value must be greater then 0! Try again->"<<endl;

	}while(n<0);
	
	cList* l1=new cList(n);
	
	cout<< "List" <<endl;
	l1->print();

	m=new double[N];
	
	cout<<"New numbers:"<<endl;

	for( int i=0; i<N; i++ )
	{
		cout<<(i+1)<<".->";
		cin>>*(m+i);
		getchar();
	}
	
	l1->insert( N, m );
	cout<< "New list" <<endl;

	l1->print();

	getchar();
	delete l1;
	return 0;
}

