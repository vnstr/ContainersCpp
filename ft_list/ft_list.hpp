#ifndef FT_LIST_HPP
# define FT_LIST_HPP

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t

// =============================================================================

// ========================== OTHER INCLUDES ===================================

# include "ft_bidirectional_iterator.hpp"

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

// =============================== LIST ========================================

	template < class T, class Alloc = std::allocator<T> >
	class List {

	private:

		// ======================= Node ========================================

		struct Node {
			T     data;
			Node* next;
			Node* prev;
			};

			// -----------------------------------------------------------------

		// =====================================================================

	public:

		// Typedef -------------------------------------------------------------

		typedef T                                               value_type;
		typedef Alloc                                           allocator_type;
		typedef typename allocator_type::reference              reference;
		typedef typename allocator_type::const_reference        const_reference;
		typedef typename allocator_type::pointer                pointer;
		typedef typename allocator_type::const_pointer          const_pointer;

		typedef ft::BidirectionalIterator<T, T*, T&, Node>      iterator;

		typedef ft::BidirectionalIterator<T, const T*, const T&, Node>
																const_iterator;

		// typedef ft::ReverseIterator<iterator>                  reverse_iterator;
		// typedef ft::ReverseIterator<const_iterator>      const_reverse_iterator;

		// typedef typename
		// ft::BidirectionalIterator<T, T*, T&, Node>::difference_type
		//                                                         difference_type;

		typedef size_t                                          size_type;


		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit List(const allocator_type& alloc = allocator_type())
		: size_(0), alloc_(alloc) {
			this->end_node_ = allocate_node();
		}

		explicit List
		(
		 size_type n,
		 const value_type& val = value_type(),
		 const allocator_type& alloc = allocator_type()
		)
		: size_(0), alloc_(alloc) {
			this->end_node_ = allocate_node();
			for (size_type i = 0; i < n; ++i) {
				this->push_back(val);
			}
		}

		template <class InputIterator>
		List
		(
		 InputIterator first,
		 InputIterator last,
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0,
		 const allocator_type& alloc = allocator_type()
		) : size_(0), alloc_(alloc) {
			this->end_node_ = allocate_node();
			while (first != last) {
				this->push_back(*first);
				++first;
			}
		}

		List (const List & x) : size_(0), alloc_(x.alloc_) {
			this->end_node_ = allocate_node();
			for (const_iterator it(x.begin()); it != x.end(); ++it) {
				this->push_back(*it);
			}
		}

		virtual ~List() {
			while (this->size_ > 0) {
				this->pop_back();
			}
			deallocate_node(this->end_node_);
		}

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

		iterator       begin() {
			return iterator(this->end_node_->next);
		}

		const_iterator begin() const {
			return const_iterator(this->end_node_->next);
		}

		iterator       end() {
			return iterator(this->end_node_);
		}

		const_iterator end() const {
			return const_iterator(this->end_node_);
		}

		// ---------------------------------------------------------------------

		// Capacity ------------------------------------------------------------

		bool empty() const {
			return this->size_ == 0;
		}

		size_type size() const {
			return this->size_;
		}

		size_type max_size() const {
			return this->alloc_.max_size();
		}

		// ---------------------------------------------------------------------

		// Modifiers -----------------------------------------------------------

		void push_back(value_type const & val) {
			Node* node;

			node                         = construct_node(val);
			node->next                   = this->end_node_;
			node->prev                   = this->end_node_->prev;
			this->end_node_->prev->next  = node;
			this->end_node_->prev        = node;
			++this->size_;
		}

		void pop_back() {
			Node* tmp;

			tmp = this->end_node_->prev->prev;
			destroy_node(this->end_node_->prev);
			--this->size_;
			this->end_node_->prev = tmp;
		}

		// ---------------------------------------------------------------------

	// private:

		Node*                end_node_;
		size_type            size_;
		allocator_type       alloc_;
		std::allocator<Node> node_alloc_;

		typedef Node                                            node_type;

	protected:
		Node* allocate_node() {
			Node* node;

			node = this->node_alloc_.allocate(1);
			node->next = node;
			node->prev = node;
			return node;
		}

		Node* construct_node(value_type val) {
			Node* node;

			node = allocate_node();
			this->alloc_.construct(&node->data, val);
			return node;
		}

		void  deallocate_node(Node* node) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			this->node_alloc_.deallocate(node, 1);
		}

		void   destroy_node(Node* node) {
			this->alloc_.destroy(&node->data);
			deallocate_node(node);
		}

	};

// =============================================================================

};

// =============================================================================

#endif /* FT_LIST_HPP */
