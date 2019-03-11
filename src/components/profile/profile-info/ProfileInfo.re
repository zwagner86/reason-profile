[%%raw "require('./ProfileInfo.css')"];

let component = ReasonReact.statelessComponent("ProfileInfo");

let make = (_children) => {
    ...component,
    render: _self => {
        <div className="ProfileInfo">
            <div className="ProfileInfo-inner">
                <div className="ProfileInfo-inner-cell">
                    <div className="ProfileInfo-pic-container">
                        <img
                            className="ProfileInfo-pic-img"
                            src={PersonalSiteData.profileImage}
                            alt="Zachary Wagner Profile" />
                    </div>
                    <h1>(ReasonReact.string("Hey, I'm Zach,"))</h1>
                    <h4 className="ProfileInfo-h4">(ReasonReact.string("a Front End Engineer"))</h4>
                    <h4 className="ProfileInfo-h4">(ReasonReact.string("working in Chicago"))</h4>
                    <h4 className="ProfileInfo-h4">(ReasonReact.string("for SpotHero"))</h4>
                    <div className="ProfileInfo-social-icons">
                        <a
                            className="ProfileInfo-social-link ProfileInfo-linkedin-link"
                            href="https://www.linkedin.com/in/zacharywagner"
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            <FontAwesomeIcon
                                className="ProfileInfo-social-icon"
                                icon={["fab", "linkedin"]}
                                size="2x"
                                fixedWidth=true
                            />
                        </a>
                        <a
                            className="ProfileInfo-social-link ProfileInfo-github-link"
                            href="https://github.com/zwagner86"
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            <FontAwesomeIcon
                                className="ProfileInfo-social-icon"
                                icon={["fab", "github"]}
                                size="2x"
                                fixedWidth=true
                            />
                        </a>
                    </div>
                    <div className="ProfileInfo-resume-link">
                        <a
                            href="https://www.zacharywagner.net/resume"
                            className="ProfileInfo-resume-btn"
                        >
                            (ReasonReact.string("View Resume"))
                        </a>
                    </div>
                </div>
            </div>
        </div>
    },
};
