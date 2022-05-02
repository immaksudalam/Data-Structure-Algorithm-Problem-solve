class{
public:
    int swapNibbles(unsigned char N){
        int h1 = N & 15;  // N AND 00001111
        int h2 = N & 240;  // N AND 11110000
        return (h1<<4) + (h2>>4);  //Exchange positions of h1 and h2;
   }
}
