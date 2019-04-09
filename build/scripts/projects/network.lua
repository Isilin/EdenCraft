#!lua

-- network.lua

local settings = Project:new()

settings:setName("network")
settings:setType("Lib")
settings:addDependencies{"core", "utility"}
settings:addExtlibs("Windows", {"ws2_32"})

return settings
