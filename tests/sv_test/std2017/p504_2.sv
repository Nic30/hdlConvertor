task exercise_bus (MyBus bus);
int res;
// EXAMPLE 1: restrict to low addresses
res = bus.randomize() with {atype == low;};
// EXAMPLE 2: restrict to address between 10 and 20
res = bus.randomize() with {10 <= addr && addr <= 20;};
// EXAMPLE 3: restrict data values to powers-of-two
res = bus.randomize() with {(data & (data - 1)) == 0;};
endtask
