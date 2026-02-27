#include <string>
class Device {
public:
    Device(std::string_view name, size_t io_count)
        : m_name(name), m_io_count(io_count) {}

    virtual ~Device() = default;
    virtual std::string DeviceName() const {
        return m_name;
    }
    virtual size_t IOCount() const { return m_io_count; }

    virtual bool IsAvailable() const = 0;

private:
    std::string m_name;
    size_t m_io_count;
};

class UnaryOpDevice : public virtual Device {
public:
    virtual ~UnaryOpDevice() = default;
    using Device::Device;
    virtual int UnaryOp(int) const = 0;
};

class BinaryOpDevice : public virtual Device {
public:
    virtual ~BinaryOpDevice() = default;
    using Device::Device;
    virtual int BinaryOp(int, int) const = 0;
};

class TernaryOpDevice : public virtual Device {
public:
    virtual ~TernaryOpDevice() = default;
    using Device::Device;
    virtual int TernaryOp(int, int, int) const = 0;
};

class UnaryBinaryDevice : public UnaryOpDevice,
                          public BinaryOpDevice {
public:
    using UnaryOpDevice::UnaryOpDevice;
    bool IsAvailable() const override { return true; }
    int UnaryOp(int x) const override { return 2 * x; }
    int BinaryOp(int x, int y) const override {
        return x + y;
    }
};

class BinaryTernaryDevice : public TernaryOpDevice,
                            public BinaryOpDevice {
public:
    using BinaryOpDevice::BinaryOpDevice;
    bool IsAvailable() const override { return true; }
    int TernaryOp(int x, int y, int z) const override {
        return x * y + z;
    }
    int BinaryOp(int x, int y) const override {
        return x * y;
    }
};
#include <iostream>
#include <string_view>
using namespace std::string_view_literals;

int main() {
    // на момент выполнения работы в списках имею вариант 19
    UnaryBinaryDevice ub("unary-binary", 1);
    std::cout << ub.DeviceName() << std::endl;
    std::cout << ub.IOCount() << std::endl;
    std::cout << ub.UnaryOp(1) << std::endl;
    std::cout << ub.BinaryOp(1, 2) << std::endl;

    BinaryTernaryDevice bt("binary-ternary", 2);
    std::cout << bt.DeviceName() << std::endl;
    std::cout << bt.IOCount() << std::endl;
    std::cout << bt.BinaryOp(1, 2) << std::endl;
    std::cout << bt.TernaryOp(3, 4, 5) << std::endl;
}
