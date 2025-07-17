#pragma once
#include "NeoPixelBusLg.h"

// Timing configuration for APA104 LEDs
class NeoEsp8266UartSpeedApa104 {
public:
    static const uint32_t ByteSendTimeUs = 8;        // ~1 MHz
    static const uint32_t UartBaud = 3880000;        // 1 MHz * 4
    static const uint32_t ResetTimeUs = 210;         // reset period
};

class NeoBitsSpeedApa104 : public NeoBitsSpeedBase {
public:
    static const uint16_t BitSendTimeNs = 1030;
    static const uint16_t ResetTimeUs = 210;
};

class NeoEsp32RmtSpeedApa104 : public NeoEsp32RmtSpeedBase {
public:
    const static DRAM_ATTR uint32_t RmtBit0 = Item32Val(320, 800);
    const static DRAM_ATTR uint32_t RmtBit1 = Item32Val(740, 200);
    const static DRAM_ATTR uint16_t RmtDurationReset = FromNs(210000);
    static void IRAM_ATTR Translate(const void* src,
        rmt_item32_t* dest,
        size_t src_size,
        size_t wanted_num,
        size_t* translated_size,
        size_t* item_num) {
        NeoEsp32RmtSpeedBase::Translate(src, dest, src_size, wanted_num, translated_size, item_num);
    }
};

class NeoEsp32RmtInvertedSpeedApa104 : public NeoEsp32RmtInvertedSpeedBase {
public:
    const static DRAM_ATTR uint32_t RmtBit0 = Item32Val(320, 800);
    const static DRAM_ATTR uint32_t RmtBit1 = Item32Val(740, 200);
    const static DRAM_ATTR uint16_t RmtDurationReset = FromNs(210000);
    static void IRAM_ATTR Translate(const void* src,
        rmt_item32_t* dest,
        size_t src_size,
        size_t wanted_num,
        size_t* translated_size,
        size_t* item_num) {
        NeoEsp32RmtInvertedSpeedBase::Translate(src, dest, src_size, wanted_num, translated_size, item_num);
    }
};

// ESP8266 DMA
using NeoEsp8266DmaApa104Method = NeoEsp8266DmaMethodBase<NeoEsp8266I2sCadence<NeoEsp8266DmaNormalPattern>, NeoBitsSpeedApa104>;
using NeoEsp8266DmaInvertedApa104Method = NeoEsp8266DmaMethodBase<NeoEsp8266I2sCadence<NeoEsp8266DmaInvertedPattern>, NeoBitsSpeedApa104>;

// UART
using NeoEsp8266Uart0Apa104Method = NeoEsp8266UartMethodBase<NeoEsp8266UartSpeedApa104, NeoEsp8266Uart<UartFeature0, NeoEsp8266UartContext>, NeoEsp8266UartNotInverted>;
using NeoEsp8266Uart1Apa104Method = NeoEsp8266UartMethodBase<NeoEsp8266UartSpeedApa104, NeoEsp8266Uart<UartFeature1, NeoEsp8266UartContext>, NeoEsp8266UartNotInverted>;

using NeoEsp32RmtNApa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannelN>;
using NeoEsp32Rmt0Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel0>;
using NeoEsp32Rmt1Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel1>;
using NeoEsp32Rmt2Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel2>;
using NeoEsp32Rmt3Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel3>;
using NeoEsp32Rmt4Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel4>;
using NeoEsp32Rmt5Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel5>;
using NeoEsp32Rmt6Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel6>;
using NeoEsp32Rmt7Apa104Method = NeoEsp32RmtMethodBase<NeoEsp32RmtSpeedApa104, NeoEsp32RmtChannel7>;

using NeoEsp32RmtNApa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannelN>;
using NeoEsp32Rmt0Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel0>;
using NeoEsp32Rmt1Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel1>;
using NeoEsp32Rmt2Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel2>;
using NeoEsp32Rmt3Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel3>;
using NeoEsp32Rmt4Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel4>;
using NeoEsp32Rmt5Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel5>;
using NeoEsp32Rmt6Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel6>;
using NeoEsp32Rmt7Apa104InvertedMethod = NeoEsp32RmtMethodBase<NeoEsp32RmtInvertedSpeedApa104, NeoEsp32RmtChannel7>;
