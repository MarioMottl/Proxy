def parse(data, port, origin):
    print("[{}({})] <- {}".format(origin,port, data[:100].encode('hex')))