#include <iostream>
#include <string>
//dependency needed for prompt
#include <fstream>

#define PROMPT_FILE "prompt.txt"

void printPrompt() {
    std::ifstream f(PROMPT_FILE);

    if (f.is_open()) {
        std::cout << f.rdbuf();
    }
}

void printHelpScreen() {
    std::cout << "---Limitations---\n";
    std::cout << "---This program only works with rectangles---\n";
    std::cout << "---All input is read from STDIN as a std::string---\n";
    std::cout << "---New Line Termination and Carriage Returns are inconsistent across platforms---\n";
    std::cout << "---All math is performed in doubles---\n";
    std::cout << "---Not a real REPL---\n";
    std::cout << "---Improvements---\n";
    std::cout << "---Store user input as uint32_t in inches or centimeters---\n";
    std::cout << "---All math is performed in int32_t, converted to double for printing only---\n";
}

#define CREDIT std::cout << "Mowing the lawn by John Spitler\n";
#define FT "feet"
#define MPH "mph"

//I don't like to type
void promptAndRead(std::string prompt, std::string &target) {
    std::cout << prompt;
    std::getline(std::cin, target);
}

//I sometimes needs to tell the user to use 'feet' :p
void promptAndReadUnits(std::string prompt, std::string unit, std::string &target) {
    return promptAndRead(prompt + "("+unit+") : ", target);
}

//Stackoverflow said to put constants as 'global' whatever that means.
const double mow = 1.5;

void doAssignment() {
    std::string L, W, HL, HW, Speed;

    std::cout << "First we will get some information on your lawn\n";
    promptAndReadUnits("lawn length",FT, L);
    promptAndReadUnits("lawn height",FT, W);
    std::cout << "Next we will remove the area of the 'house' from the 'lawn'\n";
    promptAndReadUnits("house length",FT, HL);
    promptAndReadUnits("house width",FT, HW);
    std::cout << "Finally let's gather information about your pace!\n(The average human walking speed is 2 mph on level groud)\n";
    promptAndReadUnits("walking speed",MPH, Speed);

    double lh = std::stod(L);
    double wh = std::stod(W);
    double hlh = std::stod(HL);
    double hwh = std::stod(HW);
    double sd = std::stod(Speed);
    double fpmwalk = sd / 60 * 5280;
    double apm = fpmwalk * mow;
    double eta = ((lh * wh) - (hlh * hwh)) / apm;
    CREDIT
    //I don't know how to use printf, cout is really annoying
    std::cout << "The lawn is " << lh << " by " << wh << " feet" << std::endl;
    std::cout << "Thw house is " << hwh << "by " << hlh << " feet" << std::endl;
    std::cout << "your walking speed is " << Speed << " miles per hour" << std::endl;
    std::cout << "the area to mow is " << ((lh * wh) - (hlh * hwh)) << " square feet" << std::endl;
    std::cout << "you can mow " << (fpmwalk * mow) << " sqare feet per minute" << std::endl;
    std::cout << "ETA to complete the lawn is " << eta << " minutes" << std::endl;
    return;
}

void oldLoop() {
    std::string L, W, HL, HW, Speed;
    std::cout << "please type the lawn length in feet : ";
    std::getline(std::cin, L);
    std::cout << "lawn width: ";
    std::getline(std::cin, W);
    std::cout << "house length: ";
    std::getline(std::cin, HL);
    std::cout << "house width: ";
    std::getline(std::cin, HW);
    std::cout << "walking speed (miles per hour): ";
    std::getline(std::cin, Speed);
    double lh = std::stod(L);
    double wh = std::stod(W);
    double hlh = std::stod(HL);
    double hwh = std::stod(HW);
    double sd = std::stod(Speed);
    double fpmwalk = sd / 60 * 5280;
    double apm = fpmwalk * mow;
    double eta = ((lh * wh) - (hlh * hwh)) / apm;
    std::cout << "Mowing the lawn by John Spitler";
    std::cout << "The lawn is " << lh << " by " << wh << " feet" << std::endl;
    std::cout << "Thw house is " << hwh << "by " << hlh << " feet" << std::endl;
    std::cout << "your walking speed is " << Speed << " miles per hour" << std::endl;
    std::cout << "the area to mow is " << ((lh * wh) - (hlh * hwh)) << " square feet" << std::endl;
    std::cout << "you can mow " << (fpmwalk * mow) << " sqare feet per minute" << std::endl;
    std::cout << "ETA to complete the lawn is " << eta << " minutes" << std::endl;
    std::cin.get();
}

int main() {
   
    
    bool run = true;
    while (run) {
        // Prompt the user to type something for each variable
        std::string cmd;
        promptAndRead("welcome to the lawn cutting eta. if you need help type 'help', 'credit', 'exit', or press 'Enter' to skip\n", cmd);
        if (cmd == "help") {
            printHelpScreen();
            std::cout << "\n\n";
        } else if (cmd == "credit") {
            CREDIT
        } else if (cmd == "prompt") {
            printPrompt();
        } else if (cmd == "exit") {
            run = false;
            std::cout << "good bye..! :0\n";
        } else {
            doAssignment();
            std::cout << "\n\n";
        }
    }
    
    return 0;
}