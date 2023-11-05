#ifndef STACK
#define STACK

using namespace std;

template <class T>
class Stack {

	T* begin;
	T* end;
	int size;

public:

	Stack() : size(100) {
		begin = new T[size] {};
		end = begin;
	};

	Stack(int _size) : size(_size) {
		if (_size < 0) throw invalid_argument("Length shoulf be non-negative integer");
		begin = new T[size] {};
		end = begin;
	};

	Stack(const Stack& other) : size(other.size) {
		begin = new T[size] {};
		for (int i = 0 ; i < size; i++) begin[i] = other.begin[i];
		end = begin + (other.end - other.begin);
	};

	~Stack() { delete[] begin; };

	void push(T x) {
		if ((end - begin) == size) {
			size *= 2;
			T* tmp = new T[size] {};
			std::copy(begin, end, tmp);
			end = tmp + (end - begin);
			delete[] begin;
			begin = tmp;
		}
		*end = x;
		end++;
	};

	T top() { 
		if (!isEmpty()) return *(end - 1);
		else throw out_of_range("Stack is empty");
	};

	void pop(){
		if (!isEmpty()) end--;
		else throw out_of_range("Stack is empty");
	}

	bool isEmpty() { return begin == end; };

	int getSize() { return end - begin; };
	
	bool operator==(const Stack& other) {
		if ((end - begin) != (other.end - other.begin)) return false;
		int s = end - begin;
		for (int i = 0; i < s; i++) 
			if (begin[i] != other.begin[i]) return false;
		return true;
	};

	friend ostream& operator<<(ostream& out, const Stack& v) {
		out << "{ ";
		int s = v.end - v.begin;
		for (int i = s - 1; i >= 0; i--) out << v.begin[i] << " ";
		out << "}";
		return out;
	};
};

#endif