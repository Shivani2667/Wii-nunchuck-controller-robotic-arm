#include <Servo.h>
#include <NintendoExtensionCtrl.h>

Nunchuk nchuk;

// --- MOTORS ---
Servo base;
Servo shoulder;
Servo elbow;
Servo gripper;

// --- TUNING SETTINGS (Change these numbers if needed!) ---
int speed = 2;           // Movement speed (Higher = Faster)

// GRIPPER LIMITS
// Change these to make it open/close exactly how you want
int gripperOpen = 120 ;    // START HERE. Increase (e.g. 100) if it still opens too wide.
int gripperClosed = 160; // Max closed position. Lower (e.g. 150) if it buzzes.

// --- STARTING ANGLES ---
int baseAngle = 90;
int shoulderAngle = 90;
int elbowAngle = 90;

void setup() {
  Serial.begin(115200);

  // 1. Start Nunchuck
  nchuk.begin();
  while (!nchuk.connect()) {
    Serial.println("❌ Connecting... Check Wiring!");
    delay(1000);
  }
  Serial.println("✅ Nunchuck Ready!");

  // 2. Attach Motors (Check your pins!)
  base.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  gripper.attach(9);
  
  // 3. Move to safe starting positions
  base.write(baseAngle);
  shoulder.write(shoulderAngle);
  elbow.write(elbowAngle);
  gripper.write(gripperOpen); // Start in the "Fixed" open position
}

void loop() {
  if (nchuk.update()) {
    
    int joyX = nchuk.joyX();
    int joyY = nchuk.joyY();
    int cBtn = nchuk.buttonC();
    int zBtn = nchuk.buttonZ();

    // --- MODE 1: BASE & SHOULDER (Normal) ---
    // If C button is NOT pressed
    if (cBtn == 0) {
      if (joyX < 100) baseAngle -= speed;       // Turn Left
      if (joyX > 160) baseAngle += speed;       // Turn Right
      if (joyY < 100) shoulderAngle -= speed;   // Arm Down
      if (joyY > 160) shoulderAngle += speed;   // Arm Up
    }
    
    // --- MODE 2: ELBOW (Hold C Button) ---
    else {
      // While holding C, the stick moves the Elbow instead
      if (joyY < 100) elbowAngle -= speed;      // Elbow Down
      if (joyY > 160) elbowAngle += speed;      // Elbow Up
    }

    // --- GRIPPER LOGIC (Z Button) ---
    // Uses the new limits we defined at the top
    if (zBtn == 1) {
       gripper.write(gripperClosed); // CLOSE to 160
    } else {
       gripper.write(gripperOpen);   // OPEN to 90
    }

    // --- SAFETY LIMITS (0 to 180) ---
    baseAngle = constrain(baseAngle, 0, 180);
    shoulderAngle = constrain(shoulderAngle, 0, 180);
    elbowAngle = constrain(elbowAngle, 0, 180);

    // --- UPDATE MOTORS ---
    base.write(baseAngle);
    shoulder.write(shoulderAngle);
    elbow.write(elbowAngle);
  }
  
  delay(15); // Smoothness delay
}
