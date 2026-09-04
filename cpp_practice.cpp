#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int sumOfEvenNumbers(const vector<int>& numbers) {
    int sum = 0;

    for (int number : numbers) {
        if (number % 2 == 0) {
            sum += number;
        }
    }

    return sum;
}

bool isPalindrome(const string& text) {
    string reversed = text;
    reverse(reversed.begin(), reversed.end());

    return text == reversed;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    cout << "Sum of even numbers: "
         << sumOfEvenNumbers(numbers) << '\n';

    string word = "thong";

    cout << word << " is "
         << (isPalindrome(word) ? "a palindrome" : "not a palindrome")
         << '\n';

    return 0;
}