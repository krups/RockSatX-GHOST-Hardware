# KRUPS-FemtoSat
PCB design files and documentation for the femto-satellites used in the University of Kentucky's 2025 RockSat-XG KRUPS payload

### PCB Render
<img src="Documentation/pcbtop.png" width="50%"><img src="Documentation/pcbbottom.png" width="50%">

### Components
- [ESP32-S3-WROOM-2 (32MB Flash, 8MB PSRAM)](https://www.espressif.com/sites/default/files/documentation/esp32-s3-wroom-2_datasheet_en.pdf)
- [EBYTE E22-900M33S 2W 868/915MHz LoRa Modem](https://www.cdebyte.com/pdf-down.aspx?id=2954)
- [BME280 Temperature, Pressure, Humidity Sensor](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf)
- [BNO086 9-Axis IMU](https://www.mouser.com/datasheet/2/1480/BNO080_085_Datasheet-3196201.pdf)
- [PKU5511ESI DC/DC Step-down Converter](https://flexpowermodules.com/resources/fpm-techspec-pku5500e)

### Pin Mapping
| ESP32-S3 GPIO Pin | Net Name |
| --- | --- |
| IO1 | BNO086_HINTN |
| IO2 | BNO086_RESET (active low) |
| IO3 | SPI_NSS |
| IO4 | LORA_RXEN |
| IO5 | LORA_TXEN |
| IO6 | ASYNC_UART_TX1 |
| IO7 | ASYNC_UART_TX2 |
| IO9 | SPI_CLK |
| IO10 | SPI_MOSI |
| IO11 | SPI_MISO |
| IO12 | LORA_RESET (active low)|
| IO13 | LORA_BUSY |
| IO14 | LORA_DIO1 |
| IO15 | TE_SENSE (ADC) |
| IO17 | RPI_UART4_TX |
| IO18 | RPI_UART4_RX |
| IO21 | LORA_DIO2 |
| IO43 | I2C_SCL |
| IO44 | I2C_SDA |

