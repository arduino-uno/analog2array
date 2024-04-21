/*

  Get the Min, Max & Avg Value of Array

  Reads all the analog inputs, store the result to an Array.
  Get the Minimum, Maximum & Average value of Array.
  Also prints the results to the Serial Monitor.

  The circuit:
  - LDR connected to analog pin A1.
    side pin of the LDR go to +3V

*/

// Analog input pin that the LDR is attached to
const int analogInPin = A1;
// let's say you want to read up to 100 values, start from 0
const unsigned int numReadings = 3;
unsigned int analogVals[numReadings];

void setup() {
  Serial.begin(9600);
  Serial.println("Get min & max value of the array");
  Serial.println("================================");
  for (int i=0; i<=numReadings; i++) {
      int currValue = analogRead( analogInPin );
      Serial.print("Current Value:");
      Serial.println( currValue );
      analogVals[i] = currValue;
       
      if (i>=numReadings) {
          int minValue = getMinimumValue(analogVals, numReadings);
          int maxValue = getMaximumValue(analogVals, numReadings);
          int avgValue = getAverageValue(analogVals, numReadings);
          Serial.print("Min Value:");
          Serial.println(minValue);
          Serial.print("Max Value:");
          Serial.println(maxValue);
          Serial.print("Avg Value:");
          Serial.println(avgValue);
          // reset to beginning of array, so you don't try to save readings outside of the bounds of the array
          i=0;
      }

      delay(1000);
  }
  return;
}

void loop() { /* No Loop */ }

int getMinimumValue(int* array, int size){
  int minIndex = 0;
  int min = array[minIndex];
  for (int i=0; i<size; i++){
    min = min(min, array[i]);
  }
  return min;
}

int getMaximumValue(int* array, int size){
  int maxIndex = 0;
  int max = array[maxIndex];
  for (int i=0; i<size; i++){
    max = max(max, array[i]);
  }
  return max;
}

int getAverageValue(int* array, int size){
  int maxIndex = 0;
  int sum = array[maxIndex];
  for (int i=0; i<size; i++){
    sum += array[i];
  }
  // size plus zero, b'cos the counter is start from "0"
  int avg = sum / (size + 1);
  return avg;
}