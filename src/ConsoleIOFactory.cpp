//
// Created by Surfer Boy on 11/12/2024.
//

#include "ConsoleIOFactory.hpp"
#include "ConsoleOutputStream.hpp"
#include "ConsoleInputStream.hpp"

OutputStream *IIOFactory::OutputStream() {
    return new ConsoleOutputStream();
}
InputStream* IIOFactory::InputStream() {
    return new ConsoleInputStream();
}
InputStream* IIOFactory::ErrorStream() {
    return new ConsoleErrorStream();
}