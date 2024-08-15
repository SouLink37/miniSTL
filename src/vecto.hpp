#include <bits/stdc++.h>

namespace miniSTL
{
    template <typename T>
    class MyVector
    {
    public:
        MyVector() : data_(nullptr), size_(0), capacity_(0) {}

        explicit MyVector(size_t capacity) : data_(new T[capacity]), size_(0), capacity_(capacity) {}

        MyVector(const MyVector &other) : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_)
        {

            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }

        MyVector &operator=(const MyVector &other)
        {
            if (this != &other)
            {
                delete[] data_;
                size_ = other.size_;
                capacity_ = other, capacity_;
                data_ = new T[capacity_];
                for (size_t i = 0; i < size_; ++i)
                {
                    data_[i] = other.data_[i];
                }
            }
            return *this;
        }

        ~MyVector()
        {
            delete[] data_;
            data_ = nullptr;
            size_ = 0;
            capacity_ = 0;
        };

    public:
        void push(T &element)
        {
            if (capacity_ == 0)
            {
                capacity_ = 1;
                data_ = new T[capacity_];
            }

            if (size_ == capacity_)
            {
                T *temp = new T[2 * capacity_];
                capacity_ *= 2;
                for (size_t i = 0; i < size_; ++i)
                {
                    temp[i] = data_[i];
                }
                delete[] data_;
                data_ = temp;
            }

            data_[size_++] = element;
        };

        size_t size()
        {
            return size_;
        }

        size_t capacity()
        {
            return capacity_;
        }

        const T &get(size_t index)
        {
            if (index >= size_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        void insert(size_t index, T &element)
        {
            if (index > size_)
            {
                throw std::out_of_range("Index out of range");
            }

            if (size_ == capacity_)
            {
                T *temp = new T[2 * capacity_];
                capacity_ *= 2;
                for (size_t i = 0; i < size_; ++i)
                {
                    temp[i] = data_[i];
                }
                delete[] data_;
                data_ = temp;
            }

            for (size_t i = size_; i > index; --i)
            {
                data_[i] = data_[i - 1];
            }

            data_[index] = element;
            ++size_;
        }

        void pop()
        {
            if (size_ > 0)
            {
                --size_;
            }
        }

        void clear()
        {
            size_ = 0;
        }

        void print()
        {
            if (size_ == 0)
                std::cout << "empty";
            for (size_t i = 0; i < size_; ++i)
            {
                std::cout << data_[i] << " ";
            }
            std::cout << std::endl;
        }

    private:
        T *data_;
        size_t size_;
        size_t capacity_;
        T *iter_;
    };
} // namespace miniSTL

int main()
{
    ::miniSTL::MyVector<int> test_vector;

    int N;
    std::cin >> N;

    while (N--)
    {
        std::string command;
        std::cin >> command;

        if (command == "push")
        {
            int element;
            std::cin >> element;
            test_vector.push(element);
        }
        else if (command == "size")
        {
            std::cout << test_vector.size() << std::endl;
        }
        else if (command == "get")
        {
            int index;
            std::cin >> index;
            std::cout << test_vector.get(index) << std::endl;
        }
        else if (command == "insert")
        {
            int index, element;
            std::cin >> index >> element;
            test_vector.insert(index, element);
        }
        else if (command == "pop")
        {
            test_vector.pop();
        }
        else if (command == "clear")
        {
            test_vector.clear();
        }
        else if (command == "print")
        {
            test_vector.print();
        }
        else
        {
            std::cerr << "Unknown command" << std::endl;
        }
    }
    return 0;
}