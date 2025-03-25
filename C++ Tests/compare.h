#ifndef COMPARE_H_
#define COMPARE_H_

template <typename T>
int comp( const T& a, const T& b)
{
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

#endif