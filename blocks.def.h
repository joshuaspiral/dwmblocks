// blocks.def.h
static const Block blocks[] = {
    /*Icon*/    /*Command*/                                        /*Interval*/  /*Signal*/
    
    // 1. Pacman Updates (Icon: Arch Linux Logo)
    {" ", "checkupdates | wc -l",                                 3600,         0},

    // 2. CPU Load (Icon: Microchip)
    {" ", "cat /proc/loadavg | awk '{print $1}'",                 5,            0},

    // 3. Disk Space (Icon: Hard Drive)
    {" ", "df -h / | awk '/\\// { print $4 }'",                   60,           0},

    // 4. Memory (Icon: RAM Stick)
    {" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30,        0},

    // 5. Battery (Icon: Battery)
    {" ", "cat /sys/class/power_supply/BAT*/capacity",            30,           0},

    // 6. Volume (Icon is inside the script)
    {"", "/home/joshua/.scripts/volume.sh",                        0,            10},

    // 7. Date (Icon: Clock) - Changed to 24hr format (%H:%M)
    {" ", "date '+%b %d (%a) %H:%M'",                             5,            0},
};

// Delimiter
static char delim[] = " | ";
static unsigned int delimLen = 5;
