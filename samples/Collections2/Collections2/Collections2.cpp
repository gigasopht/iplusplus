// Single versus multithreaded performance comparisons. Times are in milliseconds.

import std.core;
import iplusplus;
using namespace core;

int main()
{
	core::list<int> core_list;
	systime core_build_start;
	for (int i = 0; i < 10000000; i++) core_list << i;
	systime core_build_end;
	std::cout << "core::list build time is: " << core_build_end - core_build_start << "\n";
	systime core_sort_start;
	core_list.sort();
	systime core_sort_end;
	std::cout << "core::list sort time is: " << core_sort_end - core_sort_start << "\n";

	threaded::list<int> threaded_list;
	systime threaded_list_build_start;
	for (int i = 0; i < 10000000; i++) threaded_list << i;
	systime threaded_list_build_end;
	std::cout << "threaded::list build time is: " << threaded_list_build_end - threaded_list_build_start << "\n";
	systime threaded_list_sort_start;
	threaded_list.sort();
	systime threaded_list_sort_end;
	std::cout << "threaded::list sort time is: " << threaded_list_sort_end - threaded_list_sort_start << "\n";

	core::set<int> core_set;
	systime core_set_build_start;
	for (int i = 0; i < 10000000; i++) core_set.insert(i);
	systime core_set_build_end;
	std::cout << "core::set build time is: " << core_set_build_end - core_set_build_start << "\n";
	systime core_ssearch_start;
	for (int i = 0; i < 10000000; i++) core_set.find(i);
	systime core_ssearch_end;
	std::cout << "core::set search time is: " << core_ssearch_end - core_ssearch_start << "\n";

	threaded::set<int> threaded_set;
	systime threaded_set_build_start;
	for (int i = 0; i < 10000000; i++) threaded_set << i;
	systime threaded_set_build_end;
	std::cout << "threaded::set build time is: " << threaded_set_build_end - threaded_set_build_start << "\n";
	systime threaded_set_ssearch_start;
	for (int i = 0; i < 10000000; i++) threaded_set.contains(i);
	systime threaded_set_ssearch_end;
	std::cout << "threaded::set search time is: " << threaded_set_ssearch_end - threaded_set_ssearch_start << "\n";

	core::map<int, int> core_map;
	systime core_map_build_start;
	for (int i = 0; i < 10000000; i++) core_map[i] = i;
	systime core_map_build_end;
	std::cout << "core::map build time is: " << core_map_build_end - core_map_build_start << "\n";
	systime core_map_search_start;
	for (int i = 0; i < 10000000; i++) { int j = core_map[i]; }
	systime core_map_search_end;
	std::cout << "core::map search time is: " << core_map_search_end - core_map_search_start << "\n";

	threaded::map<int, int> threadedm;
	systime threaded_map_build_start;
	for (int i = 0; i < 10000000; i++) threadedm[i] = i;
	systime threaded_map_build_end;
	std::cout << "threaded::map build time is: " << threaded_map_build_end - threaded_map_build_start << "\n";
	systime threaded_map_search_start;
	for (int i = 0; i < 10000000; i++) { int j = threadedm[i]; }
	systime threaded_map_search_end;
	std::cout << "threaded::map search time is: " << threaded_map_search_end - threaded_map_search_start << "\n";
}