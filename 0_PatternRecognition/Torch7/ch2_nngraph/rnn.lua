require 'torch'
require 'nngraph'
require 'nn'

function get_rnn(input_size,rnn_size)
    local input=nn.Identity()()
    local prev_h=nn.Identity()()

    local i2h=nn.Linear(input_size,rnn_size)(input)
    local h2h=nn.Linear(rnn_size,rnn_size)(prev_h)
    local added_h=nn.CAddTable()({i2h,h2h})
    local next_h=nn.Tanh()(added_h)

    nngraph.annotateNodes()
    return nn.gModule({input,prev_h},{next_h})
end

local rnn_net=get_rnn(128,128)
graph.dot(rnn_net.fg,'rnn_net1','rnn_net1')


local function get_rnn2(input_size,rnn_size)
    local input1=nn.Identity()()
    local input2=nn.Identity()()
    local prev_h=nn.Identity()()
    local rnn_net1=get_rnn(128,128)({input1,prev_h})
    local rnn_net2=get_rnn(128,128)({input2,rnn_net1})
    nngraph.annotateNodes()
    return nn.gModule({input1,input2,prev_h},{rnn_net2})
end

local rnn_net2=get_rnn2(128,128)
graph.dot(rnn_net2.fg,'rnn_net2','rnn_net2')
