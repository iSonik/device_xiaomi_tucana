/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties() {
    std::string region;

    region = android::base::GetProperty("ro.boot.hwc", "");

    if (region == "CN")
    {
        property_override("ro.product.model", "MI CC9 Pro");
        property_override("ro.build.description", "tucana-user 10 QKQ1.190825.002 V11.1.1.0.QFDCNXM release-keys");
        property_override("ro.build.fingerprint", "Xiaomi/tucana/tucana:10/QKQ1.190825.002/V11.1.1.0.QFDCNXM:user/release-keys");
    }
    else if (region == "GLOBAL")
    {
        property_override("ro.product.model", "Mi Note 10");
        property_override("ro.build.description", "tucana_eea-user 10 QKQ1.190825.002 V11.1.1.0.QFDEUXM release-keys");
        property_override("ro.build.fingerprint", "Xiaomi/tucana_eea/tucana:10/QKQ1.190825.002/V11.1.1.0.QFDEUXM:user/release-keys");
    }
    else
    {
        LOG(ERROR) << __func__ << ": unexcepted region!";
    }
}
