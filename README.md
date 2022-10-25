An C++ application for parsing cron expressions.

-- How to run the application?
    -- COMMAND: make
        -- to create the binary called 'output'
    -- COMMAND: make clean
        -- to remove all the binaries
    -- COMMAND: ./output < input.txt
        -- to see the output on the console
    -- COMMAND: ./output < input.txt > output.txt
        -- To capture the output in a file

-- It consists of,
    -- Entry point (../src)
        -- main.cpp
    -- Accessories (../src/accessories)
        -- expressions(.cpp and .h)
        -- processor(.cpp and .h)
        -- tokensier(.cpp and .h)
        -- printer(.cpp and .h)
    -- Macros (../src/constants)
        -- constants.h
    -- IO files (../iofiles)
        -- input.txt    | Input file
        -- output.txt   | Output file
    -- Makefile

-- What the application does?
    -- It parses a type of cron expression.
    -- EXAMPLE: */15 0 1,15 * 1-5 /usr/bin/find
        -- exactly 6 parameters, in the same order || command: non-cron expression
            minute       0 15 30 45 60 
            hour         0 
            day of month 1 15 
            month        1 2 3 4 5 6 7 8 9 10 11 12 
            day of week  1 2 3 4 5 
            command      /usr/bin/find

-- Meanings of these characters
    -- https://docs.oracle.com/cd/E12058_01/doc/doc.1014/e12030/cron_expressions.htm
