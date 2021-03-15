#ifndef FT_LIST_HPP
# define FT_LIST_HPP

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t

// =============================================================================

// ========================== OTHER INCLUDES ===================================

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// =============================== LIST ========================================

	template < class T, class Alloc = std::allocator<T> >
	class List {

	public:

		// Typedef -------------------------------------------------------------

		typedef T                                               value_type;
		typedef Alloc                                           allocator_type;
		typedef typename allocator_type::reference              reference;
		typedef typename allocator_type::const_reference        const_reference;
		typedef typename allocator_type::pointer                pointer;
		typedef typename allocator_type::const_pointer          const_pointer;

		// typedef ft::RandomAccessIterator<T, T*, T& >            iterator;
		// typedef ft::RandomAccessIterator<T, const T*, const T&> const_iterator;

		// typedef ft::ReverseIterator<iterator>                  reverse_iterator;
		// typedef ft::ReverseIterator<const_iterator>      const_reverse_iterator;

		// typedef typename RandomAccessIterator<T, T*, T&>::difference_type
        //                                                         difference_type;

		typedef size_t                                          size_type;


		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit List(const allocator_type& alloc = allocator_type())
		: size_(0), alloc_(alloc) {
			this->end_node_ = new_node();
		}

		explicit List
		(
		 size_type n,
		 const value_type& val = value_type(),
		 const allocator_type& alloc = allocator_type()
		)
		: size_(0), alloc_(alloc) {
			this->end_node_ = new_node();
			for (size_type i = 0; i < n; ++i) {
				this->push_back(val);
			}
		}

		// template <class InputIterator>
		// list
		// (
		//  InputIterator first,
		//  InputIterator last,
		//  const allocator_type& alloc = allocator_type()
		// );

		// list (const list& x);

		virtual ~List() {
			while (this->size_ != 0) {
				this->pop_back();
			}
			delete_node(this->end_node_);
		}

		// ---------------------------------------------------------------------

		// Modifiers -----------------------------------------------------------

		void push_back(value_type const & val) {
			Node* node;

			node                          = new_node(val);
			node->next_                   = this->end_node_;
			node->prev_                   = this->end_node_->prev_;
			this->end_node_->prev_->next_ = node;
			this->end_node_->prev_        = node;
			++this->size_;
		}

		void pop_back() {
			Node* tmp;

			tmp = this->end_node_->prev_->prev_;
			delete_node(this->end_node_->prev_);
			--this->size_;
			this->end_node_->prev_ = tmp;
		}

		// ---------------------------------------------------------------------

	// private:
		class Node {

		public:
			T     data_;
			Node* next_;
			Node* prev_;

			// Constructor - Destructor ----------------------------------------

			explicit Node(T const & val = 0)
			: data_(val), next_(this), prev_(this) {}

			Node(Node const & x)
			: data_(x.date_), next_(x.next_), prev_(x.prev_) {}

			virtual ~Node() {
				this->data_ = 0;
				this->next_ = 0;
				this->prev_ = 0;
			}

			// -----------------------------------------------------------------

			// Operators -------------------------------------------------------

			Node & operator=(Node const & x) {
				if (this == &x)
					return *this;
				this->data_ = x.data_;
				this->next_ = x.next_;
				this->prev_ = x.prev_;
				return *this;
			}

			// -----------------------------------------------------------------
		};

		Node*                end_node_;
		size_type            size_;
		allocator_type       alloc_;
		std::allocator<Node> node_alloc_;

		typedef Node                                            node_type;

	protected:
		Node* new_node(value_type const & val = 0) {
			Node* node;

			node = this->node_alloc_.allocate(1);
			this->node_alloc_.construct(node, val);
			return node;
		}

		void   delete_node(Node* node) {
			this->node_alloc_.destroy(node);
			this->node_alloc_.deallocate(node, 1);
		}

	};

// =============================================================================

};

// =============================================================================

#endif /* FT_LIST_HPP */
