#include <Arduino.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

void SpinClockwise(void *parameter)
{
  // Identify the core ID on which the code is running
  Serial.print("Task1 is running on core ");
  Serial.println(xPortGetCoreID());

  for (;;)
  {
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);

    // Open ball valve
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void SpinAntiClockwise(void *parameter)
{
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for (;;)
  {
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);

    // Close ball valve
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(15200);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  xTaskCreatePinnedToCore(SpinClockwise, "Task1", 10000, NULL, 1, &Task1, 0);
  xTaskCreatePinnedToCore(SpinAntiClockwise, "Task2", 10000, NULL, 1, &Task2, 1);
}

void loop()
{
}