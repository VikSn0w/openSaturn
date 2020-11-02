# openSaturn <img src="https://i.ibb.co/H708hk5/square-open-Saturn.png" width="60" height="60">

Open-source emulator of the LVDC processor of the Saturn V.


For more informations about the LDVC, check the Wikipedia page: https://en.wikipedia.org/wiki/Launch_Vehicle_Digital_Computer

---
## Alpha 1 (0.0.1)

### What's already coded:
  #### Instruction
  * Loader (Partial)
  * Checker (Total)
  * Set (Logic model still under development)
  
  ##### Special instructions:
  These instructions use 2 bits from the address to from the call code
  * **SHR** - 01 1110 (0cXX1 / 0cXX5)
  * **CDS** - x0 1110 (0cXX0 / 0cXX2 / 0cXX4 / 0cXX6)
  * **EXM** - 11 1110 (0cXX3 / 0cXX7)
  
  Documentation about the instructions coming soon.
   
  #### Data
  * Data Loader (Total)
  * Data Checker (Total)

  #### Memory
  Model (Total Mathematical / Partially coded - for memory addressing is used the octal format)
  
  ##### Memory scheme:
  
  
  Data Word -> 26 bit (256 in a Sector)
  
  
  Instruction Word -> 14 bit (256 in a Sector)
  
  * x-xxxxxxxxx-xxxx (Parity - Memory Address - Op Code)
  
  Known register:
  * Accumulator Register: 26 bit (fixed address 0c000)
  * Result Register     : 26 bit (fixed address 0c001)
