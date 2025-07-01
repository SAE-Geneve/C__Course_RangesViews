#include <iostream>
#include <vector>
#include <ranges>

class Container {
public:
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto filtered(){
        return numbers
               | std::views::filter([](int x) { return x % 2 == 0; })
               | std::views::transform([](int x) { return x * x; })
               | std::views::take(3);
    }
};

int main(){
    Container c;

    // Pipeline-style operations with ranges
    auto result = c.filtered();

    // Lazy evaluation - no computation until iteration
    for (int value: c.numbers) {
        std::cout << value << " "; // 1, 2, 3
    }
    std::cout << std::endl;

    // Lazy evaluation - no computation until iteration
    for (int value: result) {
        std::cout << value << " "; // 4, 16, 36
    }
}
