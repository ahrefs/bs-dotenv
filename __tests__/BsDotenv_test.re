open Jest;
open Expect;

describe("BuckleScript Dotenv", () => {
  test("it should accept zero parameters", () => {
    let _ = Dotenv.config();
    let nodeEnv = Node.Process.process##env;

    let basicValue = Js.Dict.get(nodeEnv, "BASIC");

    expect(basicValue) |> toEqual(None);
  });

  test("it should get dotenv config from custom path", () => {
    let options = Dotenv.configInput(~path="./__tests__/.env", ());

    let _ = Dotenv.config(~options, ());
    let nodeEnv = Node.Process.process##env;

    let basicValue = Js.Dict.get(nodeEnv, "BASIC");
    let expectedBasicValue = Some("basic");

    expect(basicValue) |> toEqual(expectedBasicValue);
  });
});
