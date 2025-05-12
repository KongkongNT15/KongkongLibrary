//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    void Sound::Beep(uint16_t frequency, uint32_t milliseconds)
    {
        if (::Beep(frequency, milliseconds) == 0) [[unlikely]] throw HResultException();
    }

    void Sound::Play(SoundKind kind, bool async)
    {
        const wchar_t* wcs;

        switch (kind) {
            case SoundKind::AppGPFault:                 wcs = L"AppGPFault";                   break;
            case SoundKind::CCSelect:                   wcs = L"CCSelect";                     break;
            case SoundKind::ChangeTheme:                wcs = L"ChangeTheme";                  break;
            case SoundKind::Close:                      wcs = L"Close";                        break;
            case SoundKind::CriticalBatteryAlarm:       wcs = L"CriticalBatteryAlarm";         break;
            case SoundKind::Default:                    wcs = L".Default";                     break;
            case SoundKind::DeviceConnect:              wcs = L"DeviceConnect";                break;
            case SoundKind::DeviceDisconnect:           wcs = L"DeviceDisconnect";             break;
            case SoundKind::DeviceFail:                 wcs = L"DeviceFail";                   break;
            case SoundKind::FaxBeep:                    wcs = L"FaxBeep";                      break;
            case SoundKind::LowBatteryAlarm:            wcs = L"LowBatteryAlarm";              break;
            case SoundKind::MailBeep:                   wcs = L"MailBeep";                     break;
            case SoundKind::Maximize:                   wcs = L"Maximize";                     break;
            case SoundKind::MenuCommand:                wcs = L"MenuCommand";                  break;
            case SoundKind::MenuPopup:                  wcs = L"MenuPopup";                    break;
            case SoundKind::Minimize:                   wcs = L"Minimize";                     break;
            case SoundKind::MessageNudge:               wcs = L"MessageNudge";                 break;
            case SoundKind::NotificationDefault:        wcs = L"Notification.Default";         break;
            case SoundKind::NotificationIM:             wcs = L"Notification.IM";              break;
            case SoundKind::NotificationLoopingAlarm:   wcs = L"Notification.Looping.Alarm";   break;
            case SoundKind::NotificationLoopingAlarm2:  wcs = L"Notification.Looping.Alarm2";  break;
            case SoundKind::NotificationLoopingAlarm3:  wcs = L"Notification.Looping.Alarm3";  break;
            case SoundKind::NotificationLoopingAlarm4:  wcs = L"Notification.Looping.Alarm4";  break;
            case SoundKind::NotificationLoopingAlarm5:  wcs = L"Notification.Looping.Alarm5";  break;
            case SoundKind::NotificationLoopingAlarm6:  wcs = L"Notification.Looping.Alarm6";  break;
            case SoundKind::NotificationLoopingAlarm7:  wcs = L"Notification.Looping.Alarm7";  break;
            case SoundKind::NotificationLoopingAlarm8:  wcs = L"Notification.Looping.Alarm8";  break;
            case SoundKind::NotificationLoopingAlarm9:  wcs = L"Notification.Looping.Alarm9";  break;
            case SoundKind::NotificationLoopingAlarm10: wcs = L"Notification.Looping.Alarm10"; break;
            case SoundKind::NotificationLoopingCall:    wcs = L"Notification.Looping.Call";    break;
            case SoundKind::NotificationLoopingCall2:   wcs = L"Notification.Looping.Call2";   break;
            case SoundKind::NotificationLoopingCall3:   wcs = L"Notification.Looping.Call3";   break;
            case SoundKind::NotificationLoopingCall4:   wcs = L"Notification.Looping.Call4";   break;
            case SoundKind::NotificationLoopingCall5:   wcs = L"Notification.Looping.Call5";   break;
            case SoundKind::NotificationLoopingCall6:   wcs = L"Notification.Looping.Call6";   break;
            case SoundKind::NotificationLoopingCall7:   wcs = L"Notification.Looping.Call7";   break;
            case SoundKind::NotificationLoopingCall8:   wcs = L"Notification.Looping.Call8";   break;
            case SoundKind::NotificationLoopingCall9:   wcs = L"Notification.Looping.Call9";   break;
            case SoundKind::NotificationLoopingCall10:  wcs = L"Notification.Looping.Call10";  break;
            case SoundKind::NotificationMail:           wcs = L"Notification.Mail";            break;
            case SoundKind::NotificationProximity:      wcs = L"Notification.Proximity";       break;
            case SoundKind::NotificationReminder:       wcs = L"Notification.Reminder";        break;
            case SoundKind::NotificationSMS:            wcs = L"Notification.SMS";             break;
            case SoundKind::Open:                       wcs = L"Open";                         break;
            case SoundKind::PrintComplete:              wcs = L"PrintComplete";                break;
            case SoundKind::ProximityConnection:        wcs = L"ProximityConnection";          break;
            case SoundKind::RestoreDown:                wcs = L"RestoreDown";                  break;
            case SoundKind::RestoreUp:                  wcs = L"RestoreUp";                    break;
            case SoundKind::ShowBand:                   wcs = L"ShowBand";                     break;
            case SoundKind::SystemAsterisk:             wcs = L"SystemAsterisk";               break;
            case SoundKind::SystemExit:                 wcs = L"SystemExit";                   break;
            case SoundKind::SystemExclamation:          wcs = L"SystemExclamation";            break;
            case SoundKind::SystemHand:                 wcs = L"SystemHand";                   break;
            case SoundKind::SystemNotification:         wcs = L"SystemNotification";           break;
            case SoundKind::SystemQuestion:             wcs = L"SystemQuestion";               break;
            case SoundKind::SystemStart:                wcs = L"SystemStart";                  break;
            case SoundKind::WindowsLogoff:              wcs = L"WindowsLogoff";                break;
            case SoundKind::WindowsLogon:               wcs = L"WindowsLogon";                 break;
            case SoundKind::WindowsUAC:                 wcs = L"WindowsUAC";                   break;
            case SoundKind::WindowsUnlock:              wcs = L"WindowsUnlock";                break;
            default: [[unlikely]] throw InvalidArgumentException(u"無効な値が渡されました");
        }

        constexpr DWORD syncFlag = SND_ALIAS | SND_SYNC | SND_NODEFAULT;
        constexpr DWORD asyncFlag = SND_ALIAS | SND_ASYNC | SND_NODEFAULT;

        if (::PlaySoundW(wcs, nullptr, async ? asyncFlag : syncFlag) == 0) [[unlikely]] throw HResultException();
    }

    void Sound::PlayMessageBeep(MessageBeepKind kind)
    {
        if (::MessageBeep((UINT)kind) == 0) [[unlikely]] throw HResultException();
    }

    bool Sound::PlayMessageBeepUnsafe(MessageBeepKind kind) noexcept
    {
        return (bool)::MessageBeep((UINT)kind);
    }

    void Sound::PlayWave(const char16_t* path, bool async)
    {
        constexpr DWORD syncFlag = SND_FILENAME | SND_SYNC | SND_NODEFAULT;
        constexpr DWORD asyncFlag = SND_FILENAME | SND_ASYNC | SND_NODEFAULT;

        if (::PlaySoundW((const wchar_t*)path, nullptr, async ? asyncFlag : syncFlag) == 0) [[unlikely]] throw HResultException();
    }

    void Sound::PlayWave(String const& path, bool async)
    {
        PlayWave(path.c_str(), async);
    }
}
