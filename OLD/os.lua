--NOTE TO DEVS:
--THESE LUA FILES ARE DEPRECATED..
--USE RUSHELL.H INSTEAD...
args = {}
ver = "0.721 - DIY App Update!"

--UDP packet send code begin
function sendPacket(rec, cont)
	local socket = require("socket")
	local udp = assert(socket.udp())
	local data

	udp:settimeout(1)
	assert(udp:setsockname("*",0))
	assert(udp:setpeername(rec,1234))

	for i = 0, 2, 1 do
		assert(udp:send(cont))
		data = udp:receive()
		if data then
  			break
		end
	end


	if data == nil then
		print("timeout")
	else
		print(data)
	end
end
--End of socket code

function wait(s)
  local ntime = os.time() + s
 repeat until os.time() > ntime
end

function clear()
 for i = 1,26 do
  print("\n\n")
 end
end

function dog(fn)
	io.write(_G[fn] .. "\n");
end

function lf(fn)
	assert(loadstring(_G[fn] .. "\n"))();
end

function rushell(code)
		if string.find(_G.cmd, "print") then
			io.write(string.gsub(_G.cmd, "print " , "") .. "\n")
		elseif _G.cmd == "version" then
			io.write("Rushell version " .. ver .. " Beta\n");
		elseif _G.cmd == "help" then
			io.write("There are seven commands:\n");
			io.write("print - Prints to the console - Usage: print hello world\n");
			io.write("version - prints the version - Usage: version\n");
			io.write("help - lists all the different commands - Usage: help\n");
			io.write("clear - clears the screen (not perfect) - Usage: clear\n");
			io.write("about - About rushell. - Usage: about\n");
			io.write("prompt - Waits until the user presses any key.\n");
			io.write("dog - cat alternative\n");
			io.write("micro - auto-saving text editor\n");
		elseif _G.cmd == "clear" then
			clear();
		elseif _G.cmd == "about" then
			io.write('Rushell is a small shell/scripting language for the GEMS OS.\n');
		elseif _G.cmd == "wait" then
			wait(args[1]);
		elseif _G.cmd == "prompt" then
			io.write("Press any key to continue");
			io.read("*l");
		elseif string.find(_G.cmd, "loadfile")  then
			lf(string.gsub(_G.cmd, "loadfile ", ""))
		elseif string.find(_G.cmd, "loadstring")  then
			assert(loadstring(string.gsub(_G.cmd, "loadstring ", "")))();
		elseif _G.cmd == "micro" then
			fn = ""
			file = ""
			_G.buffer = ""
			exitmicro = false
			function wait(s)
			  local ntime = os.time() + s
			 repeat until os.time() > ntime
			end

			function save(file)
 			_G[fn] = _G.buffer
			end

			function try(code)
				if code == "::clear" then
					_G.buffer = ""
					io.write("Clear OK");
				elseif code == "::exit" then
					exitmicro = true
					io.write("Exit OK");
				else
					_G.buffer = _G.buffer .. "\n" .. line
				end
			end

			io.write("File name:");
			fn = io.read("*l");

			if _G[fn] ~= nil then
				_G.buffer = _G[fn]
			else
				_G.buffer = ""
			end
			while exitmicro == false do
			io.write("->");
			line = io.read("*l");
			try(line);
			save(fn)
			end
			print(_G[fn]);
		elseif string.find(_G.cmd, "dog")  then
			dog(string.gsub(_G.cmd, "dog ", ""))
		else
			io.write("Unknown command!" .. "\n")
end 
args = {}

end

io.write("GEMS LOADED SUCCESSFULLY!\n");
io.write("We didn't plan ahead but you can try the Rushell beta edition while we finish the OS.\n");
io.write("Hello! Welcome to Rushell " .. ver .. " BETA\n");
while true do
io.write("Rushell> ")
line = io.read("*l");
cmd = string.lower(line)
rushell(cmd);
end
