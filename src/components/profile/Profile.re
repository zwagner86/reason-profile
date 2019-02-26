[%%raw "require('./Profile.css')"];

let component = ReasonReact.statelessComponent("Profile");

let make = (_children) => {
    ...component,
    render: _self => {
        <div className="Profile">
            <ProfileInfo />
            <div> (ReasonReact.string("This is my app profile")) </div>
        </div>
    },
};
