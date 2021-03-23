//
// Created by Gueren Drive on 3/23/21.
//

#ifndef CONTAINERS_CPP_FT_MULTISET_HPP
#define CONTAINERS_CPP_FT_MULTISET_HPP

// ========================== OTHER INCLUDES ===================================

#include "../ft_vector/ft_vector.hpp"

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// ============================= MULTISET ======================================

	template <
	        class T,                      // multiset::key_type/value_type
	        class Compare = std::less<T>,      // multiset::key_compare/value_compare
	        class Alloc = std::allocator<T> >  // multiset::allocator_type
	class Multiset {

	public:

		// Typedef -------------------------------------------------------------

		typedef T                                               key_type;
		typedef T                                               value_type;
		typedef Compare                                         key_compare;
		typedef Compare                                         value_compare;
		typedef Alloc                                           allocator_type;
		typedef typename allocator_type::reference              reference;
		typedef typename allocator_type::const_reference        const_reference;
		typedef typename allocator_type::pointer                pointer;
		typedef typename allocator_type::const_pointer          const_pointer;

		// iterators ...


//		typedef typename RandomAccessIterator<T, T*, T&>::difference_type
//				difference_type;

		typedef size_t                                          size_type;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit Multiset
		(
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type()
		)
		: values_(), comp_(comp), alloc_(alloc)
		{}

//		template <class InputIterator>
//		Multiset
//		(
//		 InputIterator first,
//		 InputIterator last,
//		 const key_compare& comp = key_compare(),
//		 const allocator_type& alloc = allocator_type()
//		)
//		{}

		Multiset (const Multiset & x)
		: values_(x.values_), alloc_(x.alloc_), comp_(x.comp_)
		{}

		~Multiset() {
			this->values_.~Vector();
		}

		// ---------------------------------------------------------------------

		// Operator '=' --------------------------------------------------------

		Multiset & operator=(const Multiset & x) {
			this->values_ = x.values_;
			this->alloc_  = x.alloc_;
			this->comp_   = x.comp_;
		}

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

//		iterator               begin() {
//			return iterator(this->arr_);
//		}
//
//		const_iterator         begin() const {
//			return const_iterator(this->arr_);
//		}
//
//		iterator               end() {
//			return iterator(this->arr_ + this->size_);
//		}
//
//		const_iterator         end() const {
//			return const_iterator(this->arr_ + this->size_);
//		}
//
//		reverse_iterator       rbegin() {
//			if (this->size_ == 0) {
//				return reverse_iterator(iterator(this->arr_));
//			} else {
//				return reverse_iterator(iterator(this->arr_ + this->size_ - 1));
//			}
//		}
//
//		const_reverse_iterator rbegin() const {
//			if (this->size_ == 0) {
//				return iterator(this->arr_);
//			} else {
//				return iterator(this->arr_ + this->size_ - 1);
//			}
//		}
//
//		reverse_iterator       rend() {
//			if (this->size_ == 0) {
//				return reverse_iterator(iterator(this->arr_));
//			} else {
//				return reverse_iterator(iterator(this->arr_ - 1));
//			}
//		}
//
//		reverse_iterator       rend() const {
//			if (this->size_ == 0) {
//				return reverse_iterator(iterator(this->arr_));
//			} else {
//				return reverse_iterator(iterator(this->arr_ - 1));
//			}
//		}

		// ---------------------------------------------------------------------

	private:

		Vector<T, Alloc> values_;
		Alloc            alloc_;
		key_compare      comp_;

	};


// =============================================================================

}

// ============================ END NAMESPACE FT ===============================

#endif //CONTAINERS_CPP_FT_MULTISET_HPP
