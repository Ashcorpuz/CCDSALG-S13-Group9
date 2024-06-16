# CCDSALG-S13-Group9
This project contains source code for CCDSALG project, all organized within the src/ directory

#Prerequisites
Before running the project, ensure you have the necessary tool installed on your machine:
## GCC Compiler:
Required for compiling C programs. Available default on most Linux distributions and macOS. Windows users may need to install MinGW or Cygwin.
## Make:
A build utility that simplifies the compilation process. It is highly recommended for automating the build process.
### Installing Make:
1. To install make, you can use chocolatey software. Open command prompt as Administrator and ensure you are using an administrative shell.
2. Install with powershell.exe
3. Copy this command: Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
4. Paste the command into your shell and press enter
5. Wait a few seconds for the command to complete
6. If you don't see any errors, you are ready to use Chocolatey! Type *choco* or *choco -?* or see full instructions/guide [here]([https://gnuwin32.sourceforge.net/packages/make.htm](https://chocolatey.org/install))
7. Now, enter "choco install make"
8. Next, enter "choco install mingw"

Using make, we can configure the program to automatically compile all C files, and be able to check the Makefile. 

To check if chocolatey software is now installed, enter the command "choco -v" -- this is the version that you have downloaded.

## How to run the program
### Using Make
Ensure make is installed, this method is preferred for its simplicity and efficiency.
-Run the project by navigating to the project's root directory/terminal and execute:
1. choco install make
2. Y or Yes
3. make
4. ls
5. cd bin/
6. dir app.exe
7. ./app.exe

^ This command reads the Makefile to compile all C files and generates the executable.
