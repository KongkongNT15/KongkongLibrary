#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODE_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    class NSXmlNode : public NSObject {
        public:

        /// @brief nullptrとして作成
        constexpr NSXmlNode(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 指定した番号の子要素を取得
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws InvalidOperationException: 子要素がない時
        /// @throws ArgumentOutOfRangeException: indexが範囲外の時
        [[nodiscard]]
        NSXmlNode ChildAtIndex(ssize_t index) const;

        [[nodiscard]]
        ssize_t ChildCount() const;

        /// @brief このノードの子要素
        /// @attention 子要素がない場合はnullptrになるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        Collections::ArrayWrapper<NSXmlNode> Children() const;

        /// @brief このノードを親ノードから切り離します
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Detach() const;

        /// @brief このノードの要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        ssize_t Index() const;

        /// @brief このノードの種類
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNodeKind Kind() const;

        /// @brief ツリー内のこのノードのネストレベル
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        ssize_t Level() const;

        /// @brief ローカル名
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        NSString LocalName() const;

        /// @brief ノードの名前
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        NSString Name() const;

        /// @brief 名前を変更
        /// @param name 新たなる名前
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: nameがnullptrのとき
        void Name(NSString const& name) const;

        /// @brief ドキュメントの次のノードを取得
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNode NextNode() const;

        /// @brief 次の兄弟ノードを取得
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNode NextSibling() const;

        /// @brief このノードのオブジェクト値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSObject ObjectValue() const;

        /// @brief コンテンツを設定
        /// @param newValue 設定する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: newValueがnullptrのとき
        void ObjectValue(NSObject const& newValue) const;

        /// @brief 親ノードにアクセス
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNode Parent() const;

        /// @brief ドキュメントの1つ前のノードを取得
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNode PreviousNode() const;

        /// @brief 1つ前の兄弟ノードを取得
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlNode PreviousSibling() const;

        /// @brief 最上位のドキュメントオブジェクトにアクセス
        /// @attention ない場合はnullptrになるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSXmlDocument RootDocument() const;

        /// @brief コンテンツを文字列として取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        NSString StringValue() const;

        /// @brief コンテンツを設定
        /// @param newValue 設定する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentNullException: newValueがnullptrのとき
        void StringValue(NSString const& newValue) const;

        /// @brief ソースのURI
        /// @attention 設定されていない場合はnullptrになるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString Uri() const;

        /// @brief URIをnullptrに設定
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        void Uri(std::nullptr_t) const;

        /// @brief URIを設定
        /// @param value 設定する値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Uri(NSString const& value) const;

        /// @brief このノードの文字列表現を取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        NSString XmlString() const;

        /// @brief ノードを識別するプロパティ
        /// @attention nullptrの場合があるよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき 
        [[nodiscard]]
        NSString XPath() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODE_H
