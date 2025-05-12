#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAY_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAY_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Turbo._fastArrayBase.h"
#include "Kongkong.Collections.Turbo._fastArrayMethods.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Algorithms.Range.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastArray : public ValueType, public _fastArrayBase<T>, public _fastArrayMethods {

        /// @brief 要素数を指定して作成
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastArray(ssize_t length) requires ::std::default_initializable<T>
            : _fastArrayBase<T>(length)
        {
            CollectionHelper::CheckLength(length);

            this->_p = (T*)::malloc(sizeof(T) * length);

            MemoryAllocationException::CheckNull(this->_p);
            
            for (ssize_t i = 0; i < length; i++) {
                try {
                    new(this->_p + i) T();
                }
                catch (...) {
                    auto ex = ::std::current_exception();

                    for (ssize_t j = 0; j < i; j++) {
                        this->_p[j].~T();
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(ex);
                }
            }
        }

        /// @brief 要素数と初期値を指定して作成
        /// @param length 長さ
        /// @param defaultValue 初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastArray(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
            : _fastArrayBase<T>(length)
        {
            CollectionHelper::CheckLength(length);

            this->_p = (T*)::malloc(sizeof(T) * length);

            MemoryAllocationException::CheckNull(this->_p);
            
            for (ssize_t i = 0; i < length; i++) {
                try {
                    new(this->_p + i) T(defaultValue);
                }
                catch (...) {
                    auto ex = ::std::current_exception();

                    for (ssize_t j = 0; j < i; j++) {
                        this->_p[j].~T();
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(ex);
                }
            }
        }

        /// @brief 初期化リストから作成
        /// @param inil 初期化リスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        FastArray(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T>
            : _fastArrayBase<T>((ssize_t)inil.size(), (T*)::malloc(inil.size() * sizeof(T)))
        {
            MemoryAllocationException::CheckNull(this->_p);

            auto p = this->_p;

            for (T const& element : inil) {
                try {
                    new(p) T(element);
                }
                catch (...) {
                    auto ex = ::std::current_exception();
                    for (auto q = this->_p; q != p; q++) {
                        q->~T();
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(ex);
                }
                
                p++;
            }
        }

        FastArray(FastArray const& right) : _fastArrayBase<T>(right._length, (T*)::malloc(right._length * sizeof(T)))
        {
            MemoryAllocationException::CheckNull(this->_p);

            for (ssize_t i = 0; i < this->_length; i++) {
                try {
                    new (this->_p + i) T(*(right._p + i));
                }
                catch (...) {
                    auto pException = ::std::current_exception();

                    for (ssize_t j = 0; j < i; j++) {
                        this->_p[j].~T();
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(pException);
                }
            }
        }

        constexpr FastArray(FastArray&& right) noexcept : _fastArrayBase<T>(right._length, right._p)
        {
            right._p = nullptr;
        }

        FastArray& operator=(FastArray const& right)
        {
            return *this = FastArray(right);
        }

        FastArray& operator=(FastArray&& right) noexcept
        {
            this->_destroy();

            this->_p = right._p;
            this->_length = right._length;

            right._p = nullptr;

            return *this;
        }

        ~FastArray() { this->_destroy(); }

        /// @brief 最後の要素を取得
        [[nodiscard]] constexpr T& Back() noexcept { return this->_p[this->_length - 1]; }
        [[nodiscard]] constexpr T const& Back() const noexcept { return this->_p[this->_length - 1]; }

        /// @brief 最初の要素を取得
        [[nodiscard]] constexpr T& Front() noexcept { return *this->_p; }
        [[nodiscard]] constexpr T const& Front() const noexcept { return *this->_p; }

        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length) requires ::std::default_initializable<T>
        {
            CollectionHelper::CheckLength(length);

            if (length == this->_length) [[unlikely]] return;

            ssize_t i;

            if (length < this->_length) {
                for (i = length; i < this->_length; i++) {
                    this->_p[i].~T();
                }

                this->_length = length;

                return;
            }

            auto p = (T*)::malloc(length * sizeof(T));

            MemoryAllocationException::CheckNull(p);

            for (i = this->_length; i < length; i++) {
                try {
                    new(p + i) T();
                }
                catch (...) {
                    auto ex = ::std::current_exception();

                    for (ssize_t j = this->_length; j < i; j++) {
                        p[j].~T();
                    }

                    ::free(p);

                    ::std::rethrow_exception(ex);
                }
                
            }

            for (i = 0; i < this->_length; i++) {
                new(p + i) T(std::move(this->_p[i]));
            }

            ::free(this->_p);

            this->_p = p;
            this->_length = length;
        }
        
        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @param defaultValue 新たに追加される要素の初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
        {
            CollectionHelper::CheckLength(length);

            if (length == this->_length) [[unlikely]] return;

            ssize_t i;

            if (length < this->_length) {
                for (i = length; i < this->_length; i++) {
                    this->_p[i].~T();
                }

                this->_length = length;

                return;
            }

            auto p = (T*)::malloc(length * sizeof(T));

            MemoryAllocationException::CheckNull(p);

            for (i = this->_length; i < length; i++) {
                try {
                    new(p + i) T(defaultValue);
                }
                catch (...) {
                    auto ex = ::std::current_exception();

                    for (ssize_t j = this->_length; j < i; j++) {
                        p[j].~T();
                    }

                    ::free(p);

                    ::std::rethrow_exception(ex);
                }
                
            }

            for (i = 0; i < this->_length; i++) {
                new(p + i) T(std::move(this->_p[i]));
            }

            ::free(this->_p);

            this->_p = p;
            this->_length = length;
        }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept
        {
            if (this->_length == 1) [[unlikely]] return;

            Algorithms::Range::ReverseUnsafe(this->_length, this->_p);
        }

        private:
        constexpr FastArray(std::nullptr_t) noexcept : _fastArrayBase<T>(0, nullptr) {}

        friend FastThreadSafeArray<T>;
        friend ArrayHelper;
    };

    
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAY_H
