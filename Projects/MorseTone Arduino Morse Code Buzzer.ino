const int buzzer = 8;
const int dotDuration = 100;   // Dot: 100ms
const int dashDuration = 300;  // Dash: 300ms
const int frequency = 555;     // Tone frequency

String morseCode(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case ' ': return " ";
    default: return "";
  }
}

void playDot() {
  tone(buzzer, frequency);
  delay(dotDuration);
  noTone(buzzer);
}

void playDash() {
  tone(buzzer, frequency);
  delay(dashDuration);
  noTone(buzzer);
}

void playMorse(String text) {
  Serial.println("Text: " + text);
  Serial.print("Morse: ");

  for (int i = 0; i < text.length(); i++) {
    String code = morseCode(text[i]);

    if (code == " ") {
      Serial.print(" / ");
      delay(dotDuration * 7); // Word gap
    } else {
      Serial.print(code + " ");
      for (int j = 0; j < code.length(); j++) {
        if (code[j] == '.') playDot();
        else if (code[j] == '-') playDash();

        // Only add intra-symbol spacing if not the last symbol
        if (j < code.length() - 1) delay(dotDuration);
      }
      // Gap between letters
      delay(dotDuration * 3);
    }
  }
  Serial.println();
}

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  playMorse("PRAJYOT DAPHAL");
}

void loop() {
  // nothing
}
