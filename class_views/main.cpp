#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

class Element {
public:
    explicit Element(int a) : a_(a){
    }

    int a_;
};

class Container {
public:
    Container(){
        elements.emplace_back(1);
        elements.emplace_back(2);
        elements.emplace_back(3);
        elements.emplace_back(4);
        elements.emplace_back(5);
        elements.emplace_back(6);
        elements.emplace_back(7);
        elements.emplace_back(8);
    }

    std::vector<Element> elements;

    auto filtered(){
        return elements
               | std::views::filter([](Element e) { return e.a_ % 2 == 0; })
               | std::views::transform([](Element e) {
                   e.a_ *= e.a_;
                   return e;
               })
               | std::views::take(300);
    }

    auto greatest(){
        return *std::ranges::max_element(elements, {}, &Element::a_ );
    }
};

void printAll(auto&& v){
    std::cout << "vvv Printing in a function vvv \n";
    for (const auto& e: v){
        std::cout << e.a_ << " ";
    }
    std::cout << std::endl;
}

int main(){
    Container c;

    // Pipeline-style operations with ranges

    // Lazy evaluation - no computation until iteration
    printAll(c.elements);
    for (Element element: c.elements) {
        std::cout << element.a_ << " "; // 1, 2, 3
    }
    std::cout << std::endl;

    // Lazy evaluation - no computation until iteration
    printAll(c.filtered());
    for (Element element: c.filtered()) {
        std::cout << element.a_ << " "; // 4, 16, 36
    }
    std::cout << std::endl;

    // Max of every element
    std::cout << c.greatest().a_ <<  "\n";

}
