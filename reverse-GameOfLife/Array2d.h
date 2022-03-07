/*
 * Created by alimoameri on 2/27/22.
 * A generic class for building 2d arrays
 */

#ifndef Array2d_H
#define Array2d_H

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

/* Interface */
template <class Type>
class Array2d ;
template <class Type>
std::ostream& operator<<(std::ostream&, const Array2d<Type>&);

template <typename Type>
class Array2d {
public:
    Array2d();
    Array2d(std::size_t hight, std::size_t width, const Type& fill);
    Array2d(std::size_t hight, std::size_t width, const std::vector<Type>& elements);
    Array2d(const Array2d<Type>&);

    std::size_t hight() const;
    std::size_t width() const;
    bool is_empty() const;

    Array2d& operator=(const Array2d<Type>&);
    bool operator==(const Array2d<Type>&) const ;
    typename std::vector<Type>::iterator operator[] (const std::size_t& index);
    typename std::vector<Type>::const_iterator operator[](const std::size_t& index) const;
    friend std::ostream& operator<< <> (std::ostream&, const Array2d<Type>&);

private:
    std::size_t m_hight{ 0 };
    std::size_t m_width{ 0 };
    std::vector<Type> m_elements{};
};

/* Implementation */
template <typename Type>
Array2d<Type>::Array2d()
        : m_hight{0}, m_width{0} {}

template <typename Type>
Array2d<Type>::Array2d(std::size_t hight, std::size_t width, const Type& fill):
        m_hight{hight}, m_width{width}, m_elements(hight * width, fill) {}

template <typename Type>
Array2d<Type>::Array2d(std::size_t hight, std::size_t width, const std::vector<Type>& elements)
        : m_hight{hight}, m_width{width}, m_elements{elements} {}

template <typename Type>
Array2d<Type>::Array2d(const Array2d<Type>& array2d)
        : m_hight{array2d.m_hight}, m_width{array2d.m_width}, m_elements{array2d.m_elements} {}

template <typename Type>
std::size_t Array2d<Type>::hight() const { return m_hight; }

template <typename Type>
std::size_t Array2d<Type>::width() const { return m_width; }

template <typename Type>
bool Array2d<Type>::is_empty() const { return !(m_hight || m_width); }

template <typename Type>
Array2d<Type>& Array2d<Type>::operator=(const Array2d<Type>& array2D) {
    m_hight = array2D.hight();
    m_width = array2D.width();
    for(const auto& element: array2D.m_elements)
        m_elements.push_back(element);
    return *this;
}

template <typename Type>
bool Array2d<Type>::operator== (const Array2d<Type>& array2D) const {
    for(std::size_t i{0}; i < array2D.hight(); ++i)
        for(std::size_t j{0}; j < array2D.width(); ++j)
            if((*this)[i][j] != array2D[i][j])
                return false;
    return true;
}

template <typename Type>
typename std::vector<Type>::iterator Array2d<Type>::operator[] (const std::size_t& index) {
    return m_elements.begin() + (index * width());
}

template <typename Type>
typename std::vector<Type>::const_iterator Array2d<Type>::operator[](const std::size_t& index) const {
    return m_elements.cbegin() + (index * width());
}

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Array2d<Type>& array2D) {
    for (std::size_t i{0}; i < array2D.hight(); ++i) {
        for (std::size_t j{0}; j < array2D.width(); ++j)
            output << array2D[i][j];
        output << "\n";
    }
    return output;
}

#endif //Array2d_H
