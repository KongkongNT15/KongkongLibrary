#ifndef KONGKONG_WIN32_THRADING_EVENT_H
#define KONGKONG_WIN32_THRADING_EVENT_H

#include "Base.h"
#include "Kongkong.Win32.Threading.WaitHandle.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class Event final : public WaitHandle {
        public:

        explicit Event(bool isManualReset, bool isSet);
        explicit Event(std::nullptr_t, bool isManualReset, bool isSet);
        explicit Event(const char16_t* name, bool isManualReset, bool isSet);
        explicit Event(String const& name, bool isManualReset, bool isSet);
        explicit Event(bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa);
        explicit Event(std::nullptr_t, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa);
        explicit Event(const char16_t* name, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa);
        explicit Event(String const& name, bool isManualReset, bool isSet, ::SECURITY_ATTRIBUTES& sa);

        /// @brief nullptrとして作成
        constexpr Event(std::nullptr_t) noexcept : WaitHandle(nullptr) {}

        void Reset() const;
        bool ResetUnsafe() const noexcept;

        void Set() const;
        bool SetUnsafe() const noexcept;

        private:

        Event(const char16_t* name, bool isManualReset, bool isSet, ::LPSECURITY_ATTRIBUTES sa);

        static String _toString(Handle const& handle);

        friend String Handle::ToString() const;
    };
}

#endif //!KONGKONG_WIN32_THRADING_EVENT_H
