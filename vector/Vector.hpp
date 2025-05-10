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

    // constructors
    Vector() noexcept(std::is_nothrow_default_constructible<Alloc>::value) //default
        : alloc_(), data_(nullptr), size_(0), cap_(0) {}

    explicit Vector(size_type n, T const& value = T(), Alloc const& a = Alloc()) //size+value
        : alloc_(a), size_(n), cap_(n)
    {
        data_ = alloc_.allocate(cap_);
        for (size_type i = 0; i < n; ++i)
        std::allocator_traits<Alloc>::construct(alloc_, data_ + i, value);
    }

    template<typename InputIt, //range 
            typename = typename std::enable_if<!std::is_integral<InputIt>::value>::type>
    Vector(InputIt first, InputIt last, Alloc const& a = Alloc())
        : alloc_(a)
    {
        size_type n = std::distance(first, last);
        data_ = alloc_.allocate(n);
        size_ = cap_ = n;
        std::uninitialized_copy(first, last, data_);
    }

    Vector(Vector const& other) //copy 
        : alloc_(std::allocator_traits<Alloc>::select_on_container_copy_construction(other.alloc_)),
        size_(other.size_), cap_(other.size_)
    {
        data_ = alloc_.allocate(cap_);
        std::uninitialized_copy(other.data_, other.data_ + size_, data_);
    }

    Vector(Vector&& other) noexcept //move
        : alloc_(std::move(other.alloc_)),
        data_(other.data_), size_(other.size_), cap_(other.cap_)
    {
        other.data_ = nullptr;
        other.size_ = other.cap_ = 0;
    }

    Vector(std::initializer_list<T> il, Alloc const& a = Alloc()) //init list
        : Vector(il.begin(), il.end(), a) {}

    ~Vector() { //destr
        clear();
        if (data_) alloc_.deallocate(data_, cap_);
    }

    
};

#endif