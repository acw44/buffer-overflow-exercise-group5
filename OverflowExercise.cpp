#include <iostream>
#include <cstring>
#include <cstdlib>

void secret_function() {
    std::cout << "\n[!] Success: Code execution redirected to secret_function()!\n";
}


void function1(char* input) {
    char buffer[16]; 
    std::cout << "[+] Address of buffer:          " << (void*)buffer << "\n";
    std::cout << "[+] Address of secret_function: " << (void*)&secret_function << "\n";

    strcpy(buffer, input);
    secret_function();
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

