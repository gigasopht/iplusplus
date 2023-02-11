import std.core;
import iplusplus;
using namespace standard;

int main()
{
	database::set<set<string>> m("MySet");

	m.clear();

	set<string> a;
	a << L"Hello" << L"world";

	set<string> b;
	b << L"Goodbye" << L"world";

	m << a << b;

	for (set<string> i : m) std::cout << i << "\n";

	std::stack<std::string> d;

	d.push("RED");
	d.push("GREEN");
	d.push("BLUE");

	oarchive oa;

	oa << d;

	iarchive ia(oa);

	std::stack<std::string> e;

	ia >> e;

	std::cout << e.pop() << "\n";
	std::cout << e.pop() << "\n";
	std::cout << e.pop() << "\n";


	oarchive soa;

	std::string hello("Hello world");
	soa << hello;

	iarchive sia(soa);

	std::string out;
	sia >> out;

	std::cout << out << "\n";


	return 0;
}