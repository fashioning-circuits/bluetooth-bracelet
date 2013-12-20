//This is the sender
#include <SoftwareSerial.h>  

char bracelet[] = "201309291645,HC-06,1F00";
char keys[] = "201307262620,HC-06,1F00";
int bluetoothTx = 5;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 4;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600); // set up Serial library at 9600 bps
  bluetooth.begin(9600); // set up Serial library at 9600 bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the bluetooth to send back CMD
}
 

void loop()
{
  Serial.println("I,1"); // start inquiry scan for bracelet
  delay(5000);
  int h = Serial.available();
        if(h >= 42) { // we know there is a bluetooth device
            char *id = readSerial(h);
            char *str;
            while((str = strtok_r(id, "\n", &id)) != NULL) {
                if(strncmp(str,bracelet,19) == 0) {
                    Serial.print("Keys missing");
                    Serial.print("C,201309291645");
                    Serial.print("1");
                } else if(strncmp(str,bracelet,19)&&(str,keys,19) == 0) {
                    Serial.print("Keys present");
                }
            }
        }
    }
    clearAll();
}

