#!lua

-- project_loader.lua

ProjectLoader = {projects = {}}

function ProjectLoader:loadProjects()
    local projects = os.matchfiles("scripts/projects/*.lua")
    for key,file in pairs(projects) do
        local f = require(string.sub(file, 1, -5))
        local err = false
        if not f then
            print("Error while loading "..file)
            err = true
        end
        if f.name == nil then
          print("the project name field is not correct in "..file)
          err = true
        end
        if f.type == nil or (f.type ~= "StaticLib" and f.type ~= "ConsoleApp" and f.type ~= "Test") then
          print("the project type field is not correct in "..file)
          err = true
        end
        if not err then
            ProjectLoader.projects[key] = f
        end
    end
end

function ProjectLoader:process()
    for key,proj in pairs(ProjectLoader.projects) do
        ProjectLoader:processProject(proj)
    end
end

function ProjectLoader:processProject(proj)
    local includePath, srcPath
    local projectName = string.lower(proj.name)

    if proj.type == "StaticLib" then
        includePath = "../include/"..projectName
        srcPath = "../src/"..projectName
    elseif proj.type == "ConsoleApp" then
        includePath = "../examples/"..projectName
        srcPath = "../examples/"..projectName
	else
		includePath = "../"..projectName
		srcPath = "../"..projectName
		proj.type = "ConsoleApp"
    end

    local dependencies = {}
    if proj.dependencies then
        for key,dependency in pairs(proj.dependencies) do
            table.insert(dependencies, string.lower(dependency))
        end
    end
    if proj.extlibs then
        for key,extlib in pairs(proj.extlibs) do
            table.insert(dependencies, string.lower(extlib))
        end
    end

    project(proj.name)
        location("")
        files {
            includePath.."/**.inl",
            includePath.."/**.hpp",
            srcPath.."/**.cpp",
			srcPath.."/**.frag",
			srcPath.."/**.vert",
			srcPath.."/**.geom",
        }
		
        links(dependencies)

        if proj.linkOptions then
            filter {"system:windows"}
                if proj.linkOptions.windows then
                    linkoptions { proj.linkOptions.windows }
                end
            filter {"system:linux or macosx"}
                if proj.linkOptions.unix then
                    linkoptions { proj.linkOptions.unix }
                end
            filter {}
        end

	if proj.preprocessor then
		defines(proj.preprocessor)
	end
end

return ProjectLoader
