#ifndef FT_RANDOM_ACCESS_ITERATOR
# define FT_RANDOM_ACCESS_ITERATOR

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...

// =============================================================================

// ===================== RADOM ACCESS ITERATOR =================================

namespace ft {

	template < class T, class P, class R >
	class RandomAccessIterator {

	public:

		// Typedef -------------------------------------------------------------

		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef P                               pointer;
		typedef R                               reference;
		typedef std::random_access_iterator_tag iterator_category;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		RandomAccessIterator() : arr_(0) {}
		RandomAccessIterator(pointer arr) : arr_(arr) {}

		RandomAccessIterator(RandomAccessIterator<T, T*, T&> const & x)
			: arr_(x.get_pointer()) {}

		virtual ~RandomAccessIterator() {}

		// ---------------------------------------------------------------------

		// Operators -----------------------------------------------------------

		// '='
		RandomAccessIterator &operator=(RandomAccessIterator const & x) {

			if (this == &x)
				return *this;
			this->arr_ = x.arr_;
			return *this;
		}

		// '=='
		bool                 operator==(RandomAccessIterator const & x) const {

			return this->arr_ == x.arr_;
		}

		// '!='
		bool                 operator!=(RandomAccessIterator const & x) const {

			return this->arr_ != x.arr_;
		}

		// '*'
		reference            operator*() {

			return *this->arr_;
		}

		// '->'
		pointer              operator->() {

			return this->arr_;
		}

		// '++iter'
		RandomAccessIterator operator++() {

			++this->arr_;
			return (*this);
		}

		// 'iter++'
		RandomAccessIterator operator++(int) {

			RandomAccessIterator tmp(*this);
			++this->arr_;
			return (tmp);
		}

		// '--iter'
		RandomAccessIterator operator--() {

			--this->arr_;
			return (*this);
		}

		// 'iter--'
		RandomAccessIterator operator--(int) {

			RandomAccessIterator tmp(*this);
			--this->arr_;
			return (tmp);
		}

		// '+'
		RandomAccessIterator operator+(difference_type n) const {

			return (RandomAccessIterator(this->arr_ + n));
		}

		// '-'
		RandomAccessIterator operator-(difference_type n) const {

			return (RandomAccessIterator(this->arr_ - n));
		}

		// '+='
		RandomAccessIterator &operator+=(difference_type n) {

			this->arr_ += n;
			return (*this);
		}

		// '-='
		RandomAccessIterator &operator-=(difference_type n) {

			this->arr_ -= n;
			return (*this);
		}

		// '<'
		bool                 operator<(RandomAccessIterator const & x) const {

			return this->arr_ < x.get_pointer();
		}


		// '>'
		bool                 operator>(RandomAccessIterator const & x) const {

			return this->arr_ > x.get_pointer();
		}

		// '<='
		bool                 operator<=(RandomAccessIterator const & x) const {

			return this->arr_ <= x.get_pointer();
		}

		// '>='
		bool                 operator>=(RandomAccessIterator const & x) const {

			return this->arr_ >= x.get_pointer();
		}

		reference            operator[](difference_type index) {

			return this->arr_[index];
		}

		// ---------------------------------------------------------------------

		// GETTERS -------------------------------------------------------------

		pointer get_pointer() const {

			return this->arr_;
		}

		// ---------------------------------------------------------------------

	private:

		pointer arr_;

	};

	// Relational Operators ----------------------------------------------------

	// 'n + iter'
	template < class T, class P, class R >
	RandomAccessIterator<T, P, R> operator+
	(
	 typename RandomAccessIterator<T, P, R>::difference_type n,
	 RandomAccessIterator<T, P, R> const & x
	)
	{
		return x + n;
	}

	// // 'iter - iter'
	template < class T, class P, class R >
	typename RandomAccessIterator<T, P, R>::difference_type operator-
	(
	 RandomAccessIterator<T, P, R> const & a,
	 RandomAccessIterator<T, P, R> const & b
	)
	{
		return a.get_pointer() - b.get_pointer();
	}

	// -------------------------------------------------------------------------

}


// ============================================================================

#endif /* FT_VECTOR_HPP */
