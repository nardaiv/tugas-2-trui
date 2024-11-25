#include <iostream>
#include <vector>
#include <string>

class RobotPart{
private:
    std::string partName;
    int pwmValue;

public:
    RobotPart(const std::string& name, int pwm)
        : partName(name), pwmValue(pwm) {}
    
    // destructor
    virtual ~RobotPart() = default;

    virtual void performAction() = 0;

    void screamTopic(){
        std::cout << "This is " <<  partName << "dengan nilai PWM: " << pwmValue << std::endl;

    } 

    std::string getPartName() const{
        return partName;
    }

    int getPwmValue() const{
        return pwmValue;
    }

};

class RobotLeg : public RobotPart{
private:


public:
    RobotLeg(const std::string& name, int pwm)
        : RobotPart(name + " Leg", pwm){}
    
    void performAction() override{
        std::cout << getPartName() << ": Berjalan dan menendang bola dengan PWM: " << getPwmValue() << std::endl;
    }

};

int main(){

    return 0;
}