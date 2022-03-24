//
// Created by amina on 3/24/2022.
//

#ifndef FS_SCORE_V2_ELEMENTEXCEPTION_H
#define FS_SCORE_V2_ELEMENTEXCEPTION_H

#include <exception>
#include <string>

class ElementException : public std::exception{
private: std::string _message;
public:
    ElementException(const std::string& message);
    const std::string& get_message() const;

};


#endif //FS_SCORE_V2_ELEMENTEXCEPTION_H
