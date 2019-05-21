#include <iostream>
#include "THTable.h"

int main()
{
	THTable<int> A(100);
	std::cout << "Add new elem with key = ba and value = 1" << std::endl;
	A.AddElem("ba", 1);
	std::cout << "Count of elem: " << A.GetCount() << std::endl;

	std::cout << "Add new elem with key = c and value = 3" << std::endl;
	A.AddElem("c", 3);
	std::cout << "Count of elem: " << A.GetCount() << std::endl;

	std::cout << "Add new elem with key = laab and value = 88" << std::endl;
	A.AddElem("laab", 88);
	std::cout << "Count of elem: " << A.GetCount() << std::endl;

	std::cout << A;
  return 0;
}