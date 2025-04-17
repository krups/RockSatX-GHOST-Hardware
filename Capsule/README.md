# Capsule
PCB design files and documentation for the re-entry capsule used in the University of Kentucky's 2025 RockSat-XG KRUPS payload

### PCB Render


### Components
- [Raspberry Pi Pico 2 W (4MB Flash)](https://datasheets.raspberrypi.com/picow/pico-2-w-datasheet.pdf)
- [Fanstel LR62XE 1W 868/915MHz LoRa Modem](https://static1.squarespace.com/static/561459a2e4b0b39f5cefa12e/t/63ddc4b1dd728b424f1a6c23/1675478197953/LR62E_LR62XE_M262X840XE_Product+Specifications.pdf)
- [FSM300 9-Axis IMU](https://www.mouser.com/datasheet/2/1480/FSM30x_Datasheet-3196253.pdf)
- [H3LIS100DL 3-axis accelerometer](https://www.st.com/resource/en/datasheet/h3lis100dl.pdf)
- [MCP9600 thermocouple to digital converter](https://ww1.microchip.com/downloads/aemDocuments/documents/MSLD/ProductDocuments/DataSheets/MCP960X-L0X-RL0X-Thermocouple-EMF-to-Temperature-Converter-plus-minus-1-5-degrees-Celcius-Maximum-Accuracy-DS20005426.pdf)


### Pin Mapping
| Pico 2 GPIO Pin | Net Name |
| --- | --- |
| GPIO0 | T_IRIDIUM |
| GPIO1 | R_IRIDIUM |
| GPIO2 | SDA |
| GPIO3 | SCL |
| GPIO4 | TX1 |
| GPIO5 | RX1 |
| GPIO6 | TX_GPS |
| GPIO7 | RX_GPS |
| GPIO12 | SD_SPI_MISO |
| GPIO13 | SD_SPI_CS |
| GPIO14 | SD_SPI_CLK |
| GPIO15 | SD_SPI_MOSI |
| GPIO16 | LORA_SPI_MISO |
| GPIO17 | LORA_SPI_CSN |
| GPIO18 | LORA_SPI_CLK |
| GPIO19 | LORA_SPI_MOSI |
| GPIO20 | LORA_ANTW |
| GPIO21 | LORA_RESET |
| GPIO22 | LORA_BUSY |
| GPIO26 | LORA_DIO1 |
| GPIO27 | PWMLS |

