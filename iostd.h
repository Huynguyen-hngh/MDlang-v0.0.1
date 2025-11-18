// iostd.h - file tương tự iostream của C++
#ifndef IOSTD_H
#define IOSTD_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <limits>
#include <cassert>
#include <ctime>
#include <chrono>
#include <random>
#include <bitset>
#include <regex>
#include <locale>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <exception>
#include <stdexcept>
#include <cerrno>
using namespace std;
// Core
#define set using
#define iostd namespace
#define standard std
#define program int
#define exitcode 0

// IO
#define println cout
#define input cin
#define linedone endl

// Datatypes
#define integer long long
#define bigint unsigned long long
#define flt double
#define big_flt long double
#define logic bool
#define str string

// Control
#define switchcase switch
#define caseof case
#define defaultcase default

// Task / Multitask
#define spawn std::thread
#define threads_vec std::vector<std::thread>
#define joinall for(auto &t : threads) t.join();

// Utilities
#define pair std::pair
#define makepair std::make_pair
#define tuple std::tuple
#define maketuple std::make_tuple
#define swap std::swap
#define function std::function
#define bind std::bind
#define randomengine std::mt19937
#define uniformint std::uniform_int_distribution<int>
#define uniformreal std::uniform_real_distribution<double>

#endif // MDLANG_H
