```
# python
input1 = torch.ones(1,15,9999)
input2 = torch.ones(1,9999,9999)
num_classes = 15
num_channels = 15
device = torch.device("cpu")
# device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model_ = MeshSegNet(num_classes=num_classes, num_channels=num_channels).to(device, dtype=torch.float)
checkpoint = torch.load("./models/KHJ_MAX_300vtp.tar")    
model_.load_state_dict(checkpoint['model_state_dict'])
model_.eval()

traced_model_ = torch.jit.trace(model_, (input1, input2, input2))
traced_model_.save("trace_model.pt")
tensor_prob_output = traced_model_(X, A_S, A_L)
patch_prob_output = tensor_prob_output.cpu().detach().numpy()
for i_label in range(num_classes):
    predicted_labels_d[np.argmax(patch_prob_output[0, :], axis=-1)==i_label] = i_label
print(patch_prob_output, predicted_labels_d)

tensor_prob_output_ = model_(X, A_S, A_L)
patch_prob_output_ = tensor_prob_output_.cpu().detach().numpy()
for i_label in range(num_classes):
    predicted_labels_d[np.argmax(patch_prob_output_[0, :], axis=-1)==i_label] = i_label
print(patch_prob_output_, predicted_labels_d)

```


``` 
// C++
torch::jit::script::Module module;
torch::Device device_type = torch::Device(torch::kCPU);
auto predicted_labels_d = nc::NdArray<int>(decimated->GetNumberOfCells(), 1);
try {
		cout << "traced_model" << endl;
		module = torch::jit::load("C:/Users/USER/Desktop/trace_model.pt");
		//module.to(device_type)
		module.eval();
    
		std::vector<torch::jit::IValue> inputs;
		inputs.push_back(X_tensor);
		inputs.push_back(A_S_tensor);
		inputs.push_back(A_L_tensor);
		
		auto output = module.forward(inputs).toTensor();
		for (int i = 0; i < decimated->GetNumberOfCells(); i++)
		{
			predicted_labels_d(i, 0) = output.index({ 0,Slice(), Slice() }).argmax(-1)[i].item<int>();
		}
	}
	catch (const c10::Error& e) {
		cout << e.msg() << endl;
		return -1;
	}
```
