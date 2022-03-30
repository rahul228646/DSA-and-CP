- representation of binary - 

  - msb is 0 = covert to decimal
  - msb is 1 = 2's compliment -> convert to decimal -> add -ve sign
  
- min number for 4 bits is -8 (1000)
- max number for 4 bits is  7 (0111)
- range for n bits is (-2^n to 2^n - 1)
- if a number in binary is 1001 then 1001 >> 2 will give 1110 -- two one are added since msb is one
- if a number in binary is 0111 then 0111 >> 2 will give 0001 -- two zeros are added since msb is zero
- | to switch on a bit, & to turn off a bit , ^ to toggle a bit and & to check a bit

<img width="474" alt="Screenshot 2022-03-30 at 4 15 35 PM" src="https://user-images.githubusercontent.com/56363090/160814256-51724c98-e2b1-47cb-948b-c6f058fa0a69.png">
