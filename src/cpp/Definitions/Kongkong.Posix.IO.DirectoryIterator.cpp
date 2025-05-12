//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO::IMPLEMENTATION
{
    DirectoryIterator::DirectoryIterator() : _entry(nullptr, ""), _dir(nullptr)
    {
    }

    DirectoryIterator::DirectoryIterator(::dirent* dirent, ::DIR* dir, const char* directoryName) :
        _entry(dirent, directoryName),
        _dir(dir)
    {
    }

    DirectoryIterator::~DirectoryIterator()
    {
        if (_dir != nullptr) ::closedir(_dir);
    }

    bool DirectoryIterator::IsNotEqual(ConstIterator<DirectoryEntry> const& right) const
    {
        if (!right.Is<DirectoryIterator>()) [[unlikely]] return false;

        DirectoryIterator const& value = dynamic_cast<DirectoryIterator const&>(right);

        return _entry.Handle() != value._entry.Handle();
    }

    void DirectoryIterator::Increment()
    {
        ::dirent* p = ::readdir(_dir);
        _entry.Handle(p);
    }

    ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<DirectoryEntry> DirectoryIterator::Increment(int)
    {
        throw InvalidOperationException(u"前置インクリメントを使用してください");
        //DirectoryIterator* p = new DirectoryIterator(*this);
        //Increment();

        //return ::KONGKONG_NAMESPACE::Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<DirectoryEntry>, DirectoryIterator>(p);
    }

    String DirectoryIterator::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::DirectoryIterator");
    }
}

namespace KONGKONG_NAMESPACE::Posix::IO
{
    DirectoryIterator::DirectoryIterator() : ConstIterator<DirectoryEntry>(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    DirectoryIterator::DirectoryIterator(::dirent* dirent, ::DIR* dir, const char* directoryName) : ConstIterator<DirectoryEntry>(nullptr)
    {
        _setInstance(NEW ImplType(dirent, dir, directoryName));
    }
}
