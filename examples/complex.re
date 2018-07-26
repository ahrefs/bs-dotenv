
let config: Dotenv.config = {
    path: Some(".env.production"),
    encoding: None
};

let _ = Dotenv.config(~cfg=config, ());

let _ = Js.log(Node.Process.process##env);
