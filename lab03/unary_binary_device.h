#pragma once
#include "binary_op_device.h"
#include "unary_op_device.h"

class UnaryBinaryDevice final : public UnaryOpDevice,
                                public BinaryOpDevice {
public:
    using UnaryOpDevice::UnaryOpDevice;
    virtual ~UnaryBinaryDevice() = default;
    bool IsAvailable() const override final;
    int UnaryOp(int x) const override final;
    int BinaryOp(int x, int y) const override final;
    std::string DeviceName() const override final;
    size_t IOCount() const override final;
};
