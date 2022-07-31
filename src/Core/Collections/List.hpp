#pragma once

#include <cstdlib>

template<typename T>
class List
{
public:
    List() : List(4)
    {
    }

    explicit List(size_t capacity)
    {
        std::cout << "Construct" << std::endl;

        ChangeCapacity(capacity);
    }

    List(const List& other)
    {
        std::cout << "Copy" << std::endl;

        ChangeCapacity(other.m_Capacity);

        m_Size = other.m_Size;

        for (int i = 0; i < m_Size; ++i)
        {
            m_Data[i] = other.m_Data[i];
        }
    }

    List(List&& other) noexcept
    {
        std::cout << "Move" << std::endl;

        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;

        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
    }

    ~List()
    {
        std::cout << "Destruct" << std::endl;

        delete[] m_Data;
        m_Size = 0;
        m_Capacity = 0;
    }

    void Add(const T& element)
    {
        if (m_Size >= m_Capacity)
        {
            ChangeCapacity(m_Capacity * 2);
        }

        m_Data[m_Size] = element;
        m_Size++;
    }

    [[nodiscard]]
    const size_t& size() const
    {
        return m_Size;
    }

    T& operator[](size_t index)
    {
        return m_Data[index];
    }

    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

private:
    void ChangeCapacity(size_t capacity)
    {
        T* data = new T[capacity];

        if (capacity < m_Size)
        {
            m_Size = capacity;
        }

        for (int i = 0; i < m_Size; ++i)
        {
            data[i] = std::move(m_Data[i]);
        }

        delete[] m_Data;

        m_Data = data;
        m_Capacity = capacity;
    }
};
