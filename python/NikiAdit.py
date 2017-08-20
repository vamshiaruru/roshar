def check():
    """
    Obvious bruteforce method. Shouldn't be used. Takes way too much time
    """
    num = int(raw_input())
    for i in xrange(1000000):
        for j in xrange(10000):
            for k in xrange(1000):
                if 1234*i + 123456*j + 1234567*k == num:
                    print "YES"
                    return

    print "NO"
    return

check()
