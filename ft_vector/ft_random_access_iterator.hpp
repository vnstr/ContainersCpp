#ifndef FT_RANDOM_ACCESS_ITERATOR
# define FT_RANDOM_ACCESS_ITERATOR

// ========================== OTHER INCLUDES ===================================

# include "ft_iterator_traits.hpp"

// =============================================================================

// ===================== RADOM ACCESS ITERATOR =================================

namespace ft {

	template < class It >
	class RandomAccessIterator {

	public:

		// Typedef -------------------------------------------------------------

		typedef typename ft::iterator_traits<It>::difference_type
                                                              difference_type;

		typedef typename ft::iterator_traits<It>::value_type  value_type;
		typedef typename ft::iterator_traits<It>::pointer     pointer;
		typedef typename ft::iterator_traits<It>::reference   reference;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit RandomAccessIterator() : arr_(0) {}
		explicit RandomAccessIterator(pointer arr) : arr_(arr) {}

		RandomAccessIterator(RandomAccessIterator const & x)
			: arr_(x.arr_) {}

		virtual ~RandomAccessIterator() {}

		// ---------------------------------------------------------------------

		// Operators -----------------------------------------------------------

		// '='
		RandomAccessIterator operator=(RandomAccessIterator const & x) {

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
		RandomAccessIterator operator-=(difference_type n) {

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

		// Operators -----------------------------------------------------------

		pointer get_pointer() const {

			return this->arr_;
		}

		// ---------------------------------------------------------------------

	private:

		pointer arr_;

	};

	// Operators ---------------------------------------------------------------

	// 'n + iter'
	template <class It>
	RandomAccessIterator<It> operator+
	(
	 typename RandomAccessIterator<It>::difference_type n,
	 RandomAccessIterator<It> const & x
	)
	{
		return x + n;
	}

	// 'iter + iter'
	template <class It>
	typename RandomAccessIterator<It>::difference_type operator-
	(
	 RandomAccessIterator<It> const & a,
	 RandomAccessIterator<It> const & b
	)
	{
		return a.get_pointer() - b.get_pointer();
	}

	// -------------------------------------------------------------------------

}


// ============================================================================

#endif /* FT_VECTOR_HPP */
