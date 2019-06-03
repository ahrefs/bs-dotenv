[@bs.deriving abstract]
type parseOptions = {debug: option(bool)};

[@bs.deriving abstract]
type parseInput = {
  src: Node.string_buffer,
  [@bs.optional]
  options: option(parseOptions),
};

type parseOutput = Js.Dict.t(string);

[@bs.module "dotenv"] external parse: parseInput => parseOutput = "parse";

[@bs.deriving abstract]
type configInput = {
  [@bs.optional]
  path: option(string),
  [@bs.optional]
  encoding: option(string),
  [@bs.optional]
  debug: option(bool),
};

[@bs.deriving abstract]
type configOutput = {
  error: option(Js.Exn.t),
  parsed: option(Js.Dict.t(string)),
};

[@bs.module "dotenv"]
external config: option(configInput) => configOutput = "config";

let config = (~options: option(configInput)=?, ()) => config(options);
