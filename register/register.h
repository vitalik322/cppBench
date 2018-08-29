void benchWithoutRegister(int opNum) {
    for (int i1 = 0; i1 < opNum; ++i1)
        for (int i2 = 0; i2 < opNum; ++i2)
            for (int i3 = 0; i3 < opNum; ++i3);
}

void benchWithRegister(int opNum) {
    for (register int i1 = 0; i1 < opNum; ++i1)
        for (register int i2 = 0; i2 < opNum; ++i2)
            for (register int i3 = 0; i3 < opNum; ++i3);
}
