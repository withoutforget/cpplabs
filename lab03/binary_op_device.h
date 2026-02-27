#pragma once
#include "device.h"

class BinaryOpDevice : public virtual Device {
public:
    virtual ~BinaryOpDevice() = default;
    using Device::Device;
    std::string DeviceName() const override;
    virtual int BinaryOp(int, int) const = 0;

protected:
    size_t m_binary_inputs = 2;
};
