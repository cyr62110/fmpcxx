#ifndef COLLECTION_ITERATOR_H_
#define COLLECTION_ITERATOR_H_

#include <cstddef>

#include <fmrcxx/IteratorOperation.h>

namespace fmrcxx {

/**
 * \brief Class providing convenient method to iterate over a collection.
 */
template <typename T, typename It = std::nullptr_t>
class Iterator : public IteratorOperation<T, Iterator, Iterator<T, It>> {
public:
	/**
	 * \internal
	 * \brief Construct an iterator using one of its implementation
	 */
	Iterator(It&& iterator);

	/**
	 * \brief Iterator cannot be copied
	 */
	Iterator(Iterator& iterator) = delete;

	/**
	 * \brief Move constructor
	 */
	Iterator(Iterator&& iterator);

	/**
	 * \brief Return true if the iterator has a next element.
	 */
	bool fullyConsumed();

	/**
	 * \brief Return a reference to the next object on the collection we iterate over.
	 */
	T& next();

private:
	bool moved;
	It iterator;
};

}

#include <fmrcxx/impl/Iterator.hpp>

#endif