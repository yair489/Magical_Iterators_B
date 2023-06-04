
#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::AscendingIterator::operator*() const
{
    return *it;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() // ++i
{
    if (it == _p_m->_set.end())
    {
        throw std::runtime_error(" ");
    }
    ++it;

    size_step++;
    return *this;
}

const MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) // i++
{
    if (it == _p_m->_set.end())
    {
        throw std::runtime_error(" ");
    }
    AscendingIterator tmp = *this;
    ++it;
    size_step++;
    return tmp;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &rhs) const
{
    if (this->_p_m != rhs._p_m)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return it == rhs.it;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &rhs) const
{
    return !(it == rhs.it);
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this->_p_m != other._p_m)
        throw std::runtime_error("Cant copy ");
    _p_m = other._p_m;
    size_step = other.size_step;
    it = other.it;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &rhs) const
{
    if (this->_p_m != rhs._p_m)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return (size_step) > (rhs.size_step);

}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &rhs) const
{
    if (this->_p_m != rhs._p_m)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return (size_step) < (rhs.size_step);
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
{

    it = _p_m->_set.begin();
    return *this;
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
{
    it = _p_m->_set.end();
    return *this;
}
