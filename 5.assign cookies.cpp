#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    
    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) {
            child++;
        }
        cookie++;
    }
    
    return child;
}

int main() {
    std::vector<int> g = {1, 2, 3};
    std::vector<int> s = {1, 1};
    
    int result = findContentChildren(g, s);
    std::cout << "Number of content children: " << result << std::endl;
    
    return 0;
}
