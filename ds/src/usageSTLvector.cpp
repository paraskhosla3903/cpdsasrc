/**
 * @file usageSTLvector.cpp
 * @author paraskhosla
 * @brief 
 * @version 0.1
 * @date 2025-08-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>

int main()
{
    /**
     * @brief Introduction to std::vector
     * @cite https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
     */
    {
        /// @cite https://stackoverflow.com/questions/63478034/why-is-value-initialization-specified-as-not-calling-trivial-default-constructor
        std::vector<int> empty {}; // value initialisation (uses default constructor)

//    #ifndef _LIBCPP_CXX03_LANG
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(initializer_list<value_type> __il);
//
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
//        vector(initializer_list<value_type> __il, const allocator_type& __a);
//
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector& operator=(initializer_list<value_type> __il) {
//            assign(__il.begin(), __il.end());
//            return *this;
//        }
//    #endif // !_LIBCPP_CXX03_LANG
        std::vector<int> even {0, 2, 4, 6, 8, 10}; // list initialisation (initializer_list)

        // typedef _Tp value_type;
        // typedef value_type& reference;

//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference operator[](size_type __n) _NOEXCEPT;
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference operator[](size_type __n) const _NOEXCEPT;
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference at(size_type __n);
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference at(size_type __n) const;

//        template <class _Tp, class _Allocator>
//        _LIBCPP_CONSTEXPR_SINCE_CXX20 inline _LIBCPP_HIDE_FROM_ABI typename vector<_Tp, _Allocator>::reference
//        vector<_Tp, _Allocator>::operator[](size_type __n) _NOEXCEPT {
//            _LIBCPP_ASSERT_VALID_ELEMENT_ACCESS(__n < size(), "vector[] index out of bounds");
//            return this->__begin_[__n];
//        }
        auto x = even[0];
        std::cout << x << " " << &x << '\n';

        const std::vector<int> odd {1, 3, 5, 7, 9};
        auto y = odd[0]; // "const" overloaded function signature for [] operator
        std::cout << y << " " << &y << '\n';

        size_t n = even.size();
        std::cout << even[n] << '\n'; // undefined behavior

        for(auto& i : even)
        {
            std::cout << &i << '\n';
        }
        // 0x128e05f60
        // 0x128e05f64
        // 0x128e05f68
        // 0x128e05f6c
        // 0x128e05f70
        // 0x128e05f74

        // explicit std::vector<T>(std::size_t)
        /// @cite https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
        // explicit keyword prevents the compiler from using implicit converting ctors
        std::vector<int> (10); // Each of the created elements are value-initialized
        // which for int does zero-initialization (and for class types calls the default constructor)

        std::vector<int> {10}; // list ctor takes precedence when more than one ctor matches ctor definition

        return 0;
    }
}