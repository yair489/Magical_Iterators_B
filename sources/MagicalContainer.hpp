#pragma once

#include <vector>
#include <iterator>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>

namespace ariel
{
    class MagicalContainer
    {
        std::vector<int> _set ;
        std::vector<int * > _prime;
        std::vector<int > _p;

        bool isPrime(int number);
        void update();
    public:
        MagicalContainer(){}
        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other) ;

        MagicalContainer &operator=(const MagicalContainer &other)noexcept = default ;
        MagicalContainer(MagicalContainer &&other) = default;
        MagicalContainer &operator=(MagicalContainer &&other) = default;

        void addElement(int element);
        void insertElement(int element);
        void removeElement(int element);
        size_t size() const{
            return _set.size();
        }

        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        class AscendingIterator
        {
            
             private:
        std::vector<int>::iterator it;
        MagicalContainer * _p_m;
        int size_step =0;
    public:
      
        AscendingIterator(MagicalContainer  &pointer1)
            : it(pointer1._set.begin()),_p_m(&pointer1),size_step(0)
        {
        }
        int  operator*() const;
        AscendingIterator &operator++() ;// ++i;
        const AscendingIterator operator++(int) ;// i++;
        bool operator==(const AscendingIterator &rhs) const;
        bool operator!=(const AscendingIterator &rhs) const;
        AscendingIterator &operator=(const AscendingIterator &other);

    AscendingIterator(const AscendingIterator &other) = default;
    AscendingIterator(AscendingIterator &&other) noexcept = default;
        AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;
            //     AscendingIterator(const AscendingIterator &other);
            // AscendingIterator(const MagicalContainer &other);
            ~AscendingIterator() = default;
            // AscendingIterator(AscendingIterator &&other) noexcept = default;
            // AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;



            bool operator>(const AscendingIterator &rhs) const;
            bool operator<(const AscendingIterator &rhs) const;
            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator
        {
            
             private:
        std::vector<int>::iterator it_s;
        std::vector<int>::iterator it_e;
        std::vector<int>::iterator current;
        std::vector<int>::iterator _end ;
        MagicalContainer * _p_m;
        int size_step =0;
        int count;
    public:
      
        SideCrossIterator(MagicalContainer  &pointer1)
            : current(pointer1._set.begin()),it_s(pointer1._set.begin()),it_e(pointer1._set.end()),
            _p_m(&pointer1),count(0),_end(pointer1._set.begin()),size_step(0)
        {
            //  std::cout << "++SideCrossIterator"<<std::endl;
        }
        int  operator*() const;
        SideCrossIterator &operator=(const SideCrossIterator &other);
        SideCrossIterator &operator++(); // ++i;

        const SideCrossIterator operator++(int); // i++;

        bool operator==(const SideCrossIterator &rhs) const;
        bool operator!=(const SideCrossIterator &rhs) const;

SideCrossIterator(const SideCrossIterator &other) = default;
    SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;
                    ~SideCrossIterator() = default;

            // SideCrossIterator(const SideCrossIterator &other);
            // SideCrossIterator(const MagicalContainer &other);
            // ~SideCrossIterator() = default;
            // SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            // SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;



            bool operator>(const SideCrossIterator &rhs) const;
            bool operator<(const SideCrossIterator &rhs) const;
            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator
        {
            
             private:
        std::vector<int*>::iterator it;
        MagicalContainer * _p_m;
    public:
      
        PrimeIterator(MagicalContainer  &pointer1)
            : it(pointer1._prime.begin()),_p_m(&pointer1)
        {
        }
        int  operator*() const;

        PrimeIterator &operator++() ;// ++i;
PrimeIterator &operator=(const PrimeIterator &other);
        const PrimeIterator operator++(int); // i++;

        bool operator==(const PrimeIterator &rhs) const;

        bool operator!=(const PrimeIterator &rhs) const;

    
PrimeIterator(const PrimeIterator &other) = default;
    PrimeIterator(PrimeIterator &&other) noexcept = default;
        PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;
        ~PrimeIterator() = default;
            bool operator>(const PrimeIterator &rhs) const;
            bool operator<(const PrimeIterator &rhs) const;
            PrimeIterator &begin();
            PrimeIterator &end();
        };

    };
}