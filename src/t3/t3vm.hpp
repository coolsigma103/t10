#pragma once
#include <cstdint>
#include <cstdlib>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace t3
{
    using ObjId = uint32_t;

    struct HeapEntry
    {
        void* ptr;
        bool isMarked;
    };

    struct Value
    {
        enum Type
        {
            INT,
            FLOAT,
            BOOL,
            REF,
            NIL
        } type;

        union
        {
            int i;
            float f;
            bool b;
            ObjId ref;
        };
        Value(Type t) : type(t) {}
    };

    struct Symbols
    {
        enum Type
        {
            GLOBAL,
            CONSTANT,
            LABEL,
            NATIVE_LAB
        };
    };

    class VM
    {
        std::vector<Value> globals;
        std::stack<Value> stack;
        std::vector<HeapEntry> heap;
        std::unordered_map<std::string, Symbols> symbols;

        std::stack<ObjId> freeId;
        ObjId highestId = 0;

        size_t allocatedBytes = 0;
        size_t nextGC = 1024 * 1024;

        void mark();
        void markObject(ObjId id);
        void sweep();

    public:
        VM() = default;
        ~VM();

        ObjId allocObj(size_t size);
        void freeObj(ObjId obj);

        void collectGarbage();

        void push(Value v);
        Value pop();
    };

} // namespace t3