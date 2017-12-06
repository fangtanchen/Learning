require 'torch'
require 'cutorch'

function addTensors(a,b)
    a:add(b)
    return a
end

a=torch.ones(5,2)
print(a)
b=torch.Tensor(2,5):fill(4)
print(b)
print(addTensors(a,b))
