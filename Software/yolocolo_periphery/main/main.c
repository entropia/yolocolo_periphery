#include <stdio.h>

#include "esp_system.h"
#include "bme280.h"

void app_main(void)
{
    printf("SDK version:%s\n", esp_get_idf_version());
}
