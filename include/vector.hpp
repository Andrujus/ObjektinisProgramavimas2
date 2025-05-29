#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
class Vector {
public:

    
    Vector(size_t size = 0)
    : size_(size), capacity_(size > 0 ? size : 1) {
    data_ = new T[capacity_];
}



    Vector(const Vector& other)
    : size_(other.size_), capacity_(other.capacity_), data_(new T[other.capacity_]) {
    for (size_t i = 0; i < size_; ++i)
        data_[i] = other.data_[i];
    }


    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
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
            delete[] data_;
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
        delete[] data_;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reserve(capacity_ * 2);
        }
        data_[size_++] = value;
    }

        void reserve(size_t new_capacity) {
            if (new_capacity <= capacity_) return;

            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
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

    void pop_back() {
        if (size_ > 0) {
            --size_;
        } else {
            throw std::out_of_range("Cannot pop from empty Vector");
        }
    }


private:
    T* data_;
    size_t size_;
    size_t capacity_;
};

#endif
