let component = ReasonReact.statelessComponent("Menu");

let make = (_children) => {
    ...component,
    render: _self => <div> (ReasonReact.string("This is my menu")) </div>,
};
