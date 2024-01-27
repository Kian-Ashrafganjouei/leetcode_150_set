#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void mergeArrays(std::vector<int>& vector1, int n, std::vector<int>& vector2, int m) 
{
    // Ensure that vector1 has enough space to accommodate both arrays
    vector1.resize(n + m);

    int i = n - 1;  // Index of the last element in vector1
    int j = m - 1;  // Index of the last element in vector2
    int k = n + m - 1;  // Index of the last position in the merged vector

    // Merge vector1 and vector2 in descending order
    while (i >= 0 && j >= 0) {
        if (vector1[i] > vector2[j]) {
            vector1[k--] = vector1[i--];
        } else {
            vector1[k--] = vector2[j--];
        }
    }

    // If vector2 has remaining elements, copy them to vector1
    while (j >= 0) {
        vector1[k--] = vector2[j--];
    }
}

int main() 
{
    // Seed for random number generation
    std::srand(std::time(0));

    // Get user input for n and m
    int n, m;
    std::cout << "Enter the size of the first vector (n): ";
    std::cin >> n;
    std::cout << "Enter the size of the second vector (m): ";
    std::cin >> m;

    // Generate vector 1 with random values in increasing order
    std::vector<int> vector1;
    for (int i = 0; i < n; ++i) {
        vector1.push_back(std::rand() % 101); // Random value between 0 and 100
    }
    std::sort(vector1.begin(), vector1.end());

    // Generate vector 2 with random values in increasing order
    std::vector<int> vector2;
    for (int i = 0; i < m; ++i) {
        vector2.push_back(std::rand() % 101); // Random value between 0 and 100
    }
    std::sort(vector2.begin(), vector2.end());

    // Display the generated vectors
    std::cout << "\nGenerated Vector 1: ";
    for (int value : vector1) {
        std::cout << value << " ";
    }

    std::cout << "\nGenerated Vector 2: ";
    for (int value : vector2) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
    mergeArrays(vector1, n, vector2, m);

    // Display the generated vectors
    std::cout << "\nMerged vector 1 Vector 1: ";
    for (int value : vector1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
