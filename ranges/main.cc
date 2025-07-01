//
// Created by sebas on 01/07/2025.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <random>
#include <span>

void Print(std::span<int> ints){
    for (auto &i: ints) {
        std::cout << i << " ";
    }
    std::cout << " - " << std::endl;
}

int main(){
    std::array<int, 10> ints = {};
    std::iota(std::begin(ints), std::end(ints), 0);

    Print(ints);

    std::ranges::reverse(ints);
    Print(ints);

    std::ranges::shuffle(ints, std::default_random_engine{});
    Print(ints);

    if (std::find(ints.begin(), ints.end(), 5) != std::end(ints)) {
        std::cout << "Found 5" << std::endl;
    }

    if (std::ranges::find(ints, 5) != std::end(ints)) {
        std::cout << "Found 5" << std::endl;
    }


    std::array<int, 10> ints_copy = {0};
    std::ranges::fill(ints_copy, 10);
    std::ranges::copy_if(ints, ints_copy.begin(),
                         [](int i) { return i % 3 == 0; });

    Print(ints_copy);
}
