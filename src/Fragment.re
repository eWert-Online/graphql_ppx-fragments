module WorkspaceData = [%graphql
  {|
    fragment WorkspaceData on Query {
      workspace(id: "123") {
        id
        title
      }
    }
  |}
];
