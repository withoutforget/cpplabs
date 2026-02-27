#include "unary_binary_device.h"

bool UnaryBinaryDevice::IsAvailable() const { return true; }
int UnaryBinaryDevice::UnaryOp(int x) const {
    return 2 * x;
}
int UnaryBinaryDevice::BinaryOp(int x, int y) const {
    return x + y;
}
std::string UnaryBinaryDevice::DeviceName() const {
    return Device::DeviceName() + " [unary+binary]";
}
size_t UnaryBinaryDevice::IOCount() const {
    return Device::IOCount() + m_unary_inputs +
           m_binary_inputs;
}
