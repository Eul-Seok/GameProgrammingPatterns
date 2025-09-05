#pragma once
#include <vector>
#include <queue>
#include <memory>

class UnitObjectPool_Interface
{
public:
    UnitObjectPool_Interface() = default;
    virtual ~UnitObjectPool_Interface() {}

public:
    virtual void Init(int InitialSize) = 0;
    virtual Unit* Pop() = 0;
    virtual void Return(Unit* Object) = 0;
};

template <typename T>
class UnitObjectPool : public UnitObjectPool_Interface
{
public:
    UnitObjectPool() = default;
    ~UnitObjectPool() = default;
    
    // 복사 생성자, 복사 대입 연산자 금지
    UnitObjectPool(const UnitObjectPool&) = delete;
    UnitObjectPool& operator=(const UnitObjectPool&) = delete;


private:
    std::vector<std::unique_ptr<T>> AllObjects;
    std::queue<T*> AvailableObjects;


public:
    void Init(int InitialSize)
    {
        for (int i = 0; i < InitialSize; ++i)
        {
            std::unique_ptr<T> Object = std::make_unique<T>();
            AvailableObjects.push(Object.get());
            AllObjects.push_back(std::move(Object)); // 소유권 이전
        }
    }

    Unit* Pop()
    {
        if (AvailableObjects.empty())
        {
            std::unique_ptr<T> Object = std::make_unique<T>();
            Unit* newUnit = Object.get();
            AllObjects.push_back(std::move(Object));
            return newUnit;
        }

        T* Object = AvailableObjects.front();
        AvailableObjects.pop();
        return Object;
    }

    void Return(Unit* Object)
    {
        T* castedObject = dynamic_cast<T*>(Object);
        if (castedObject)
        {
            AvailableObjects.push(castedObject);
        }
    }
};