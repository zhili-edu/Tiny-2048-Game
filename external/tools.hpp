#ifndef MYTOOLS_H
#define MYTOOLS_H

#include <string>
#include <sstream>

template <size_t Rows, size_t Cols>
std::string arrayToString(int (&arr)[Rows][Cols]) {
    std::ostringstream oss;
    for (size_t i = 0; i < Rows; ++i) {
        for (size_t j = 0; j < Cols; ++j) {
            oss << arr[i][j] << " ";
        }
        oss << "\n";
    }
    return oss.str();
}

#endif