import argparse, zipfile,gzip,tarfile


parser = argparse.ArgumentParser()
parser.add_argument("--file", type=str, required=True)
parser.add_argument("--action", type=str, required=True)
parser.add_argument("--list", required=True)
args = parser.parse_args()

lis = args.list

listu = lis.split("&=")


def file_to_zip():
    print("")



def unzip_file():
    print(5)



def folder_to_zip():
    print(6)


def unzip_folder():
    print(5)



def   file_to_gzip():
    print(5)


def ungzip_file():
    print(5)



def folder_to_gzip():
    print(6)


def ungzip_folder():
    print(5)



def file_to_tar():
    print("")


def untar_file():
    print(5)



def folder_to_tar():
    print(6)


def untar_folder():
    print(5)


