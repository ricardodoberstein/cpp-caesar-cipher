# C++ Caesar Cipher

This project was made by learning purposes, it uses plain c++ with no libraries whatsoever.
## Requirements
* CMake

## Usage
```txt
Usage: {executable} <command>
where <command> is one of:
            --help  (display information)
            -d       Decode a file
            -e       Encode a file
            --shift  (required) How much to shift
            --path   (required) Path to file for processing
            --output (optional) filename to output decoded or encoded .txt
```

### Example
```txt
./CaesarCipher -e --path ./input.txt --output myOutput --shift 5
./CaesarCipher -d --path ./myOutput.txt --output output --shift 5
```

## Compilation

```bash
mkdir build
./build.sh
```

## Running tests

```bash
./test.sh
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)