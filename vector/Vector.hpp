#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <initializer_list>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <utility>

template<typename T, typename Alloc = std::allocator<T>>
class Vector {

    // member types
    using value_type = T;
    using allocator_type = Alloc;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = T const&;
    using pointer = typename std::allocator_traits<Alloc>::pointer;
    using const_pointer = typename std::allocator_traits<Alloc>::const_pointer;
    using iterator = T*;
    using const_iterator = T const*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


};

#endif