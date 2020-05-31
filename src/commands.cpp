//
// Created by mornie on 30.05.2020.
//

#include "commands.hpp"

void load_command_t::apply(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        this->print_help();
    }
    else {
        images[args[1]] = new Magick::Image;
        try {
            images[args[1]]->read(args[2]);
            std::cout << "The image was successfully loaded." << std::endl;
        }
        catch (const Magick::Exception& e) {
            std::cout << "Caught Magick exception: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
}

void load_command_t::print_help() {
    std::cout << "Usage: load <name> <filename>,\n"
                 "       ld <name> <filename>\n";
}

void store_command_t::apply(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        this->print_help();
    }
    else if (!images[args[1]]) {
        std::cout << "There's no such image in memory. Specify a valid name." << std::endl;
    }
    else {
        try {
            images[args[1]]->write(args[2]);
            std::cout << "The image was successfully stored.\n";
        }
        catch (const Magick::Exception &e) {
            std::cout << "Caught Magick exception: " << e.what() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
}

void store_command_t::print_help() {
    std::cout << "Usage: store <name> <filename>,\n"
                 "       s <name> <filename>\n";
}

void blur_command_t::apply(const std::vector<std::string> &args) {
    // No matching names validation is performed,
    // Magick::Exception will be thrown.
    if (args.size() != 4) {
        this->print_help();
    }
    else if (!images[args[1]]) {
        std::cout << "There's no such image in memory. Specify a valid name." << std::endl;
    }
    else {
        try {
            images[args[2]] = new Magick::Image;
            *images[args[2]] = *images[args[1]];
            images[args[2]]->blur(stod(args[3]), 2.0);
            std::cout << "The image was successfully blurred." << std::endl;
        }
        catch (const Magick::Exception &e) {
            std::cout << "Caught Magick exception: " << e.what() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
}

void blur_command_t::print_help() {
    std::cout << "Usage: blur <from_name> <to_name> <size>" << std::endl;
}

void resize_command_t::apply(const std::vector<std::string> &args) {
    // No matching names validation is performed,
    // Magick::Exception will be thrown.
    if (args.size() != 5) {
        this->print_help();
    }
    else if (!images[args[1]]) {
        std::cout << "There's no such image in memory. Specify a valid name." << std::endl;
    }
    else {
        try {
            std::string c;
            c.append(args[3]);
            c.append("x");
            c.append(args[4]);
            c.append("!");
            images[args[2]] = new Magick::Image;
            *images[args[2]] = *images[args[1]];
            images[args[2]]->resize(c);
            std::cout << "The image was successfully resized.\n";
        }
        catch (const Magick::Exception &e) {
            std::cout << "Caught Magick exception: " << e.what() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
}

void resize_command_t::print_help() {
    std::cout << "Usage: resize <from_name> <to_name> <new_width> <new_height>\n";
}

// Help command class: prints help message
void help_command_t::apply(const std::vector<std::string> &args) {
    /*
     * No need to check the number of args here.
     * If the user doesn't know how to use the app,
     * print this help message disregarding
     * all the possible redundant arguments.
     */
    std::cout <<
              "Usage:\n"
              "  -  load <name> <filename>,   : load a JPG-file with with the name <filename>\n"
              "     ld <name> <filename>        and save it in memory by the name <name>.\n"
              "  -  store <name> <filename>,  : save the image with the name <name>\n"
              "     s <name> <filename>         to a JPG-file with the name <filename>.\n"
              "  -  blur <from_name> <to_name> <radius>\n"
              "                               : blur the image <from_name> by specifying\n"
              "                                 the <radius> value and save it in memory\n"
              "                                 by the name <to_name>. Please note that\n"
              "                                 due to sigma value being hardcoded to value '2.0',\n"
              "                                 <radius> value of either '0' or at a minimum\n"
              "                                 double that of the sigma is recommended.\n"
              "  -  resize <from_name> <to_name> <new_width> <new_height>\n"
              "                               : change the dimensions of the image <from_name>\n"
              "                                 to width <new_width> and height <new_height>\n"
              "                                 and save it in memory by the name <to_name>.\n"
              "                                 Please note that aspect ratio is ignored.\n"
              "  -  help, h                   : print this help message.\n"
              "  -  exit, quit, q             : quit the application.\n";
}

void help_command_t::print_help() {}

void exit_command_t::apply(const std::vector<std::string> &args) {
    end_session = true;
}

void exit_command_t::print_help() {}