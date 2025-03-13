add_executable(femtosat-verifier
    main.cpp
)

target_include_directories(femtosat-verifier PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(femtosat-verifier 
    pico_stdlib 
    hardware_i2c
    hardware_spi
    hardware_dma
    hardware_pio
    hardware_interp
    hardware_timer
    hardware_watchdog
    hardware_clocks
    hardware_pwm
    pico_multicore

    BNO08x_Pico_Library
    Pico_BME280_Driver
    RadioLib
    )

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(femtosat-verifier 
        pico_cyw43_arch_none 
    )
endif()

pico_add_extra_outputs(femtosat-verifier)

# Modify the below lines to enable/disable console output over UART/USB
# usb is inaccessible and soldering headers onto uart lines takes time so this is kinda useless
pico_enable_stdio_uart(femtosat-verifier 0)
pico_enable_stdio_usb(femtosat-verifier 0)