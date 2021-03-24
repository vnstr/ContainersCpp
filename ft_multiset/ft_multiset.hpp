//
// Created by Gueren Drive on 3/23/21.
//

// TODO ReverseIterator
// TODO binary_search() refactoring

#ifndef CONTAINERS_CPP_FT_MULTISET_HPP
#define CONTAINERS_CPP_FT_MULTISET_HPP

// ========================== OTHER INCLUDES ===================================

# include "../ft_vector/ft_vector.hpp"

# include "ft_multiset_bidir_iterator.hpp"

// =============================================================================

// ============================ NAMESPACE FT ===================================

namespace ft {

// ============================= MULTISET ======================================

	template <
	        class T,                           // multiset::key_type/value_type
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

		typedef ft::MultisetBidirIterator
		        <ft::RandomAccessIterator<T, T*, T&> >
		                                                        iterator;

		typedef ft::MultisetBidirIterator
		        <ft::RandomAccessIterator<T, const T*, const T&> >
		                                                        const_iterator;

		typedef typename
		ft::MultisetBidirIterator
		        <ft::RandomAccessIterator<T, T*, T&> >::difference_type
		                                                        difference_type;

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

		template <class InputIterator>
		Multiset
		(
		 InputIterator first,
		 InputIterator last,
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type()
		)
		: comp_(comp), alloc_(alloc)
		{
			while(first != last) {
				insert(*first);
				++first;
			}
		}

		Multiset (const Multiset & x)
		: values_(x.values_), comp_(x.comp_), alloc_(x.alloc_)
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

		iterator               begin() {
			return iterator(this->values_.begin());
		}
//
		const_iterator         begin() const {
			return const_iterator(this->values_.begin());
		}

		iterator               end() {
			return iterator(this->values_.end());
		}

		const_iterator         end() const {
			return const_iterator(this->values_.end());
		}

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

		// Capacity ------------------------------------------------------------

		bool      empty() const {
			return values_.empty();
		}

		size_type size() const {
			return values_.size();
		}

		size_type max_size() const {
			return alloc_.max_size();
		}

		// ---------------------------------------------------------------------

		// Modifiers -----------------------------------------------------------

		iterator insert(const value_type & val) {
			if (values_.size() == 0) {
				return iterator(values_.insert(values_.begin(), val));
			}
			size_type pos_index;

			pos_index = binary_search(val, this->values_.size());
			return iterator(values_.insert(values_.begin() + pos_index + (val > values_[pos_index]), val));
		}

		// ---------------------------------------------------------------------

	private:

		Vector<T, Alloc> values_;
		key_compare      comp_;
		Alloc            alloc_;

	protected:
		iterator   find_position(const value_type & val) {
			return iterator(this->begin() + binary_search(val));
		}

		// Binary search -------------------------------------------------------

		size_type binary_search
		(
		 const value_type &val,
		 size_type size,
		 size_type start = 0
		)
		{
			if (size == 1) {
				return start;
			}

			size_type half = start + size / 2 + (size % 2);

			return (val < values_[half]) ?
			binary_search(val, half - start, start)
			: binary_search(val, start + size - half, half);
		}

		// ---------------------------------------------------------------------
	};


// =============================================================================

}

// ============================ END NAMESPACE FT ===============================

#endif //CONTAINERS_CPP_FT_MULTISET_HPP
