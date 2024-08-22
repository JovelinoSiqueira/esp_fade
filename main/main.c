#include <stdio.h>
#include "driver/ledc.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void vDuty(int dt, int time){
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, dt);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
    vTaskDelay(time / portTICK_PERIOD_MS);
}

void vFadeIn(void){
    for (int duty = 0; duty <= 255; duty+=10) {
        vDuty(duty, 10);
    }
}

void vFadeOut(void){
    for (int duty = 255; duty >= 0; duty-=10) {
        vDuty(duty, 10);
    }
}

void vfade(void *pvParameter){

    ledc_timer_config_t ledc_timer = {
        .speed_mode      = LEDC_HIGH_SPEED_MODE,
        .timer_num       = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .freq_hz         = 5000,
        .clk_cfg         = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel    = LEDC_CHANNEL_0,
        .timer_sel  = LEDC_TIMER_0,
        .intr_type  = LEDC_INTR_DISABLE,
        .gpio_num   = GPIO_NUM_2,
        .duty       = LEDC_TIMER_8_BIT,
        .hpoint     = 0
    };
    ledc_channel_config(&ledc_channel);

    while(1){
        vFadeIn();
        vFadeOut();
    }
}

void app_main(void){
    xTaskCreate(vfade, "vfade", 1024, NULL, 1, NULL);
}
