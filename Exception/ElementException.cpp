//
// Created by amina on 3/24/2022.
//

#include "ElementException.h"

ElementException::ElementException(const std::string &message): std::exception(), _message{message} {

}

const std::string &ElementException::get_message() const {
    return this->_message;
}
