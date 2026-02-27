#pragma once
#include "device.h"

class UnaryOpDevice : public virtual Device {
public:
    virtual ~UnaryOpDevice() = default;
    using Device::Device;
    std::string DeviceName() const override;
    virtual int UnaryOp(int) const = 0;

protected:
    size_t m_unary_inputs = 1;
};
