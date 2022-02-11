--NOTE TO DEVS:
--THESE LUA FILES ARE DEPRECATED..
--USE RUSHELL.H INSTEAD...
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
