#include <iostream>
using std::cout,std::cin,std::string,std::endl;
// speak.cpp
// Speaks whatever text is given, using a female voice on each OS.
//
// Build:  g++ -std=c++17 -O2 -o speak speak.cpp
// Run:    ./speak "Hello, world!"   or run with no args to type lines

// STEP 1: Detect the OS at compile time, since each one needs a
// different TTS command.
#if defined(_WIN32)
    #define PLATFORM_WINDOWS
#elif defined(__APPLE__)
    #define PLATFORM_MACOS
#elif defined(__linux__)
    #define PLATFORM_LINUX
#endif

// STEP 2: Escape single quotes for macOS/Linux shell commands, so the
// text can't break out of the quoted argument.
std::string shellEscapeSingleQuotes(const std::string& text) {
    std::string escaped;
    escaped.reserve(text.size());
    for (char c : text) {
        if (c == '\'') escaped += "'\\''";
        else escaped += c;
    }
    return escaped;
}

// STEP 3: Escape double quotes/backticks for the Windows PowerShell string.
std::string shellEscapeDoubleQuotes(const std::string& text) {
    std::string escaped;
    escaped.reserve(text.size());
    for (char c : text) {
        if (c == '"') escaped += "`\"";
        else if (c == '`') escaped += "``";
        else escaped += c;
    }
    return escaped;
}

// STEP 4: Build and run the right TTS command for this OS, using a
// female voice.
bool speak(const std::string& text) {
    if (text.empty()) return true;

    std::string command;

#if defined(PLATFORM_MACOS)
    // "Samantha" is macOS's default female voice.
    command = "say -v Samantha '" + shellEscapeSingleQuotes(text) + "'";

#elif defined(PLATFORM_LINUX)
    // espeak/espeak-ng: "+f3" selects a female voice variant.
    command = "espeak-ng -v en+f3 '" + shellEscapeSingleQuotes(text) +
              "' 2>/dev/null || espeak -v en+f3 '" + shellEscapeSingleQuotes(text) + "'";

#elif defined(PLATFORM_WINDOWS)
    // Ask System.Speech to pick an installed female voice before speaking.
    std::string escaped = shellEscapeDoubleQuotes(text);
    command =
        "powershell -Command \""
        "Add-Type -AssemblyName System.Speech; "
        "$synth = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
        "$synth.SelectVoiceByHints('Female'); "
        "$synth.Speak(\\\"" + escaped + "\\\")\"";
#else
    std::cerr << "Unsupported platform: no TTS backend configured.\n";
    return false;
#endif

    // STEP 5: Run the command via the OS shell.
    int result = std::system(command.c_str());
    if (result != 0) {
        std::cerr << "TTS command failed. On Linux, make sure espeak or "
                     "espeak-ng is installed (e.g. `sudo apt install espeak`).\n";
        return false;
    }
    return true;
}

// STEP 6: main() decides where the text comes from, then speaks it.
int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string text;
        for (int i = 1; i < argc; ++i) {
            if (i > 1) text += " ";
            text += argv[i];
        }
        speak(text);
        return 0;
    }

    std::cout << "Enter text to speak (empty line or Ctrl+D to quit):\n";
    std::string line;
    while (std::cout << "> " && std::getline(std::cin, line)) {
        if (line.empty()) break;
        speak(line);
    }
    return 0;
}
