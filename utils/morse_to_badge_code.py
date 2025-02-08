import sys

dash_func = "dash();"
dot_func = "dot();"
space_func = "chardelay();"
word_delay="worddelay();" # not implemented

# input morse string as arg1, use out of this for example:
# https://morsecodetranslator.com/

def convert_to_c_code(msg):
   for c in msg:
      match c:
        case '-':
          print(dash_func, end='')
        case '.':
          print(dot_func, end='')
        case ' ':
          print(space_func, end='')
        case '/':
          print(word_delay, end='')
   print("\n")     

def convert_from_c_code(msg):
    for c in msg.split(";"):
      match c[2:3]:
        case 's': # dash();
          print("-", end='')
        case 't': # dot();
          print(".", end='')
        case 'a': # chardelay();
             print("", end='')
        case 'r': # worddelay(); 
             print(" / ", end='')
    print("\n")

def usage():
   print(f"Usage: {sys.argv[0]} mode input") 
   print("mode: 0 = to C-code, 1 = from C-code")
   sys.exit(1)

if(len(sys.argv) < 3):
   usage()

if sys.argv[1] == '0':
   convert_to_c_code(sys.argv[2])
elif sys.argv[1] == '1':
   convert_from_c_code(sys.argv[2])
else:
   usage()

