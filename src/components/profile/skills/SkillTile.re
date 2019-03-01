[%%raw "require('./SkillTile.css')"];

let component = ReasonReact.statelessComponent("SkillTile");

let make = (~name, ~logo, ~star, _children) => {
    ...component,
    render: _self => {
        <div className="SkillTile">
            <div className="SkillTile-label">
                <div className="SkillTile-text">
                    (ReasonReact.string(name))
                    (star ?
                        ReasonReact.string("Star")
                        : ReasonReact.null
                    )
                </div>
            </div>
            <div className="SkillTile-image-block">
                <div className="SkillTile-image-cell">
                    <img
                        className="SkillTile-image"
                        src=("./assets/logos/" ++ String.sub(logo, 0, String.length(logo) - 4) ++ ".png")
                        alt=name
                    />
                </div>
            </div>
        </div>
    },
};
