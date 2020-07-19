// MyLC-3-VM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>

#include "LC-3-Hardware.h"

using std::cout, std::endl, std::hex, std::cerr, std::showbase;

Op inline parse_op(Instr &instr) {
    return static_cast<Op>((instr >> 12).to_ulong());
}

Instr inline fetch_instr(uint16_t addr) {
    cout << "Fetch instruction at address: " << showbase << hex << addr << endl;
    return memory.at(addr);
}

void init(int argc, const char* argv[]) {
    reg[R_PC] = PC_START;

    // Argument parsing
    if (argc < 2)
    {
        cerr << argv[0] << " [executable.lc3] ..." << endl;
        exit(2);
    }

    // Open file to 
    std::filesystem::path exe = argv[1];
    std::ifstream fd(exe, std::ios::binary);

    // Check if file exists
    if (!fd.is_open()) {
        cerr << "Couldn't find file " << exe << endl;
        exit(2);
    }

    // Copy file to memory at PC_START
    auto stream = std::istreambuf_iterator<char>(fd);
    auto end_stream = std::istreambuf_iterator<char>();
    auto pos = memory.begin();
    std::advance(pos, PC_START);
    std::copy(stream, end_stream, pos);

    cout << "First 100 bytes of payload" << endl;
    for (size_t i = PC_START; i < PC_START + 100; i++) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << std::showbase << std::setw(4) << std::right << hex << memory[i] << " ";
    }
}

int main(int argc, const char* argv[])
{
    init(argc, argv);

    bool running = true;
    cout << "Start executing ..." << endl;
    while (running) {    
        // Fetch
        Instr instr = fetch_instr(reg[R_PC]++);

        // Decode
        Op op = parse_op(instr);
        switch (op) {
        case Op::BR: /* branch */
            break;
        case Op::ADD:    /* add  */
            break;
        case Op::LD:     /* load */
            break;
        case Op::ST:     /* store */
            break;
        case Op::JSR:    /* jump register */
            break;
        case Op::AND:    /* bitwise and */
            break;
        case Op::LDR: /* load register */
            break;
        case Op::STR:    /* store register */
            break;
        case Op::LEA:    /* load effective address */
            break;
        case Op::TRAP: /* execute trap */
            break;
        case Op::NOT:    /* bitwise not */
            break;
        case Op::LDI: /* load indirect */
            break;
        case Op::STI:    /* store indirect */
            break;
        case Op::JMP:    /* jump */
            break;
        case Op::RES:    /* reserved (unused) */
            break;
        case Op::RTI:    /* unused */
            break;
        default:
            std::stringstream ss;
            ss << "Instruction does not exist: 0x" << std::hex << instr << std::endl;
            throw std::runtime_error(ss.str());
        }

    }

    std::cout << "Done executing!\n";
}
