#include "device.h"

Device::Device(std::string_view name, size_t io_count)
    : m_name(name), m_io_count(io_count) {}

std::string Device::DeviceName() const { return m_name; }
size_t Device::IOCount() const { return m_io_count; }
