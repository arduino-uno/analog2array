/*

  Get the Min & Max Value of Array

  Reads all the analog inputs, store the result to an Array.
  Get the Minimum & the Maximum value of Array.
  Also prints the results to the Serial Monitor.

  The circuit:
  - LDR connected to analog pin A1.
    side pin of the LDR go to +3V

*/

// Analog input pin that the LDR is attached to
const int analogInPin = A1;
//let's say you want to read up to 100 values
const unsigned int numReadings = 6;
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
          Serial.print("Min Value:");
          Serial.println(minValue);
          Serial.print("Max Value:");
          Serial.println(maxValue);
          //reset to beginning of array, so you don't try to save readings outside of the bounds of the array
          i=0;
      }

      delay(1000);
  }
  return;
}

void loop() {
    /* Loop Code here */   
}

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
