#include <iostream>
#include <vector>
#include <ranges>

class Container {
public:
    std::vector<int> datas = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto filtered(){
        return datas
        | std::views::filter([](int n){return n % 3 == 0; })
        | std::views::transform([](int n){return n * n;})
        | std::views::take_while([](int n){return n < 50;});
    }
};

int main(){

    // std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //
    // for (int number: numbers) {
    //     std::cout << number << " ";
    // }
    // std::cout << std::endl;
    //
    //
    // auto numbers_with_view = numbers
    // | std::views::filter([](int n){return n % 3 == 0; })
    // | std::views::transform([](int n){return n * n;})
    // | std::views::take_while([](int n){return n < 50;});
    //
    // for (int v: numbers_with_view) {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;


    Container c;

    // Lazy evaluation - no computation until iteration
    for (int value: c.datas) {
        std::cout << value << " "; // 1, 2, 3
    }
    std::cout << std::endl;

    // Lazy evaluation - no computation until iteration
    for (auto value: c.filtered()) {
        std::cout << value << " "; // 4, 16, 36
    }

}
