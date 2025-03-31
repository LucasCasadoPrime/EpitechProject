#!/usr/bin/env lua

require("src/functions")

if (#arg == 1 and arg[1] == "-h") then
    display_help()
    os.exit(0)
end

if (#arg ~= 2 and #arg ~= 3) then
    print("Error: arguments count incorrect.")
    os.exit(84)
end

if (#arg == 2) then
    if (tonumber(arg[2]) <= 1 or tonumber(arg[2]) >= 4) then
        print("Error: arguments \"k\" must be between 1 and 4.")
        os.exit(84)
    end

    if (tonumber(arg[1]) == nil or tonumber(arg[2]) == nil) then
        print("Error: incorrect argument type")
        os.exit(84)
    end

    local args = {
        ['n'] = tonumber(arg[1]),
        ['k'] = tonumber(arg[2]),
        ['i0'] = tonumber(arg[3]),
        ['i1'] = tonumber(arg[4])
    }

    calculate_two_args(args)
elseif (#arg == 3) then
    if (tonumber(arg[1]) == nil or tonumber(arg[2]) == nil or tonumber(arg[3]) == nil) then
        print("Error: incorrect argument type")
        os.exit(84)
    end

    local args = {
        ['n'] = tonumber(arg[1]),
        ['i0'] = tonumber(arg[2]),
        ['i1'] = tonumber(arg[3])
    }

    calculate_three_args(args)
end