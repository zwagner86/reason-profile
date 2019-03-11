[%%raw "require('./Skills.css')"];

let component = ReasonReact.statelessComponent("Skills");

let make = (_children) => {
    ...component,
    render: _self => {
        <div className="Skills">
            <div className="Skills-inner">
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHO?"))</div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-description">
                            <span>(ReasonReact.string("Hey, what's up? My full name is "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Zachary "))</span>
                            <span>(ReasonReact.string("but you can call me "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Zach"))</span>
                            <span>(ReasonReact.string(". I am a "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Software Engineer "))</span>
                            <span>(ReasonReact.string("with "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("full-stack experience"))</span>
                            <span>(ReasonReact.string(", but a passion for working in the "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("front-end"))</span>
                            <span>(ReasonReact.string(". For example, I made this page so I could play around with "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("ReasonML"))</span>
                            <span>(ReasonReact.string(" and "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("ReasonReact"))</span>
                            <span>(ReasonReact.string("!"))</span>
                        </div>
                    </div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-description">
                            (ReasonReact.string("I also made versions of this page using React and Vue!  You can get to those using the menu.  They really aren't any different.  I just wanted to be able to compare the frameworks firsthand."))
                        </div>
                    </div>
                </div>
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHAT?"))</div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-description">(ReasonReact.string(PersonalSiteData.whatSectionDescription))</div>
                        <div className="Skills-languages">
                            <div className="Skills-languages-description">(ReasonReact.string("Here are some languages I have experience with:"))</div>
                            <div className="Skills-languages-list">
                                (
                                    PersonalSiteData.languages
                                    |> Array.map(language => {
                                        <SkillTile
                                            key=language##name
                                            name=language##name
                                            logo=language##logoName
                                            star=language##star
                                        />
                                    })
                                    |> ReasonReact.array
                                )
                            </div>
                        </div>
                        <div className="Skills-frameworks">
                            <div className="Skills-frameworks-description">
                                (ReasonReact.string("And here are some frameworks, libraries, and tools I've used:"))
                            </div>
                            <div className="Skills-frameworks-list">
                                (
                                    PersonalSiteData.frameworks
                                    |> Array.map(framework => {
                                        <SkillTile
                                            key=framework##name
                                            name=framework##name
                                            logo=framework##logoName
                                            star=framework##star
                                        />
                                    })
                                    |> ReasonReact.array
                                )
                            </div>
                        </div>
                    </div>
                </div>
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHERE?"))</div>
                    (
                        PersonalSiteData.companies
                        |> Array.map(company => {
                            <div className="Skills-section-info">
                                <div>
                                    <a
                                        className="Skills-section-employer-link"
                                        href=company##url
                                        target="_blank"
                                        rel="noopener noreferrer"
                                    >
                                        (ReasonReact.string(company##name))
                                    </a>
                                </div>
                                <div>(ReasonReact.string(company##fromDate ++ " - " ++ company##toDate))</div>
                                <div>(ReasonReact.string(company##location))</div>
                                <div>(ReasonReact.string(company##title))</div>
                            </div>
                        })
                        |> ReasonReact.array
                    )
                </div>
            </div>
        </div>
    },
};
