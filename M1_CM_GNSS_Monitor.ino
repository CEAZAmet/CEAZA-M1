/*  
 * For this codee you have to connect an M1 board to a CEAZA MEGA borad.
 * To program the CEAZA MEGA borad you have to select the "Arduino Mega or Mega 2560" board.
 * 
 * This code acts as a M1's GNSS module monitor through CEAZA MEGA board.
 * You can see by serial monitor all messages sent by the GNSS module and also send commands to the module.
 * 
 *  https://github.com/adgallardo/CEAZA-M1
 *  
 */
#define M1_3V_EN_PIN      35
#define M1_VGPS_EN_PIN    34
#define M1_UART2_MUX_PIN  42
#define GNSS_SERIAL Serial2

void setup() {
  // initialize serial ports:
  Serial.begin(115200);     // Serial monitor serial port
  GNSS_SERIAL.begin(9600);  // GNSS module serial port at 9600bps by default

  // Activate GNSS module and establish communication rute
  pinMode(M1_3V_EN_PIN,OUTPUT);digitalWrite(M1_3V_EN_PIN,HIGH);         // +3.3V power supply on board activated
  delay(10);                                                            // +3.3V power supply start time 
  pinMode(M1_VGPS_EN_PIN,OUTPUT);digitalWrite(M1_VGPS_EN_PIN,HIGH);     // Turn GNSS module on
  pinMode(M1_UART2_MUX_PIN,OUTPUT);digitalWrite(M1_UART2_MUX_PIN,HIGH); // Select GNSS module in UART2 multiplexer
}

void loop() {
  // Show by serial monitor data from GNSS module
  if (GNSS_SERIAL.available()) {
    int inByte = GNSS_SERIAL.read();
    Serial.write(inByte);
  }

  // Send to GNSS module any byte send by serial monitor
  if (Serial.available()) {
    int inByte = Serial.read();
    GNSS_SERIAL.write(inByte);
  }
}
