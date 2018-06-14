open Jest;
open Expect;

describe("BuckleScript Dotenv", () => {
    test("it should get dotenv config from custom path", () => {
        let config: Dotenv.config = {
            path: Some("./__tests__/.env"),
            encoding: None
        };

        let _ = Dotenv.config(~cfg=config, ());
        let nodeEnv = Node.Process.process##env;

        let basicValue = Js.Dict.get(nodeEnv, "BASIC");
        let expectedBasicValue = Some("basic");

        expect(basicValue) |> toEqual(expectedBasicValue);
    });
});
