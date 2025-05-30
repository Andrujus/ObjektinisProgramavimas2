#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <new>
#include <utility>

template <typename T>
class Vector {
public:
    Vector(std::size_t size = 0)
        : size_(0), capacity_(size > 0 ? size : 1) {
        data_ = static_cast<T*>(::operator new[](capacity_ * sizeof(T)));
    }

    Vector(const Vector& other)
        : size_(other.size_), capacity_(other.capacity_) {
        data_ = static_cast<T*>(::operator new[](capacity_ * sizeof(T)));
        for (std::size_t i = 0; i < size_; ++i) {
            new (data_ + i) T(other.data_[i]);
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            clear();
            ::operator delete[](data_);
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = static_cast<T*>(::operator new[](capacity_ * sizeof(T)));
            for (std::size_t i = 0; i < size_; ++i) {
                new (data_ + i) T(other.data_[i]);
            }
        }
        return *this;
    }

    Vector(Vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            ::operator delete[](data_);
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    ~Vector() {
        clear();
        ::operator delete[](data_);
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reserve(capacity_ * 2);
        }
        new (data_ + size_) T(value);
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) throw std::out_of_range("pop_back() on empty vector");
        data_[size_ - 1].~T();
        --size_;
    }

    void reserve(std::size_t new_capacity) {
        if (new_capacity <= capacity_) return;

        T* new_data = static_cast<T*>(::operator new[](new_capacity * sizeof(T)));

        for (std::size_t i = 0; i < size_; ++i) {
            new (new_data + i) T(std::move(data_[i]));
            data_[i].~T();
        }

        ::operator delete[](data_);
        data_ = new_data;
        capacity_ = new_capacity;
    }

    Vector(std::initializer_list<T> init)
        : size_(init.size()), capacity_(init.size()), data_(new T[capacity_]) {
        size_t i = 0;
        for (const auto& value : init) {
            data_[i++] = value;
        }
    }


    T& operator[](std::size_t index) {
        return data_[index];
    }

    const T& operator[](std::size_t index) const {
        return data_[index];
    }

    T& at(std::size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& at(std::size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    T* begin() {
        return data_;
    }

    T* end() {
        return data_ + size_;
    }

    const T* begin() const {
        return data_;
    }

    const T* end() const {
        return data_ + size_;
    }


    T& front() {
        return data_[0];
    }

    const T& front() const {
        return data_[0];
    }

    T& back() {
        return data_[size_ - 1];
    }

    const T& back() const {
        return data_[size_ - 1];
    }

    std::size_t size() const {
        return size_;
    }

    std::size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        size_ = 0;
    }
private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;
};
#endif
