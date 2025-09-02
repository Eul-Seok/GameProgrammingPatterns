#pragma once
#include <vector>
#include <queue>

template <typename T>
class ObjectPool
{
public:
    ObjectPool() = default;

    ~ObjectPool()
    {
        while (!AvailableObjects.empty())
        {
            AvailableObjects.pop();
        }

        for (T* obj : AllObjects)
        {
            delete obj;
        }
        AllObjects.clear();
    }

    // 복사 생성자, 복사 대입 연산자 금지
    ObjectPool(const ObjectPool&) = delete;
    ObjectPool& operator=(const ObjectPool&) = delete;


private:
    std::vector<T*> AllObjects;
    std::queue<T*> AvailableObjects;


public:
    void Init(int InitialSize)
    {
        for (int i = 0; i < InitialSize; ++i)
        {
            T* Object = new T();
            AllObjects.push_back(Object);
            AvailableObjects.push(Object);
        }
    }

    T* Pop()
    {
        if (AvailableObjects.empty())
        {
            T* Object = new T();
            AllObjects.push_back(Object);
            return Object;
        }

        T* Object = AvailableObjects.front();
        AvailableObjects.pop();
        return Object;
    }

    void Return(T* Object)
    {
        AvailableObjects.push(Object);
    }
};