// Import required libraries
#include <Adafruit_CC3000.h>
#include <SPI.h>
#include <CC3000_MDNS.h>
#include <aREST.h>

// These are the pins for the CC3000 chip if you are using a breakout board
#define ADAFRUIT_CC3000_IRQ   3
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10

// Create CC3000 instance
Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
                                         SPI_CLOCK_DIV2);
// Create aREST instance
aREST rest = aREST();

// Your WiFi SSID and password
#define WLAN_SSID       "NETGEAR86"     // cannot be longer than 32 characters!
#define WLAN_PASS       "royallightning188"
#define WLAN_SECURITY   WLAN_SEC_WPA2

// The port to listen for incoming TCP connections
#define LISTEN_PORT           80

// Server instance
Adafruit_CC3000_Server restServer(LISTEN_PORT);

// DNS responder instance
MDNSResponder mdns;

// Variables to be exposed to the API
int temperature;
int humidity;
int ledEyes = 7;
int ledAnt = 8;
int beep = 9;

void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Function to be exposed
  rest.function("morse", morseCommand);

  // Give name and ID to device
  rest.set_id("008");
  rest.set_name("mighty_cat");

  // Set up CC3000 and get connected to the wireless network.
  if (!cc3000.begin())
  {
    while(1);
  }
  if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    while(1);
  }
  while (!cc3000.checkDHCP())
  {
    delay(100);
  }
  Serial.println();

  // Print CC3000 IP address. Enable if mDNS doesn't work
  //while (! displayConnectionDetails()) {
   // delay(1000);
  //}

  // Start multicast DNS responder
  if (!mdns.begin("arduino", cc3000)) {
    while(1);
  }

  // Start server
  restServer.begin();
  Serial.println(F("Listening for connections..."));

  // Set pins 7, 8, and 9 to OUTPUT
  pinMode(ledEyes, OUTPUT);
  pinMode(ledAnt, OUTPUT);
  pinMode(beep, OUTPUT);

  //setup
}

void loop() {

  // Handle any multicast DNS requests
  mdns.update();

  // Handle REST calls
  Adafruit_CC3000_ClientRef client = restServer.available();
  rest.handle(client);

}

// Print connection details of the CC3000 chip
bool displayConnectionDetails(void)
{
  uint32_t ipAddress, netmask, gateway, dhcpserv, dnsserv;

  if(!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv, &dnsserv))
  {
    Serial.println(F("Unable to retrieve the IP Address!\r\n"));
    return false;
  }
  else
  {
    Serial.print(F("\nIP Addr: ")); cc3000.printIPdotsRev(ipAddress);
    Serial.print(F("\nNetmask: ")); cc3000.printIPdotsRev(netmask);
    Serial.print(F("\nGateway: ")); cc3000.printIPdotsRev(gateway);
    Serial.print(F("\nDHCPsrv: ")); cc3000.printIPdotsRev(dhcpserv);
    Serial.print(F("\nDNSserv: ")); cc3000.printIPdotsRev(dnsserv);
    Serial.println();
    return true;
  }
}

//MORSE LOGIC

//define short morse function
void shortMorse(){
  // turn pin on
  digitalWrite(ledEyes, HIGH);
  digitalWrite(ledAnt, HIGH);
  analogWrite(beep, 180);
  // delay for a short amount of time
  delay(80);
  // turn pin off
  digitalWrite(ledEyes, LOW);
  digitalWrite(ledAnt, LOW);
  analogWrite(beep, 0);
  // delay for space between beeps
  delay(80);

}

//define long morse function
void longMorse(){
  // turn pin on
  digitalWrite(ledEyes, HIGH);
  digitalWrite(ledAnt, HIGH);
  analogWrite(beep, 180);
  // delay for a longer time than short function
  delay(186);
  // turn pin off
  digitalWrite(ledEyes, LOW);
  digitalWrite(ledAnt, LOW);
  analogWrite(beep, 0);
  // delay for space between beeps
  delay(80);

}

//create array of function pointers for each letter

 //A
int a(void){
  static void (*ptr[2])() = {shortMorse, longMorse};
  int k=0;
  for(k=0; k<2; k++)
    ptr[k]();
  return 0;
}
//B
int b(void){
  static void (*ptr[4])() = {longMorse, shortMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//C
int c(void){
  static void (*ptr[4])() = {longMorse, shortMorse, longMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//D
int d(void){
  static void (*ptr[3])() = {longMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//E
int e(void){
  static void (*ptr[1])() = {shortMorse};
  int k=0;
  for(k=0; k<1; k++)
    ptr[k]();
  return 0;
}
//F
int f(void){
  static void (*ptr[4])() = {shortMorse, shortMorse, longMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//G
int g(void){
  static void (*ptr[3])() = {longMorse, longMorse, shortMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//H
int h(void){
  static void (*ptr[4])() = {shortMorse, shortMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//I
int ix(void){
  static void (*ptr[2])() = {shortMorse, shortMorse};
  int k=0;
  for(k=0; k<2; k++)
    ptr[k]();
  return 0;
}
//J
int j(void){
  static void (*ptr[4])() = {shortMorse, longMorse, longMorse, longMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//K
int k(void){
  static void (*ptr[3])() = {longMorse, shortMorse, longMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//L
int l(void){
  static void (*ptr[4])() = {shortMorse, longMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//M
int m(void){
  static void (*ptr[2])() = {longMorse, longMorse};
  int k=0;
  for(k=0; k<2; k++)
    ptr[k]();
  return 0;
}
//N
int n(void){
  static void (*ptr[2])() = {longMorse, shortMorse};
  int k=0;
  for(k=0; k<2; k++)
    ptr[k]();
  return 0;
}
//O
int o(void){
  static void (*ptr[3])() = {longMorse, longMorse, longMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//P
int p(void){
  static void (*ptr[4])() = {shortMorse, longMorse, longMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//Q
int q(void){
  static void (*ptr[4])() = {longMorse, longMorse, shortMorse, longMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//R
int r(void){
  static void (*ptr[3])() = {shortMorse, longMorse, shortMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//S
int s(void){
  static void (*ptr[3])() = {shortMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//T
int t(void){
  static void (*ptr[1])() = {longMorse};
  int k=0;
  for(k=0; k<1; k++)
    ptr[k]();
  return 0;
}
//U
int u(void){
  static void (*ptr[3])() = {shortMorse, shortMorse, longMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//V
int v(void){
  static void (*ptr[4])() = {shortMorse, shortMorse, shortMorse, longMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//W
int w(void){
  static void (*ptr[3])() = {shortMorse, longMorse, longMorse};
  int k=0;
  for(k=0; k<3; k++)
    ptr[k]();
  return 0;
}
//X
int x(void){
  static void (*ptr[4])() = {longMorse, shortMorse, shortMorse, longMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//Y
int y(void){
  static void (*ptr[4])() = {longMorse, shortMorse, longMorse, longMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//Z
int z(void){
  static void (*ptr[4])() = {longMorse, longMorse, shortMorse, shortMorse};
  int k=0;
  for(k=0; k<4; k++)
    ptr[k]();
  return 0;
}
//SPACE
int space(void){
  delay(80);
}

// Custom function accessible by the API
int morseCommand(String command) {

  // params string

  if(command){
    Serial.println("Command recieved");
  }

  for (int i = 0; command[i] != '\0'; i++){

    if (command[i] == 'a') {
      a();
    }
    if (command[i] == 'b') {
      b();
    }
    if (command[i] == 'c') {
      c();
    }
    if (command[i] == 'd') {
      d();
    }
    if (command[i] == 'e') {
      e();
    }
    if (command[i] == 'f') {
      f();
    }
    if (command[i] == 'g') {
      g();
    }
    if (command[i] == 'h') {
      h();
    }
    if (command[i] == 'i') {
      ix();
    }
    if (command[i] == 'j') {
      j();
    }
    if (command[i] == 'k') {
      k();
    }
    if (command[i] == 'l') {
      l();
    }
    if (command[i] == 'm') {
      m();
    }
    if (command[i] == 'n') {
      n();
    }
    if (command[i] == 'o') {
      o();
    }
    if (command[i] == 'p') {
      p();
    }
    if (command[i] == 'q') {
      q();
    }
    if (command[i] == 'r') {
      r();
    }
    if (command[i] == 's') {
      s();
    }
    if (command[i] == 't') {
      t();
    }
    if (command[i] == 'u') {
      u();
    }
    if (command[i] == 'v') {
      v();
    }
    if (command[i] == 'w') {
      w();
    }
    if (command[i] == 'x') {
      x();
    }
    if (command[i] == 'y') {
      y();
    }
    if (command[i] == 'z') {
      z();
    }
    else {
      space();
    }

  }
  Serial.println("Command executed");
  return 1;
}
