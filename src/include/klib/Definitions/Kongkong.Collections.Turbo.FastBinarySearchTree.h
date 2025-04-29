#ifndef KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.TreeNode.h"
#include "Kongkong.Collections.Turbo._fastBinarySearchTreeMethods.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.InvalidArgumentException.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct KONGKONG_INCOMPLETED_CLASS FastBinarySearchTree final : public ValueType, public _fastBinarySearchTreeMethods, public _fastCollection {

        constexpr FastBinarySearchTree() noexcept : _fastCollection(0), _root(nullptr) {}
        FastBinarySearchTree(std::initializer_list<T> const& inil) : FastBinarySearchTree()
        {
            try {
                Append(inil);
            }
            catch (...) {
                _deleteChild(_root);

                std::rethrow_exception(std::current_exception());
            }
            
        }

        FastBinarySearchTree(FastBinarySearchTree const& right) : _fastCollection(right._length), _root(nullptr)
        {
            if (this->_length == 0) return;

            _root = NEW TreeNode<T>(right._root->Value(), nullptr);

            MemoryAllocationException::CheckNull(_root);

            try {
                _copy(_root, right._root);
            }
            catch (...) {
                _deleteChild(_root);

                std::rethrow_exception(std::current_exception());
            }
        }

        constexpr FastBinarySearchTree(FastBinarySearchTree&& right) noexcept : _fastCollection(right._length), _root(right._root)
        {
            right._root = nullptr;
        }

        ~FastBinarySearchTree()
        {
            _deleteChild(_root);
        }

        /// @brief 木構造をコピー
        /// @attention 途中で例外がスローされた場合は何も変更しないよ！
        /// @param right コピー元
        /// @return *this
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        FastBinarySearchTree& operator=(FastBinarySearchTree const& right)
        {
            if (right._length == 0) {
                _deleteChild(_root);
                this->_length = right._length;
                _root = nullptr;
                return;
            }

            TreeNode<T>* root = NEW TreeNode<T>(right._root->Value(), nullptr);

            MemoryAllocationException::CheckNull(root);

            try {
                _copy(root, right._root);
            }
            catch (...) {
                _deleteChild(root);

                std::rethrow_exception(std::current_exception());
            }

            _deleteChild(_root);
            _root = root;
            this->_length = right._length;

            return *this;
        }

        FastBinarySearchTree& operator=(FastBinarySearchTree&& right) noexcept
        {
            _deleteChild(_root);

            this->_length = right._length;
            _root = right._root;

            right._root = nullptr;

            return *this;
        }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @return *this
        /// @throws MemoryAllocationException: 要素の作成に失敗したとき
        FastBinarySearchTree& operator+=(T const& value)
        {
            Append(value);
            return *this;
        }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @return *this
        /// @throws MemoryAllocationException: 要素の作成に失敗したとき
        FastBinarySearchTree& operator+=(T&& value)
        {
            Append(std::move(value));
            return *this;
        }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @throws MemoryAllocationException: 要素の作成に失敗したとき
        void Append(T const& value)
        {
            if (this->_length == 0) {
                _root = NEW TreeNode<T>(value, nullptr);
                MemoryAllocationException::CheckNull(_root);
                ++this->_length;
                return;
            }

            bool isRight;
            TreeNode<T>* parentNode = _appendFunc(_root, value, isRight);

            TreeNode<T>* node = NEW TreeNode<T>(value, parentNode);

            _appendFunc1(parentNode, node, isRight);

            ++this->_length;
        }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @throws MemoryAllocationException: 要素の作成に失敗したとき
        void Append(T&& value)
        {
            if (this->_length == 0) {
                _root = NEW TreeNode<T>(std::move(value), nullptr);
                MemoryAllocationException::CheckNull(_root);
                ++this->_length;
                return;
            }

            bool isRight;
            TreeNode<T>* parentNode = _appendFunc(_root, value, isRight);

            TreeNode<T>* node = NEW TreeNode<T>(std::move(value), parentNode);

            _appendFunc1(parentNode, node, isRight);

            ++this->_length;
        }

        void Append(std::initializer_list<T> const& inil)
        {
            for (T const& v : inil) {
                Append(v);
            }
        }

        /// @brief 要素を検索
        /// @param value 検索する値
        /// @return 値が見つかったかどうか
        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            return _contains(_root, value);
        }

        bool Remove(T const& value) noexcept
        {
            if (_remove(_root, value, _root)) {
                --this->_length;
                return true;
            }

            return false;
        }

        private:

        TreeNode<T>* _root;

        /// @brief 追加する要素の親を決定
        /// @param node ルート
        /// @param value 追加する値
        /// @param isRight 右側に追加するかどうかを取得
        /// @return 追加する要素の親
        /// @throws InvalidArgumentException: 値が既に存在しているとき
        static TreeNode<T>* _appendFunc(TreeNode<T>* node, T const& value, bool& isRight)
        {
            //C++23 [[assume(node != nullptr)]];

            T const& nodeValue = node->Value();

            if (nodeValue == node) [[unlikely]] throw InvalidArgumentException(u"この値は既に存在します");

            bool isLeft = nodeValue < value;

            TreeNode<T>* tmp = isLeft ? node->Left() : node->Right();

            if (tmp == nullptr) {
                isRight = !isLeft;
                return node;
            }

            return _appendFunc(tmp, value, isRight);
        }

        static void _appendFunc1(TreeNode<T>* parent, TreeNode<T>* child, bool isRight) noexcept
        {
            MemoryAllocationException::CheckNull(child);

            if (isRight) parent->Right(child);
            else parent->Left(child);
        }

        static bool _contains(TreeNode<T>* node, T const& value) noexcept
        {
            if (node == nullptr) return false;

            T const& nodeValue = node->Value();

            if (nodeValue == value) return true;

            return _contains(nodeValue < value ? node->Left() : node->Right(), value);
        }

        static void _copy(TreeNode<T>* target, TreeNode<T>* fromNode)
        {
            //C++23 [[assume(target != nullptr)]];
            //C++23 [[assume(fromNode != nullptr)]];

            TreeNode<T>* fromLeftNode = fromNode->Left();
            TreeNode<T>* fromRightNode = fromNode->Right();

            TreeNode<T>* newNode;

            if (fromLeftNode != nullptr) {
                newNode = NEW TreeNode<T>(fromLeftNode->Value(), target);
                MemoryAllocationException::CheckNull(newNode);

                target->Left(newNode);

                _copy(newNode, fromLeftNode);
            }

            if (fromRightNode != nullptr) {
                newNode = NEW TreeNode<T>(fromRightNode->Value(), target);
                MemoryAllocationException::CheckNull(newNode);

                target->Right(newNode);

                _copy(newNode, fromRightNode);
            }
        }

        static void _deleteChild(TreeNode<T>* node) noexcept
        {
            if (node == nullptr) return;

            _deleteChild(node->Left());
            _deleteChild(node->Right());

            delete node;
        }

        static bool _remove(TreeNode<T>* node, T const& value, TreeNode<T>*& root) noexcept
        {
            if (node == nullptr) return false;

            T const& nodeValue = node->Value();

            //両方の子ノードがある場合は右側を結合
            if (nodeValue == value) {
                TreeNode<T>* parent = node->Parent();
                TreeNode<T>* left = node->Left();
                TreeNode<T>* right = node->Right();

                if (right == nullptr) {
                    if (left != nullptr) left->Parent(parent);

                    if (parent == nullptr) {
                        root = left;
                    }
                    else {
                        if (node->IsLeftNodeUnsafe()) parent->Left(left);
                        else parent->Right(left);
                    }
                }
                else {
                    if (parent == nullptr) {
                        right->Parent(nullptr);
                        root = right;
                    }
                    else {
                        right->Parent(parent);
                        if (node->IsLeftNodeUnsafe()) {
                            parent->Left(right);
                        }
                        else {
                            parent->Right(right);
                        }
                    }
                    
                    if (left != nullptr) {
                        TreeNode<T>* rLeft = right;

                        //右側の一番深い左のノードを取得
                        while (true) {
                            TreeNode<T>* tmp = rLeft->Left();

                            if (tmp == nullptr) break;

                            rLeft = tmp;
                        }
                        
                        rLeft->Left(left);
                        left->Parent(rLeft);
                    }
                }
                
                delete node;
                return true;
            }

            return _remove(nodeValue < value ? node->Left() : node->Right(), value, root);
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREE_H
