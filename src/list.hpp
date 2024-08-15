#include <bits/stdc++.h>

namespace miniSTL
{
    template <typename T>
    class List
    {
    public:
        List() : size_(0), head_(nullptr), tail_(nullptr) {}
        ~List()
        {
            clear();
        }

    private:
        struct Node
        {
            T data;
            Node *next;
            Node *prev;
            //   Node(): data(0), prev(nullptr), next(nullptr){}
            Node(const T &vaule, Node *nextNode = nullptr, Node *prevNode = nullptr)
                : data(vaule), next(nextNode), prev(prevNode) {}
        };

        size_t size_;
        Node *head_;
        Node *tail_;

    public:
        void push_back(const T &vaule)
        {
            Node *new_node = new Node(vaule, nullptr, tail_);

            if (size_ == 0)
            {
                head_ = new_node;
            }
            else
            {
                tail_->next = new_node;
            }
            tail_ = new_node;
            ++size_;
        }

        void push_front(const T &vaule)
        {
            Node *new_node = new Node(vaule, head_, nullptr);

            if (size_ == 0)
            {
                tail_ = new_node;
            }
            else
            {
                head_->prev = new_node;
            }
            head_ = new_node;
            ++size_;
        }

        void pop_back()
        {
            if (size_ > 0)
            {
                // Node* temp = tail_;
                // tail_ = tail_->prev;
                // delete temp;
                // temp = nullptr;
                Node *temp = tail_->prev;
                delete tail_;
                tail_ = temp;

                if (tail_)
                {
                    tail_->next = nullptr;
                }
                else
                {
                    head_ = nullptr;
                }
                --size_;
            }
        }

        void pop_front()
        {
            if (size_ > 0)
            {
                // Node* temp = head_;
                // head_ = head_->next;
                // delete temp;
                // temp = nullptr;
                Node *temp = head_->next;
                delete head_;
                head_ = temp;

                if (head_)
                {
                    head_->prev = nullptr;
                }
                else
                {
                    tail_ = nullptr;
                }
                --size_;
            }
        }

        void remove(const T &vaule)
        {
            Node *cur = head_;
            while (cur)
            {
                if (cur->data == vaule)
                {
                    if (cur == head_)
                    {
                        cur = cur->next;
                        pop_front();
                        // cur = head_;
                    }
                    else if (cur == tail_)
                    {
                        pop_back();
                        cur = nullptr;
                    }
                    else
                    {
                        Node *temp = cur->next;
                        cur->prev->next = cur->next;
                        cur->next->prev = cur->prev;
                        delete cur;
                        cur = temp;
                        --size_;
                    }
                }
                else
                {
                    cur = cur->next;
                }
            }
        }

        void clear()
        {
            if (size_)
            {
                Node *cur = head_;
                while (cur)
                {
                    Node *next = cur->next;
                    delete cur;
                    cur = next;
                }
                size_ = 0;
                head_ = nullptr;
                tail_ = nullptr;
            }
        }

        size_t size()
        {
            return size_;
        }

        const T &get(size_t index)
        {
            if (index >= size_)
            {
                // throw std::out_of_range("Index out of range");
                throw -1;
            }
            else
            {
                Node *cur = head_;
                while (index--)
                {
                    cur = cur->next;
                }
                return cur->data;
            }
        }

        void print()
        {
            if (size_ == 0)
            {
                std::cout << "empty" << std::endl;
            }
            else
            {
                Node *cur = head_;
                while (cur)
                {
                    std::cout << cur->data << " ";
                    cur = cur->next;
                }
                std::cout << std::endl;
            }
        }
    };
} // namespace miniSTL

// test
int main()
{
    ::miniSTL::List<int> test_list;
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string command;
        std::cin >> command;

        if (command == "push_back")
        {
            int element;
            std::cin >> element;
            test_list.push_back(element);
        }
        else if (command == "push_front")
        {
            int element;
            std::cin >> element;
            test_list.push_front(element);
        }
        else if (command == "pop_back")
        {
            test_list.pop_back();
        }
        else if (command == "pop_front")
        {
            test_list.pop_front();
        }
        else if (command == "remove")
        {
            int element;
            std::cin >> element;
            test_list.remove(element);
        }
        else if (command == "clear")
        {
            test_list.clear();
        }
        else if (command == "size")
        {
            std::cout << test_list.size() << std::endl;
        }
        else if (command == "get")
        {
            size_t index;
            std::cin >> index;
            try
            {
                std::cout << test_list.get(index) << std::endl;
            }
            catch (int err)
            {
                std::cerr << err << std::endl;
            }
        }
        else if (command == "print")
        {
            test_list.print();
        }
    }

    return 0;
}