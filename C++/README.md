Visual Studio 외부 DLL 경로 추가 
 - https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220817543315

2차원 동적 배열
 - https://codeng.tistory.com/8   (malloc) 
``` 
        float** A_S_array;
	A_S_array = new float* [A_S.shape().rows];
	for (int i = 0; i < A_S.shape().rows; i++)
		A_S_array[i] = new float[A_S.shape().cols];
	for (int i = 0; i < A_S.shape().rows; i++)
		for (int j = 0; j < A_S.shape().cols; j++)
			A_S_array[i][j] = A_S(i, j);
```
