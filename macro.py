




def main():

    keys = init_map()
    cmds_one = init_stack(keys, "Profile_One")
    cmds_two = init_stack(keys, "Profile_Two")
    cmds_three = init_stack(keys, "Profile_Three")
    cmds_four = init_stack(keys, "Profile_Four")

    while 1:
        if True:
            _exec(cmds_one)
        if True:
            _exec(cmds_two)
        if True:
            _exec(cmds_three)
        if True:
            _exec(cmds_four)

def _exec(cmds):
    pass

def init_stack(keys, filename):

    
    profile = open(filename, "r")
    unparsed_actions = profile.read().splitlines()
    print(unparsed_actions)
    actions = []

    i = len(unparsed_actions)-1

    while i >= 0:
        if unparsed_actions[i] in keys:
            actions.append(keys[unparsed_actions[i]])
        elif unparsed_actions[i].isnumeric():
            actions.append(int(unparsed_actions[i]))
        i -= 1

    profile.close()

    return actions

    

def init_map():
    return {"A":1,
    "B":2,
    "X":3,
    "Y":4,
    "RB":5,
    "RT":6,
    "LB":7,
    "LT":8,
    "U":9,
    "D":10,
    "L":11,
    "R":12,
    "UR":13,
    "UL":14,
    "DR":15,
    "DL":16,
    "QCF":17,
    "QCB":18,
    "HCF":19,
    "HCB":20,
    "HCFB":21,
    "HCBF":22,
    "DP":23,
    "RDP":24,
    "DQCF":25,
    "DQCB":26,
    "DHCF":27,
    "DHCB":28,
    "DHCFB":29,
    "DHCBF":30,
    "SPD":31,
    "DSPD":32,
    }

main()