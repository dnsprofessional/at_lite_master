#ifndef UltraPlanner_helpers_h
#define UltraPlanner_helpers_h

#include "../config.h"

#include <vector>
#include <string>
#include <stdint.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
//#include <stxxl.h>

using namespace std;

ULTRA_CORE_API void string_split(std::vector<std::string> & result, const char * c_str, const char * c_separator);

// trim from start
ULTRA_CORE_API std::string &ltrim(std::string &s);

// trim from end
ULTRA_CORE_API std::string &rtrim(std::string &s);

// trim from both ends
ULTRA_CORE_API std::string trim(std::string s);

/*
Converts '<xxxxx>' to 'xxxxx'.
*/
ULTRA_CORE_API std::string removeBrackets(std::string str);

/*
Looks for object with given name through vector
of pointers.
*/
template<typename T> T * find_by_name(const std::vector<T*> & vec, const std::string _name)
{
	auto el_it = std::find_if(vec.begin(), vec.end(), [=](const T * el){return (el->name == _name);});
	if(el_it == vec.end())
		return nullptr;
	else
		return *el_it;
}

template<typename ObjectContainer>
ObjectContainer objects_from_indices(const std::vector<size_t> & indices_array, const ObjectContainer & objects_array)
{
	ObjectContainer result;

	for(auto i : indices_array)
	{
		auto obj_it = objects_array.begin();
		std::advance(obj_it, i);
		result.insert(result.end(), *obj_it);
	}

	return result;
}



namespace Serializing
{
	template<typename T>
	size_t serialize(void * dest, const T value)
	{
		const size_t s = sizeof(T);
		memcpy(dest, &value, s);
		return s;
	};

	ULTRA_CORE_API size_t serialize_uchar(char * dest, const unsigned char value);
	ULTRA_CORE_API size_t serialize_int(char * dest, const int value);
	ULTRA_CORE_API size_t deserialize_int(char * data, int & value);
};

class URatio
{
public:
	URatio(double num_ = 0.0, double denom_ = 1.0);
	double value() const;
	void add(double num_, double denom_);
private:
	double m_num, m_denom;
};

std::ostream & operator<<(std::ostream & os, const URatio & ratio);

template <class VecType>
float internal_memory_usage(const VecType & vec)
{
	//cout << "Memory usage is " << 1 << "MBs\n";
	double bytes = static_cast<double>(VecType::page_size) * static_cast<double>(VecType::block_size) * static_cast<double>(vec.numpages());
	return bytes / 1024 / 1024;
}

ULTRA_CORE_API double get_internal_memory_usage();

ULTRA_CORE_API void serialize_int(std::ofstream & fout, int32_t value);
ULTRA_CORE_API int32_t deserialize_int(std::ifstream & fin);

template<typename T>
void serialize_value(std::ofstream & fout, const T value)
{
	fout.write((char*)&value, sizeof(T));
}

template<typename T>
T deserialize_value(std::ifstream & fin)
{
	T value;
	fin.read((char*)&value, sizeof(T));
	return value;
}

template<class T>
void serialize_vector(std::ofstream & fout, const T & vec)
{
	//Size
	serialize_value<size_t>(fout, vec.size());

	//Data
	for(auto it = vec.begin(); it != vec.end(); ++it)
		serialize_value(fout, *it);
}
/*
#ifndef WIN32
template<typename C>
using Element_type = typename C::value_type;
#endif*/

template<class T>
T deserialize_vector(std::ifstream & fin)
{
	//Size
	size_t vec_size = deserialize_value<size_t>(fin);

	T vec;
	vec.resize(vec_size);

	//Data
	for(size_t i = 0; i < vec_size; ++i)
	{
//#ifdef WIN32
		vec[i] = deserialize_value<typename T::value_type>(fin);
/*#else
		vec[i] = deserialize_value<Element_type<T>>(fin);
#endif*/
	}

	return std::move(vec);
}

ULTRA_CORE_API void serialize_string(std::ofstream & fout, const std::string & str);
ULTRA_CORE_API std::string deserialize_string(std::ifstream & fout);


template<class T>
std::string to_string(const T & obj)
{
	std::stringstream ss;
	ss << obj;
	return ss.str();
}


template<typename T>
int element_index(vector<T> & data, const T & val)
{
	auto it = std::find(data.begin(), data.end(), val);
	if (it == data.end())
	{
		//throw runtime_error("Unable to find element in array");
		cout << "Unable to find element " << val << std::endl;
	}
	return std::distance(data.begin(), it);
}


ULTRA_CORE_API int integer_ceil(int x, int y);

ULTRA_CORE_API std::wstring to_wstring(const std::string & str);

template<typename T>
void resize_if_less(T & container, size_t expected_size)
{
	if (container.size() < expected_size)
		container.resize(expected_size);
}

template<typename It, typename Pred>
void sort_wrapper(It begin, It end, Pred pred)
{
	std::sort(begin, end, pred);
}

//True, if left radix is less
ULTRA_CORE_API std::pair<size_t, bool> different_radix(size_t lhs, size_t rhs);
ULTRA_CORE_API bool check_radix(size_t val, size_t radix_id);

ULTRA_CORE_API std::ostream & operator<<(std::ostream & os, const std::pair<unsigned char, unsigned char> & pair);

template<typename It>
void print_range(std::ostream & os, It first, It last, char delimeter)
{
	if (first == last)
		return;

	os << *first++;
	while (first != last)
		os << delimeter << *first++;
}

template<typename ValueT>
void loop_offset(/*bool inversed,*/ ValueT & ref1, ValueT & ref2, ValueT & ref3, ValueT & ref4)
{
	/*if (inversed)
	{
		ValueT last_val = ref1;
		ref1 = ref2;
		ref2 = ref3;
		ref3 = ref4;
		ref4 = last_val;
	}
	else
	{*/
		ValueT last_val = ref4;
		ref4 = ref3;
		ref3 = ref2;
		ref2 = ref1;
		ref1 = last_val;
	//}
}

template<typename C>
void loop_offset(C & container)
{
	auto last_val = *container.rbegin();
	for (int i = container.size() - 1; i > 0; --i)
		container[i] = container[i - 1];
	container[0] = last_val;
}

ULTRA_CORE_API int bits_for_representing(int max_value);

template<typename It, typename PIt>
void permutate(It first, It last, PIt permutation_first)
{
	std::vector<typename It::value_type> tmp(first, last);
	for (; first != last; ++first, ++permutation_first)
		*first = tmp[*permutation_first];
}

ULTRA_CORE_API struct point2
{
	point2(int _x, int _y)
	:x(_x), y(_y)
	{}

	friend bool operator==(const point2 & lhs, const point2 & rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
	}

	int x, y;
};

#endif
