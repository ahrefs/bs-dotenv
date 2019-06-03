let options = Dotenv.configInput(~path=".env.production", ());

let _ = Dotenv.config(~options, ());

let () = Js.log(Node.Process.process##env);
