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

	private:

		pointer arr_;

	};
}

// ============================================================================

#endif /* FT_VECTOR_HPP */
