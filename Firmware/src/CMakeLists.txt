if (TARGET tinyusb_device)
    add_executable(usb_tri main.cpp usb_descriptors.c)
    pico_generate_pio_header(usb_tri ${CMAKE_CURRENT_LIST_DIR}/pio/i2s.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/pio)

    # pull in common dependencies
    target_link_libraries(usb_tri pico_stdlib pico_unique_id tinyusb_device tinyusb_board pico_util hardware_pio hardware_gpio)
    target_include_directories(usb_tri PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

    pico_enable_stdio_usb(usb_tri 0)
    pico_enable_stdio_uart(usb_tri 1)

    pico_set_program_name(usb_tri "Korg USB-TRI Adapter") # as "foo" would be the default
    pico_set_program_description(usb_tri "Provides a MIDI and USB audio interface for the Korg Trinity.")
    pico_set_program_version(usb_tri "0.1")
    pico_set_program_url(usb_tri "https://spacechicken.gay/usb-tri")

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(usb_tri)

    add_compile_options(-Wall -Werror -Wextra -Wpedantic -Wno-format -Wno-unused-function -Wno-maybe-uninitialized -flto)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building usb_tri because TinyUSB submodule is not initialized in the SDK")
endif()