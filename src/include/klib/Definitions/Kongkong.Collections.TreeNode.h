#ifndef KONGKONG_COLLECTIONS_TREENODE_H
#define KONGKONG_COLLECTIONS_TREENODE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections._treeNodeMethods.h"

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    struct TreeNode final : public ValueType, public _treeNodeMethods {

        TreeNode() requires std::default_initializable<T> : _parent(), _left(), _right(), _value() {}
        TreeNode(TreeNode* parent, TreeNode* left, TreeNode* right) requires std::default_initializable<T> : _parent(parent), _left(left), _right(right), _value() {}
        TreeNode(T const& value, TreeNode* parent) requires std::copy_constructible<T> : _parent(parent), _left(), _right(), _value(value) {}
        TreeNode(T&& value, TreeNode* parent) noexcept requires std::move_constructible<T> : _parent(parent), _left(), _right(), _value(std::move(value)) {}
        TreeNode(T const& value, TreeNode* parent, TreeNode* left, TreeNode* right) requires std::copy_constructible<T> : _parent(parent), _left(left), _right(right), _value(value) {}
        TreeNode(T&& value, TreeNode* parent, TreeNode* left, TreeNode* right) noexcept requires std::move_constructible<T> : _parent(parent), _left(left), _right(right), _value(std::move(value)) {}

        [[nodiscard]] constexpr bool HasParent() const noexcept { return _parent != nullptr; }

        [[nodiscard]]
        bool IsLeftNode() const noexcept
        {
            if(_parent == nullptr) return false;

            return _parent->_left == this;
        }

        [[nodiscard]]
        bool IsLeftNodeUnsafe() const noexcept { return _parent->_left == this; }

        [[nodiscard]]
        constexpr bool IsRightNode() const noexcept
        {
            if(_parent == nullptr) return false;

            return _parent->_right == this;
        }

        [[nodiscard]]
        bool IsRightNodeUnsafe() const noexcept { return _parent->_right == this; }

        [[nodiscard]] constexpr TreeNode* Left() noexcept { return _left; }
        [[nodiscard]] constexpr const TreeNode* Left() const noexcept { return _left; }

        constexpr void Left(std::nullptr_t) noexcept { _left = nullptr; }
        constexpr void Left(TreeNode* value) noexcept { _left = value; }

        [[nodiscard]] constexpr TreeNode* Parent() noexcept { return _parent; }
        [[nodiscard]] constexpr const TreeNode* Parent() const noexcept { return _parent; }

        constexpr void Parent(std::nullptr_t) noexcept { _parent = nullptr; }
        constexpr void Parent(TreeNode* value) noexcept { _parent = value; }

        [[nodiscard]] constexpr TreeNode* Right() noexcept { return _right; }
        [[nodiscard]] constexpr const TreeNode* Right() const noexcept { return _right; }

        constexpr void Right(std::nullptr_t) noexcept { _right = nullptr; }
        constexpr void Right(TreeNode* value) noexcept { _right = value; }

        [[nodiscard]] T& Value() noexcept { return _value; }
        [[nodiscard]] T const& Value() const noexcept { return _value; }

        void Value(T const& value) { _value = value; }
        void Value(T&& value) noexcept { _value = std::move(value); }

        private:

        T _value;

        TreeNode* _parent;
        TreeNode* _left;
        TreeNode* _right;
    };
}

#endif //!KONGKONG_COLLECTIONS_TREENODE_H
