# Simple DES Encryption and Decryption - C++

## Overview

This project is an implementation of the **Simplified Data Encryption Standard (DES)** algorithm using **C++**. The goal is to demonstrate the encryption and decryption process using a simplified version of DES, where a **10-bit key** and **8-bit plaintext** are used.

## Features

- **DES Encryption:** Converts plaintext into ciphertext using a simplified DES process.
- **DES Decryption:** Recovers the original plaintext from ciphertext.
- **Key Generation:** Implements key scheduling using permutation and bit shifting.
- **Customizable Parameters:** Users can modify:
  - Encryption key
  - Plaintext
  - P10, P8, P4 permutations
  - Initial and inverse permutation (IP, IPI)
  - Expansion permutation (E/P)
- **Step-by-Step Analysis:** Displays key generation, encryption, and decryption steps.
- **Interactive CLI Menu:** Provides an intuitive interface for testing encryption and decryption.

## Capabilities

1. **Encrypt and Decrypt Messages** - Users can enter plaintext and keys to see encryption and decryption results.
2. **Step-by-Step Key Generation** - Shows how DES keys are derived through permutations and shifts.
3. **View Encryption Process** - Displays all intermediate steps, including function calculations and S-Box transformations.
4. **View Decryption Process** - Shows how ciphertext is transformed back to plaintext.
5. **Modify DES Parameters** - Users can change permutation tables, initial key, and plaintext.

## Installation

### Prerequisites

- **C++ Compiler** (e.g., g++, clang++)
- **Windows Operating System** (required due to Windows-specific libraries used)

### Build and Run

```sh
# Clone the repository
git clone https://github.com/erfan-tahvilian/simple-des.git
cd simple-des

# Compile the project
g++ -o simple-des.exe main.cpp -std=c++17

# Run the program
simple-des.exe
```

## Usage

1. **Select an option** from the main menu:
   - `[1] Simple DES with default initialization` → Runs DES encryption/decryption with predefined values.
   - `[2] Show key generation steps` → Displays the detailed process of key generation.
   - `[3] Show encryption steps` → Displays encryption calculations step-by-step.
   - `[4] Show decryption steps` → Displays decryption calculations step-by-step.
   - `[5] Change Key` → Modify the encryption key.
   - `[6] Change Plain Text` → Modify the input plaintext.
   - `[7-11] Change permutation values (P10, P8, P4, IP, IPI, E/P)` → Adjust transformation tables.
   - `[12] Exit` → Close the application.
2. **View results:**
   - **Key Generation Steps:** Shows key derivation using P10 and P8 permutations.
   - **Encryption Steps:** Displays intermediate calculations including S-Boxes and bitwise operations.
   - **Decryption Steps:** Reverses the encryption process and restores plaintext.

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

## Support & Donations

If you find this project useful and would like to support further development, you can donate via:

- **Tron (TRX) Address:** `TL8WyZLLGu8UraHAT8dCoeMsnzGpX2oAYn`
- **Binance Coin (BNB - BEP20) Address:** `0xeC4F61F21238685cC842bC236D86684e5fc2Bc57`
- **Bitcoin (BTC) Address:** `bc1q2y9m8y02fqgsr4c6533duwmqtmrhadc8k8mkt4`

Your support is greatly appreciated! 🚀