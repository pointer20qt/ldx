#include<iostream>
#include<memory>
#include"tool.h"

using namespace std;

class tool
{
public:
	int value = 0;
	tool()
	{
		cout << "tool������" << endl;
	}
	~tool()
	{
		cout << "tool������" << endl;
	}
};

void run()
{
	//tool* p = new tool;
	L_autoPtr<tool> ptr{ new tool };
	L_autoPtr<tool> ptr2(ptr);
	L_autoPtr<tool> ptr3;			//��ָ������Ȩת��ptr3
	ptr3 = ptr2;
	
	
	
}
int main()
{
	run();


	return 0;

}