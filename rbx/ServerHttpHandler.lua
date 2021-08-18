local HttpService = game:GetService("HttpService")

local network = {
	["IPADDR"] = "ip",
	["PORT"] = "8080",
	["POSTURL"] = "/post"
}

game.ReplicatedStorage.Post.OnServerEvent:Connect(function()
	
	local url = "http://"..network["IPADDR"]..":"..network["PORT"]..network["POSTURL"]
	HttpService:PostAsync(url, "", Enum.HttpContentType.ApplicationUrlEncoded, false)
end)
