def validate_length(euid: str) -> bool:
    return len(str(euid)) == 6 or len(str(euid)) == 7

def validate_contents(euid: str) -> bool:
    for x in euid:
        if x.isspace():
            return False
        if x.isupper():
            return False
        if not x.isascii():
            return False
    if len(euid) == 6:
        return euid[:1].islower() and euid[2:].isdigit()
    elif len(euid) == 7:
        return euid[:2].islower() and euid[3:].isdigit()
    return False

def validate(euid: str) -> bool:
    return validate_length(euid) and validate_contents(euid)

if __name__ == "__main__":
    # Prompt the user for their EUID,
    euid = input("Please enter your EUID: ").strip()

    if validate(euid):
        print(f"'{euid}' is a valid EUID")
    else:
        print(f"'{euid}' is NOT a valid EUID")

