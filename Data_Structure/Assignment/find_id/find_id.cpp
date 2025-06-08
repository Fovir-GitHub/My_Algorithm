#include <iostream>
#include <vector>

class FindId {
private:
    enum { LIMIT = 10 };

    std::vector<int> numbers;
    int search_id;

    bool IsAscending();
    int SequentialSearch();
    int BinarySearch(int left, int right);

public:
    FindId() : numbers(LIMIT, 0), search_id(0) {}
    FindId(const std::vector<int> & num) : numbers(num), search_id(0) {}
    ~FindId() {}

    void GetSearchId();
    void Solve();
};

bool FindId::IsAscending() {
    for (int i = 0; i < numbers.size() - 1; i++)
        if (numbers[i] > numbers[i + 1])
            return false;

    return true;
}

int FindId::SequentialSearch() {
    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == search_id)
            return i;

    return -1;
}

int FindId::BinarySearch(int left, int right) {
    if (left >= right)
        return -1;

    int middle = (left + right) / 2;

    if (numbers[middle] == search_id)
        return middle;

    if (numbers[middle] < search_id)
        return BinarySearch(middle + 1, right);

    return BinarySearch(left, middle - 1);
}

void FindId::GetSearchId() {
    std::cout << "Product IDs: [";
    for (int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << (i == numbers.size() - 1 ? "]\n" : ", ");

    std::cout << "Search for: ";
    std::cin >> search_id;
}

void FindId::Solve() {
    bool use_sequential_search = !IsAscending();

    std::cout << "-> "
              << (use_sequential_search ? "Sequential Search used"
                                        : "Binary Search used")
              << '\n';

    int product_index =
        (use_sequential_search ? SequentialSearch()
                               : BinarySearch(0, numbers.size()));

    if (product_index == -1)
        std::cout << "Not found\n";
    else
        std::cout << "Product ID found at index " << product_index << '\n';

    return;
}

int main(void) {
    FindId fi({10, 12, 22, 29, 33, 43, 48, 67, 89, 90});

    while (true) {
        fi.GetSearchId();
        fi.Solve();
    }

    return 0;
}