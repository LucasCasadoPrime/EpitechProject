function display_help()
    print("USAGE")
    print("\t./106bombyx n [k | i0 i1]\n")
    print("DESCRIPTION")
    print("\tn\tnumber of first generation individuals")
    print("\tk\tgrowth rate from 1 to 4")
    print("\ti0\tinitial generation (included)")
    print("\ti1\tfinal generation (included)")
end

function calculate_two_args(args)
    local i = 0
    local kxi = args['n'] * args['k']
    local calc = args['n']
    
    while i <= 99 do
        print((i + 1).." "..string.format("%.2f", calc))
        kxi = calc * args['k']
        calc = kxi * ((1000 - calc) / 1000)
        args['n'] = args['n'] + 1
        i = i + 1
    end
end

function calculate_three_args(args)
    local k = 1
    local i = 1
    local x = args['n']
    
    while (k <= 4) do
        i = 1
        while (i <= args['i1']) do
            while (i < args['i0']) do
                x = k * x * ((1000 - x) / 1000);
                i = i + 1
            end
            i = i + 1
            x = k * x * ((1000 - x) / 1000);
            print(string.format("%.2f", k) .. " " .. string.format("%.2f", x))
        end
        -- print(k)
        k = k + 0.01
    end
end