#ifndef ARRAY_H_
#define ARRAY_H_

#include <initializer_list>
#include <stdexcept>
#include <algorithm>

namespace s21 {
template <typename T, size_t N>
class array {
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
 public:
    array();
    explicit array(std::initializer_list<value_type> const &items);
    array(const array &a);
    array(array &&a);
    ~array();
    array& operator=(array &&a);
    reference at(size_type pos);
    const_reference at(size_type pos) const;
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();
    iterator data() noexcept;
    const_iterator data() const noexcept;
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    constexpr bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;
    void swap(array& other) noexcept;
    void fill(const_reference value);
 private:
    T *_data;
};
#include "array.tpp"
}  // namespace s21
 
#endif  // ARRAY_H_

