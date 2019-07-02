#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Display density
TARGET_SCREEN_DENSITY := 480

# Inherit from sm6150-common
-include device/xiaomi/sm6150-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/tucana

# Assert
TARGET_OTA_ASSERT_DEVICE := tucana

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):libinit_tucana
TARGET_RECOVERY_DEVICE_MODULES := libinit_tucana

# Kernel
BOARD_KERNEL_BASE := 0x00000000
BOARD_RAMDISK_OFFSET := 0x01000000
ifeq ($(TARGET_PREBUILT_KERNEL),)
  TARGET_KERNEL_CONFIG := vendor/lineage_tucana_defconfig
endif

# Platform
TARGET_BOARD_PLATFORM_GPU := qcom-adreno618

# Fingerprint
SOONG_CONFIG_XIAOMI_SM6150_FOD_POS_X = 445
SOONG_CONFIG_XIAOMI_SM6150_FOD_POS_Y = 1715
SOONG_CONFIG_XIAOMI_SM6150_FOD_SIZE = 190

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# NFC
TARGET_USES_NQ_NFC := true

# Partitions
BOARD_VENDORIMAGE_PARTITION_SIZE := 1610612736

# Inherit from the proprietary version
-include vendor/xiaomi/tucana/BoardConfigVendor.mk
