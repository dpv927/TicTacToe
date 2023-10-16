#ifndef BITS_H
#define BITS_H

#define getBit(word,bit) (word&(0x01<<(bit)))
#define setbit(word,bit) (word|=(0x01<<(bit)))

#define changeBit(word,bit) (word^=(0x01<<(bit)))
#define setZeroBit(word,bit) (word&=~(0x01<<(bit)))

#endif // !BITS_H
