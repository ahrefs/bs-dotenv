let config = Dotenv.configInput(~path=".env.production", ());

let _ = Dotenv.config(~options=?Some(config), ());

let () = Js.log(Node.Process.process##env);
