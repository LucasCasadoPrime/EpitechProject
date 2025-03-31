function display_help()
    print("USAGE")
    print("\t./105torus opt a0 a1 a2 a3 a4 n\n\n")
    print("DESCRIPTION")
    print("\topt       method option:")
    print("\t              1 for the bisection method")
    print("\t              2 for Newton’s method")
    print("\t              3 for the secant method")
    print("\ta[0-4]    coefficients of the equation")
    print("\tn         precision (the application of the polynomial to the solution should")
    print("\t          be smaller than 10ˆ-n)")
    os.exit(0)
end

function calcul_f(A, x)
    return (A['4'] * math.pow(x, 4)) + (A['3'] * math.pow(x, 3)) + (A['2'] * math.pow(x, 2)) + (A['1'] * x) + A['0']
end

function calcul_f_prime(A, x)
    return (4 * A['4'] * math.pow(x, 3)) + (3 * A['3'] * math.pow(x, 2)) + (2 * A['2'] * x) + A['1']
end

function bisection(A, n)
    local a = 0
    local b = 1
    local c = 0.5
    local i = 0

    if (calcul_f(A, a) * calcul_f(A, b) >= 0) then
        print("Error ".. calcul_f(A, a) * calcul_f(A, b))
        os.exit(84)
    end

    while math.abs(calcul_f(A, c)) >= math.pow(10, -n) do
        c = (a + b) / 2
        if (0 <= c and c <= 1) then
            if (i == 0) then
                print(string.format("x = %.1f", c))
            else
                print(string.format("x = %."..n.."f", c))
            end
        else
            os.exit(84)
        end
        if calcul_f(A, c) * calcul_f(A, a) >= 0 then
            a = c
        else
            b = c
        end
        i = i + 1
    end
    return result
end

function newton(A, n)
    local i = 1
    local xn_ = 0.5
    local xn = 0
    
    while (i < 300) do
        local first_xn = calcul_f(A, xn_)
        local second_xn = calcul_f_prime(A, xn_)

        if (second_xn == 0) then
            print("Error: division by zero.")
            os.exit(84)    
        end
        xn = xn_ - (first_xn / second_xn)
        if (i == 1) then
            print(string.format("x = %.1f", xn_))
        end
        if (math.floor(xn_ * math.pow(10, n)) == math.floor(xn * math.pow(10, n))) then
            break
        end
        print(string.format("x = %."..n.."f", xn))
        if (math.floor(xn_ * math.pow(10, n)) == math.floor(xn * math.pow(10, n))) then
            break
        end
        xn_ = xn
        i = i + 1
    end
    return result
end

function secant(A, n)
    local i = 1
    local xn_ = 0.5
    local xn = 0
    
    while (i < 300) do
        local first_xn = calcul_f(A, xn_)
        local second_xn = calcul_f_prime(A, xn_)

        if (second_xn == 0) then
            print("Error: division by zero.")
            os.exit(84)    
        end
        xn = xn_ - (first_xn / second_xn)
        if (i == 1) then
            print(string.format("x = %.1f", xn_))
        end
        if (math.floor(xn_ * math.pow(10, n)) == math.floor(xn * math.pow(10, n))) then
            break
        end
        print(string.format("x = %."..n.."f", xn))
        if (math.floor(xn_ * math.pow(10, n)) == math.floor(xn * math.pow(10, n))) then
            break
        end
        xn_ = xn
        i = i + 1
    end
    return result
end