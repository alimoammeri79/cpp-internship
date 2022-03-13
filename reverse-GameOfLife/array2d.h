#ifndef ARRAY_2D
#define ARRAY_2D

/**
 * @file array2d.h
 * @author Ali Moameri (https://github.com/alimoammeri79)
 * @brief A generic class for building 2d arrays
 * @date 2022-03-13
 */

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

template <class Type>
class Array2d ;
template <class Type>
std::ostream& operator<<(std::ostream&, const Array2d<Type>&);

/**
 * @brief Array2d template class
 */
template <typename Type>
class Array2d {
public:
    /** Default constructor */
    Array2d();

    /**  Constructor
     *   @param hight Array hight (rows)
     *   @param width Array width (columns)
     *   @param width Object that we wonna fill array with it
     */
    Array2d(std::size_t hight, std::size_t width, const Type& fill);

    /**  Constructor
     *   @param hight Array hight (rows)
     *   @param width Array width (columns)
     *   @param width Initial elements
     */
    Array2d(std::size_t hight, std::size_t width, const std::vector<Type>& elements);

    /**  Get array hight 
     *   @return Array hight
     */
    std::size_t hight() const;

    /**  Get array width 
     *   @return Array width
     */
    std::size_t width() const;

    /**  Check wheter array is empty
     *   @return true if array is empty, false otherwise
     */
    bool is_empty() const;

    /**  Assigment operator overloading */
    Array2d& operator=(const Array2d<Type>&);

    /**  Equality operator overloading */
    bool operator==(const Array2d<Type>&) const ;

    /**  [] operator overloading (read/write access) */
    typename std::vector<Type>::iterator operator[] (const std::size_t& index);

    /**  [] operator overloading (read access only) */
    typename std::vector<Type>::const_iterator operator[](const std::size_t& index) const;

    /**  Stream insertion operator overloading (read access only) */
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

#endif //ARRAY_2D
