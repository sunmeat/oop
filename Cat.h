#pragma once

#include <iostream>
#include <ostream>

using namespace std;

/**
 * \brief this is my class cat for animal description
 */
class cat
{
public:
	cat(const cat& other)
		: nick_(other.nick_),
		  lapki_(other.lapki_),
		  weight_(other.weight_)
	{
	}

	cat(cat&& other) noexcept
		: nick_(other.nick_),
		  lapki_(other.lapki_),
		  weight_(other.weight_)
	{
	}

	cat& operator=(const cat& other)
	{
		if (this == &other)
			return *this;
		nick_ = other.nick_;
		lapki_ = other.lapki_;
		weight_ = other.weight_;
		return *this;
	}

	cat& operator=(cat&& other) noexcept
	{
		if (this == &other)
			return *this;
		nick_ = other.nick_;
		lapki_ = other.lapki_;
		weight_ = other.weight_;
		return *this;
	}

private:
	char* nick_;

	friend bool operator<(const cat& lhs, const cat& rhs);

	friend bool operator<=(const cat& lhs, const cat& rhs);

	friend bool operator>(const cat& lhs, const cat& rhs);

	friend bool operator>=(const cat& lhs, const cat& rhs);

	friend std::ostream& operator<<(std::ostream& os, const cat& obj);


	int lapki_;
	double weight_;


	friend bool operator==(const cat& lhs, const cat& rhs);

	friend bool operator!=(const cat& lhs, const cat& rhs);

public:
	cat(char* nick, int lapki, double weight);

	char* get_nick() const;

	void set_nick(char* const nick);

	int get_lapki() const;

	void set_lapki(const int lapki);

	double get_weight() const;

	void set_weight(const double weight);
	::cat& operator=(int i);

	cat(char* nick, int lapki);

	/**
	 * \brief default ctor
	 */
	cat();

	// copy c-tor
	cat(cat& another);

	~cat();

	static void CopyTest();
};

inline bool operator<(const cat& lhs, const cat& rhs)
{
	if (lhs.nick_ < rhs.nick_)
		return true;
	if (rhs.nick_ < lhs.nick_)
		return false;
	if (lhs.lapki_ < rhs.lapki_)
		return true;
	if (rhs.lapki_ < lhs.lapki_)
		return false;
	return lhs.weight_ < rhs.weight_;
}

inline bool operator<=(const cat& lhs, const cat& rhs)
{
	return !(rhs < lhs);
}

inline bool operator>(const cat& lhs, const cat& rhs)
{
	return rhs < lhs;
}

inline bool operator>=(const cat& lhs, const cat& rhs)
{
	return !(lhs < rhs);
}

inline std::ostream& operator<<(std::ostream& os, const cat& obj)
{
	
		os << "nick_: " << obj.nick_
		<< " lapki_: " << obj.lapki_
		<< " weight_: " << obj.weight_;

		return os;
}

inline bool operator==(const cat& lhs, const cat& rhs)
{
	return lhs.nick_ == rhs.nick_
		&& lhs.lapki_ == rhs.lapki_
		&& lhs.weight_ == rhs.weight_;
}

inline bool operator!=(const cat& lhs, const cat& rhs)
{
	return !(lhs == rhs);
}

inline cat::cat(char* nick, int lapki, double weight): nick_(nick),
                                                       lapki_(lapki),
                                                       weight_(weight)
{
}

inline char* cat::get_nick() const
{
	return nick_;
}

inline void cat::set_nick(char* const nick)
{
	nick_ = nick;
}

inline int cat::get_lapki() const
{
	return lapki_;
}

inline void cat::set_lapki(const int lapki)
{
	lapki_ = lapki;
}

inline double cat::get_weight() const
{
	return weight_;
}

inline void cat::set_weight(const double weight)
{
	weight_ = weight;
}

inline ::cat& cat::operator=(int i)
{
	this->lapki_ = i;
	return *this;
}

inline cat::cat(char* nick, int lapki): nick_(nick),
                                        lapki_(lapki)
{
}

inline cat::cat()
{
	cout << "Default Cat C-tor!\n";
	nick_ = new char[200];
	strcpy_s(nick_, 200, "Barsik");
}

inline cat::cat(cat& another)
{
	cout << "Copy Cat C-tor!\n";
	// default code:
	// nick = another.nick; // bad! two pointers on the same memory
	nick_ = new char[200];
	strcpy_s(nick_, 200, another.nick_);
}

inline cat::~cat()
{
	cout << "Cat Destructor!\n";
	delete[] nick_;
}

inline void cat::CopyTest()
{
	// add to main:
	// Cat::CopyTest();

	cat original;
	cat copy = original;
}
