#include <iostream>
#include <memory>

// Base interface for a data stream
class DataStream {
public:
    virtual void write(const std::string& data) = 0;
    virtual ~DataStream() = default;
};

// Concrete component: Basic file stream
class FileStream : public DataStream {
public:
    void write(const std::string& data) override {
        std::cout << "[FileStream] Writing data: " << data << std::endl;
    }
};

// Base decorator class
class StreamDecorator : public DataStream {
protected:
    std::unique_ptr<DataStream> stream;
public:
    StreamDecorator(std::unique_ptr<DataStream> s) : stream(std::move(s)) {}
    void write(const std::string& data) override {
        stream->write(data);
    }
};

// Concrete decorator: Buffering
class BufferedStream : public StreamDecorator {
public:
    BufferedStream(std::unique_ptr<DataStream> s) : StreamDecorator(std::move(s)) {}
    void write(const std::string& data) override {
        std::cout << "[BufferedStream] Buffering data..." << std::endl;
        stream->write(data);
    }
};

// Concrete decorator: Compression
class CompressedStream : public StreamDecorator {
public:
    CompressedStream(std::unique_ptr<DataStream> s) : StreamDecorator(std::move(s)) {}
    void write(const std::string& data) override {
        std::cout << "[CompressedStream] Compressing data..." << std::endl;
        stream->write("COMPRESSED(" + data + ")");
    }
};

// Concrete decorator: Encryption
class EncryptedStream : public StreamDecorator {
public:
    EncryptedStream(std::unique_ptr<DataStream> s) : StreamDecorator(std::move(s)) {}
    void write(const std::string& data) override {
        std::cout << "[EncryptedStream] Encrypting data..." << std::endl;
        stream->write("ENCRYPTED(" + data + ")");
    }
};

// Test the decorator pattern
int main() {
    std::unique_ptr<DataStream> stream = std::make_unique<FileStream>();
    
    // Apply decorators: Buffering -> Compression -> Encryption
    stream = std::make_unique<BufferedStream>(std::move(stream));
    stream = std::make_unique<CompressedStream>(std::move(stream));
    stream = std::make_unique<EncryptedStream>(std::move(stream));

    // Write data with all decorators applied
    stream->write("Hello, World!");

    return 0;
}
