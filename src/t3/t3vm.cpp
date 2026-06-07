#include "t3vm.hpp"

namespace t3
{
    ObjId VM::allocObj(size_t size)
    {
        if (allocatedBytes >= nextGC)
        {
            collectGarbage();
        }

        void* data = malloc(size);
        if (!data)
        {
            exit(1);
        }
        allocatedBytes += size;

        HeapEntry entry = {data, false};

        if (!freeId.empty())
        {
            ObjId id = freeId.top();
            freeId.pop();
            heap[id] = entry;
            return id;
        }
        else
        {
            heap.push_back(entry);
            return highestId++;
        }
    }

    void VM::freeObj(ObjId obj)
    {
        if (obj >= heap.size() || heap[obj].ptr == nullptr)
            return;

        free(heap[obj].ptr);
        heap[obj].ptr = nullptr;
        freeId.push(obj);
    }

    void VM::push(Value v)
    {
        stack.push(v);
    }

    Value VM::pop()
    {
        if (stack.empty())
        {
            exit(1);
        }
        Value v = stack.top();
        stack.pop();
        return v;
    }

    void VM::markObject(ObjId id)
    {
        if (id >= heap.size() || heap[id].ptr == nullptr)
            return;
        if (heap[id].isMarked)
            return;

        heap[id].isMarked = true;
    }

    void VM::mark()
    {
        std::stack<Value> tempStack = stack;
        while (!tempStack.empty())
        {
            Value val = tempStack.top();
            tempStack.pop();
            if (val.type == Value::Type::REF)
            {
                markObject(val.ref);
            }
        }

        for (const auto& val : globals)
        {
            if (val.type == Value::Type::REF)
            {
                markObject(val.ref);
            }
        }
    }

    void VM::sweep()
    {
        for (size_t i = 0; i < heap.size(); ++i)
        {
            if (heap[i].ptr == nullptr)
                continue;

            if (!heap[i].isMarked)
            {
                free(heap[i].ptr);
                heap[i].ptr = nullptr;
                freeId.push(static_cast<ObjId>(i));
            }
            else
            {
                heap[i].isMarked = false;
            }
        }
    }

    void VM::collectGarbage()
    {
        mark();
        sweep();
        nextGC = allocatedBytes * 2;
    }

    VM::~VM()
    {
        for (auto& entry : heap)
        {
            if (entry.ptr != nullptr)
            {
                free(entry.ptr);
            }
        }
    }
} // namespace t3