#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// ======================== BIDIRECTIONAL IERATOR ==============================

	template <class T, class P, class R>
	class BidirectionalIterator {

	public:

		// Typedef -------------------------------------------------------------

		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef P                               pointer;
		typedef R                               reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		// ---------------------------------------------------------------------

		BidirectionalIterator()

	private:

	};

// =============================================================================

};

// =============================================================================

#endif /* BIDIRECTIONAL_ITERATOR_HPP */
