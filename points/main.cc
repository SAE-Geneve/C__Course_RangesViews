#include <array>
#include <iostream>
#include <random>
#include <vector>
#include <ranges>

constexpr float kPointMin = 0;
constexpr float kPointMax = 100;

enum class Type {
    kTriangle = 0,
    kLength
};

struct Point {
    float x_;
    float y_;

    Type type_;
};

class PointCloud {
    std::array<Point, 100> points_ = {};

public:
    void Fill();

    auto NearPoints(Point p, float radius);

    auto AllPoints(){
        return points_;
    }

    auto GetTruc();
};

inline float RandomRange(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(kPointMin, kPointMax);
    return dis(gen);
}

inline Type RandomType(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, static_cast<int>(Type::kLength) - 1);
    return static_cast<Type>(dis(gen));
}

inline float Distance(Point p1, Point p2){
    float a = p2.x_ - p1.x_;
    float b = p2.y_ - p1.y_;
    return std::sqrt(a * a + b * b);
}

inline void PointCloud::Fill(){
    std::ranges::generate(points_, []() { return Point{RandomRange(), RandomRange(), RandomType()}; });
}

inline auto PointCloud::NearPoints(Point p, float radius){
    // return points_
    // | std::views::filter([p, radius](auto q){return Distance(p, q) <= radius;})
    // | std::views::filter([](auto q) {return q.type_ == Type::kTriangle;});


    return std::views::filter(points_, [](auto p) { return p.type_ == Type::kTriangle; });
}

inline auto PointCloud::GetTruc(){
    return points_
           | std::views::transform([](Point p) { return p.type_; });
}

int main(){
    std::cout << "Hello World!" << std::endl;

    PointCloud pc;
    Point origin = {50, 50};

    pc.Fill();

    std::cout << "Origin [" << origin.x_ << ":" << origin.y_ << "]" << std::endl;
    std::cout << "All points" << std::endl;
    for (auto p: pc.AllPoints()) {
        std::cout << p.x_ << ":" << p.y_ << ":" << static_cast<int>(p.type_) << std::endl;
    }
    std::cout << "Count: " << pc.AllPoints().size() << std::endl;

    std::cout << "Near points" << std::endl;
    auto points = pc.NearPoints(origin, 35);
    for (auto p: points) {
        std::cout << p.x_ << ":" << p.y_ << ":" << static_cast<int>(p.type_) << std::endl;
    }
    std::cout << "Distance: " << std::ranges::distance(points) << std::endl;

    return EXIT_SUCCESS;
}
