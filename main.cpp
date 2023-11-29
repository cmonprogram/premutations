#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <iterator>

template <typename T>
std::deque<std::deque<T>> permutations_rec(std::list<T> input)
{
    if (input.size() == 1)
        return {{*input.begin()}};
    std::deque<std::deque<T>> result;
    for (int i = 0; i < input.size(); ++i)
    {
        std::list<T> other = input;

        auto fixed_elem = other.begin();
        for (int j = 0; j != i; ++j, ++fixed_elem);

        T fixed_elem_val = *fixed_elem;
        other.erase(fixed_elem);

        std::deque<std::deque<T>> other_permutations = permutations_rec(other);
        for (std::deque<T> permutation : other_permutations)
        {
            permutation.push_front(fixed_elem_val);
            result.push_back(permutation);
        }
    }
    return result;
}

template <typename T>
void PrintResult(std::deque<std::deque<T>> &result)
{
    int i = 0;
    for (auto elements : result)
    {
        ++i;
        std::cout << i << ": ";
        for (auto element : elements)
        {
            std::cout << element;
        }
        std::cout << std::endl;
    }
    std::cout << "----" << std::endl
              << "total: " << i << std::endl;
}

int main()
{
    std::list<int> input = {1, 2, 3};
    auto result = permutations_rec(input);
    PrintResult(result);
}
