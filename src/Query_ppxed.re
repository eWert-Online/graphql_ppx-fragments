open Fragment;
module Query: {
  module Query_inner: {
    module Raw: {
      type t = {workspace: UserData.Raw.t};
      type t_variables = {userId: string};
    };
    type t = {workspace: UserData.t};
    type t_variables = {userId: string};
    /** The GraphQL query */
    let query: ApolloClient.GraphQL_PPX.templateTagReturnType;
    /** Parse the JSON-compatible GraphQL data to ReasonML data types */
    let parse: Raw.t => t;
    /** Serialize the ReasonML GraphQL data that was parsed using the parse
function back to the original JSON compatible data */
    let serialize: t => Raw.t;
    let serializeVariables: t_variables => Raw.t_variables;
    let makeVariables: (~userId: string, unit) => t_variables;
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  };
  include (module type of {
    include Query_inner;
  });
  include (module type of {
    include ApolloClient.GraphQL_PPX.ExtendQuery(Query_inner);
  });
} = {
  module Query_inner: {
    module Raw: {
      type t = {workspace: UserData.Raw.t};
      type t_variables = {userId: string};
    };
    type t = {workspace: UserData.t};
    type t_variables = {userId: string};
    /** The GraphQL query */
    let query: ApolloClient.GraphQL_PPX.templateTagReturnType;
    /** Parse the JSON-compatible GraphQL data to ReasonML data types */
    let parse: Raw.t => t;
    /** Serialize the ReasonML GraphQL data that was parsed using the parse
function back to the original JSON compatible data */
    let serialize: t => Raw.t;
    let serializeVariables: t_variables => Raw.t_variables;
    let makeVariables: (~userId: string, unit) => t_variables;
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  } = {
    [@ocaml.warning "-32"];
    module Raw = {
      type t = {workspace: UserData.Raw.t};
      type t_variables = {userId: string};
    };
    type t = {workspace: UserData.t};
    type t_variables = {userId: string};
    let query: ApolloClient.GraphQL_PPX.templateTagReturnType =
      {
        module J = {
          external unsafe_expr: _ => _ = "#raw_expr";
        };
        J.unsafe_expr(
          "(frag_0) => require(\"@apollo/client\").gql`\n  query WorkspaceQuery($userId: String!)  {\n    workspace(id: \"123\")  {\n      ...UserData\n    }\n  }\n  ${frag_0}\n`",
        );
      }(
        UserData.query,
      );
    let parse: Raw.t => t =
      (value) => (
        {
          workspace: {
            let value = (value: Raw.t).workspace;

            UserData.verifyArgsAndParse(
              ~userId=`NonNull_String,
              ~fragmentName=`UserData,
              value,
            );
          },
        }: t
      );
    let serialize: t => Raw.t =
      (value) => (
        {
          let workspace = {
            let value = (value: t).workspace;
            UserData.serialize(value);
          };
          {workspace: workspace};
        }: Raw.t
      );
    let serializeVariables: t_variables => Raw.t_variables =
      inp => {userId: (a => a)((inp: t_variables).userId)};
    let makeVariables = (~userId, ()): t_variables => {userId: userId};
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  };
  include Query_inner;
  include ApolloClient.GraphQL_PPX.ExtendQuery(Query_inner);
};

