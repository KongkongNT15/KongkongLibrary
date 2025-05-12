#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLELEMENT_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLELEMENT_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlNode.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    class NSXmlElement : public NSXmlNode {
        public:

        [[nodiscard]]
        static NSXmlElement FromUriName(NSString const& name, NSString const& uri);

        /// @brief ふぁ！？っく
        NSXmlElement(::std::nullptr_t, ::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        NSXmlElement(::std::nullptr_t, NSString const&) = delete;

        /// @brief 名前を指定して作成
        /// @param name 名前
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlElement(NSString const& name);

        /// @brief 名前とテキストを指定して作成
        /// @param name 名前
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlElement(NSString const& name, ::std::nullptr_t);

        /// @brief 名前とテキストを指定して作成
        /// @param name 名前
        /// @param stringValue テキスト
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlElement(NSString const& name, NSString const& stringValue);

        /// @brief nullptrとして作成
        constexpr NSXmlElement(std::nullptr_t) noexcept : NSXmlNode(nullptr) {}

        /// @brief 属性を追加
        /// @param attribute 属性
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: attributeがnullptrのとき
        void AddAttribute(NSXmlAttribute const& attribute) const;

        /// @brief ふぁ！？っく 
        void AddChild(std::nullptr_t) const = delete;

        /// @brief 要素を追加
        /// @param node 追加する要素
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nodeがnullptrのとき
        /// @throws InvalidArgumentException: nodeが*thisの時
        /// @throws InvalidArgumentException: nodeが親ノードの時
        void AddChild(NSXmlNode const& node) const;

        /// @brief 属性リスト
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        Collections::ArrayWrapper<NSXmlAttribute> Attributes() const;

        /// @brief 全ての属性を削除
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        void Attributes(std::nullptr_t) const;

        /// @brief 属性を総入れ替え
        /// @param attributes 属性リスト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Attributes(Collections::ArrayWrapper<NSXmlAttribute> const& attributes) const;

        /// @brief 子要素を全て削除
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        void Children(std::nullptr_t) const;

        /// @brief Childrenを設定
        /// @attention 親を子要素にしようとするとアプリケーションが固まるよ！
        /// @param children 設定するオブジェクト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Children(Collections::ArrayWrapper<NSXmlNode> const& children) const;

        /// @brief ふぁ！？っく
        NSXmlAttribute GetAttribute(std::nullptr_t) const = delete;

        /// @brief 名前に一致する属性オブジェクトを取得
        /// @param name 名前
        /// @return 指定した名前に一致する属性オブジェクト
        /// @return 見つからない場合はnullptr
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nameがnullptrのとき
        [[nodiscard]]
        NSXmlAttribute GetAttribute(NSString const& name) const;

        /// @brief ふぁ！？っく
        Collections::ArrayWrapper<NSXmlElement> GetElements(std::nullptr_t) const = delete;

        /// @brief 指定した名前に一致する子要素リストを取得
        /// @attention 見つからない場合は空のリストになるよ！
        /// @param name 名前
        [[nodiscard]]
        Collections::ArrayWrapper<NSXmlElement> GetElements(NSString const& name) const;

        /// @brief 要素を指定した位置に追加
        /// @param index 要素番号
        /// @param node 追加する要素
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nodeがnullptrのとき
        /// @throws InvalidArgumentException: nodeが*thisの時
        /// @throws InvalidArgumentException: nodeが親ノードの時
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        void InsertChild(ssize_t index, NSXmlNode const& node) const;

        /// @brief 要素を指定した位置に追加
        /// @attention 親を子要素に追加しようとするとするとアプリケーションが固まるよ！
        /// @param index 要素番号
        /// @param children 追加する要素のリスト
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: childrenがnullptrのとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        void InsertChildren(ssize_t index, Collections::ArrayWrapper<NSXmlNode> const& children) const;

        /// @brief ふぁ！？っく
        void RemoveAttributeForName(std::nullptr_t) const = delete;

        /// @brief 指定した属性を削除
        /// @attention 指定した属性が見つからない場合は何もしないよ！
        /// @param name 属性名
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nameがnullptrのとき
        void RemoveAttributeForName(NSString const& name) const;

        /// @brief 指定した要素番号の要素を削除
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        void RemoveChildAtIndex(ssize_t index) const;

        /// @brief 要素を置き換え
        /// @param index 要素番号
        /// @param node 置き換え後の要素
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nodeがnullptrのとき
        /// @throws InvalidArgumentException: nodeが*thisの時
        /// @throws InvalidArgumentException: nodeが親ノードの時
        void ReplaceChildAtIndex(ssize_t index, NSXmlNode const& node) const;

        private:

        void* _checkAddChild(NSXmlNode const& node) const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLELEMENT_H
