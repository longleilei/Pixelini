
struct IHDR
{
    unsigned int width;
    unsigned int height;
    unsigned unsigned char bitDepth;
    unsigned unsigned char colorType;
    unsigned unsigned char compressionType;
    unsigned unsigned char filterMethod;
    unsigned unsigned char interlace;
};

class PNG
{

    long long header{};
    IHDR ihdr{};
    std::unique_ptr<unsigned char[]> buffer;

public:
    PNG(std::string fileName);
};