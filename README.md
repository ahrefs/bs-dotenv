# bs-dotenv

`bs-dotenv` is a package for bucklescript bindings to
[dotenv](https://github.com/motdotla/dotenv).

## Installation

```
yarn add @ahrefs/bs-dotenv
```

or to follow master version:

```
yarn add https://github.com/ahrefs/bs-dotenv.git
```

## Usage

Add `@ahrefs/bs-dotenv` to the `bs-dependencies` of `bsconfig.json`.

See original [dotenv usage](https://github.com/motdotla/dotenv#usage).

## Example

Create a `.env` file:

```
VALUE1=demo1
VALUE2=demo2
```

Create a `demo.re` file:

```reason
Dotenv.config();

let _ =
  Js.log(Node.Process.process##env);
```

more examples [here](./examples/)

Add the package as a dependency in `bsconfig.json`.

Run it:

```
$ nodejs src/demo.bs.js | grep demo
  VALUE1: 'demo1',
  VALUE2: 'demo2',
```
