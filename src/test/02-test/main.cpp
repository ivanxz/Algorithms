//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <tuple>

using namespace std;

//void quick_sort(auto begin, auto end) {
//    if (begin != end) {
//        auto pivot = *std::next(begin, std::distance(begin, end) / 2);
//        const auto[lt, gt] = ::partition(begin, end, pivot);
//        quick_sort(begin, lt);
//        quick_sort(gt, end);
//    }
//}

int main() {
//    std::vector<int> vec{5, 0, 1, 5, 3, 7, 4, 2};
//    //quick_sort(vec.begin(), vec.end());
//    std::for_each(vec.begin(), vec.end(), [](const int elem) { std::cout << elem << " "; });
//    cout << endl;
//
//    std::vector<double> temperatures{65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50};
//    std::copy(std::begin(temperatures), std::end(temperatures), std::ostream_iterator<double>{std::cout, " "});
//    std::cout << std::endl;
//    auto average = std::accumulate(std::begin(temperatures), std::end(temperatures), 0.0) / temperatures.size();
//    std::cout << "Average temperature: " << average << std::endl;
//    std::stable_partition(std::begin(temperatures), std::end(temperatures),
//                          [average](double t) { return t < average; });
//    std::copy(std::begin(temperatures), std::end(temperatures), std::ostream_iterator<double>{std::cout, " "});
//    std::cout << std::endl;
    return 0;
}