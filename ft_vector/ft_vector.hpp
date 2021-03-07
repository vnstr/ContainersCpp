#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// ============================ STD-LIBS =======================================

# include <iostream>
# include <memory>   // allocator
# include <cstddef>  // ptrdiff_t
# include <iterator> // std::random_access_iterator_tag

// =============================================================================

// ========================== OTHER INCLUDES ===================================

# include "ft_random_access_iterator.hpp"

// =============================================================================

namespace ft {

// ============================= VECTOR ========================================

  template < class T, class Alloc = std::allocator<T> >
  class Vector {

  public:

	// Iterators --------------------------------------------------------------

	struct        vector_iterator {

		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef T*                              pointer;
		typedef T &                             reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	// ------------------------------------------------------------------------

	// Typedef ----------------------------------------------------------------

	typedef T                                                   value_type;
	typedef Alloc                                               allocator_type;
	typedef typename allocator_type::reference                  reference;
	typedef typename allocator_type::const_reference            const_reference;
	typedef typename allocator_type::pointer                    pointer;
	typedef typename allocator_type::const_pointer              const_pointer;

	typedef ft::RandomAccessIterator<vector_iterator>           iterator;
	// typedef [> random_access_iterator_t <]                   const_iterator;
	// typedef [> reverse_iterator<iterator> <]                 reverse_iterator;
	// typedef [> reverse_iterator<const_iterator> <]           const_reverse_iterator;
	// typedef [> iterator_traits<iterator>::difference_type <] difference_type;
	typedef size_t                                              size_type;

	// ------------------------------------------------------------------------

	// Constructor - Destructor -----------------------------------------------

	explicit Vector(const allocator_type & alloc = allocator_type())
	  : arr_(0), size_(0), capacity_(0), alloc_(alloc) {}

	explicit Vector
	  (
	   size_type n,
	   const value_type& val = value_type(),
       const allocator_type& alloc = allocator_type()
	  )
	  : size_(n), capacity_(n), alloc_(alloc) {

		this->arr_ = this->alloc_.allocate(n);
		for (size_type i = 0; i < n; ++i) {
			this->arr_[i] = val;
		}
	  }

	// template <class InputIterator>
    // Vector
	// (
	//  InputIterator first,
	//  InputIterator last,
    //  const allocator_type& alloc = allocator_type()
	// )

	Vector(const Vector & x)
		: size_(x.size_), capacity_(x.capacity_), alloc_(x.alloc_) {

			this->arr_ = this->alloc_.allocate(x.size_);
			for (size_type i = 0; i < x.size_; ++i) {
				this->arr_[i]  = x.arr_[i];
			}
		}

	~Vector() {

		this->alloc_.deallocate(this->arr_, this->capacity_);
	}

	// ------------------------------------------------------------------------

	// Operators --------------------------------------------------------------

	Vector & operator=(Vector const & x) {

		if (this == &x)
			return (*this);

		this->alloc_.deallocate(this->arr_, this->capacity_);

		this->alloc_    = x.alloc_;
		this->arr_      = this->alloc_.allocate(x.capacity_);
		this->size_     = x.size_;
		this->capacity_ = x.capacity_;

		for (size_type i = 0; i < x.size_; ++i) {
			this->arr_[i] = x.arr_[i];
		}
		return (*this);
	}


  private:
	pointer          arr_;
	size_type        size_;
	size_type        capacity_;
	allocator_type   alloc_;
  };

}

#endif /* FT_VECTOR_HPP */
