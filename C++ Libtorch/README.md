Libtorch 설치 (vsextension 을 사용한 torch project 이용)
 - https://pytorch.org/cppdocs/installing.html#support
 - https://github.com/mszhanyi/VSIXTorch

Libtorch 설치 
 - https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=riverrun17&logNo=221878319307
 - https://data-gardner.tistory.com/107

vtk 설치
 - https://jihunlee25.tistory.com/7

vtk 9.2.0 QuadricDecimation 
 - https://github.com/introlab/rtabmap/issues/736
 - https://gitlab.kitware.com/vtk/vtk/-/merge_requests/9388
 - https://gitlab.kitware.com/vtk/vtk/-/merge_requests/9388/diffs?commit_id=4a9059bca97c17d3be78e93c229df3212d37949e
![image](https://user-images.githubusercontent.com/73815944/195732986-83e8e2ba-8a6c-468c-957c-aae5f37ca8c5.png)

C++ Eigen 설치
 - https://himbopsa.tistory.com/8

외부라이브러리 링크
 - https://wnsgml972.github.io/setting/2018/11/01/dll_lib/

파이선 모델 가중치 복사하기 (이 방법 잘 안되네)
```
## Python ##
model = MeshSegNet(num_classes=num_classes, num_channels=num_channels).to(device, dtype=torch.float)
checkpoint = torch.load(os.path.join(model_path, model_name), map_location='cpu')
model.load_state_dict(checkpoint['model_state_dict'])

class Container(torch.nn.Module):
    def __init__(self, my_values):
        super().__init__()
        for key in my_values:
            setattr(self, key, my_values[key])

container = torch.jit.script(Container(checkpoint["model_state_dict']))
container.save("container.pt)

## C++ ##
MeshSegNet model = MeshSegNet(num_classes, num_channels, dropout_p);
auto container = torch::jit::load("C:/Users/USER/Desktop/container.pt");  // <torch/script.h>
for (auto p : model.named_parameters().keys())                 // pt 데이터 가중치 모델에 넣기
{	
	model.named_parameters()[p].data() = container.attr(p).toTensor();   
}

cout << container.attr("mlp1_conv1.bias").toTensor() << endl; // 불러온 pt 파일 weight
cout << model.named_parameters()["mlp1_conv1.bias"] << endl;  // 모델 weight
```

python 모델 c++ 에서 사용하기
-> https://github.com/HyungJoo-Kwon/study/blob/main/C%2B%2B%20Libtorch/libtorch.py

save tensor 
```
torch::save({ x_tensor, a_s_tensor, a_l_tensor }, "c:/users/user/desktop/tensor.pt"); // https://shuye.dev/kb/ai-engineering/libtorch/
```

tensor slicing & indexing
```
tensor_prob_output.index({ 0,slice(),slice() }).sizes() // https://github.com/prabhuomkar/pytorch-cpp/blob/master/notebooks/tensor_slicing.ipynb
tensor_prob_output.index({ 0,slice(), slice() }).argmax(-1) // https://pytorch.org/cppdocs/notes/tensor_indexing.html
```

