


// TODO
// 1) ReverseIterator;



#ifndef FT_LIST_HPP
# define FT_LIST_HPP

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t
# include <algorithm> // std::swap(); std::equal(); std::rotate();

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
		 const allocator_type& alloc = allocator_type(),
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0
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

		// Element access ------------------------------------------------------

		reference       front() {
			return this->end_node_->next->data;
		}

		const_reference front() const {
			return this->end_node_->next->data;
		}

		reference       back() {
			return this->end_node_->prev->data;
		}

		const_reference back() const {
			return this->end_node_->prev->data;
		}

		// ---------------------------------------------------------------------

		// Modifiers -----------------------------------------------------------

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			List new_list(first, last, allocator_type());
			this->swap(new_list);
		}

		void assign (size_type n, const value_type & val) {
			List new_list(n, val, allocator_type());
			this->swap(new_list);
		}

		void push_front(const value_type & val) {
			Node* node;

			node                         = construct_node(val);
			node->next                   = this->end_node_->next;
			node->prev                   = this->end_node_;
			this->end_node_->next->prev  = node;
			this->end_node_->next        = node;
			++this->size_;
		}

		void pop_front() {
			Node* tmp;

			tmp = this->end_node_->next->next;
			destroy_node(this->end_node_->next);
			this->end_node_->next = tmp;
			--this->size_;
		}

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
			this->end_node_->prev = tmp;
			--this->size_;
		}

		iterator insert(iterator position, const value_type & val) {
			Node* new_node;

			new_node                        = construct_node(val);
			new_node->next                  = position.get_node();
			new_node->prev                  = position.get_node()->prev;
			position.get_node()->prev->next = new_node;
			position.get_node()->prev       = new_node;
			++this->size_;
			return iterator(new_node);
		}

		void insert(iterator position, size_type n, const value_type & val) {
			for (size_type i = 0; i < n; ++i) {
				position = insert(position, val);
			}
		}

		template <class InputIterator>
		void insert
		(
		 iterator position,
		 InputIterator first,
		 InputIterator last,
		 typename enable_if
		 < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0
		) {
			while (first != last) {
				position = insert(position, *first);
				++position;
				++first;
			}
		}

		iterator erase(iterator position) {
			Node* next;

			next = position.get_node()->next;
			destroy_node(position.get_node());
			--this->size_;
			return iterator(next);
		}

		iterator erase (iterator first, iterator last) {
			iterator current;
			while (first != last) {
				current = first;
				++first;
				destroy_node(current.get_node());
				--this->size_;
			}
			return last;
		}

		void     swap(List & x) {
			std::swap(this->end_node_, x.end_node_);
			std::swap(this->size_, x.size_);
			std::swap(this->alloc_, x.alloc_);
			std::swap(this->node_alloc_, x.node_alloc_);
		}

		void resize(size_type n, value_type val = value_type()) {
			for (size_type i = n; i < this->size_; ++i) {
				this->push_back(val);
			}
			for (size_type i = n; i > this->size_; --i) {
				this->pop_back();
			}
		}

		void clear() {
			while (this->size_ > 0) {
				pop_back();
			}
		}

		// ---------------------------------------------------------------------

		// Operations ----------------------------------------------------------

		void merge(List & x) {
			if (this == &x) {
				return ;
			}

			iterator this_begin;
			iterator x_begin;

			this_begin = this->begin();
			x_begin    = x.begin();

			while (this_begin != this->end() && x_begin != x.end()) {
				if (*this_begin > *x_begin) {
					++x_begin;
					put(this_begin, x_begin.get_node()->prev);
				} else {
					++this_begin;
				}
			}
			while (x_begin != x.end()) {
				++x_begin;
				put(this_begin, x_begin.get_node()->prev);
			}
			this->size_      += x.size_;
			x.size_           = 0;
			x.end_node_->next = x.end_node_;
			x.end_node_->prev = x.end_node_;
		}

		template <class Compare>
		void merge (List & x, Compare comp) {
			if (this == &x) {
				return ;
			}

			iterator this_begin;
			iterator x_begin;

			this_begin = this->begin();
			x_begin    = x.begin();

			while (this_begin != this->end() && x_begin != x.end()) {
				if (!comp(*this_begin, *x_begin)) {
					++x_begin;
					put(this_begin, x_begin.get_node()->prev);
				} else {
					++this_begin;
				}
			}
			while (x_begin != x.end()) {
				++x_begin;
				put(this_begin, x_begin.get_node()->prev);
			}
			this->size_      += x.size_;
			x.size_           = 0;
			x.end_node_->next = x.end_node_;
			x.end_node_->prev = x.end_node_;
		}

		void sort() {
			merge_sort(this->begin(), this->end());
		}

		// ---------------------------------------------------------------------

	private:

		Node*                end_node_;
		size_type            size_;
		allocator_type       alloc_;
		std::allocator<Node> node_alloc_;

	protected:
		iterator half_split(iterator first, iterator last) {
			iterator slow;
			iterator fast;

			slow = first;
			fast = first;

			while
			(
			 fast.get_node()->next != last.get_node() &&
			 fast.get_node()->next->next != last.get_node()
			) {
				++slow;
				++fast;
				++fast;
			}
			return (++slow);
		}

		iterator merge_by_it
		(
		 iterator first1,
		 iterator last1,
		 iterator first2,
		 iterator last2
		) {
			Node*    node1;
			Node*    node2;
			iterator ret(first1);

			while (first2 != last2) {
				if (*first2 < *first1) {
					if (ret == first1) {
						ret = first2;
					}
					node1 = first1.get_node();
					node2 = first2.get_node();
					node2->next->prev = node2->prev;
					node2->prev->next = node2->next;
					node1->prev->next = node2;
					node2->prev = node1->prev;
					node1->prev = node2;
					node2->next = node1;
					if (first2++ == last1) {
						last1 = first2;
					}
				} else if (first1 != last1) {
					++first1;
				} else {
					++first2;
				}
			}
			return ret;
}

		iterator merge_sort(iterator first, iterator last) {
			iterator half;

			half = half_split(first, last);

			if (half == last)
				return first;

			first = merge_sort(first, half);
			half  = merge_sort(half, last);
			first = merge_by_it(first, half, half, last);
			return first;
		}

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

		void   put(iterator position, Node* node) {
			node->prev                      = position.get_node()->prev;
			node->next                      = position.get_node();
			position.get_node()->prev->next = node;
			position.get_node()->prev       = node;
		}

	};

// =============================================================================

}

// =============================================================================

#endif /* FT_LIST_HPP */
