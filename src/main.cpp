#include "Magick++.h"
#include "commands.hpp"
#include "tokenizer.hpp"

bool end_session;

std::map< std::string, Magick::Image * > images;
std::map< std::string, command_t * > commands;

// Clear memory used to store container objects
template <typename M> void map_mem_clear(M& mmap) {
    for (auto it = mmap.begin(); it != mmap.end(); ++it) {
        delete it->second;
    }
    mmap.clear();
}

int main(int argc, char **argv){
    end_session = false;

    // Populate the commands container
    commands["load"] = new load_command_t();
    commands["ld"] = new load_command_t();;
    commands["store"] = new store_command_t();
    commands["s"] = new store_command_t();
    commands["blur"] = new blur_command_t();
    commands["resize"] = new resize_command_t();
    commands["help"] = new help_command_t();
    commands["h"] = new help_command_t();
    commands["exit"] = new exit_command_t();
    commands["quit"] = new exit_command_t();
    commands["q"] = new exit_command_t();

    // Main loop
    while (!end_session){
        std::string cmd;
        std::cout << ">>> ";
        std::getline(std::cin, cmd); // Read a string from the console

        std::vector< std::string > tokens = tokenize(cmd); // Tokenize the string

        auto iter = commands.find(tokens[0]);
        if (iter != commands.end()){            // If the command was found...
            commands[tokens[0]]->apply(tokens); // ...perform the corresponding action
        }
        else {                                  // Otherwise, print a warning
            std::cout << "Invalid command. Use \'help\' or \'h\' to see the list of all available commands.\n";
        }
    }
    map_mem_clear(images);
    map_mem_clear(commands);
}
