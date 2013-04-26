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
    if(argc != 3){
	std::cout << "Usage: collatz n m \n  n: start\n  m: end\n\n    m must be larger than n." << std::endl;
	return -1;
    }
    std::istringstream isN( argv[1] ); 
    std::istringstream isM( argv[2] );
    
    ULL n,m;
    isN >> n;
    isM >> m;

//    std::cout << n << ',' << m << std::endl;
    
    List list;
    for(ULL i{n};i<=m;++i){
	collatz(i,&list);
	std::cout << i << ": ";
	for(const auto e:list){
	    std::cout << e << ' ';
	}
	list.clear();
	std::cout << std::endl;
    }
    return 0;
}

