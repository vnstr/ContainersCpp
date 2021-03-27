//
// Created by Gueren Drive on 3/25/21.
//

#ifndef CONTAINERS_CPP_FT_MAP_BIDIR_ITERATOR_HPP
#define CONTAINERS_CPP_FT_MAP_BIDIR_ITERATOR_HPP

// ============================ NAMESPACE FT ===================================

namespace ft {

// ======================== BIDIRECTIONAL ITERATOR =============================

	template <class Iterator>
	class MapBidirIterator {

	public:

		// Typedef -------------------------------------------------------------

		typedef Iterator                             iterator_type;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
		typedef typename Iterator::difference_type   difference_type;
		typedef std::bidirectional_iterator_tag      iterator_category;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		MapBidirIterator() : it_() {}
		explicit MapBidirIterator(iterator_type it) : it_(it) {}

		template <class Iter>
		MapBidirIterator(const MapBidirIterator<Iter> & it)
		: it_(it.base())
		{}

		virtual ~MapBidirIterator() {}

		// ---------------------------------------------------------------------

		// Getters -------------------------------------------------------------

		iterator_type base() const {
			return it_;
		}

		// ---------------------------------------------------------------------

		// Operators -----------------------------------------------------------

		// '='
		MapBidirIterator & operator=(MapBidirIterator const & x) {

			if (this == &x) {
				return *this;
			}
			this->it_ = x.it_;
			return *this;
		}

		// '=='
		bool                  operator==
		(
				MapBidirIterator const & x
		) const
		{
			return this->it_ == x.it_;
		}

		// '!='
		bool                  operator!=
		(
				MapBidirIterator const & x
		) const
		{
			return this->it_ != x.it_;
		}

		// '*'
		reference             operator*() {
			return *this->it_;
		}

		// '->'
		pointer               operator->() {
			return this->it_.base().get_pointer();
		}

		// '++iter'
		MapBidirIterator   operator++() {
			++this->it_;
			return (*this);
		}

		// 'iter++'
		MapBidirIterator   operator++(int) {
			MapBidirIterator tmp(*this);
			++this->it_;
			return (tmp);
		}

		// '--iter'
		MapBidirIterator   operator--() {
			--this->it_;
			return (*this);
		}

		// 'iter--'
		MapBidirIterator   operator--(int) {
			MapBidirIterator tmp(*this);
			--this->it_;
			return (tmp);
		}

		// ---------------------------------------------------------------------

	private:
		iterator_type it_;
	};

}

// ============================ END NAMESPACE FT ===============================

#endif //CONTAINERS_CPP_FT_MAP_BIDIR_ITERATOR_HPP
