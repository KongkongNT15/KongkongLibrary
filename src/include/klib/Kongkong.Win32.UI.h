#ifndef KONGKONG_WIN32_UI_H
#define KONGKONG_WIN32_UI_H

#include "Definitions/Base.h"

//Windowsのみ
#ifdef KONGKONG_ENV_WINDOWS

#include "Definitions/Kongkong.Win32.UI.Button.h"
#include "Definitions/Kongkong.Win32.UI.ButtonBase.h"
#include "Definitions/Kongkong.Win32.UI.Color.h"
#include "Definitions/Kongkong.Win32.UI.Control.h"
#include "Definitions/Kongkong.Win32.UI.DpiChangedEventArgs.h"
#include "Definitions/Kongkong.Win32.UI.ElementTheme.h"
#include "Definitions/Kongkong.Win32.UI.HorizontalAlignment.h"
#include "Definitions/Kongkong.Win32.UI.PaintRequestedEventArgs.h"
#include "Definitions/Kongkong.Win32.UI.Rect.h"
#include "Definitions/Kongkong.Win32.UI.Size.h"
#include "Definitions/Kongkong.Win32.UI.SizeChangedEventArgs.h"
#include "Definitions/Kongkong.Win32.UI.SystemBackDrop.h"
#include "Definitions/Kongkong.Win32.UI.TextBlock.h"
#include "Definitions/Kongkong.Win32.UI.Thickness.h"
#include "Definitions/Kongkong.Win32.UI.TitleBar.h"
#include "Definitions/Kongkong.Win32.UI.UIElement.h"
#include "Definitions/Kongkong.Win32.UI.VerticalAlignment.h"
#include "Definitions/Kongkong.Win32.UI.Window.h"
#include "Definitions/Kongkong.Win32.UI.WindowActivate.h"
#include "Definitions/Kongkong.Win32.UI.WindowActivatedEventArgs.h"
#include "Definitions/Kongkong.Win32.UI.WindowClosingEventArgs.h"
#include "Definitions/Kongkong.Win32.UI.WindowCornerPreference.h"
#include "Definitions/Kongkong.Win32.UI.WindowCreatingEventArgs.h"

#endif //!KONGKONG_ENV_WINDOWS

#endif //!KONGKONG_WIN32_UI_H
