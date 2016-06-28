TestClass = { }
TestClass.__index = TestClass

TestClass.ClassVariable = "test"

-- Constructor
function TestClass.Create()
  local Class = {}
  setmetatable(Class, TestClass)
  return Class
end

-- Print class variable value
function TestClass:Print()
  print(self.ClassVariable)
end

function main()
  class = TestClass.Create()
  class:Print()
end