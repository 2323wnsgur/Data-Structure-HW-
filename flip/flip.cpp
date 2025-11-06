#include <iostream>
#include <vector>
#include <set>


void process_flip(std::set<long long>& boundaries, long long index) {
    if (boundaries.count(index)) {
        boundaries.erase(index);
    } else {
        boundaries.insert(index);
    }
}

int main() {


    long long N, K;
    std::cin >> N >> K;

    std::set<long long> boundaries;

    for (int k = 0; k < K; ++k) {
        long long i, j;
        std::cin >> i >> j;
        process_flip(boundaries, i);
        process_flip(boundaries, j + 1);
    }

    long long run_count = boundaries.size() / 2;
    long long total_ones = 0;


    auto it = boundaries.begin();
    while (it != boundaries.end()) {
        long long start = *it;
        ++it;
        if (it != boundaries.end()) {
            long long end = *it;
            total_ones += (end - start);
            ++it;
        }
    }

    std::cout << run_count << " " << total_ones << std::endl;

    return 0;
}
