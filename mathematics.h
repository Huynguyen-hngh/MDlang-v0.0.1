// mathematics.h - thư viện toán học Mdlang
#ifndef MDMATH_H
#define MDMATH_H

#include <initializer_list>
#include <cmath>
#include <cstdlib>
#include <random>
#include <limits>
#include <vector>
#include "iostd.h" // nếu muốn dùng alias của Mdlang
// Static RNG engine Mdlang-style, seed 1 lần duy nhất
static std::mt19937 md_rng(std::random_device{}());

// ================================
// Mdlang Math Macro & Aliases
// ================================

// Hằng số
#define PI 3.14159265358979323846
#define E  2.71828182845904523536

// Hàm cơ bản
#define sqrtf std::sqrt
#define powf std::pow
#define sinf std::sin
#define cosf std::cos
#define tanf std::tan
#define asinf std::asin
#define acosf std::acos
#define atanf std::atan
#define expf std::exp
#define logf std::log
#define log10f std::log10
#define floorf std::floor
#define ceilf std::ceil
#define absf std::abs

// Random numbers
integer randint(integer a, integer b) {
    std::uniform_int_distribution<integer> dist(a, b);
    return dist(md_rng);
}
flt randflt(double a, double b) {
    std::uniform_real_distribution<double> dist(a, b);
    return dist(md_rng);
}

// ================================
// Utilities
// ================================
#define clamp(val, lo, hi) ((val)<(lo)?(lo):((val)>(hi)?(hi):(val)))
#define sign(val) ((val>0)?1:((val<0)?-1:0))

// ================================
// Fibonacci function
// ================================

long long fibo(long long a, long long b, long long n) {
    long long f0 = 0, f1 = 1;
    long long count = 0;

    while (f0 <= b) {
        if (f0 >= a) {
            count++;
            if (count == n) return f0;
        }
        long long next = f0 + f1;
        f0 = f1;
        f1 = next;
    }

    return -1; // Không tìm thấy
}

bool is_prime(integer n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (integer i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
long long sumbetween(long long a, long long b) {
    if (b < a) return 0; // nếu b < a thì trả về 0
    return (b - a + 1) * (a + b) / 2;
}

// Hàm tính GCD 2 số
integer gcd(integer a, integer b) {
    while (b != 0) {
        integer tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a >= 0) ? a : -a;
}

// Hàm tính GCD cho nhiều số (từ 2 trở lên)
integer gcd(std::initializer_list<integer> nums) {
    auto it = nums.begin();
    integer result = *it;
    ++it;
    for (; it != nums.end(); ++it) {
        result = gcd(result, *it);
    }
    return result;
}

integer lcm(integer a, integer b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a / gcd(a, b) * b); // tránh tràn khi a*b lớn
}


integer lcm(std::initializer_list<integer> nums) {
    auto it = nums.begin();
    integer result = *it;
    ++it;
    for (; it != nums.end(); ++it) {
        result = lcm(result, *it);
    }
    return result;
}

// Tính tổng các số chẵn từ a đến b (inclusive)
integer sum_even(integer a, integer b) {
    if(a % 2 != 0) a += 1;      // bắt đầu từ số chẵn gần a nhất
    if(b % 2 != 0) b -= 1;      // kết thúc ở số chẵn gần b nhất
    if(a > b) return 0;          // nếu khoảng rỗng
    integer n = (b - a) / 2 + 1; // số lượng số chẵn
    return n * (a + b) / 2;      // công thức tổng cấp số cộng
}

// Trong mathematics.h

// Đếm số chẵn từ a đến b (inclusive)
integer count_even(integer a, integer b) {
    if(a % 2 != 0) a += 1; // bắt đầu từ số chẵn đầu tiên
    if(b % 2 != 0) b -= 1; // kết thúc ở số chẵn cuối cùng
    if(a > b) return 0;     // khoảng rỗng
    return (b - a) / 2 + 1; // số lượng số chẵn
}

// Tương tự, đếm số lẻ
integer count_odd(integer a, integer b) {
    if(a % 2 == 0) a += 1; // bắt đầu từ số lẻ đầu tiên
    if(b % 2 == 0) b -= 1; // kết thúc ở số lẻ cuối cùng
    if(a > b) return 0;
    return (b - a) / 2 + 1;
}

// Tính tổng các số lẻ từ a đến b (inclusive)
integer sum_odd(integer a, integer b) {
    if(a % 2 == 0) a += 1;  // bắt đầu từ số lẻ đầu tiên
    if(b % 2 == 0) b -= 1;  // kết thúc ở số lẻ cuối cùng
    if(a > b) return 0;      // khoảng rỗng
    integer n = (b - a) / 2 + 1;  // số lượng số lẻ
    return n * (a + b) / 2;       // công thức tổng cấp số cộng
}

// Giải phương trình bậc 2: ax^2 + bx + c = 0
std::vector<flt> solve_quadratic(flt a, flt b, flt c) {
    std::vector<flt> roots;
    if(a == 0) {
        if(b == 0) return roots;         // 0x + 0 = 0 -> vô nghiệm
        roots.push_back(-c / b);         // b*x + c = 0
        return roots;
    }
    flt delta = b*b - 4*a*c;
    if(delta > 0) {
        roots.push_back((-b + sqrt(delta)) / (2*a));
        roots.push_back((-b - sqrt(delta)) / (2*a));
    } else if(delta == 0) {
        roots.push_back(-b / (2*a));
    }
    // delta < 0 -> roots rỗng (vô nghiệm trong R)
    return roots;
}

integer factorial_iter(integer n) {
    if(n < 0) return 0;
    integer res = 1;
    for(integer i = 2; i <= n; i++) res *= i;
    return res;
}

#endif // MDMATH_H
