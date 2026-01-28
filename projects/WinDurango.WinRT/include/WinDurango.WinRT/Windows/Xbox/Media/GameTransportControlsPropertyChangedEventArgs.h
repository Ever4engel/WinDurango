#pragma once
#include <Windows.h>
#include "Windows.Xbox.Media.GameTransportControlsPropertyChangedEventArgs.g.h"

namespace winrt::Windows::Xbox::Media::implementation {
    struct GameTransportControlsPropertyChangedEventArgs : GameTransportControlsPropertyChangedEventArgsT<GameTransportControlsPropertyChangedEventArgs> {
        GameTransportControlsPropertyChangedEventArgs() = default;
        GameTransportControlsProperty Property();
    };
}