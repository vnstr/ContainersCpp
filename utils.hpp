#ifndef CONTAINERS_CPP_UTILS_HPP
#define CONTAINERS_CPP_UTILS_HPP

# include <type_traits>

namespace ft {
	template<class T>
	void swap(T &a, T &b) {
		T tmp(a);

		a = b;
		b = tmp;
	}

	template<class T>
	class Less {

	public:
			Less() {};
			Less(const Less & x) {(void)(x);}
			~Less() {};

			Less & operator=(const Less & x) {(void)(x); return *this;}

			bool   operator()(const T & a, const T & b) const {
				return a < b;
			}
		};

//	template <class K, class V>
//	class KeyComp {
//	public:
//		KeyComp() {}
//		KeyComp(const KeyComp & x) {(void)(x);}
//		~KeyComp() {}
//		KeyComp & operator=(const KeyComp & x) {(void)(x);}
//
//		bool operator()(const std::pair<K, V> & a, const std::pair<K, V> & b) {
//			return a.first < b.first;
//		}
//	};
}

#endif //CONTAINERS_CPP_UTILS_HPP
