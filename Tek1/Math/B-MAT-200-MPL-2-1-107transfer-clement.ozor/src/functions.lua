function display_help()
    print("USAGE")
    print("\t./107transfer [num den]*\n")
    print("DESCRIPTION")
    print("\tnum\tpolynomial numerator defined by its coefficients")
    print("\tden\tpolynomial denominator defined by its coefficients")
end

function split_string(str, delimiter)
    result = {}
    for match in (str..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end

function round(num, numDecimalPlaces)
    local mult = 10^(numDecimalPlaces or 0)
    return math.floor(num * mult + 0.5) / mult
  end

function get_nb_in_array(array)
    local i = 1
    calc = 0

    while i <= #array do
        calc = calc + #array[i]
        i = i + 1
    end
    return calc
end

function calcul_hormer(x, nb)
    local res = 0   

    for i = #nb, 1, -1 do
        res = res * x + tonumber(nb[i])
    end
    return res
end

function calcul_bootstrap(array_args)
    local x = 0
    local i = 1
    local j = 1
    local k = 1
    local l = 1
    local calcul = 0
    local array = {}
    local array_2 = {}

    while x <= 1.001 do
        i = 1
        calcul = 1
        while i <= #array_args do
            table.insert(array, calcul_hormer(x, tonumber(array_args[i])))
            i = i + 1
        end
        while k <= #array do
            table.insert(array_2, array[k] / array[k + 1])
            k = k + 2
        end
        while l < #array_2 do
            calcul = calcul * array_2[l]
            l = l + 1
        end
        if (round(x, 3) == x) then
            print(string.format("%.3f", x) .. " -> " .. string.format("%.5f", calcul))
        else
            print(string.format("%.3f", round(x, 3)) .. " -> " .. string.format("%.5f", calcul))
        end
        x = x + 0.001
    end
end