/* 
 * File:   exceptionsprob1.h
 * Author: leannapangan
 *
 * 
 */

#ifndef EXCEPTIONSPROB1_H
#define	EXCEPTIONSPROB1_H

// exception class thrown in getProductID() if product is not found in the array
class Exception_ID_Not_Found : public std::exception {
    
    public:
        const char *what() const throw() {
            return "Product name is not found in the array.";
        }
};

// function that retrieves the product id of a product in the array
int getProductID(int ids[], std::string names[], int numProducts, std::string target);

#endif	/* EXCEPTIONSPROB1_H */

