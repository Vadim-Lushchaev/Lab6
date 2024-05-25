// one_of
// is_palindrome

#include <iostream>
#include <vector>

class CPoint
{
    double x;
    double y;
public:
    CPoint(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double get_x() const
    {
        return x;
    }

    double get_y() const
    {
        return y;
    }

    bool operator==(const CPoint& p) const
    {
        return x == p.x && y == p.y;
    }

    double get_distance(CPoint p) const
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

template <typename Iterator, typename Predicate>
bool any_of(const Iterator& begin, const Iterator& end, Predicate pred)
{
    for (Iterator iterator = begin; iterator != end; ++iterator)
        if (pred(*iterator))
            return true;
    return false;
}

template <typename Iterator, typename Predicate>
bool one_of(const Iterator& begin, const Iterator& end, Predicate pred)
{
    int count = 0;
    for (Iterator iterator = begin; iterator != end; ++iterator)
        if (pred(*iterator))
            count++;
    return count == 1;
}

template <typename Iterator, typename Predicate>
bool is_palindrome(const Iterator& begin, const Iterator& end, Predicate pred)
{
    Iterator start, finish;
    for (start = begin, finish = end - 1; start != end && finish != begin; ++start, --finish)
        if (pred(*start) != pred(*finish))
            return false;
    return true;
}

int main(int argc, char* argv[])
{
    std::vector<int> nums {3, 2, 3, 3, 2, 1};
    // Можно вводить с клавиатуры
    int xxx = 1;
    std::cout << is_palindrome(nums.begin(), nums.end(), [](int x){return x % 2 == 0;}) << '\n';
    std::cout << any_of(nums.begin(), nums.end(), [&xxx](int x){return x > xxx;}) << '\n';
    std::cout << one_of(nums.begin(), nums.end(), [](int x){return x % 2 != 0;}) << '\n';

    std::vector<CPoint> points {CPoint(1, 1), CPoint(2, 2), CPoint(2, 2), CPoint(1, 1)};
    std::cout << is_palindrome(points.begin(), points.end(), [](CPoint x){return x.get_distance(CPoint(0, 0));}) << '\n';
    std::cout << any_of(points.begin(), points.end(), [](CPoint x){return x.get_distance(CPoint(0, 0)) > 1;}) << '\n';
    std::cout << one_of(points.begin(), points.end(), [](CPoint x){return x == CPoint(0, 0);});

    return 0;
}
