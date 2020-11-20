//
// Created by rick on 2020/11/19.
//

#include <rx.hpp>
int main() {
    auto values = rxcpp::observable<>::range(1,3)
    .concat(rxcpp::observable<>::error<int>(std::runtime_error("Error from producer!")))
    .retry()
    .take(5);
    values.subscribe([](int v){printf("OnNext: %d\n",v);},
                     [](){printf("OnCompleted\n");});
}