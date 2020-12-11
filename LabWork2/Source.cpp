#include <iostream>
using namespace std;

class String {
public:
	String() {
		arr = nullptr;
		size = 0;
		capacity = 0;
	}

	String(const char *const arr) {
		size_t size = strlen(arr);
		this->arr = new char[size + 1]();
		this->size = size;
		this->capacity = size;
		strcpy_s(this->arr, size + 1, arr);
	}

	String(const String &str) {
		this->arr = new char[str.size + 1]();
		this->size = str.size;
		this->capacity = str.size;
		strcpy_s(this->arr, str.size + 1, str.arr);
	}

	String(String &&str) noexcept {
		this->arr = str.arr;
		this->size = str.size;
		this->capacity = str.capacity;
		str.arr = nullptr;
		str.size = 0;
		str.capacity = 0;
	}

	String &operator=(const String &str) {
		if (str.size <= this->capacity) {
			this->size = str.size;
		}
		else {
			delete[] this->arr;
			this->arr = new char[str.size + 1]();
			this->size = str.size;
			this->capacity = str.size;
		}
		strcpy_s(this->arr, str.size + 1, str.arr);
	
		return *this;
	}

	String &operator=(const char *const arr) {
		size_t size = strlen(arr);
		if (size <= this->capacity) {
			this->size = size;
		}
		else {
			delete[] this->arr;
			this->arr = new char[size + 1]();
			this->size = size;
			this->capacity = size;
		}
		strcpy_s(this->arr, size + 1, arr);
	
		return *this;
	}

	String &operator+=(const String &str) {
		char *oldArr = this->arr;
		size_t size = this->size + str.size;

		this->arr = new char[size + 1]();
		this->size = size;
		this->capacity = size;
		strcpy_s(this->arr, this->size + 1, oldArr);
		strcat_s(this->arr, size + 1, str.arr);

		delete[] oldArr;
		return *this;
	}

	String &operator+=(const char *const arr) {
		char *oldArr = this->arr;
		size_t size = this->size + strlen(arr);

		this->arr = new char[size + 1]();
		this->size = size;
		this->capacity = size;
		strcpy_s(this->arr, this->size + 1, oldArr);
		strcat_s(this->arr, size + 1, arr);

		delete[] oldArr;
		return *this;
	}

	String operator+(const String &str) const {
		String newStr;
		size_t size = this->size + str.size;

		newStr.arr = new char[size + 1]();
		newStr.size = size;
		newStr.capacity = size;
		strcpy_s(newStr.arr, this->size + 1, this->arr);
		strcat_s(newStr.arr, size + 1, str.arr);
		
		return newStr;
	}

	String operator+(const char *const arr) const {
		String newStr;
		size_t size = this->size + strlen(arr);

		newStr.arr = new char[size + 1]();
		newStr.size = size;
		newStr.capacity = size;
		strcpy_s(newStr.arr, this->size + 1, this->arr);
		strcat_s(newStr.arr, size + 1, arr);
		
		return newStr;
	}

	friend istream &operator>>(istream &istr, String &str) {
		char buffer[257];
		istr >> buffer;
		str = buffer;
		return istr;
	}

	friend ostream &operator<<(ostream &ostr, const String &str) {
		return ostr << str.arr;
	}

	const char *getCharArray() const {
		return arr;
	}

	size_t getSize() const {
		return size;
	}

	size_t getCapacity() const {
		return capacity;
	}

	~String() {
		delete[] arr;
		arr = nullptr;
		size = 0;
		capacity = 0;
	}

private:
	char *arr;
	size_t size;
	size_t capacity;
};

int main() {
	String str("str");
	str = "STR";
	str += "STR";

	String str2(str); 
	cin >> str;
	cout << str << endl;

	return 0;
}