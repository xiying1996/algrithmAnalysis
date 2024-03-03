#include "2D_array.h"

template <typename T>
TwoDArray<T>::TwoDArray(int m, int n): _rows(m), _cols(n){
    _arr.resize(m, std::vector<T>(n, T{}));
}

template <typename T>
TwoDArray<T>::TwoDArray(int m, int n, const T& defaultValue) : _rows(m), _cols(n) {
    _arr.resize(m, std::vector<T>(n, defaultValue)); // 初始化二维数组为指定默认值
}

template <typename T>
T TwoDArray<T>::get(int i, int j) const {
    return _arr[i][j];
}

template <typename T>void TwoDArray<T>::set (int i, int j, const T& value){
        _arr[i][j] = value;
    }

template <typename T>
bool TwoDArray<T>::find_num_order(const T& value){
    for(int i = 0; i < _rows; i++){
        for (int j = 0; j < _cols; j++) {
            if(_arr[i][j] == value){
                return true;
            }
            else if (_arr[i][j] > value) {
                break;
            }
        }
    }

}

template <typename T>
TwoDArray<T>::TwoDArray(std::initializer_list<std::initializer_list<T>> init) {
    _rows = init.size();
    _cols = (init.begin() != init.end()) ? init.begin()->size() : 0;
    _arr.resize(_rows, std::vector<T>(_cols));

    int i = 0;
    for (const auto& row : init) {
        int j = 0;
        for (const auto& value : row) {
            _arr[i][j] = value;
            ++j;
        }
        ++i;
    }
}    


// 线形实例化模版类，不然无法使用
template class TwoDArray<int>;