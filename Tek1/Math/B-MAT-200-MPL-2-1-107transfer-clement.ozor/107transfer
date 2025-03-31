#!/usr/bin/env lua

require("src/functions")

if (#arg < 1) then
    print("Error: arguments count incorrect.")
    os.exit(84)
end

if (#arg == 1 and arg[1] == "-h") then
    display_help()
    os.exit(0)
end


local array_args = {}
local i = 1

while i <= #arg do
    table.insert(array_args, split_string(arg[i], "*"))
    i = i + 1
end

calcul_bootstrap(array_args)