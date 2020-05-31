//
// Created by mornie on 30.05.2020.
//

#ifndef IMAGE_MAGICK_TEST_COMMANDS_HPP
#define IMAGE_MAGICK_TEST_COMMANDS_HPP

#include "Magick++.h"
#include <iostream>
#include <vector>

// A function to clear memory used to store container objects
//template <typename M> void map_mem_clear(M& mmap);

// A flag to keep terminal session running
extern bool end_session;

// Container to keep track of images by their names
extern std::map< std::string, Magick::Image * > images;

// Base class for a terminal command
class command_t {
public:
    virtual ~command_t() = default;
    virtual void apply(std::vector< std::string > const &args) = 0;
    virtual void print_help() = 0;
};

// Container to store commands
extern std::map< std::string, command_t * > commands;

// Load command class: performs image loading from disk
class load_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

// Store command class: performs image writing to disk
class store_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

// Blur command class: performs image copying and blurring
class blur_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

// Resize command class: performs image copying and resizing
class resize_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

// Help command class: prints help message
class help_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

// Exit command class: performs application closing
class exit_command_t : public command_t {
public:
    void apply(std::vector< std::string > const &args) override;
    void print_help() override;
};

#endif //IMAGE_MAGICK_TEST_COMMANDS_HPP
