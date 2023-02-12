import std.core;
import iplusplus;
using namespace core;

//void* operator new(size_t s) {	return allocate_from_heap(s); }
//void operator delete(void* p) { free_from_heap(p);}

int main()
{
	{
		std::list<int> sm;
		core::time stl_build_start;
		for (int i = 0; i < 10000000; i++) sm.push_back(i);
		core::time stl_build_end;
		std::cout << "stl list build time is: " << stl_build_end - stl_build_start << "\n";
		core::time stl_sort_start;
		sm.sort();
		core::time stl_sort_end;
		std::cout << "stl list sort time is: " << stl_sort_end - stl_sort_start << "\n";

		std::forward_list<int> stlfl;
		core::time stlfl_build_start;
		for (int i = 0; i < 10000000; i++) stlfl.push_front(i);
		core::time stlfl_build_end;
		std::cout << "stl forward_list build time is: " << stlfl_build_end - stlfl_build_start << "\n";
		core::time stlfl_sort_start;
		stlfl.sort();
		core::time stlfl_sort_end;
		std::cout << "stl forward_list sort time is: " << stlfl_sort_end - stlfl_sort_start << "\n";

		list<int> fl;
		core::time fl_build_start;
		for (int i = 0; i < 10000000; i++) fl << i;
		core::time fl_build_end;
		std::cout << "core::list build time is: " << fl_build_end - fl_build_start << "\n";
		core::time fl_sort_start;
		fl.sort();
		core::time fl_sort_end;
		std::cout << "core::list sort time is: " << fl_sort_end - fl_sort_start << "\n";

		linked_list<int> s;
		core::time ipp_build_start;
		for (int i = 0; i < 10000000; i++) s << i;
		core::time ipp_build_end;
		std::cout << "core::linked_list build time is: " << ipp_build_end - ipp_build_start << "\n";
		core::time ipp_sort_start;
		s.sort();
		core::time ipp_sort_end;
		std::cout << "core::linked_list sort time is: " << ipp_sort_end - ipp_sort_start << "\n";

		std::set<int> ss;
		core::time stl_ss_build_start;
		for (int i = 0; i < 10000000; i++) ss.insert(i);
		core::time stl_ss_build_end;
		std::cout << "stl set build time is: " << stl_ss_build_end - stl_ss_build_start << "\n";
		core::time stl_ssearch_start;
		for (int i = 0; i < 10000000; i++) ss.find(i);
		core::time stl_ssearch_end;
		std::cout << "stl set search time is: " << stl_ssearch_end - stl_ssearch_start << "\n";

		set<int> sts;
		core::time stl_sts_build_start;
		for (int i = 0; i < 10000000; i++) sts << i;
		core::time stl_sts_build_end;
		std::cout << "I++ set build time is: " << stl_sts_build_end - stl_sts_build_start << "\n";
		core::time sts_ssearch_start;
		for (int i = 0; i < 10000000; i++) sts.find(i);
		core::time sts_ssearch_end;
		std::cout << "I++ set search time is: " << sts_ssearch_end - sts_ssearch_start << "\n";

		std::unordered_set<int> us;
		core::time stl_us_build_start;
		for (int i = 0; i < 10000000; i++) us.insert(i);
		core::time stl_us_build_end;
		std::cout << "stl unordered_set build time is: " << stl_us_build_end - stl_us_build_start << "\n";
		core::time stl_ussearch_start;
		for (int i = 0; i < 10000000; i++) us.find(i);
		core::time stl_ussearch_end;
		std::cout << "stl unordered_set search time is: " << stl_ussearch_end - stl_ussearch_start << "\n";

		std::map<int, int> stlm;
		core::time stl_map_build_start;
		for (int i = 0; i < 10000000; i++) stlm[i] = i;
		core::time stl_map_build_end;
		std::cout << "stl map build time is: " << stl_map_build_end - stl_map_build_start << "\n";
		core::time map_search_start;
		for (int i = 0; i < 10000000; i++) { int j = stlm[i]; }
		core::time map_search_end;
		std::cout << "stl map search time is: " << map_search_end - map_search_start << "\n";

		std::unordered_map<int, int> stlum;
		core::time stl_umap_build_start;
		for (int i = 0; i < 10000000; i++) stlum[i] = i;
		core::time stl_umap_build_end;
		std::cout << "stl unordered map build time is: " << stl_umap_build_end - stl_umap_build_start << "\n";
		core::time umap_search_start;
		for (int i = 0; i < 10000000; i++) { int j = stlum[i]; }
		core::time umap_search_end;
		std::cout << "stl unordered map search time is: " << umap_search_end - umap_search_start << "\n";

		map<int, int> dic;
		core::time dic_build_start;
		for (int i = 0; i < 10000000; i++) dic[i] = i;
		core::time dic_build_end;
		std::cout << "I++ map build time is: " << dic_build_end - dic_build_start << "\n";
		core::time dic_search_start;
		for (int i = 0; i < 10000000; i++) { int j = dic[i]; }
		core::time dic_search_end;
		std::cout << "I++ map search time is: " << dic_search_end - dic_search_start << "\n";

		multimap<int, int> mm;
		core::time mm_build_start;
		for (int i = 0; i < 10000000; i++) mm.insert(i,i);
		core::time mm_build_end;
		std::cout << "I++ multimap build time is: " << mm_build_end - mm_build_start << "\n";
		core::time mm_search_start;
		for (int i = 0; i < 10000000; i++) { list<int> j = mm[i]; }
		core::time mm_search_end;
		std::cout << "I++ multimap search time is: " << mm_search_end - mm_search_start << "\n";

		core::time ipp_copy_start;
		oarchive oa;
		oa << s;
		void* data = oa.allocate(); // data points to the serialized list.
		iarchive ia(data);
		list<int> t;
		ia >> t;
		oa.free(data);              // you should free the data once you are done with it.
		core::time ipp_copy_end;
		std::cout << "I++ serialization/deserialization time is: " << ipp_copy_end - ipp_copy_start << "\n";

		array<int> l;
		core::time array_build_start;
		for (int i = 0; i < 10000000; i++) l.push(i);
		core::time array_build_end;
		std::cout << "array build time is: " << array_build_end - array_build_start << "\n";

		std::vector<int> stlv;
		core::time stl_vector_build_start;
		for (int i = 0; i < 10000000; i++) stlv.push_back(10000000 - i);
		core::time stl_vector_build_end;
		std::cout << "stl vector build time is: " << stl_vector_build_end - stl_vector_build_start << "\n";
		core::time stlv_sort_start;
		sort(stlv.begin(), stlv.end());
		core::time stlv_sort_end;
		std::cout << "stl vector sort time is: " << stlv_sort_end - stlv_sort_start << "\n";

		int* ai = new int[10000000];
		for (int i = 0; i < 10000000; i++) ai[i] = 10000000 - i;
		core::time qsort_start;
		quick_sort(ai, 1000000);
		core::time qsort_end;
		std::cout << "Quick Sort time is: " << qsort_end - qsort_start << "\n";
		delete[] ai;

		database::set<int> st("Speed Test");
		st.clear();
		core::time db_start;
		for (int i = 0; i < 1000; i++) st << i;
		core::time db_end;
		core::time db_search_start;
		for (int i = 0; i < 25000; i++) bool present = st.contains(i%1000);
		core::time db_search_end;
		std::cout << "Database search for: 25000 entries is: " << db_search_end - db_search_start << "\n";

		std::cout << "heap allocations: " << get_heap_units() << "\n";
	}
	std::cout << "heap allocations: " << get_heap_units() << "\n";


	return 0;
}