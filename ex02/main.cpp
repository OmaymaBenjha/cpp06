#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base*	generate(void)
{
	std::vector<Base*> list;
	list.push_back(new A);
	list.push_back(new B);
	list.push_back(new C);
	int r = rand() % 3;
	return (list[r]);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The actual type of the object pointed to by p: C" << std::endl;
}
void	identify(Base& p)
{
	try 
	{
		dynamic_cast<A&>(p);
		std::cout << "The actual type of the object pointed to by p: A" << std::endl;
	}
	catch (...)
	{
		try 
		{
			dynamic_cast<B&>(p);
			std::cout << "The actual type of the object pointed to by p: B" << std::endl;

		}
		catch (...)
		{
			dynamic_cast<C&>(p);
			std::cout << "The actual type of the object pointed to by p: C" << std::endl;
		}
	}
}
int main()
{
	srand(time(0));
	Base *p = generate();
	identify(p);
	identify(*p);
	return 1;
}