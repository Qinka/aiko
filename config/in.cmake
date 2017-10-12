##
## maintainer Johann Lee <me@qinka.pro>
## Copyright (C) 2017 Johann Lee <me@qinka.pro>
## GPLv3
##
## .in file configure
##


variable_watch(AIKO_FIRMWARE_SRC_FILE)
## stm32f103x config
set (AIKO_FIRMWARE_SRC_FILE
  "source/firmware/core_cm3.c"
  "source/firmware/misc.c"
  )
## for adc
if(DEFINED "AIKO_FIRMWARE_USE_ADC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_adc.c")
endif(DEFINED "AIKO_FIRMWARE_USE_ADC")
## for bkp
if(DEFINED "AIKO_FIRMWARE_USE_BKP")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_bkp.c")
endif(DEFINED "AIKO_FIRMWARE_USE_BKP")
## for can
if(DEFINED "AIKO_FIRMWARE_USE_CAN")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_can.c")
endif(DEFINED "AIKO_FIRMWARE_USE_CAN")
## for cec
if(DEFINED "AIKO_FIRMWARE_USE_CEC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_cec.c")
endif(DEFINED "AIKO_FIRMWARE_USE_CEC")
## for crc
if(DEFINED "AIKO_FIRMWARE_USE_CRC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_crc.c")
endif(DEFINED "AIKO_FIRMWARE_USE_CRC")
## for dac
if(DEFINED "AIKO_FIRMWARE_USE_DAC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_dac.c")
endif(DEFINED "AIKO_FIRMWARE_USE_DAC")
## for dbgmcu
if(DEFINED "AIKO_FIRMWARE_USE_DBGMCU")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_dbgmcu.c")
endif(DEFINED "AIKO_FIRMWARE_USE_DBGMCU")
## for dma
if(DEFINED "AIKO_FIRMWARE_USE_DMA")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_dma.c")
endif(DEFINED "AIKO_FIRMWARE_USE_DMA")
## for exti
if(DEFINED "AIKO_FIRMWARE_USE_EXTI")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_exti.c")
endif(DEFINED "AIKO_FIRMWARE_USE_EXTI")
## for flash
if(DEFINED "AIKO_FIRMWARE_USE_FLASH")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_flash.c")
endif(DEFINED "AIKO_FIRMWARE_USE_FLASH")
## for fsmc
if(DEFINED "AIKO_FIRMWARE_USE_FSMC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_fsmc.c")
endif(DEFINED "AIKO_FIRMWARE_USE_FSMC")
## for gpio
if(DEFINED "AIKO_FIRMWARE_USE_GPIO")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_gpio.c")
endif(DEFINED "AIKO_FIRMWARE_USE_GPIO")
## for i2c
if(DEFINED "AIKO_FIRMWARE_USE_I2C")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_i2c.c")
endif(DEFINED "AIKO_FIRMWARE_USE_I2C")
## for iwdg
if(DEFINED "AIKO_FIRMWARE_USE_IWDG")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_iwdg.c")
endif(DEFINED "AIKO_FIRMWARE_USE_IWDG")
## for pwr
if(DEFINED "AIKO_FIRMWARE_USE_PWR")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_pwr.c")
endif(DEFINED "AIKO_FIRMWARE_USE_PWR")
## for rcc
if(DEFINED "AIKO_FIRMWARE_USE_RCC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_rcc.c")
endif(DEFINED "AIKO_FIRMWARE_USE_RCC")
## for rtc
if(DEFINED "AIKO_FIRMWARE_USE_RTC")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_rtc.c")
endif(DEFINED "AIKO_FIRMWARE_USE_RTC")
## for sdio
if(DEFINED "AIKO_FIRMWARE_USE_SDIO")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_sdio.c")
endif(DEFINED "AIKO_FIRMWARE_USE_SDIO")
## for spi
if(DEFINED "AIKO_FIRMWARE_USE_SPI")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_spi.c")
endif(DEFINED "AIKO_FIRMWARE_USE_SPI")
## for tim
if(DEFINED "AIKO_FIRMWARE_USE_TIM")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_tim.c")
endif(DEFINED "AIKO_FIRMWARE_USE_TIM")
## for usart
if(DEFINED "AIKO_FIRMWARE_USE_USART")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_usart.c")
endif(DEFINED "AIKO_FIRMWARE_USE_USART")
## for wwdg
if(DEFINED "AIKO_FIRMWARE_USE_WWDG")
  set (AIKO_FIRMWARE_SRC_FILE
		 ${AIKO_FIRMWARE_SRC_FILE} "source/firmware/stm32f10x_wwdg.c")
endif(DEFINED "AIKO_FIRMWARE_USE_WWDG")

configure_file(
  "include/config.in/stm32f10x_conf.h.in"
  "${PROJECT_BINARY_DIR}/include/config/stm32f10x_conf.h"
)


## add include path
include_directories("${PROJECT_BINARY_DIR}/include")