# KRUPS-RocketStation
PCB design files and documentation for the base station/rocket station used in the University of Kentucky's 2025 RockSat-XG KRUPS payload

### PCB Render
<img src="Documentation/pcbtop.png" width="50%"><img src="Documentation/pcbbottom.png" width="50%">

### Components
- [Raspberry Pi Pico 2 W (4MB Flash)](https://datasheets.raspberrypi.com/picow/pico-2-w-datasheet.pdf)
- [Fanstel LR62XE 1W 868/915MHz LoRa Modem](https://static1.squarespace.com/static/561459a2e4b0b39f5cefa12e/t/63ddc4b1dd728b424f1a6c23/1675478197953/LR62E_LR62XE_M262X840XE_Product+Specifications.pdf)
- [BME280 Temperature, Pressure, Humidity Sensor](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf)
- [BNO086 9-Axis IMU](https://www.mouser.com/datasheet/2/1480/BNO080_085_Datasheet-3196201.pdf)
- [PKU5511ESI DC/DC Step-down Converter](https://flexpowermodules.com/resources/fpm-techspec-pku5500e)

### Pin Mapping
| Pico 2 W GPIO Pin | Net Name |
| --- | --- |
| GPIO0 | RPI_UART4_TX |
| GPIO1 | RPI_UART4_RX |
| GPIO4 | ASYNC_UART_TX1 |
| GPIO5 | ASYNC_UART_TX2 |
| GPIO6 | SPI_CLK |
| GPIO7 | SPI_MOSI |
| GPIO8 | SPI_MISO |
| GPIO9 | SPI_NSS |
| GPIO10 | LORA_DIO1 |
| GPIO11 | LORA_BUSY |
| GPIO12 | LORA_RESET (active low)|
| GPIO13 | LORA_ANTSW |
| GPIO14 | I2C_SDA |
| GPIO15 | I2C_SCL |
| GPIO19 | BNO086_RESET (active low) |
| GPIO20 | BNO086_HINTN |
| GPIO26 | TE_SENSE (ADC) |
