import std.core;
import iplusplus;
using namespace core;

struct t
{
	int i;
	string s;

	t() {}

	t(int _i, const string& _s) : i(_i), s(_s) {}
};

oarchive& operator<<(oarchive& oa, const t& _t)
{
	oa << _t.i;
	oa << _t.s;
	return oa;
}

iarchive& operator>>(iarchive& ia, t& _t)
{
	ia >> _t.i;
	ia >> _t.s;
	return ia;
}

std::ostream& operator<<(std::ostream& s, const t& _t)
{
	s << "(" << _t.i << "," << _t.s << ")";
	return s;
}

bool operator<(const t& a, const t& b)
{
	if (a.i < b.i) return true;
	return false;
}

struct tree_compare
{
	int operator()(const int& key, const t& type) const
	{
		if (key < type.i) return -1;
		if (type.i < key) return 1;
		return 0;
	}
};

int main()
{
	{
		database::tree<int, t, tree_compare> tr("MyTree");
		tr.clear();
		tr << t(0, "hello") << t(1, "world");
		std::cout << tr << "\n";
		std::cout << tr[0] << "\n";

		database::dictionary<string, string> d("MyDictionary");
		d.clear();
		d["0"] = "hello";
		d["1"] = "world";
		std::cout << d << "\n";

		database::set<string> ss("StringSet");
		ss.clear();
		ss << "Hello" << "World";
		std::cout << ss << "\n";

		database::multiset<string> multiset("multiset");
		multiset.clear();
		multiset << "Hello" << "World" << "World";
		std::cout << multiset << "\n";

		database::list<string> l("MyList");
		l.clear();
		l << "Hello" << "World" << "World";
		std::cout << l << "\n";
		string s = l[0];
		std::cout << s << "\n";

		std::cout << "heap allocations: " << get_heap_units() << "\n";
	}

	std::cout << "heap allocations: " << get_heap_units() << "\n";

	return 0;
}