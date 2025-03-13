## Femtosat Verification Program

Simple program that uses a pico debugger to verify that the BME280, BNO086, and LR62XE on a newly assembled femtosat are working. 

## Usage
Import this folder as a project into the VS Code Raspberry Pi Pico extension:
1. Set up your Raspberry Pi Pico development environment by following chapter 3 of [this](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) guide
2. Clone this repo and its submodules using your preferred method.
- If you're new to git, I'd recommend [Github Desktop](https://github.com/apps/desktop).
- If you're downloading a zip archive from Github, make sure that you download each linked submodule (external repositories linked in the lib folder) manually as they will not be included.
2. Click "Import Project" under the General tab from within the extension.
3. Select the location of this folder
4. Change the debugger from DebugProbe to SWD (If you're using a pico to debug. If you're using the debug probe, leave it as-is.)
5. Click "Import"
6. Click "Configure CMake" under the Project tab from within the extension.
7. Set a debugging breakpoint in main.cpp in the src folder. It should be near line 121, with a comment saying BREAKPOINT HERE
8. Power on the femtosat with a bench top power supply. 9V to the GSE input usually works fine. Pay attention to polarity.
9. Connect the debugger wires to the debugging header on the pico. 
- Starting from the board edge going to the center, the wire colors should be orange, black, yellow (with the pico debug probe).
10. Debug the project from the pico extension window. This will start a debugging session.
11. Continue the debugging session until you hit the breakpoint set earlier
12. Verify that the initialization state variables in the debugger match the expected values. 
- If not, that sensor is not operational. Check solder joints and replace the component if necessary.
- Error code specifics can be found [here](https://jgromes.github.io/RadioLib/group__status__codes.html) for the LoRa module, and within lib\BME280_Drivers\bme280_defs.h for the BME280. The BNO086 does not give any useful error codes.