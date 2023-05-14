/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * Configuration settings for the SAMSUNG ORIGEN (EXYNOS4210) board.
 */

#ifndef __CONFIG_EX4412_H
#define __CONFIG_EX4412_H

#include <configs/exynos4-common.h>

#define CONFIG_EXYNOS4412 	1
#define CONFIG_EX4412		1
/* #define CONFIG_SYS_L2CACHE_OFF           1  */
#define CONFIG_SPL_TEXT_BASE   0x02023400
#define CONFIG_SYS_TEXT_BASE   0x43E00000
#define COPY_BL2_FNPTR_ADDR    0x02020030
#define CONFIG_DEFAULT_CONSOLE “console=ttySAC2,115200n8\0”

#define CONFIG_DEBUG_UART_BASE   0x13820000
#define CONFIG_DEBUG_UART_CLOCK 100000000
#define CONFIG_SPL_SERIAL_SUPPORT       1
#define CONFIG_SPL_GPIO_SUPPORT         1

#define CONFIG_CLK_1000_200_200
/* #define CONFIG_SPL_BUILD run wrong*/

/* #define CONFIG_SYS_DRAM_TEST     1  */
/* ORIGEN has 4 bank of DRAM */
#define CONFIG_NR_DRAM_BANKS       4
#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define PHYS_SDRAM_1			CONFIG_SYS_SDRAM_BASE
#define SDRAM_BANK_SIZE			(256 << 20)	/* 256 MB */

#define CONFIG_SYS_MONITOR_BASE    0x00000000

#define CONFIG_SYS_MEMTEST_START    CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END      (CONFIG_SYS_SDRAM_BASE + 0x6000000)

/* Power Down Modes */
#define S5P_CHECK_SLEEP			0x00000BAD
#define S5P_CHECK_DIDLE			0xBAD00000
#define S5P_CHECK_LPA			0xABAD0000

/* MMC SPL */
#define CONFIG_SYS_MMC_ENV_DEV     0
#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x40007000\0" \
	"rdaddr=0x48000000\0" \
	"kerneladdr=0x40007000\0" \
	"ramdiskaddr=0x48000000\0" \
	"console=ttySAC2,115200n8\0" \
	"mmcdev=0\0" \
	"bootenv=uEnv.txt\0" \
	"loadbootenv=load mmc ${mmcdev} ${loadaddr} ${bootenv}\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t $loadaddr $filesize\0" \
        "loadbootscript=load mmc ${mmcdev} ${loadaddr} boot.scr\0" \
        "bootscript=echo Running bootscript from mmc${mmcdev} ...; " \
                "source ${loadaddr}\0"

/* MIU (Memory Interleaving Unit) */
#define CONFIG_MIU_2BIT_21_7_INTERLEAVED
#define RESERVE_BLOCK_SIZE		(512)
#define BL1_SIZE			(8 << 10) /*16 K reserved for BL1*/
#define BL2_SIZE        		(16 << 10) /* 512 KB */

/* #define SPI_FLASH_UBOOT_POS  (SEC_FW_SIZE + BL1_SIZE) */

#endif	/* __CONFIG_H */
