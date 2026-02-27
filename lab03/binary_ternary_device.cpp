#include "binary_ternary_device.h"

bool BinaryTernaryDevice::IsAvailable() const {
    return true;
}
int BinaryTernaryDevice::TernaryOp(int x, int y,
                                   int z) const {
    return x * y + z;
}
int BinaryTernaryDevice::BinaryOp(int x, int y) const {
    return x * y;
}
std::string BinaryTernaryDevice::DeviceName() const {
    return Device::DeviceName() + " [binary+ternary]";
}
size_t BinaryTernaryDevice::IOCount() const {
    return Device::IOCount() + m_binary_inputs +
           m_ternary_inputs;
}
