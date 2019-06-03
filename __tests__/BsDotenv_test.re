open Jest;
open Expect;

let dotenv_example = {js|
NODE_ENV=development
BASIC=basic

# previous line intentionally left blank
AFTER_LINE=after_line
UNDEFINED_EXPAND=$TOTALLY_UNDEFINED_ENV_KEY
EMPTY=
SINGLE_QUOTES='single_quotes'
DOUBLE_QUOTES="double_quotes"
EXPAND_NEWLINES="expand\nnewlines"
DONT_EXPAND_NEWLINES_1=dontexpand\nnewlines
DONT_EXPAND_NEWLINES_2='dontexpand\nnewlines'
# COMMENTS=work
EQUAL_SIGNS=equals==
RETAIN_INNER_QUOTES={"foo": "bar"}
RETAIN_INNER_QUOTES_AS_STRING='{"foo": "bar"}'
INCLUDE_SPACE=some spaced out string
USERNAME="therealnerdybeast@example.tld"
|js};

let dotenv_example_buffer = Node.Buffer.fromString(dotenv_example);

let expectedBasicValue = Some("basic");

describe("BuckleScript Dotenv", () => {
  test("config should accept zero parameters", () => {
    let _ = Dotenv.config();
    let nodeEnv = Node.Process.process##env;

    let basicValue = Js.Dict.get(nodeEnv, "BASIC");

    expect(basicValue) |> toEqual(None);
  });

  test("config should get dotenv config from custom path", () => {
    let options = Dotenv.configInput(~path="./__tests__/.env", ());

    let _ = Dotenv.config(~options, ());
    let nodeEnv = Node.Process.process##env;

    let basicValue = Js.Dict.get(nodeEnv, "BASIC");

    expect(basicValue) |> toEqual(expectedBasicValue);
  });

  test("parseString can read a string", () => {
    let env = Dotenv.parseString(~src=dotenv_example, ());
    let basicValue = Js.Dict.get(env, "BASIC");
    expect(basicValue) |> toEqual(expectedBasicValue);
  });

  test("parseBuffer can read a buffer", () => {
    let env = Dotenv.parseBuffer(~src=dotenv_example_buffer, ());
    let basicValue = Js.Dict.get(env, "BASIC");
    expect(basicValue) |> toEqual(expectedBasicValue);
  });

  test("parse can read a string", () => {
    let env = Dotenv.parse(~src=`Str(dotenv_example), ());
    let basicValue = Js.Dict.get(env, "BASIC");
    expect(basicValue) |> toEqual(expectedBasicValue);
  });

  test("parse can read a buffer", () => {
    let env =
      Dotenv.parse(~src=`Buffer(dotenv_example_buffer), ());
    let basicValue = Js.Dict.get(env, "BASIC");
    expect(basicValue) |> toEqual(expectedBasicValue);
  });
});
