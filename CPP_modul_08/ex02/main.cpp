#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(20);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
	cout << "it =" << *it << endl;
    ++it;
	cout << "it =" << *it << endl;
    --it;
	cout << "it =" << *it << endl;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
	cout << "---------------------------------------\n";
    std::stack<int> s(mstack);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << "---------------------------------------\n";
	MutantStack<string> sstack;
	sstack.push("Hello");
	sstack.push(" ");
	sstack.push("world!");
    MutantStack<string>::iterator t = sstack.begin();
    MutantStack<string>::iterator te = sstack.end();
	while (t != te)
    {
		cout << *t;
   		++t;
    }
	cout << endl;
    return 0;
}