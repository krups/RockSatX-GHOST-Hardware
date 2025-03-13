#include <stdio.h>
#include "pico/stdlib.h"

// IMU
#include "bno08x.h"
#include "utils.h"  // BNO08X driver related

// BME280
extern "C" {    // extern because drivers are .c files
#include "bme280_driver.h"
}

// LoRa
#include "hardware/spi.h"
#include "RadioLib.h"
#include "hal/RPiPico/PicoHal.h"

// WiFi modem
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

// I2C defines
#define I2C_PORT i2c0           // i2c port. shared between BME280 & BNO08X
#define I2C_SDA 8        // gpio pin for i2c SDA
#define I2C_SCL 9        // gpio pin for i2c SCL
#define I2C_SPEED 400000 // i2c bus speed, 400KHz

// SPI defines. only used for radio
// TO-DO: update this to match femtosat pinout
// right now it's set to whatever my breadboard is wired up to
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_MOSI 19
#define PIN_SCK 18
#define PIN_CS 17
#define PIN_DIO1 26
#define PIN_RST 21
#define PIN_BUSY 22

// LoRa defines
// see https://unsigned.io/understanding-lora-parameters/

// TO-DO: update parameters for LR62XE
// these are set for the LAMBDA62 lora breakouts we have and 
// not the LR62XE that we're actually using.
#define LORA_FREQ               915.0
#define LORA_BANDWIDTH          500.0
#define LORA_SPREADINGFACTOR    9
#define LORA_CODINGRATE         7
#define LORA_SYNCWORD           RADIOLIB_SX126X_SYNC_WORD_PRIVATE // 0x12
#define LORA_TX_POWER           -9      // in dBm. DO NOT EXCEED 9 dBm! 
                                        // set to lowest option (-9dBm) to prevent overcurrent on USB power
#define LORA_PREAMBLE_LENGTH    8
#define LORA_TXCO_VOLTAGE       0
#define LORA_USE_LDO            false


// BME280
#define BME280_ADDR 0x76        // i2c address of the BME280


int main()
{
    stdio_init_all();
    cyw43_arch_init();

    // turn on light to show you things are happening
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(500);

    // I2C Initialization
    i2c_init(I2C_PORT, I2C_SPEED);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // volatile variables showing initialization states. inspect these with debugger!
    volatile int loraInitState;         // 0 means successful init
    volatile int8_t bme280InitState;    // 0 means successful init
    volatile bool BNO086InitState;      // TRUE means it initialized successfully

    // initialize sensors

    // lora
    PicoHal myHal(SPI_PORT, PIN_MISO, PIN_MOSI, PIN_SCK);
    SX1262 radio = SX1262(new Module( & myHal, PIN_CS, PIN_DIO1, PIN_RST, PIN_BUSY));
    loraInitState= radio.begin(
        LORA_FREQ, 
        LORA_BANDWIDTH, 
        LORA_SPREADINGFACTOR, 
        LORA_CODINGRATE, 
        LORA_SYNCWORD, 
        LORA_TX_POWER, 
        LORA_PREAMBLE_LENGTH, 
        LORA_TXCO_VOLTAGE, 
        LORA_USE_LDO
    );
    sleep_ms(100);

    // bme280
    struct bme280_inst bme280;
    bme280InitState = bme280_init(
        I2C_PORT,
        BME280_ADDR,
        &bme280,
        BME280_FORCED_MODE,
        BME280_FILTER_OFF,
        BME280_T_OVERSAMPLE_1,
        BME280_H_OVERSAMPLE_1,
        BME280_P_OVERSAMPLE_1
    );
    sleep_ms(100);

    // bno086
    BNO08x IMU;
    BNO086InitState = IMU.begin(CONFIG::BNO08X_ADDR, I2C_PORT);

    // shut off LED if everything initializes successfully
    // BREAKPOINT HERE
    if ((loraInitState == RADIOLIB_ERR_NONE) && (bme280InitState == BME280_OK) && (BNO086InitState == true)) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    }

    // otherwise, make LED blink for eternity
    else {
        while(true) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(1000);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(1000);
        }
    }
    while(1){};
}