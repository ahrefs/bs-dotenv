[@bs.deriving abstract]
type parseOptions = {debug: option(bool)};

[@bs.module "dotenv"]
external parseString:
  (~src: string, ~options: parseOptions=?, unit) =>
  Js.Dict.t(string) =
  "parse";

[@bs.module "dotenv"]
external parseBuffer:
  (~src: Node.buffer, ~options: parseOptions=?, unit) =>
  Js.Dict.t(string) =
  "parse";

[@bs.module "dotenv"]
external parse:
  (
    ~src: [@bs.unwrap] [ | `Str(string) | `Buffer(Node.buffer)],
    ~options: parseOptions=?,
    unit
  ) =>
  Js.Dict.t(string) =
  "parse";

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
external config: (~options: configInput=?, unit) => configOutput =
  "config";
