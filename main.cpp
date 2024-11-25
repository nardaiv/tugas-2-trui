#include <iostream>
#include <vector>
#include <string>
#include <memory>

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
        std::cout << "Ini adalah " <<  partName << " dengan nilai PWM: " << pwmValue << std::endl;

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

class RobotHead : public RobotPart{
private:
    bool hasCamera;
    bool hasInfrared;

public:
    RobotHead(bool cam, bool inf, int pwm)
        : RobotPart("Head", pwm), hasCamera(cam), hasInfrared(inf) {}
    
    void performAction() override{
        std::cout << getPartName() << ": Menganalisis dengan Kamera:: " << (hasCamera ? "Nyala" : "Mati") << ", Sensor Infrared: " << (hasInfrared ? "Aktif" : "Tidak Aktif") << ", dan PWM: "<< getPwmValue() <<std::endl;
    }
};

class HumanoidRobot{
private:
    std::vector<RobotPart*> parts;

public:
    //HumanoidRobot(){}

    void addPart(RobotPart* part){
        parts.push_back(part);
    }

    void controlParts(){
        for(const auto& part : parts){
            part->performAction();
            part->screamTopic();
        }
    }

    virtual ~HumanoidRobot() = default;
};

int main(){

    // Membuat objek robot humanoid
    HumanoidRobot gladiatosRobot;

    // Menambahkan bagian tubuh ke robot (Inheritance dan Polimorfisme)
    gladiatosRobot.addPart(new RobotLeg("Left", 120));  // PWM 120
    gladiatosRobot.addPart(new RobotLeg("Right", 130)); // PWM 130
    gladiatosRobot.addPart(new RobotLeftArm(true, 140)); // Sensor aktif, PWM 140
    gladiatosRobot.addPart(new RobotRightArm(true, 150)); // Tangan bisa menggenggam, PWM 150
    gladiatosRobot.addPart(new RobotHead(true, true, 160)); // Kamera dan Infrared aktif, PWM 160

    // Mengontrol semua bagian tubuh robot
    std::cout << "Mengontrol Bagian-Bagian Tubuh Gladiatos Robot:" << std::endl;
    gladiatosRobot.controlParts();

    return 0;
}