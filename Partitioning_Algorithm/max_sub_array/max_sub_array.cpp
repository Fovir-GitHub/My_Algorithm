#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

typedef std::vector<int>::iterator Iter;

class ReturnThree
{
private:
    Iter left;
    Iter right;
    int  sum;

public:
    ReturnThree(Iter l, Iter r, int s) : left(l), right(r), sum(s) {}

    int  GetSum() { return sum; }
    Iter GetLeft() { return left; }
    Iter GetRight() { return right; }
};

ReturnThree findMaxSubArray(std::vector<int> & v, Iter low, Iter high);
ReturnThree findCrossSubArray(std::vector<int> & v, Iter low, Iter middle,
                              Iter high);

int generateData()
{
    return rand() % 20;
}

int main(void)
{
    const int VECTOR_SIZE = 10;
    std::srand(std::time(0));
    // std::freopen("./test.in", "r", stdin);

    std::vector<int> temp_vec(VECTOR_SIZE), v;
    int              temp;

    while (std::cin >> temp) temp_vec.push_back(temp);
    // std::generate(temp_vec.begin(), temp_vec.end(), generateData);

    for (size_t i = 1; i < temp_vec.size(); i++)
        v.push_back(temp_vec[i] - temp_vec[i - 1]);

    ReturnThree max_sub_array = findMaxSubArray(v, v.begin(), v.end());
    std::cout << "Left: " << *max_sub_array.GetLeft() << '\n'
              << "Right: " << *(max_sub_array.GetRight() - 1) << '\n'
              << "Sum: " << max_sub_array.GetSum() << '\n';

    std::cout << "Original array:\n";
    for (auto x : temp_vec) std::cout << x << ' ';
    std::cout << "\nNew array:\n";
    for (auto x : v) std::cout << x << ' ';
    std::cout << "\n";

    for (auto iter = max_sub_array.GetLeft(); iter != max_sub_array.GetRight();
         iter++)
        std::cout << *iter << " ";

    return 0;
}

ReturnThree findMaxSubArray(std::vector<int> & v, Iter low, Iter high)
{
    if (std::distance(low, high) <= 1)
        return ReturnThree(low, high, *low);

    Iter middle   = low;
    int  distance = std::distance(low, high);
    std::advance(middle, distance >> 1);

    ReturnThree left_sum  = findMaxSubArray(v, low, middle),
                right_sum = findMaxSubArray(v, middle, high),
                cross_sum = findCrossSubArray(v, low, middle, high);

    if (left_sum.GetSum() > right_sum.GetSum() &&
        left_sum.GetSum() > cross_sum.GetSum())
        return left_sum;
    else if (right_sum.GetSum() > left_sum.GetSum() &&
             right_sum.GetSum() > cross_sum.GetSum())
        return right_sum;
    else
        return cross_sum;
}

ReturnThree findCrossSubArray(std::vector<int> & v, Iter low, Iter middle,
                              Iter high)
{
    static const int INF = 0x7FFFFFFF;

    Iter temp;
    int  left_sum = -INF, right_sum = -INF;
    int  sum          = 0;
    Iter left_max_pos = middle, right_max_pos = middle;

    for (temp = middle; temp != low;)
    {
        --temp;
        if ((sum += *temp) > left_sum)
        {
            left_sum     = sum;
            left_max_pos = temp;
        }
    }

    sum = 0;
    for (temp = middle; temp != high; temp++)
        if ((sum += *temp) > right_sum)
        {
            right_sum     = sum;
            right_max_pos = temp + 1;
        }

    return ReturnThree(left_max_pos, right_max_pos, left_sum + right_sum);
}
