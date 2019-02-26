[%%raw "require('./Menu.css')"];

type state = {
    isMenuOpen: bool
};

type action = | Toggle;

let component = ReasonReact.reducerComponent("Menu");

let make = (_children) => {
    ...component,
    initialState: () => {isMenuOpen: false},
    reducer: (action, state) =>
        switch (action) {
            | Toggle => ReasonReact.Update({isMenuOpen: !state.isMenuOpen})
        },
    render: self => {
        let menuClass = (self.state.isMenuOpen) ? "Menu Menu-is-open" : "Menu";

        <div className=menuClass>
            <div className="Menu-toggle">
                <button
                    className="Menu-toggle-button"
                    onClick=(_event => self.send(Toggle))
                >
                    (ReasonReact.string("Menu"))
                </button>
            </div>
            <div className="Menu-links">
                <a
                    href="https://www.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("Home"))
                </a>
                <a
                    href="https://www.zacharywagner.net/resume"
                    className="Menu-link"
                >
                    (ReasonReact.string("Resume"))
                </a>
                <div className="Menu-link-divider-block">
                    <div className="Menu-link-divider">
                        <span>(ReasonReact.string("Other Versions"))</span>
                    </div>
                </div>
                <a
                    href="https://www.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("React"))
                </a>
                <a
                    href="https://vue.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("Vue"))
                </a>
            </div>
        </div>
    },
};
