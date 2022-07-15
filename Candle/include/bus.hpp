#pragma once

#include "usbDevice.hpp"
#include "mab_types.hpp"
#include "spiDevice.hpp"

namespace mab
{
    enum class BusType_E
    {
        USB,
        SPI,
        UART
    };

    class Bus
    {
        private:
        BusType_E busType;
        static const int rxBufferSize = 1024;
        static const int txBufferSize = 1024;
        char rxBuffer[rxBufferSize];
        char txBuffer[txBufferSize];

        public:
        UsbDevice* usb;
        SpiDevice* spi;
        
        Bus();
        Bus(mab::BusType_E type);
        ~Bus();
        mab::BusType_E getType();
        char* getRxBuffer(int index = 0);
        bool transfer(char* buffer, int len, bool waitForResponse = false, int timeout = 100, int responseLen = 0);
        bool receive(int timeoutMs = 100, int responseLen = 0);
        int getBytesReceived();
        int getRxBufferSize(){return rxBufferSize;};
        int getTxBufferSize(){return txBufferSize;};
    };
}
