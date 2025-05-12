#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAYBASE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAYBASE_H

#include "Base.h"
#include "Kongkong.Collections.Turbo._fastCollection.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct _fastArrayBase : public _fastCollection {

        friend bool operator==(_fastArrayBase const& left, _fastArrayBase const& right) noexcept;
        friend bool operator!=(_fastArrayBase const& left, _fastArrayBase const& right) noexcept;

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] constexpr T& operator[] (ssize_t index) noexcept { return _p[index]; }
        [[nodiscard]] constexpr T const& operator[] (ssize_t index) const noexcept { return _p[index]; }

        [[nodiscard]] constexpr T* begin() noexcept { return _p; }
        [[nodiscard]] constexpr const T* begin() const noexcept { return _p; }
        [[nodiscard]] constexpr T* end() noexcept { return _p + _length; }
        [[nodiscard]] constexpr const T* end() const noexcept { return _p + _length; }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]]
        T& At(ssize_t index)
        {
            CollectionHelper::CheckIndex(index, _length);
            return _p[index];
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T const& At(ssize_t index) const
        {
            CollectionHelper::CheckIndex(index, _length);
            return _p[index];
        }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        constexpr bool Contains(T const& value) const noexcept
        {
            auto p = _p;
            auto end = p + _length;

            while (p != end) {
                if (*p == value) return true;
                p++;
            }

            return false;
        }

        /// @brief 配列へのポインター
        [[nodiscard]] constexpr T* Data() noexcept { return _p; }
        [[nodiscard]] constexpr const T* Data() const noexcept { return _p; }

        /// @brief 最後の要素を取得
        [[nodiscard]] constexpr T& GetBackUnsafe() noexcept { return _p[_length - 1]; }
        [[nodiscard]] constexpr T const& GetBackUnsafe() const noexcept { return _p[_length - 1]; }

        /// @brief 最初の要素を取得
        [[nodiscard]] constexpr T& GetFrontUnsafe() noexcept { return *_p; }
        [[nodiscard]] constexpr T const& GetFrontUnsafe() const noexcept { return *_p; }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        constexpr ssize_t IndexOf(T const& value) const noexcept
        {
            auto p = _p;
            auto end = p + _length;

            while (p != end) {
                if (*p == value) return p - _p;
                p++;
            }

            return CollectionHelper::NotFound();
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        constexpr const T* Pointer() const noexcept { return _p; }

        protected:
        T* _p;

        void _destroy() noexcept
        {
            if (this->_p == nullptr) return;

            auto p = this->_p;
            auto end = p + this->_length;

            while (p != end) {
                p->~T();
                p++;
            }

            std::free(this->_p);
        }

        private:

        _fastArrayBase() = default;
        constexpr _fastArrayBase(ssize_t length) noexcept : _fastCollection(length), _p(nullptr) {}
        constexpr _fastArrayBase(ssize_t length, T* p) noexcept : _fastCollection(length), _p(p) {}

        friend FastArray<T>;
        friend FastArrayList<T>;
        friend ArrayHelper;
    };

    template <class T>
    [[nodiscard]]
    bool operator==(_fastArrayBase<T> const& left, _fastArrayBase<T> const& right) noexcept
    {
        if (left._length != right._length) return false;

        for (ssize_t i = 0; i < left._length; i++) {
            if (left._p[i] != right._p[i]) return false;
        }

        return true;
    }

    template <class T>
    [[nodiscard]]
    bool operator!=(_fastArrayBase<T> const& left, _fastArrayBase<T> const& right) noexcept
    {
        return !(left == right);
    }
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAYBASE_H
