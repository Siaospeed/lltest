#pragma once

#include <ll/api/plugin/NativePlugin.h>

namespace plugin {

class Plugin {
public:
    explicit Plugin(ll::plugin::NativePlugin& self);

    Plugin(Plugin&&)                 = delete;
    Plugin(const Plugin&)            = delete;
    Plugin& operator=(Plugin&&)      = delete;
    Plugin& operator=(const Plugin&) = delete;

    ~Plugin(); // NOLINT(performance-trivially-destructible)

    static Plugin& getInstance();

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const;

    /// @return True if the plugin is loaded successfully.
    bool load();

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

private:
    ll::plugin::NativePlugin& mSelf;
};

} // namespace plugin
