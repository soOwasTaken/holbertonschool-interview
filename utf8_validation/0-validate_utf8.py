# /usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """ determines if a given data set
    represents a valid UTF-8 encoding"""
    bytes_to_follow = 0

    for byte in data:
        if bytes_to_follow == 0:
            if byte & 0x80 == 0:
                bytes_to_follow = 0
            elif byte & 0xE0 == 0xC0:
                bytes_to_follow = 1
            elif byte & 0xF0 == 0xE0:
                bytes_to_follow = 2
            elif byte & 0xF8 == 0xF0:
                bytes_to_follow = 3
            else:
                return False
        else:
            if byte & 0xC0 == 0x80:
                bytes_to_follow -= 1
            else:
                return False

    return bytes_to_follow == 0
