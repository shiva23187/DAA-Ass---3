#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i = 0, j = 0, count = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            count++;
            i++;
        }
        j++;
    }
    return count;
}

int main() {
    std::vector<int> greedFactor = {1, 2, 3};
    std::vector<int> cookieSize = {1, 1};
    std::cout << findContentChildren(greedFactor, cookieSize);
    return 0;
}