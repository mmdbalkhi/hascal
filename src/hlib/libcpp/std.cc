typedef std::string string;
typedef std::string __hascal__string;

// should support all compilers(todo)
// #if __GNUC__ || __clang__
// typedef __int128 int128;
// #else
// typedef __int128_t int128;
// #endif
typedef int __hascal__int;
typedef bool __hascal__bool;
typedef float __hascal__float;
typedef double __hascal__double;
typedef char __hascal__char;
typedef void __hascal__void;

typedef int __hascal__int;
typedef long long __hascal__int64;
typedef unsigned long long __hascal__uint64;

typedef unsigned int __hascal__uint;
typedef unsigned long long __hascal__uint64;

typedef short __hascal__int16;
typedef unsigned short __hascal__uint16;

typedef unsigned char __hascal__uint8;
typedef char __hascal__int8;

#define __hascal__NULL NULL
// #define dict std::unordered_map

void __hascal__error(string err_msg){
	std::cerr << err_msg << std::endl ;
}

void __hascal__panic(string err_msg){
	__hascal__error(err_msg);
	exit(1);
}


string __hascal__ReadStr(){
	string res;
	std::cin >> res;
	return res;
}

string __hascal__ReadStr(string p){
	std::cout << p;
	string res;
	std::cin >> res;
	return res;
}

char __hascal__ReadChar(){
	char res;
	std::cin >> res;
	return res;
}

char __hascal__ReadChar(string p){
	std::cout << p;
	char res;
	std::cin >> res;
	return res;
}

bool __hascal__ReadBool(){
	string tmp = __hascal__ReadStr();
	if(tmp == "0" || tmp == "true")
		return true;
	return false;
}

bool __hascal__ReadBool(string p){
	string tmp = __hascal__ReadStr(p);
	if(tmp == "0" || tmp == "true")
		return true;
	return false;
}

int __hascal__ReadInt(){
	int res;
	std::cin >> res;
	return res;
}

int __hascal__ReadInt(string p){
	std::cout << p;
	int res;
	std::cin >> res;
	return res;
}

float __hascal__ReadFloat(){
	float res;
	std::cin >> res;
	return res;
}

float __hascal__ReadFloat(string p){
	std::cout << p;
	float res;
	std::cin >> res;
	return res;
}



template<typename Test, template<typename...> class Ref>
struct is_specialization : std::false_type {};

template<template<typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref>: std::true_type {};

// this function is used to get length of a vector
template <typename T>
int __hascal__len(std::vector<T> v){
	return v.size();
}

// this function is used to get length of a string
int __hascal__len(string s){
	return s.length();
}

// this function is used to append a value to a vector
template <typename T>
void __hascal__append(std::vector<T>& v, T val){
	v.push_back(val);
}

string __hascal__input(){
	return __hascal__ReadStr();
}
string __hascal__input(string text){
	return __hascal__ReadStr(text);
}

std::vector<std::string> __hascal__split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

// format function -> e.g : format("Hi, {}",name)
template <typename T, typename ... ARGS>
string __hascal__format(T text,ARGS... args){
	string res;

	std::vector<string> fmt_list = { args... };
  	std::vector<string> points = __hascal__split(text,"{}");

  	int fmt_size = fmt_list.size();
  	int points_size = points.size();

  	for(int i,j=0;i<=points_size-1 && j<=fmt_size;j++,i++){
		res += points[i] + fmt_list[j];
  	} 
	return res;
}

template <typename T>
T* __hascal__mem_new(T val){
	T* res = new T(val);
	return res;
}
template <typename T>
T* __hascal__mem_realloc(T* ptr, T val){
	delete ptr;
	T* res = new T(val);
	return res;
}
template <typename T>
void __hascal__mem_delete(T* ptr){
	delete ptr;
}
template <typename T>
std::vector<T>* __hascal__mem_new(){
	auto res = new std::vector<T>();
	return res;
}
template <typename T>
std::vector<T>* __hascal__mem_renew(std::vector<T>* ptr,std::vector<T> val){
	delete ptr;
	auto res = new std::vector<T>(val);
	return res;
}
template <typename T>
void __hascal__mem_delete(std::vector<T>* ptr){
	delete ptr;
}


template <typename T>
constexpr auto __hascal___type_name() {
  	std::string_view name, prefix, suffix;
#ifdef __clang__
  	name = __PRETTY_FUNCTION__;
  	prefix = "auto type_name() [T = ";
  	suffix = "]";
#elif defined(__GNUC__)
  	name = __PRETTY_FUNCTION__;
  	prefix = "constexpr auto type_name() [with T = [with T =  ";
  	suffix = "]";
#elif defined(_MSC_VER)
  	name = __FUNCSIG__;
  	prefix = "auto __cdecl type_name<";
  	suffix = ">(void)";
#endif
  	name.remove_prefix(prefix.size());
  	name.remove_suffix(suffix.size());
  	return name;
}

template <typename T>
std::string __hascal__typeof(T val) {
	std::string res(__hascal___type_name<decltype(val)>());
	if (res == "std::__cxx11::basic_string<char>")
		return "string";
	
	// replace `*` with `^`
	std::ostringstream oss;
    std::size_t pos = 0;
    std::size_t prevPos = pos;

    while (true) {
        prevPos = pos;
        pos = res.find("*", pos);
        if (pos == std::string::npos)
            break;
        oss << res.substr(prevPos, pos - prevPos);
        oss << "^";
        pos += std::string("*").size();
    }

    oss << res.substr(prevPos);
    res = oss.str();

	return res;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	out << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
	if (__hascal__typeof(*it) == "string"){
		out << "\"" << *it << "\"";
	} else if(__hascal__typeof(*it) == "char"){
		out << "'" << *it << "'";		
	}else {
		out << *it;
	}

	if (it != v.end() - 1) {
	  out << ", ";
	}
  }
  out << "]";
  return out;
}

struct HascalException : public std::exception
{
	std::string msg;
	HascalException(std::string msg){
		this->msg = msg;
	}
	const char * what () const throw ()
    {
    	return this->msg.c_str();
    }
};

void __hascal__exit(int code){
	exit(code);
}

std::vector<int> __hascal__range(int start, int stop, int step)
{
  	if (step == 0){
		__hascal__panic("HascalError: step for range must be non-zero");
	}

	std::vector<int> result;
	int i = start;
	while ((step > 0) ? (i < stop) : (i > stop))
	{
		result.push_back(i);
		i += step;
	}

	return result;
}

std::vector<int> __hascal__range(int start, int stop)
{
 	return __hascal__range(start, stop, 1);
}

std::vector<int> __hascal__range(int stop)
{
	return __hascal__range(0, stop, 1);
}

// builtin assert()
#define __hascal__assert(cond) if(!(cond)){throw HascalException("Assertion failed: " #cond);}

#define __hascal__sizeof(a) sizeof(a)