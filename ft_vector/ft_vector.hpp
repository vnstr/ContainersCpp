#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// ============================ STD-LIBS =======================================

# include <iostream>
# include <memory>   // allocator
# include <cstddef>  // ptrdiff_t
# include <iterator> // std::random_access_iterator_tag
# include <limits> // std::numeric_limits

// =============================================================================

// ========================== OTHER INCLUDES ===================================

# include "ft_random_access_iterator.hpp"

// =============================================================================

namespace ft {

template < bool B, class T = void >
struct enable_if {};

template < class T >
struct enable_if <true, T> {
	typedef T type;
};

// ============================= VECTOR ========================================

	template < class T, class Alloc = std::allocator<T> >
	class Vector {

	public:

		// Iterators-structs ---------------------------------------------------

		struct vector_iterator {

			typedef ptrdiff_t                       difference_type;
			typedef T                               value_type;
			typedef T*                              pointer;
			typedef T &                             reference;
			typedef std::random_access_iterator_tag iterator_category;
		};

		struct const_vector_iterator {

			typedef ptrdiff_t                       difference_type;
			typedef T                               value_type;
			typedef T const *                       pointer;
			typedef T const &                       reference;
			typedef std::random_access_iterator_tag iterator_category;
		};

		// ---------------------------------------------------------------------

		// Typedef -------------------------------------------------------------

		typedef T                                                   value_type;
		typedef Alloc                                               allocator_type;
		typedef typename allocator_type::reference                  reference;
		typedef typename allocator_type::const_reference            const_reference;
		typedef typename allocator_type::pointer                    pointer;
		typedef typename allocator_type::const_pointer              const_pointer;

		typedef ft::RandomAccessIterator<vector_iterator>           iterator;
		typedef ft::RandomAccessIterator<vector_iterator>           const_iterator;
		// typedef [> reverse_iterator<iterator> <]                 reverse_iterator;
		// typedef [> reverse_iterator<const_iterator> <]           const_reverse_iterator;
		//
		typedef typename ft::iterator_traits<vector_iterator>::difference_type
                                                                    difference_type;

		typedef size_t                                              size_type;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

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
				this->alloc_.construct(this->arr_ + i, val);
			}
		  }

		template <class InputIterator>
		Vector
		(
		 InputIterator first,
		 InputIterator last,
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0,
		 const allocator_type& alloc = allocator_type()
		) : alloc_(alloc)
		{
			this->size_     = last - first;
			this->capacity_ = this->size_;
			this->arr_      = this->alloc_.allocate(this->size_);
			for (size_type i = 0; i < this->size_; ++i) {
				this->arr_[i] = *first;
				++first;
			}
		}

		Vector(const Vector & x)
			: size_(x.size_), capacity_(x.capacity_), alloc_(x.alloc_) {

				this->arr_ = this->alloc_.allocate(x.size_);
				for (size_type i = 0; i < x.size_; ++i) {
					this->arr_[i]  = x.arr_[i];
				}
			}

		virtual ~Vector() {

			this->alloc_.deallocate(this->arr_, this->capacity_);
		}

		// ---------------------------------------------------------------------

		// Operators -----------------------------------------------------------

		Vector &   operator=(Vector const & x) {

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
			return *this;
		}

		reference  operator[](difference_type index) {

			return this->arr_[index];
		}

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

		iterator    begin() {

			return iterator(this->arr_);
		}

		iterator    end() {

			return iterator(this->arr_ + this->size_);
		}

		// iterator rbegin() {

		//     return iterator(this->arr_);
		// }

		// iterator rend() {

		//     return iterator(this->arr_);
		// }

		// Capacity ------------------------------------------------------------

		size_type size() const {

			return this->size_;
		}

		// ---------------------------------------------------------------------

		// ---------------------------------------------------------------------
	private:
		pointer          arr_;
		size_type        size_;
		size_type        capacity_;
		allocator_type   alloc_;
  };

}

#endif /* FT_VECTOR_HPP */
