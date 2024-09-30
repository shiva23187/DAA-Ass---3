#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;

    for (const auto& item : items) {
        if (W <= 0) break;

        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }
    
    return totalValue;
}

int main() {
    int W = 50;
    std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    double maxValue = fractionalKnapsack(W, items);
    std::cout << "Maximum value in Knapsack = " << maxValue << std::endl;

    return 0;
}

