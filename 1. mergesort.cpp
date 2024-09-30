#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftHalf(n1);
    std::vector<int> rightHalf(n2);

    for (int i = 0; i < n1; i++)
        leftHalf[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightHalf[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    
    merge_sort(array, 0, array.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
