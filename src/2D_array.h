#ifndef D_ARRAY_H
#define D_ARRAY_H

#include <vector>
#include <initializer_list>

template <typename T>
class TwoDArray{
private:
    std::vector<std::vector<T>> _arr;
    int _rows;
    int _cols;

public:
    TwoDArray(int m, int n);

    TwoDArray(int m, int n, const T& defaultValue);

    T get(int i, int j) const;

    void set (int i, int j, const T& value);
    TwoDArray(std::initializer_list<std::initializer_list<T>> init);
    // 在顺序二维表中找到value
    bool find_num_order(const T& value);

};


#endif