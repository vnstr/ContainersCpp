#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// ============================ STD-LIBS =======================================

# include <iostream>
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t
# include <iterator>  // std::random_access_iterator_tag
# include <limits>    // std::numeric_limits
# include <exception> // std::exception

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

		template < class TYPE >
		struct vector_iterator {

			typedef vector_iterator<TYPE>           iterator;
			typedef ptrdiff_t                       difference_type;
			typedef TYPE                            value_type;
			typedef TYPE*                           pointer;
			typedef TYPE&                           reference;
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

		typedef ft::RandomAccessIterator<T, T*, T& >                iterator;
		typedef ft::RandomAccessIterator<T, const T*, const T&>     const_iterator;

		// typedef [> reverse_iterator<iterator> <]                 reverse_iterator;
		// typedef [> reverse_iterator<const_iterator> <]           const_reverse_iterator;
		//
		typedef typename RandomAccessIterator<T, T*, T&>::difference_type
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

			for (size_type i = 0; i < this->size_; ++i) {
				this->alloc_.destroy(this->arr_ + i);
			}
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

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

		iterator          begin() {

			return iterator(this->arr_);
		}

		const_iterator    begin() const {

			return const_iterator(this->arr_);
		}

		iterator          end() {

			return iterator(this->arr_ + this->size_);
		}

		const_iterator    end() const {

			return const_iterator(this->arr_ + this->size_);
		}

		// iterator rbegin() { + const version

		//     return iterator(this->arr_);
		// }

		// iterator rend() { + const version

		//     return iterator(this->arr_);
		// }

		// ---------------------------------------------------------------------

		// Capacity ------------------------------------------------------------

		size_type size() const {

			return this->size_;
		}

		size_type max_size() const {

			return this->alloc_.max_size();
		}

		void resize (size_type n, value_type val = value_type()) {

			(void)(val);
			if (this->size_ == n) {
				return ;
			}
			else if (this->size_ > n) {

				for (size_type i = n; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
				this->size_ = n;
			}
			else {

				pointer new_arr = this->alloc_.allocate(n);

				size_type i = 0;

				while (i < this->size_) {
					new_arr[i] = this->arr_[i];
					++i;
				}

				while (i < n) {
					this->alloc_.construct(new_arr + i, val);
					++i;
				}

				for (i = 0; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
				this->alloc_.deallocate(this->arr_, this->capacity_);

				this->arr_      = new_arr;
				this->size_     = n;
				this->capacity_ = n;
			}
		}

		size_type capacity() const {

			return this->capacity_;
		}

		bool empty() const {

			return this->size_ == 0;
		}

		void reserve (size_type n) {

			if (this->capacity_ > n) {
				return ;
			}

			pointer new_arr = this->alloc_.allocate(n);

			size_type i;
			for (i = 0; i < this->size_; ++i) {
				new_arr[i] = this->arr_[i];
			}

			for (i = 0; i < this->size_; ++i) {
				this->alloc_.destroy(this->arr_ + i);
			}
			this->alloc_.deallocate(this->arr_, this->capacity_);

			this->arr_      = new_arr;
			this->capacity_ = n;

		}


		// ---------------------------------------------------------------------

		// Element access ------------------------------------------------------

		reference    operator[] (size_type n) {

			return this->arr_[n];
		}

		const_reference operator[] (size_type n) const {

			return this->arr_[n];
		}

		reference at (size_type n) {

			if (n >= this->size_) {
				throw Vector::OutOfRange();
			}
			else {
				return this->arr_[n];
			}
		}

		const_reference at (size_type n) const {

			if (n >= this->size_) {
				throw Vector::OutOfRange();
			}
			else {
				return this->arr_[n];
			}
		}

		reference front() {

			return this->arr_[0];
		}

		const_reference front() const {

			return this->arr_[0];
		}









		// ---------------------------------------------------------------------




		// Exceptions ----------------------------------------------------------

		class OutOfRange : public std::exception {
		public:
			const char*  what() const throw() {
				return "vector";
			}
		};

		// ---------------------------------------------------------------------

	private:
		pointer          arr_;
		size_type        size_;
		size_type        capacity_;
		allocator_type   alloc_;
  };

}

#endif /* FT_VECTOR_HPP */
