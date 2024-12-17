//
// Created by Surfer Boy on 11/12/2024.
//

#include "ConsoleIOFactory.hpp"
#include "../Standards/ConsoleOutputStream.hpp"
#include "../Standards/ConsoleInputStream.hpp"
#include "../Standards/ConsoleErrorStream.hpp"

OutputStream* ConsoleIOFactory::fabricateOutputStream() {
    return new ConsoleOutputStream();
}
InputStream* ConsoleIOFactory::fabricateInputStream() {
    return new ConsoleInputStream();
}
ErrorStream* ConsoleIOFactory::fabricateErrorStream() {
    return new ConsoleErrorStream();
}
