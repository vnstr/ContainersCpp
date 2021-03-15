#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// ============================ STD-LIBS =======================================

# include <iostream>
# include <cstddef>   // size_t, ptrdiff_t ...
# include <cstring>   // memcpy();
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t
# include <iterator>  // std::random_access_iterator_tag
# include <limits>    // std::numeric_limits
# include <exception> // std::exception
# include <algorithm> // std::swap(); std::equal(); std::rotate();

// =============================================================================

// ========================== OTHER INCLUDES ===================================

# include "ft_random_access_iterator.hpp"
# include "ft_reverse_iterator.hpp"

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// For correct working with size_t ---------------------------------------------

	template < bool B, class T = void >
	struct enable_if {};

	template < class T >
	struct enable_if <true, T> {
		typedef T type;
	};

// ----------------------------------------------------------------------------

// ============================= VECTOR ========================================

	template < class T, class Alloc = std::allocator<T> >
	class Vector {

	public:

		// Typedef -------------------------------------------------------------

		typedef T                                               value_type;
		typedef Alloc                                           allocator_type;
		typedef typename allocator_type::reference              reference;
		typedef typename allocator_type::const_reference        const_reference;
		typedef typename allocator_type::pointer                pointer;
		typedef typename allocator_type::const_pointer          const_pointer;

		typedef ft::RandomAccessIterator<T, T*, T& >            iterator;
		typedef ft::RandomAccessIterator<T, const T*, const T&> const_iterator;

		typedef ft::ReverseIterator<iterator>                  reverse_iterator;
		typedef ft::ReverseIterator<const_iterator>      const_reverse_iterator;

		typedef typename RandomAccessIterator<T, T*, T&>::difference_type
                                                                difference_type;

		typedef size_t                                          size_type;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit Vector(const allocator_type & alloc = allocator_type())
		: arr_(0), begin_(0), size_(0), capacity_(0), alloc_(alloc) {}

		explicit Vector
		(
		 size_type n,
		 const value_type & val = value_type(),
		 const allocator_type & alloc = allocator_type()
		) : size_(n), capacity_(n), alloc_(alloc) {

			try {
				 this->arr_   = this->alloc_.allocate(n);
			} catch (std::exception & e) {
			this->arr_      = 0;
			this->begin_    = 0;
			this->size_     = 0;
			this->capacity_ = 0;
			throw Vector::LengthError();
		}

			this->begin_ = this->arr_;
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
		) : alloc_(alloc) {

			this->size_     = last - first;
			this->capacity_ = this->size_;

			try {
				this->arr_ = this->alloc_.allocate(this->size_);
			} catch (std::exception & e) {
				this->arr_      = 0;
				this->begin_    = 0;
				this->size_     = 0;
				this->capacity_ = 0;
				throw Vector::LengthError();
			}

			this->begin_ = this->arr_;
			for (size_type i = 0; i < this->size_; ++i) {
				this->alloc_.construct(this->arr_ + i, *first);
				++first;
			}
		}

		Vector(const Vector & x)
		: size_(x.size_), capacity_(x.capacity_), alloc_(x.alloc_) {

			try {
				this->arr_ = this->alloc_.allocate(x.capacity_);
			} catch (std::exception & e) {
				this->arr_      = 0;
				this->begin_    = 0;
				this->size_     = 0;
				this->capacity_ = 0;
				throw Vector::LengthError();
			}

			this->begin_    = this->arr_;
			this->size_     = x.size_;
			this->capacity_ = x.capacity_;
			this->alloc_    = x.alloc_;
			for (size_type i = 0; i < x.size_; ++i) {
				this->alloc_.construct(this->arr_ + i, x[i]);
			}
		}

		virtual ~Vector() {

			if (this->begin_ == 0) {
				return ;
			}
			for (size_type i = 0; i < this->size_; ++i) {
				this->alloc_.destroy(this->arr_ + i);
			}
			this->alloc_.deallocate(this->begin_, this->capacity_);

			this->arr_      = 0;
			this->begin_    = 0;
			this->size_     = 0;
			this->capacity_ = 0;
		}

		// ---------------------------------------------------------------------

		// Operator '=' --------------------------------------------------------

		Vector &   operator=(Vector const & x) {

			if (this == &x)
				return (*this);

			this->~Vector();
			this->alloc_ = x.alloc_;

			try {
				this->arr_ = this->alloc_.allocate(x.capacity_);
			} catch (std::exception & e) {
				this->arr_      = 0;
				this->begin_    = 0;
				this->size_     = 0;
				this->capacity_ = 0;
				throw Vector::LengthError();
			}

			for (size_type i = 0; i < x.size_; ++i) {
				this->arr_[i] = x[i];
			}

			this->begin_    = this->arr_;
			this->size_     = x.size_;
			this->capacity_ = x.capacity_;

			return *this;
		}

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

		iterator               begin() {

			return iterator(this->arr_);
		}

		const_iterator         begin() const {

			return const_iterator(this->arr_);
		}

		iterator               end() {

			return iterator(this->arr_ + this->size_);
		}

		const_iterator         end() const {

			return const_iterator(this->arr_ + this->size_);
		}

		reverse_iterator       rbegin() {

			if (this->size_ == 0) {
				return reverse_iterator(iterator(this->arr_));
			} else {
				return reverse_iterator(iterator(this->arr_ + this->size_ - 1));
			}
		}

		const_reverse_iterator rbegin() const {

			if (this->size_ == 0) {
				return iterator(this->arr_);
			} else {
				return iterator(this->arr_ + this->size_ - 1);
			}
		}

		reverse_iterator       rend() {

			if (this->size_ == 0) {
				return reverse_iterator(iterator(this->arr_));
			} else {
				return reverse_iterator(iterator(this->arr_ - 1));
			}
		}

		reverse_iterator       rend() const {

			if (this->size_ == 0) {
				return reverse_iterator(iterator(this->arr_));
			} else {
				return reverse_iterator(iterator(this->arr_ - 1));
			}
		}

		// ---------------------------------------------------------------------

		// Capacity ------------------------------------------------------------

		size_type size() const {

			return this->size_;
		}

		size_type max_size() const {

			return this->alloc_.max_size();
		}

		void      resize (size_type n, value_type val = value_type()) {

			size_type i;

			if (this->size_ >= n) {
				for (i = n; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
				this->size_ = n;
			}
			else if (this->capacity_ >= n) {
				for (i = this->size_; i < n; ++i) {
					this->alloc_.construct(this->arr_ + i, val);
				}
				this->size_ = n;
			}
			else {
				pointer new_arr;
				try {
					new_arr = this->alloc_.allocate(n);
				} catch (std::exception & e) {
					throw Vector::LengthError();
				}

				memcpy(new_arr, this->arr_, sizeof(value_type) * this->size_);
				for (i = this->size_; i < n; ++i) {
					this->alloc_.construct(new_arr + i, val);
				}

				if (this->begin_ != 0) {
					this->alloc_.deallocate(this->begin_, this->capacity_);
				}

				this->arr_      = new_arr;
				this->begin_    = new_arr;
				this->size_     = n;
				this->capacity_ = n;
			}
		}

		size_type capacity() const {

			return this->capacity_;
		}

		bool      empty() const {

			return this->size_ == 0;
		}

		void      reserve(size_type n) {

			if (this->capacity_ >= n) {
				return ;
			}

			pointer new_arr = this->alloc_.allocate(n);;
			memcpy(new_arr, this->arr_, sizeof(value_type) * this->size_);

			if (this->begin_ != 0) {
				this->alloc_.deallocate(this->begin_, this->capacity_);
			}

			this->arr_      = new_arr;
			this->begin_    = new_arr;
			this->capacity_ = n;
		}


		// ---------------------------------------------------------------------

		// Element access ------------------------------------------------------

		reference       operator[] (size_type n) {

			return this->arr_[n];
		}

		const_reference operator[] (size_type n) const {

			return this->arr_[n];
		}

		reference       at(size_type n) {

			if (n >= this->size_) {
				throw Vector::OutOfRange();
			}
			else {
				return this->arr_[n];
			}
		}

		const_reference at(size_type n) const {

			if (n >= this->size_) {
				throw Vector::OutOfRange();
			}
			else {
				return this->arr_[n];
			}
		}

		reference       front() {

			return this->arr_[0];
		}

		const_reference front() const {

			return this->arr_[0];
		}

		reference       back() {

			return this->arr_[this->size_ - 1];
		}

		const_reference back() const {

			return this->arr_[this->size_ - 1];
		}

		// ---------------------------------------------------------------------

		// Modifiers -----------------------------------------------------------

		template <class InputIterator>
		void     assign
		(
		 InputIterator first,
		 InputIterator last,
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0
		)
		{
			if
			(
			 last - first < 0 ||
			 static_cast<size_type>(last - first) > this->max_size()
			)
			{
				this->~Vector();
				throw Vector::LengthError();
			}

			size_type new_size = static_cast<size_type>(last - first);
			size_type  i = 0;

			if (this->capacity_ > new_size) {
				for (i = 0; i < new_size; ++i, ++first) {
					this->arr_[i] = *first;
				}
				for (; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
				this->size_ = new_size;
			} else {
				pointer new_arr = this->alloc_.allocate(new_size);

				for (i = 0; i < new_size; ++i, ++first) {
					this->alloc_.construct(new_arr + i, *first);
				}
				this->~Vector();
				this->arr_      = new_arr;
				this->begin_    = new_arr;
				this->size_     = new_size;
				this->capacity_ = new_size;
			}
		}

		void     assign(size_type n, const value_type& val) {

			size_type  i = 0;

			if (this->capacity_ > n) {
				for (i = 0; i < n; ++i) {
					this->arr_[i] = val;
				}
				for (; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
				this->size_ = n;
			} else {
				pointer new_arr = this->alloc_.allocate(n);

				for (i = 0; i < n; ++i) {
					this->alloc_.construct(new_arr + i, val);
				}
				this->~Vector();
				this->arr_      = new_arr;
				this->begin_    = new_arr;
				this->size_     = n;
				this->capacity_ = n;
			}
		}

		void     push_back(const value_type & val) {

			if (this->size_ < capacity_) {
				this->alloc_.construct(this->arr_ + this->size_, val);
				++this->size_;
				return ;
			}
			size_type new_capacity;
			pointer   new_arr;

			if (this->capacity_ == 0) {
				new_capacity = 1;
			} else {
				new_capacity = this->capacity_ * 2;
			}
			try {
				new_arr = this->alloc_.allocate(new_capacity);
			} catch (std::exception & e) {
				throw Vector::LengthError();
			}
			memcpy(new_arr, this->arr_, sizeof(value_type) * this->size_);
			this->alloc_.construct(new_arr + this->size_, val);
			if (this->begin_ != 0) {
				this->alloc_.deallocate(this->begin_, this->capacity_);
			}
			++this->size_;
			this->arr_      = new_arr;
			this->begin_    = new_arr;
			this->capacity_ = new_capacity;
		}

		void     pop_back() {

			this->alloc_.destroy(this->arr_ + this->size_ - 1);
			--this->size_;
		}

		iterator insert(iterator position, const value_type& val) {

			size_type before = static_cast<size_type>(position - this->begin());

			this->insert(position, 1, val);
			return iterator(this->arr_ + before);
		}

		iterator insert(iterator position, size_type n, const value_type& val) {

			size_type before = static_cast<size_type>(position - this->begin());

			if (this->capacity_ > this->size_ + n) {
				size_type last = (this->size_ == 0) ? 0 : this->size_ - 1;

				for (size_type i = before; i < this->size_; ++i, --last) {
					memmove
					(
					 this->arr_ + last + n,
					 this->arr_ + last,
					 sizeof(value_type)
					);
				}
				for (size_type i = 0; i < n; ++i) {
					this->alloc_.construct(this->arr_ + before + i, val);
				}
				this->size_ += n;
			} else {
				size_type new_capacity = this->capacity_ * 2;

				if (new_capacity < this->size_ + n) {
					new_capacity += (this->size_ + n - new_capacity);
				}

				pointer   new_arr = this->alloc_.allocate(new_capacity);

				memcpy(new_arr, this->arr_, sizeof(value_type) * before);
				for (size_type i = 0; i < n; ++i) {
					this->alloc_.construct(new_arr + before + i, val);
				}
				memcpy
				(new_arr + before + n,
				 this->arr_ + before,
				 sizeof(value_type) * (this->size_ - before)
				);

				if (this->begin_ != 0) {
					this->alloc_.deallocate(this->begin_, this->capacity_);
				}
				this->size_     += n;
				this->arr_      = new_arr;
				this->begin_    = new_arr;
				this->capacity_ = new_capacity;
			}
			return iterator(this->arr_ + before);
		}

		template <class InputIterator>
		void     insert
		(
		 iterator position,
		 InputIterator first,
		 InputIterator last,
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0
		 ) {

			difference_type n      = last - first;
			difference_type before = position - this->begin();

			if (n <= 0)
				return ;

			if (this->capacity_ > this->size_ + n) {
				while (first != last) {
					insert(position, *first);
					++first;
					++position;
				}
			} else {
				pointer new_arr;
				size_t  new_capacity = this->capacity_ * 2;

				if (this->size_ + n > new_capacity) {
					new_capacity = this->size_ + n;
				}

				new_arr = this->alloc_.allocate(new_capacity);

				memcpy(new_arr, this->arr_, sizeof(value_type) * before);
				std::copy(first, last, new_arr + before);
				memcpy
					(
					 new_arr + before + n,
					 this->arr_ + before,
					 sizeof(value_type) * (this->size_ - before)
					 );

				if (this->begin_ != 0) {
					this->alloc_.deallocate(this->begin_, this->capacity_);
				}

				this->size_     += n;
				this->arr_      = new_arr;
				this->begin_    = new_arr;
				this->capacity_ = new_capacity;
			}

		}

		iterator erase(iterator position) {

			difference_type index = position - this->begin();

			this->alloc_.destroy(this->arr_ + index);
			--this->size_;
			memmove
				(
				 this->arr_ + index,
				 this->arr_ + index + 1,
				 sizeof(value_type) * (this->size_ - index)
				 );

			return iterator(this->arr_ + index);
		}

		iterator erase(iterator first, iterator last) {

			size_type n     = last - first;
			size_type start = first - this->begin();

			for (size_type i = 0 ; i < n; ++i) {
				this->alloc_.destroy(this->arr_ + start + i);
				--this->size_;
			}
			memmove
				(
				 this->arr_ + start,
				 this->arr_ + start + n,
				 sizeof(value_type) * (this->size_ - start)
				 );
			return iterator(this->arr_ + start);
		}

		void     swap (Vector & x) {

			std::swap(this->arr_, x.arr_);
			std::swap(this->begin_, x.begin_);
			std::swap(this->size_, x.size_);
			std::swap(this->capacity_, x.capacity_);
			std::swap(this->alloc_, x.alloc_);
		}

		void     clear() {

			if (this->begin_ != 0) {
				for (size_type i = 0; i < this->size_; ++i) {
					this->alloc_.destroy(this->arr_ + i);
				}
			}
			this->size_ = 0;
		}

		// ---------------------------------------------------------------------

		// Allocator -----------------------------------------------------------

		allocator_type get_allocator() const {

			return this->alloc_;
		}

		// ---------------------------------------------------------------------

		// Exceptions ----------------------------------------------------------

		class OutOfRange : public std::exception {
		public:
			const char*  what() const throw() {
				return "vector";
			}
		};

		class LengthError : public std::exception {
			const char* what() const throw() {
				return "vector";
			}
		};

		// ---------------------------------------------------------------------

	private:
		pointer          arr_;
		pointer          begin_;
		size_type        size_;
		size_type        capacity_;
		allocator_type   alloc_;
  };

// =============================================================================

// Relational operators ========================================================

template <class T, class Alloc>
bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return lhs.size() == rhs.size() &&
		   std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return !(lhs.size() == rhs.size() &&
		   std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return std::lexicographical_compare
		(
		 lhs.begin(),
		 lhs.end(),
		 rhs.begin(),
		 rhs.end()
		);
}

template <class T, class Alloc>
bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return !std::lexicographical_compare
		(
		 rhs.begin(),
		 rhs.end(),
		 lhs.begin(),
		 lhs.end()
		);
}

template <class T, class Alloc>
bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return std::lexicographical_compare
		(
		 rhs.begin(),
		 rhs.end(),
		 lhs.begin(),
		 lhs.end()
		);
}

template <class T, class Alloc>
bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	return !std::lexicographical_compare
		(
		 lhs.begin(),
		 lhs.end(),
		 rhs.begin(),
		 rhs.end()
		);
}

// =============================================================================

}

// ============================ END NAMESPACE FT ===============================

#endif /* FT_VECTOR_HPP */
