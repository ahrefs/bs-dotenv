let config = Dotenv.configInput(~path=Some(".env.production"), ());

let _ = Dotenv.config(~options=?Some(config), ());

let _ = Js.log(Node.Process.process##env);
