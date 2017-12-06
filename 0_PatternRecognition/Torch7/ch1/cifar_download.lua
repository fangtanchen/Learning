require 'paths'
require 'torch'
if (not paths.filep("cifar10torchsmall.zip")) then
    os.execute('wget -c https://s3.amazonaws.com/torch7/data/cifar10torchsmall.zip')
    os.execute('unzip cifar10torchsmall.zip')
end

trainset=torch.load('cifar10-train.t7')
testset=torch.load('cifar10-test.t7')
classes={'airplane', 'automobile', 'bird', 'cat',
'deer', 'dog', 'frog', 'horse', 'ship', 'truck'}

print(trainset)
print(#trainset.data)

setmetatable(trainset,
{__index=function(t,i)
            return {t.data[i],t.label[i]}
        end}
);
trainset.data=trainset.data:double()
function trainset:size()
    return self.data:size(1)
end

print(trainset:size())
print(trainset[33])


