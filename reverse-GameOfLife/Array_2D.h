/*
 * Created by alimoameri on 2/27/22.
 *
 */

#ifndef Array_2D_H
#define Array_2D_H

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

template <class Type>
class Array_2D ;
template <class Type>
std::ostream& operator<<(std::ostream&, const Array_2D<Type>&);

template <typename Type>
class Array_2D {
public:
    Array_2D();
    Array_2D(std::size_t hight, std::size_t width, const Type& fill);
    Array_2D(std::size_t hight, std::size_t width, const std::vector<Type>& elements);
    Array_2D(const Array_2D<Type>&);

    std::size_t hight() const;
    std::size_t width() const;
    bool is_empty() const;

    Array_2D& operator=(const Array_2D<Type>&);
    bool operator==(const Array_2D<Type>&) const ;
    typename std::vector<Type>::iterator operator[] (const std::size_t& index);
    typename std::vector<Type>::const_iterator operator[](const std::size_t& index) const;
    friend std::ostream& operator<< <> (std::ostream&, const Array_2D<Type>&);

private:
    std::size_t m_hight{ 0 };
    std::size_t m_width{ 0 };
    std::vector<Type> m_elements{};
};

/* Implementation */
template <typename Type>
Array_2D<Type>::Array_2D()
        : m_hight{0}, m_width{0} {}

template <typename Type>
Array_2D<Type>::Array_2D(std::size_t hight, std::size_t width, const Type& fill):
        m_hight{hight}, m_width{width}, m_elements(hight * width, fill) {}

template <typename Type>
Array_2D<Type>::Array_2D(std::size_t hight, std::size_t width, const std::vector<Type>& elements)
        : m_hight{hight}, m_width{width}, m_elements{elements} {}

template <typename Type>
Array_2D<Type>::Array_2D(const Array_2D<Type>& Array_2D)
        : m_hight{Array_2D.m_hight}, m_width{Array_2D.m_width}, m_elements{Array_2D.m_elements} {}

template <typename Type>
std::size_t Array_2D<Type>::hight() const { return m_hight; }

template <typename Type>
std::size_t Array_2D<Type>::width() const { return m_width; }

template <typename Type>
bool Array_2D<Type>::is_empty() const { return !(m_hight || m_width); }

template <typename Type>
Array_2D<Type>& Array_2D<Type>::operator=(const Array_2D<Type>& array2D) {
    m_hight = array2D.hight();
    m_width = array2D.width();
    for(const auto& element: array2D.m_elements)
        m_elements.push_back(element);
    return *this;
}

template <typename Type>
bool Array_2D<Type>::operator== (const Array_2D<Type>& array2D) const {
    for(std::size_t i{0}; i < array2D.hight(); ++i)
        for(std::size_t j{0}; j < array2D.width(); ++j)
            if((*this)[i][j] != array2D[i][j])
                return false;
    return true;
}

template <typename Type>
typename std::vector<Type>::iterator Array_2D<Type>::operator[] (const std::size_t& index) {
    return m_elements.begin() + (index * width());
}

template <typename Type>
typename std::vector<Type>::const_iterator Array_2D<Type>::operator[](const std::size_t& index) const {
    return m_elements.cbegin() + (index * width());
}

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Array_2D<Type>& array2D) {
    for (std::size_t i{0}; i < array2D.hight(); ++i) {
        for (std::size_t j{0}; j < array2D.width(); ++j)
            output << array2D[i][j];
        output << "\n";
    }
    return output;
}

#endif //Array_2D_H