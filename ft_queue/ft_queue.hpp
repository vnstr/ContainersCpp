#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP

// Notes:
// - add class Container = List<t>;

// ============================ STD-LIBS =======================================

# include <cstddef>   // size_t, ptrdiff_t ...

// =============================================================================

// ========================== OTHER INCLUDES ===================================

# include "../ft_vector/ft_vector.hpp"

// =============================================================================


// ============================ NAMESPACE FT ===================================

namespace ft {

// =============================== QUEUE =======================================

	// template <class T, class Container = Vector<T> >
	template <class T, class Container >
	class Queue {

	public:

		// Typedef -------------------------------------------------------------

		typedef T         value_type;
		typedef Container container_type;
		typedef size_t    size_type;

		// ---------------------------------------------------------------------

		// Constructor - Destructor --------------------------------------------

		explicit queue(const container_type & ctnr = container_type())
		: c_(ctnr) {}

		// ---------------------------------------------------------------------

		// Member functions ----------------------------------------------------

		bool               empty() const {

			return this->c_.empty();
		}

		size_type          size() const {

			return this->c_.size();
		}

		value_type &       front() {

			return this->c_.front();
		}

		const value_type & front() const {

			return this->c_.front();
		}

		value_type &       back() {

			return this->back();
		}

		const value_type & back() const {

			return this->back();
		}

		void               push (const value_type & val) {

			return this->push_back(val);
		}

		void               pop() {

			return this->c_.pop_front();
		}

		// ---------------------------------------------------------------------

		// Getters -------------------------------------------------------------

		container_type get_container() {

			return this->c_;
		}

		// ---------------------------------------------------------------------

	private:

		container_type c_;
	};

// =============================================================================

// Relational operators ========================================================

template <class T, class Container>
bool operator==(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() == rhs.get_container();
}

template <class T, class Container>
bool operator!=(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() != rhs.get_container();
}

template <class T, class Container>
bool operator<(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() < rhs.get_container();
}

template <class T, class Container>
bool operator<=(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() <= rhs.get_container();
}

template <class T, class Container>
bool operator>(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() > rhs.get_container();
}

template <class T, class Container>
bool operator>=(const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

	return lhs.get_container() >= rhs.get_container();
}

// =============================================================================

}

// ============================ END NAMESPACE FT ===============================

#endif /* FT_VECTOR_HPP */
