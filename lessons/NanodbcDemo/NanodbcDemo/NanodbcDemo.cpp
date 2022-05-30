#include <iostream>
#include <string>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template<>
const char* sum(const char* a, const char* b)
{
    return a;
}

int main()
{
    Node<int> node1;
    Node<float> node2;

    int a = sum<int>(5, 6);
    float f = sum<int>(5, 6.5);
    float f = sum<float>(5, 6);
    const char* asd = sum<const char*>("ABC" , "DEF");
}

