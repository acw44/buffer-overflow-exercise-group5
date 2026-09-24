// Group 5 Buffer Overflow Exercise
// i used Github Copilot for C++ help bc i only know js in recent years - andrew

#include <iostream>
#include <string>
#include <cstring>

// removed secret_function to prevent exploitation
void function1(const std::string& input) {
    char buffer[16] = {0};
    std::cout << "[+] Address of buffer: " << static_cast<const void*>(buffer) << "\n";
    std::cout << "[+] Input length: " << input.size() << "\n";

    // checking if input is too long
    if (input.size() >= sizeof(buffer)) {
        std::cout << "[-] Input is too long for the buffer. Refusing to copy.\n";
        return;
    }

    // copying input safely
    std::strncpy(buffer, input.c_str(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    std::cout << "[+] Copied input: " << buffer << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input_string>\n";
        return 1;
    }

    std::cout << "[+] Starting program...\n";
    function1(argv[1]);
    std::cout << "[-] Exiting normally.\n";

    return 0;
}