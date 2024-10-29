# KRUPS-FemtoSat
PCB design files and documentation for the femto-satellites used in the University of Kentucky's 2025 RockSat-XG KRUPS payload

### PCB Render
<img src="Documentation/pcbtop.png" width="25%"><img src="Documentation/pcbbottom.png" width="25%">

### Components
- [ESP32-S3-WROOM-1U (16MB Flash, 8MB PSRAM)](https://www.espressif.com/sites/default/files/documentation/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
- [EBYTE E22-900M33S 2W 868/915MHz LoRa Modem](https://www.cdebyte.com/pdf-down.aspx?id=2954)
- [BME280 Temperature, Pressure, Humidity Sensor](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf)
- [BNO086 9-Axis IMU](https://www.mouser.com/datasheet/2/1480/BNO080_085_Datasheet-3196201.pdf)

### Pin Mapping
| ESP32-S3 GPIO Pin | Net Name |
| --- | --- |
| IO4 | BNO086_HINTN |
| IO5 | BNO086_RESET (active low)|
| IO6 | I2C_SCL |
| IO7 | I2C_SDA |
| IO9 | SPI_CLK |
| IO10 | SPI_MOSI |
| IO11 | SPI_MISO |
| IO12 | LORA_RESET (active low)|
| IO13 | LORA_BUSY |
| IO14 | LORA_DIO1 |
| IO21 | LORA_DIO2 |
| IO47 | LORA_TXEN |
| IO48 | LORA_RXEN |
