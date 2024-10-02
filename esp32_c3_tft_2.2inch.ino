#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS    5
#define TFT_RST   6
#define TFT_DC    7
#define TFT_CLK   8
#define TFT_MOSI  10
#define TFT_MISO  9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

// Function prototype
void displayMessage(const char* message, int textSize = 3);

const char* messages[] = {"FIRMWARE-DEV", "SHIVAM", "ARDUINO", "RASPBERRY PI", "ESP32", "STM32", "PCB DESIGN", "IoT"};
int currentMessageIndex = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!");

  tft.begin();  Q w
  tft.setRotation(3);  // Adjust rotation if needed

  tft.fillScreen(ILI9341_BLACK);
  displayMessage(messages[currentMessageIndex]);
}

void loop() {
  static unsigned long startTime = millis();

  // Check if 3000 milliseconds (3 seconds) have passed
  if (millis() - startTime >= 1000) {
    // Increment the message index
    currentMessageIndex = (currentMessageIndex + 1) % (sizeof(messages) / sizeof(messages[0]));

    // Display the next message with a different color
    displayMessage(messages[currentMessageIndex], currentMessageIndex + 1); // Use currentMessageIndex + 1 as the color

    // Reset the timer
    startTime = millis();
  }

  // You can add other code here as needed.
}

void displayMessage(const char* message, int color) {
  tft.fillScreen(ILI9341_BLACK); // Clear the screen before displaying the new message

  tft.setTextSize(3);

  // Set text color based on the current message index
  switch (color) {
    case 1:
      tft.setTextColor(ILI9341_GREEN);
      break;
    case 2:
      tft.setTextColor(ILI9341_ORANGE);
      break;
      case 3:
      tft.setTextColor(ILI9341_BLUE);
      break;
      case 4:
      tft.setTextColor(ILI9341_CYAN);
      break;
      case 5:
      tft.setTextColor(ILI9341_PINK);
      break;
      case 6:
      tft.setTextColor(ILI9341_YELLOW);
      break;
      case 7:
      tft.setTextColor(ILI9341_RED);
      break;
      case 8:
      tft.setTextColor(ILI9341_PURPLE);
      break;
      case 9:
      tft.setTextColor(ILI9341_OLIVE);
      break;
      
    // Add more cases for other colors as needed
    default:
      tft.setTextColor(ILI9341_GREEN); // Default color
  }

  // Get the dimensions of the text
  int16_t x, y;
  uint16_t w, h;
  tft.getTextBounds(message, 0, 0, &x, &y, &w, &h);

  // Calculate the position to center the text
  int16_t xPos = (tft.width() - w) / 2;
  int16_t yPos = (tft.height() - h) / 2;

  tft.setCursor(xPos, yPos);
  tft.println(message);
}









