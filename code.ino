#include <Adafruit_NeoPixel.h>

#define LED_PIN 12  
#define NUM_LEDS 5  

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int simulatedHour = 8;  
int simulatedMonth = 1;  

void setup() {
    strip.begin();
    strip.show(); 
}

void loop() {
    uint32_t color = getColorByTime(simulatedHour, simulatedMonth);
    
    for (int i = 0; i < NUM_LEDS; i++) {
        strip.setPixelColor(i, color);
    }
    strip.show();

    delay(5000); 
    simulatedHour++;
    if (simulatedHour >= 24) {
        simulatedHour = 0;
        simulatedMonth++;
        if (simulatedMonth > 12) simulatedMonth = 1;  
    }
}

uint32_t getColorByTime(int hour, int month) {
    if (month == 12) { 
        return strip.Color(255, 0, 0);  
    }
    if (hour >= 6 && hour < 12) {  
        return strip.Color(255, 165, 0);  
    } else if (hour >= 12 && hour < 18) {  
        return strip.Color(255, 255, 0);  
    } else if (hour >= 18 && hour < 22) {  
        return strip.Color(0, 0, 255);  
    } else {  
        return strip.Color(0, 0, 128);  
    }
}
