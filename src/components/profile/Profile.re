let component = ReasonReact.statelessComponent("Profile");

let make = (_children) => {
    ...component,
    render: _self => <div> (ReasonReact.string("This is my app profile")) </div>,
};
