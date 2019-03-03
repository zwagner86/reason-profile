[%%raw "require('./SkillTile.css')"];

let component = ReasonReact.statelessComponent("SkillTile");

let make = (~name, ~logo, ~star, _children) => {
    ...component,
    render: _self => {
        <div className="SkillTile">
            <div className="SkillTile-label">
                <div className="SkillTile-text">
                    (ReasonReact.string(name ++ " "))
                    (star ?
                        <FontAwesomeIcon
                            className="SkillTile-icon-star"
                            icon={["fas", "star"]}
                        />
                        : ReasonReact.null
                    )
                </div>
            </div>
            <div className="SkillTile-image-block">
                <div className="SkillTile-image-cell">
                    <img
                        className="SkillTile-image"
                        src=Logo.get(logo)
                        alt=name
                    />
                </div>
            </div>
        </div>
    },
};
