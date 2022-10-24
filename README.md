포트폴리오 영상
=============
[![Video Label](http://img.youtube.com/vi/cL6MY6CVErk/0.jpg)](https://youtu.be/cL6MY6CVErk)


프로젝트 소개
=============


![포트폴리오](https://user-images.githubusercontent.com/71704395/197560719-f17b7d5b-20d9-4ae8-8fbf-9e2e7f29932f.png)

캐릭터
=============
* Player Character
    + Movement
       - 캐릭터 이동시 자연스러운 이동을 위하여 Character Movement의 가속/감속 이용.
           - Character Movement :: MaxAcceleration -> 500으로 조정.
           - UseSeperateBreakingFriction -> true
           - CharacterMovement:Walking -> MaxStepHeight -> 100
           - Walkable Floor Angle -> 70

           -> 캐릭터 이동시 가속/감속 적용, 자연스러운 움직임 구현.
    + Event Dispatcher
       - Onlanded
       - OnHitted
* Enemy Character 
    + Normal Enemy
    + Boss
