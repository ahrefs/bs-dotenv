[@bs.deriving abstract]
type parseOptions = {debug: option(bool)};

[@bs.deriving abstract]
type parseInput = {
  src: Node.string_buffer,
  [@bs.optional]
  options: parseOptions,
};

type parseOutput = Js.Dict.t(string);

[@bs.module "dotenv"] external parse: parseInput => parseOutput = "parse";

[@bs.deriving abstract]
type configInput = {
  [@bs.optional]
  path: string,
  [@bs.optional]
  encoding: string,
  [@bs.optional]
  debug: bool,
};

[@bs.deriving abstract]
type configOutput = {
  error: option(Js.Exn.t),
  parsed: option(Js.Dict.t(string)),
};

[@bs.module "dotenv"]
external config: option(configInput) => configOutput = "config";

let config = (~options: option(configInput)=?, ()) => config(options);
