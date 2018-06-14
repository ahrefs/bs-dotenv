/**
 * Bindings to dotenv
 * https://www.npmjs.com/package/dotenv
 * https://github.com/DefinitelyTyped/DefinitelyTyped/blob/master/types/dotenv/index.d.ts
 */
type js_config = {
  .
  "path": Js.Nullable.t(string),
  "encoding": Js.Nullable.t(string),
};

type error = {
  .
  "name": string,
  "message": string,
  "stack": Js.Nullable.t(string),
};

type result = {
  .
  "error": error,
  "parsed": Js.Dict.t(string),
};

[@bs.module "dotenv"]
external js_config : Js.Nullable.t(js_config) => result = "config";

type config = {
  path: option(string),
  encoding: option(string),
};

let config = (~cfg=?, ()) => 
  switch (cfg) {
  | None => js_config(Js.Nullable.undefined)
  | Some(cfg) => 
    let config = {
      "path": Js.Nullable.fromOption(cfg.path),
      "encoding": Js.Nullable.fromOption(cfg.encoding),
    };
    Js.Nullable.return(config) |> js_config;
  };

[@bs.module "dotenv"]
external parseString : string => Js.Dict.t(string) = "parse";

[@bs.module "dotenv"]
external parseBuffer : Node.Buffer.t => Js.Dict.t(string) = "parse";
