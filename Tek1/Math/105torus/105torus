#!/usr/bin/env lua

require("src/functions")

if (#arg == 1 and arg[1] == "-h") then
    display_help()
    os.exit(0)
end

if (#arg ~= 7) then
    print("Error: not enough arguments")
    os.exit(84)
end

if (tonumber(arg[1]) == nil or tonumber(arg[2]) == nil or tonumber(arg[3]) == nil or tonumber(arg[4]) == nil or tonumber(arg[5]) == nil or tonumber(arg[6]) == nil) or tonumber(arg[7]) == nil then
    print("Error: incorrect argument")
    os.exit(84)
end

if (tonumber(arg[7]) < 1) then
    print("Error: bad precision")
    os.exit(84)
end

local A = {
    ['0'] = tonumber(arg[2]),
    ['1'] = tonumber(arg[3]),
    ['2'] = tonumber(arg[4]),
    ['3'] = tonumber(arg[5]),
    ['4'] = tonumber(arg[6])
}
local n = tonumber(arg[7])

if (tonumber(arg[1]) == 1) then
    bisection(A, n)
elseif (tonumber(arg[1]) == 2) then
    newton(A, n)
elseif (tonumber(arg[1]) == 3) then
    secant(A, n)
else
    print("Error: arg #1 must be between 1 and 3.")
    os.exit(84)
end