#pragma once
#include <string>

class Device {
public:
    Device(std::string_view name, size_t io_count);
    virtual ~Device() = default;
    virtual std::string DeviceName() const;
    virtual size_t IOCount() const;
    virtual bool IsAvailable() const = 0;

private:
    std::string m_name;
    size_t m_io_count;
};
