Skate It (Wii) Decompilation
===============================

This repo was built using the decomp-toolkit-template.

See [decomp-toolkit](https://github.com/encounter/decomp-toolkit) and [dtk-template](https://github.com/encounter/dtk-template) for background on the concept and more information on the tooling used.

Note: this does **not** include any game assets or binaries or assemblies.

The decompiled game code can be found in the code folder.
This project aims to use a similar folder structure to the original source code's folder structure.

This project uses the leftover elf.bak file in the japanese release of skate it. 
You will need to rename the extension of sk82_na_f.elf.bak to sk82_na_f.elf,
and then use decomp toolkit to convert the binary to a .dol file:
dtk elf2dol sk82_na_f.elf main.dol
You can then place main.dol in orig\RVSE69\DATA\sys before running ninja in the root project folder to generate the split object and disassembly files.

This project requires python 3 and ninja.
You can install ninja through pip using:
pip install ninja