#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

// Definição do pino do buzzer
#define BUZZER_PIN  26

// frequência do som (em Hz)
#define FREQUENCIA_SOM 2000

void inicializar_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    pwm_config cfg = pwm_get_default_config();
    uint32_t clock = 125000000;
    uint32_t divider = clock / FREQUENCIA_SOM / 4096;
    pwm_config_set_clkdiv(&cfg, (float)divider);
    pwm_config_set_wrap(&cfg, 4095);
    pwm_init(pwm_gpio_to_slice_num(BUZZER_PIN), &cfg, true);
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
}

void emitir_som() {
    pwm_set_gpio_level(BUZZER_PIN, 2048);
    sleep_ms(500);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}


