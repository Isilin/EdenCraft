#!lua

-- utility.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("utility")
settings:setType("Lib")

return settings
