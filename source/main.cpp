#include "flags.h"

const flag flagsQuad[] {
    {"-h", "--help", "shows avalible commands"},
    {"-t", "--test", "runs tests"}
};

int main(int argc, const char *argv[]) {
    int flagsSize = sizeof(flagsQuad) / sizeof(flag);
    checkFlags(argc, argv, flagsSize, flagsQuad);
}
