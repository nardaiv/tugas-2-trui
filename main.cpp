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

class RobotLeftArm : public RobotPart{
private:
    bool hasSensor;

public:
    RobotLeftArm(bool sensor, int pwm) 
        : RobotPart("Left Arm", pwm), hasSensor(sensor) {};

    void performAction() override{
        std::cout << getPartName() << ": Menyeimbangkan dengan status sensor: " << (hasSensor ? "Aktif" : "Tidak Aktif") << " dan PWM: "<< getPwmValue() <<std::endl;
    }
};

class RobotRightArm : public RobotPart{
private:
    bool canGrab;

public:
    RobotRightArm(bool grab, int pwm)
        : RobotPart("Right Arm", pwm), canGrab(grab) {}

    void performAction() override{
        std::cout << getPartName() << ": Menggenggam objek dengan tangan:: " << (canGrab ? "Bisa" : "Tidak Bisa") << " dan PWM: "<< getPwmValue() <<std::endl;
    }
};

int main(){

    return 0;
}