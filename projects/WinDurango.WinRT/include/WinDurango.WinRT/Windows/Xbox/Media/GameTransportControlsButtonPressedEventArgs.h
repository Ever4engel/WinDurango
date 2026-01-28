#pragma once
#include <Windows.h>
#include "Windows.Xbox.Media.GameTransportControlsButtonPressedEventArgs.g.h"

namespace winrt::Windows::Xbox::Media::implementation {
    struct GameTransportControlsButtonPressedEventArgs : GameTransportControlsButtonPressedEventArgsT<GameTransportControlsButtonPressedEventArgs> {
        GameTransportControlsButtonPressedEventArgs() = default;
        GameTransportControlsButton Button();
    };
}