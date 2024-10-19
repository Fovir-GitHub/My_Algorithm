#include<iostream>
#include<vector>
#include<iterator>

typedef std::vector<int>::iterator Iter;

static int count = 1;

void mergeSort(std::vector<int> & v, Iter left_pos, Iter right_pos);
void merge(std::vector<int> & v, Iter left_pos,
    Iter middle_pos, Iter right_pos);

int main(void)
{
    // std::freopen("./test.in", "r", stdin);
    std::vector<int> a;
    int temp;

    while (std::cin >> temp)
        a.push_back(temp);

    mergeSort(a, a.begin(), a.end());
    for (auto x : a)
        std::cout << x << " ";

    return 0;
}

void mergeSort(std::vector<int> & v, Iter left_pos, Iter right_pos)
{
    int distance;
    Iter middle_pos = left_pos;


    if ((distance = std::distance(left_pos, right_pos)) <= 1)  /* remain only one element */
        return;

    std::advance(middle_pos, distance / 2);
    mergeSort(v, left_pos, middle_pos);
    mergeSort(v, middle_pos, right_pos);
    merge(v, left_pos, middle_pos, right_pos);

    return;
}

void merge(std::vector<int> & v, Iter left_pos, Iter middle_pos, Iter right_pos)
{
    std::vector<int> temp(std::distance(left_pos, right_pos));
    Iter left_head = left_pos, right_head = middle_pos;
    Iter temp_iter = temp.begin();

    while (left_head != middle_pos && right_head != right_pos)
    {
        if (*left_head < *right_head)
        {
            *temp_iter = *left_head;
            left_head++;
        }
        else
        {
            *temp_iter = *right_head;
            right_head++;
        }
        temp_iter++;
    }

    while (left_head != middle_pos)
    {
        *temp_iter = *left_head;
        left_head++;
        temp_iter++;
    }
    while (right_head != right_pos)
    {
        *temp_iter = *right_head;
        right_head++;
        temp_iter++;
    }

    std::copy(temp.begin(), temp.end(), left_pos);
    return;
}