#ifndef KONGKONG_NUMERIC_DYNAMICVECTOR_H
#define KONGKONG_NUMERIC_DYNAMICVECTOR_H

#include "Base.h"
#include "Kongkong.InvalidArgumentException.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Algorithms.Range.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    /// @brief 次元を変更できるベクトル型
    /// @tparam TNum 要素の型
    template <NumberType TNum>
    struct DynamicVector final : public ValueType {

        /// @brief 要素のメモリサイズ
        [[nodiscard]]
        static constexpr ssize_t ElementSize() noexcept { return (ssize_t)sizeof(TNum); }

        DynamicVector(ssize_t dimension) : DynamicVector(dimension, (TNum)0) {}
        DynamicVector(ssize_t dimension, TNum defaultValue) : _p(nullptr), _dimension(dimension)
        {
            _checkInvalidDimension(dimension);

            _p = (TNum*)::malloc(dimension * sizeof(TNum));

            MemoryAllocationException::CheckNull(_p);

            TNum* p = _p;
            TNum* e = p + dimension;

            while (p != e) {
                *p = defaultValue;
                ++p;
            }
        }
        DynamicVector(std::initializer_list<TNum> const& iList) :
            _p((TNum*)::malloc(iList.size() * sizeof(TNum))),
            _dimension((ssize_t)iList.size())
        {
            MemoryAllocationException::CheckNull(_p);

            TNum* p = _p;

            for (TNum const& value : iList) {
                *p = value;
                ++p;
            }
        }
        DynamicVector(DynamicVector const& right) : 
            _p((TNum*)::malloc(right._dimension * sizeof(TNum))), 
            _dimension(right._dimension)
        {
            ::memcpy(_p, right._p, _dimension);
        }
        DynamicVector(DynamicVector&& right) :
            _p(right._p),
            _dimension(right._dimension)
        {
            right._p = nullptr;
        }

        ~DynamicVector()
        {
            if (_p != nullptr) ::free(_p);
        }

        DynamicVector& operator=(DynamicVector const& right)
        {
            ::free(_p);
            _p = (TNum*)::malloc(right._dimension * sizeof(TNum));

            MemoryAllocationException::CheckNull(_p);

            _dimension = right._dimension;
            ::memcpy(_p, right._p, _dimension);

            return *this;
        }
        DynamicVector& operator=(DynamicVector&& right)
        {
            if (_p != nullptr) ::free(_p);
            _p = right._p;
            _dimension = right._dimension;
            right._p = nullptr;

            return *this;
        }

        [[nodiscard]] friend bool operator!=(DynamicVector const& left, DynamicVector const& right)
        {
            if (left._dimension != right._dimension) return true;
            return ::memcmp(left._p, right._p, left._dimension * sizeof(TNum)) != 0;
        }
        [[nodiscard]] friend bool operator==(DynamicVector const& left, DynamicVector const& right) { return !(left != right); }

        [[nodiscard]] TNum& operator[] (ssize_t index) noexcept { return _p[index]; }
        [[nodiscard]] TNum const& operator[] (ssize_t index) const noexcept { return _p[index]; }

        //範囲for文
        [[nodiscard]] TNum* begin() noexcept { return _p; }
        [[nodiscard]] const TNum* begin() const noexcept { return _p; }
        [[nodiscard]] TNum* end() noexcept { return _p + _dimension; }
        [[nodiscard]] const TNum* end() const noexcept { return _p + _dimension; }

        /// @brief 関数 TNum func(TNum v) を各要素に適用
        /// @param func 関数ポインタ
        void ApplyToAll(TNum(*func)(TNum))
        {
            for (TNum& value : *this) {
                value = func(value);
            }
        }

        /// @brief 関数 void func(TNum& v) を各要素に適用
        /// @param func 関数ポインタ
        void ApplyToAll(void(*func)(TNum&))
        {
            for (TNum& value : *this) {
                func(value);
            }
        }

        [[nodiscard]] TNum& At(ssize_t index)
        {
            Collections::CollectionHelper::CheckIndex(index, _dimension);
            return _p[index];
        }

        [[nodiscard]] TNum const& At(ssize_t index) const
        {
            Collections::CollectionHelper::CheckIndex(index, _dimension);
            return _p[index];
        }

        [[nodiscard]]
        constexpr bool Contains(TNum value) const noexcept
        {
            for (TNum const& n : *this) {
                if (n == value) return true;
            }

            return false;
        }

        [[nodiscard]] TNum* Data() noexcept { return _p; }
        [[nodiscard]] const TNum* Data() const noexcept { return _p; }

        [[nodiscard]] constexpr ssize_t Dimension() const noexcept { return _dimension; }

        /// @brief 次元を変更
        /// @param newDimension 次元
        void Resize(ssize_t newDimension) { Resize(newDimension, (TNum)0); }

        /// @brief 次元を変更
        /// @param newDimension 次元
        /// @param value 新しく要素が追加された場合の初期値
        void Resize(ssize_t newDimension, TNum value)
        {
            if (newDimension == _dimension) [[unlikely]] return;

            _checkInvalidDimension(newDimension);
            TNum* tmp = (TNum*)::realloc(_p, newDimension * sizeof(TNum));

            MemoryAllocationException::CheckNull(tmp);

            _p = tmp;

            if (newDimension > _dimension) {
                TNum* p = _p + _dimension;
                TNum* e = _p + newDimension;

                while (p != e) {
                    *p = value;
                    ++p;
                }
            }

            _dimension = newDimension;
        }

        /// @brief 最大値
        [[nodiscard]]
        TNum MaxValue() const noexcept
        {
            TNum* p = begin();
            TNum* e = end();

            TNum maxValue = *p;
            ++p;

            while (p != e) {
                if (*p > maxValue) maxValue = *p;
                ++p;
            }

            return maxValue;
        }

        /// @brief 最小値
        [[nodiscard]]
        TNum MinValue() const noexcept
        {
            TNum* p = begin();
            TNum* e = end();

            TNum minValue = *p;
            ++p;

            while (p != e) {
                if (*p < minValue) minValue = *p;
                ++p;
            }

            return minValue;
        }

        /// @brief ベクトルの長さの２乗
        [[nodiscard]]
        TNum SquareMagnitude() const noexcept
        {
            TNum sMagnitude{};

            for (TNum const& value : *this) {
                sMagnitude += value * value;
            }

            return sMagnitude;
        }

        /// @brief 要素の合計を取得
        /// @return 要素の合計
        [[nodiscard]] TNum Sum() const noexcept
        {
            TNum value{};

            for (TNum const& v : *this) {
                value += v;
            }

            return value;
        }

        /// @brief 別のオブジェクトと要素を交換
        /// @param right 交換するオブジェクト
        void Swap(DynamicVector& right)
        {
            TNum* pTmp = _p;
            ssize_t tDimension = _dimension;

            _p = right._p;
            _dimension = right._dimension;

            right._p = pTmp;
            right._dimension = tDimension;
        }

        [[nodiscard]] String ToString() const
        {
            ::std::ostringstream wsout;

            wsout << "[ ";

            for (ssize_t i = 0; i < _dimension; ++i) {
                wsout << _p[i];

                if (i == _dimension - 1) wsout << ' ';
                else wsout << ", ";
            }
            wsout << ']';

            return String::FromAscii(wsout.str());
        }

        void X(TNum value) { At(0) = value; }
        [[nodiscard]] TNum& X() { return At(0); }
        [[nodiscard]] TNum const& X() const { return At(0); }

        void Y(TNum value) { At(1) = value; }
        [[nodiscard]] TNum& Y() { return At(1); }
        [[nodiscard]] TNum const& Y() const { return At(1); }

        void Z(TNum value) { At(2) = value; }
        [[nodiscard]] TNum& Z() { return At(2); }
        [[nodiscard]] TNum const& Z() const { return At(2); }

        private:
        TNum* _p;
        ssize_t _dimension;

        static void _checkInvalidDimension(ssize_t dimension) { if (dimension <= 0) [[unlikely]] throw InvalidArgumentException(u"DynamicVectorの次元に正でない値が指定されました"); }

    };
}

#endif //!KONGKONG_NUMERIC_DYNAMICVECTOR_H
