#include <iostream>

template<typename T>void linePrinter(const T& x) {
    if constexpr (std::is_integral_v<T>)
        std::cout << "num: "<< x << '\n';
    else if constexpr (std::is_floating_point_v<T>) {
        const auto frac = x - static_cast<long>(x);
        std::cout << "flt: " << x << ", frac " << frac << '\n';
    }else if constexpr (std::is_pointer_v<T>) {
        std::cout <<"ptr, ";
        linePrinter(*x);
    } else
        std::cout << x<<'\n';
}

template<typename ...Args>void printWithInfo(Args... args) {
    (linePrinter(args),...);
}

int main(){
    int i = 10;
    float f = 2.56f;
    printWithInfo(&i,&f,30);
}
