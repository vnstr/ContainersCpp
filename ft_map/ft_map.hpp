//
// Created by Gueren Drive on 3/25/21.
//

#ifndef CONTAINERS_CPP_FT_MAP_HPP
#define CONTAINERS_CPP_FT_MAP_HPP

// ========================== OTHER INCLUDES ===================================

# include "../ft_multiset/ft_multiset.hpp"
# include "ft_map_bidir_iterator.hpp"

// =============================================================================

namespace ft {

// ================================ MAP ========================================

	template
	< class Key,                                       // map::key_type
	  class T,                                         // map::mapped_type
//	  class Compare = ft::Less<Key>,                   // map::key_compare
	  class Compare = ft::KeyComp<Key, T>,
	  class Alloc = std::allocator<std::pair<const Key,T> > // map::allocator_type
	>
	class Map {

	public:

		// Typedef -------------------------------------------------------------

		typedef Key                                             key_type;
		typedef T                                               mapped_type;
		typedef std::pair<const key_type, mapped_type>          value_type;
		typedef Compare                                         key_compare;
		typedef Alloc                                           allocator_type;

		typedef typename allocator_type::reference              reference;
		typedef typename allocator_type::const_reference        const_reference;
		typedef typename allocator_type::pointer                pointer;
		typedef typename allocator_type::const_pointer          const_pointer;

		typedef ft::MapBidirIterator
		        <
		         ft::MultisetBidirIterator
		                <
		                 ft::RandomAccessIterator
		                        <
		                         value_type, value_type*, value_type&
		                        >
		                >
		        >                                               iterator;

		typedef ft::MapBidirIterator
		        <
		         ft::MultisetBidirIterator
		                 <
		                  ft::RandomAccessIterator
		                          <
		                           value_type,
		                           const value_type*,
		                           const value_type&
		                          >
		                 >
		         >                                              const_iterator;


//		typedef ft::MultisetBidirIterator
//				<ft::RandomAccessIterator<T, const T*, const T&> >
//				const_iterator;
//
		typedef typename ft::MapBidirIterator
		<
		 ft::MultisetBidirIterator
		         <
		          ft::RandomAccessIterator
		                  <
		                   value_type, value_type*, value_type&
		                  >
		         >
		 >::difference_type                                     difference_type;

		typedef size_t                                          size_type;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit Map
		(
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type()
		)
		: values_(), comp_(comp), alloc_(alloc)
		{}

		template <class InputIterator>
		Map
		(
		 InputIterator first,
		 InputIterator last,
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type()
		)
		: values_(), comp_(comp), alloc_(alloc)
		{
			this->insert(first, last);
		}

		Map
		(
		 const Map & x
		)
		: values_(x.values_), comp_(x.comp_), alloc_(x.alloc_)
		{}

		// ---------------------------------------------------------------------

		// Operators -------------------------------------------------------

		// '='
		Map &         operator=(const Map & x) {
			if (this == &x) {
				return *this;
			}
			values_ = x.values_;
			alloc_  = x.alloc_;
			comp_   = x.comp_;
			return *this;
		}

		mapped_type & operator[] (const key_type & k) {
			iterator position
			(
			 values_.find(std::pair<key_type, mapped_type>(k, 0))
			);

			return (*position).second;
		}

		// ---------------------------------------------------------------------

		// Element access ------------------------------------------------------

		mapped_type & at (const key_type & k) {
			if (values_.size() == 0) {
				throw OutOfRange();
			}

			iterator position
			(
			 values_.find(std::pair<key_type, mapped_type>(k, 0))
			);
			if (position == this->end()) {
				throw OutOfRange();
			}
			return (*position).second;
		}

		// ---------------------------------------------------------------------

		// Iterators -----------------------------------------------------------

		iterator       begin() {
			return iterator(values_.begin());
		}

		const_iterator begin() const {
			return const_iterator(values_.begin());
		}

		iterator       end() {
			return iterator(values_.end());
		}

		const_iterator end() const {
			return const_iterator(values_.end());
		}

		//TODO ReverseIterator

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

		std::pair<iterator, bool> insert (const value_type & val) {
			if (values_.size() == 0) {
				return
				(
				 std::pair<iterator, bool>(iterator(values_.insert(val)), true)
				);
			}

			iterator position(values_.find(val));

			if (position == end()) {
				return
				(
				 std::pair<iterator, bool>(iterator(values_.insert(val)), true)
				);
			}
			return std::pair<iterator, bool>(position, false);
		}

		iterator insert (iterator position, const value_type& val) {
			(void)(position);
			if (values_.size() == 0) {
				return iterator(values_.insert(val));
			}

			iterator pos(values_.find(val));

			if (pos == end()) {
				return iterator(values_.insert(val));
			}
			return pos;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while (first != last) {
				if (values_.size() == 0) {
					this->insert(*first);
					++first;
					continue ;
				}
				this->insert(*first);
				++first;
			}
		}

		void erase (iterator position) {
			if (this->size() == 0) {
				return ;
			}
			values_.erase(position.base());
		}

		size_type erase (const key_type & k) {
			if (this->size() == 0) {
				return 0;
			}

			iterator  found(values_.find(value_type(k, T())));
			size_type i = 0;

			while (found != this->end()) {
				erase(found);
				found = iterator(values_.find(value_type(k, T())));
				++i;
			}
			return i;
		}

		// ---------------------------------------------------------------------

		// Exceptions ----------------------------------------------------------

		class OutOfRange : public std::exception {
		public:
			const char*  what() const throw() {
				return "map::at:  key not found";
			}
		};
		// ---------------------------------------------------------------------

//	private:
//		template <class K, class V>
//		class KeyComp {
//		public:
//			KeyComp() {}
//			KeyComp(const KeyComp & x) {(void)(x);}
//			~KeyComp() {}
//			KeyComp & operator=(const KeyComp & x) {(void)(x);}
//
//			bool operator()
//			(
//			 const std::pair<const K, const V> & a,
//			 const std::pair<const K, const V> & b
//			) const
//			{
//				return a.first < b.first;
//			}
//		};

	private:
		Multiset
		<
		 value_type,
		 Compare,
		 Alloc
		>                                                            values_;

		key_compare                                                  comp_;
		Alloc                                                        alloc_;

	};

// =============================================================================

}

// ============================ END NAMESPACE FT ===============================

#endif //CONTAINERS_CPP_FT_MAP_HPP
