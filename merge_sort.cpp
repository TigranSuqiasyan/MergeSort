#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &vec, int start, int end)
{
    std::vector<T> temp(vec.size());
    int mid = start + (end - start) / 2;
    int start_1 = start;
    int end_1 = mid;
    int start_2 = mid + 1;
    int end_2 = end;
    int index = start;
    while ((start_1 <= end_1) && (start_2 <= end_2))
    {
        if (vec[start_1] < vec[start_2])
            temp[index++] = vec[start_1++];
        else
            temp[index++] = vec[start_2++];
    }
    while(start_1 <= end_1)
        temp[index++] = vec[start_1++];
    while(start_2 <= end_2)
        temp[index++] = vec[start_2++];
    for(int i{start}; i <= end; ++i)
    {
        vec[i] = temp[i];
    }
}

template <typename T>
void merge_sort(std::vector<T> &vec, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort(vec, start, mid);
        merge_sort(vec, mid + 1, end);
        merge(vec, start, end);
    }
}

int main()
{
    std::vector<int> vec{1,3,9,5,47,36,-58,-69, 17, 16, 17, 0, 14,25,36,69,85,547};
    merge_sort(vec, 0, vec.size() - 1);
    for(int i{}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
}