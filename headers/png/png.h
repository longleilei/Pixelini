
struct IHDR{
    unsigned int width; 
    unsigned int height; 
    unsigned char bitDepth; 
    unsigned char colorType; 
    unsigned char compressionType; 
    unsigned char filterMethod; 
    unsigned char interlace; 

}; 

class PNG {

    long long header{}; 
    IHDR ihdr{}; 
    std::unique_ptr<char[]> buffer; 
public: 
    PNG(std::string fileName); 


    
}; 