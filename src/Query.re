open Fragment;

module Query = [%graphql
  {|
    query {
      # isLoggedIn # <== Uncomment this Line to "fix" the error
      ...WorkspaceData
    }
  |}
];
