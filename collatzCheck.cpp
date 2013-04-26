#include <iostream>
#include <list>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using ULL = boost::multiprecision::cpp_int;
using List = std::list<ULL>; 

inline void collatz(ULL n,List* list){
    list->push_back(n);
    if(n == 1) return;

    if(n%2){
	collatz(3*n+1,list);
	return;
    }
    collatz(n/2,list);
    return;
}

int main(int argc, char** argv){
    
//    std::cout << n << ',' << m << std::endl;
    ULL sum;
    List list;
    for(ULL i{12000001};i< 1<< 30;++i){
	collatz(i,&list);
//	std::cout << i << ": Stopped";
//	for(const auto e:list){
//	    std::cout << e << ' ';
//	}
	sum += *(list.rbegin()); // 最適化によってcollatz の呼び出しがなくなることを避けるため
	list.clear();
	if(i%(1<<16) == 0) std::cout << i << std::endl;
    }
    std::cout << sum; // 最適化によってcollatz の呼び出しがなくなることを避けるため
    return 0;
}

