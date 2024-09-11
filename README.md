## Git cmd
git add README.md : README.md 파일만 올릴 때    
git add . : 전체를 올릴 때  
git commit -m "fix: a function fixed"   
git push origin main    

window 정품인증 창 없애기
cmd 관리자 실행 - ( bcdedit -set TESTSIGNING OFF ) - 재부팅

https://engineer-mole.tistory.com/75

---------------------------------------------------------------------
   폴더 만든 후 
   git init
   git remote add origin "https://github.com/HyungJoo-Kwon/study.git"
   
   1. git pull origin main
   2. git fetch --all
      git reset --hard origin/main
      git pull origin main

   파일 수정 후   
   git add .
   git commit -m "comment"
   git push origin main 
   git status → 확인
---------------------------------------------------------------------
