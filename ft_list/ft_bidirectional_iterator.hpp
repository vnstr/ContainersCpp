#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// ======================== BIDIRECTIONAL IERATOR ==============================

	template <class T, class P, class R, class Node>
	class BidirectionalIterator {

	public:

		// Typedef -------------------------------------------------------------

		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef P                               pointer;
		typedef R                               reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		BidirectionalIterator(Node* node = 0) : node_(node) {};

		BidirectionalIterator
		(
		 const BidirectionalIterator<T, T*, T&, Node> & x
		)
		: node_(x.node_) {};

		virtual ~BidirectionalIterator(){};

		// ---------------------------------------------------------------------

		// Operatorsor ---------------------------------------------------------

		// '='
		BidirectionalIterator & operator=(const BidirectionalIterator & x) {
			if (this == &x)
				return *this;
			this->node_ = x.node_;
			return *this;
		}

		// '=='
		bool                    operator==(const BidirectionalIterator & x) {
			return this->node_ == x.node_;
		}

		// '!='
		bool                    operator!=(const BidirectionalIterator & x) {
			return this->node_ != x.node_;
		}

		// '*'
		reference               operator*() {
			return this->node_->data;
		}

		// '->'
		pointer                 operator->() {
			return &this->node_->data;
		}

		// '++iter'
		BidirectionalIterator   operator++() {
			this->node_ = this->node_->next;
			return (*this);
		}

		// 'iter++'
		BidirectionalIterator   operator++(int) {
			BidirectionalIterator tmp(*this);
			this->node_ = this->node_->next;
			return (tmp);
		}

		// '--iter'
		BidirectionalIterator   operator--() {

			this->node_ = this->node_->prev;
			return (*this);
		}

		// 'iter--'
		BidirectionalIterator   operator--(int) {

			BidirectionalIterator tmp(*this);
			this->node_ = this->node_->prev;
			return (tmp);
		}

		// ---------------------------------------------------------------------

	private:
		Node* node_;

	};

// =============================================================================

};

// =============================================================================

#endif /* FT_BIDIRECTIONAL_ITERATOR_HPP */
