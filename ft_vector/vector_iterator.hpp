
template <class TYPE>
struct vector_iterator {

	typedef ptrdiff_t                       difference_type;
	typedef TYPE                            value_type;
	typedef TYPE*                           pointer;
	typedef TYPE&                           reference;
	typedef std::random_access_iterator_tag iterator_category;
};

template <class TYPE>
struct const_vector_iterator {

	typedef ptrdiff_t                       difference_type;
	typedef TYPE                            value_type;
	typedef const TYPE*                     pointer;
	typedef const TYPE&                     reference;
	typedef std::random_access_iterator_tag iterator_category;
};
