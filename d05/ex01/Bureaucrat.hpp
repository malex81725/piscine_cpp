/**
 * @Author: ademenet
 * @Date:   2017-04-10T11:48:57+02:00
 * @Last modified by:   ademenet
 * @Last modified time: 2017-04-10T18:37:27+02:00
 */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>

class Form;

class Bureaucrat {

public:
    Bureaucrat(const std::string name, unsigned int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat(void);
    Bureaucrat &operator=(Bureaucrat const &rhs);

    /* Getter */
    std::string getName() const;
    unsigned int getGrade() const;

    /* Functionnal */
    void incrementGrade();
    void decrementGrade();
    std::string display() const;

    /* Exceptions */
    class GradeTooLowException : public std::exception {
        public:
            GradeTooLowException();
            virtual ~GradeTooLowException() throw();
            GradeTooLowException(Bureaucrat::GradeTooLowException const &src);
            GradeTooLowException &operator=(GradeTooLowException const &rhs);
            virtual const char * what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public:
            GradeTooHighException();
            virtual ~GradeTooHighException() throw();
            GradeTooHighException(Bureaucrat::GradeTooHighException const &src);
            GradeTooHighException &operator=(GradeTooHighException const &rhs);
            virtual const char * what() const throw();
    };

private:
    Bureaucrat(void);

    /* Attributes */
    const std::string _name;
    unsigned int _grade; // from 1 (higher) to 150 (lowest)

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
