//
// Created by artom on 24.10.2021.
//

#ifndef COURSEPROJECT4AND6_ICOMPANY_H
#define COURSEPROJECT4AND6_ICOMPANY_H

class ICompany {
    virtual const char *getNameOfCompany() = 0;
    virtual void setNameOfCompany(const char *) = 0;
};

#endif //COURSEPROJECT4AND6_ICOMPANY_H
