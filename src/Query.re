open Fragment;

module Query = [%graphql
  {|
    query WorkspaceQuery($userId: String!) {
      workspace(id: "123") {
        ...UserData @arguments(userId: $userId)
      }
    }
  |}
];
