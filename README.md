포트폴리오 영상
=============
[![Video Label](http://img.youtube.com/vi/cL6MY6CVErk/0.jpg)](https://youtu.be/cL6MY6CVErk)


[새 탭에서 열기](https://www.google.com/){:target="_blank"}

프로젝트 소개
=============



![포트폴리오](https://user-images.githubusercontent.com/71704395/197560719-f17b7d5b-20d9-4ae8-8fbf-9e2e7f29932f.png)

캐릭터
=============
 ## Player Character
    + Movement
       - 캐릭터 이동시 자연스러운 이동을 위하여 Character Movement의 가속/감속 이용.
           - Character Movement :: MaxAcceleration -> 500으로 조정.
           - UseSeperateBreakingFriction -> true
           - CharacterMovement:Walking -> MaxStepHeight -> 100
           - Walkable Floor Angle -> 70

           -> 캐릭터 이동시 가속/감속 적용, 자연스러운 움직임 구현.
           
           
    + Event Dispatcher
       - Onlanded
           - 캐릭터가 공중에서 바닥으로 착지시 타 컴포넌트 등에서 조절하였던 Character Movement :: Jumping/Falling 값 초기화 목적.
           - 캐릭터가 바닥으로 착지 시 착지 모션 수행 목적.
       - OnHitted
           - 플레이어가 피격시 타 컴포넌트 등에 BroadCasting 목적.
           - 해당 BroadCast로 타 컴포넌트에서 수행중인 기능 중 피격시 정지될 기능들 초기화.


    + Camera
        - Camera PostProcess
            - Vigntte
              - 은신, 일부 무기의 조준시 해당 효과 적용하여 몰입감 부여.                   
            - DepthOfField
              - 일부 무기의 조준시 조준하고 있는 타겟에게 초점 부여, 그 외의 영역은 약간의 Blur 처리.
              - 해당 기능 활성화시 플레이어 카메라 기준 정면으로 LineTrace, 해당 반환값 중 Distance를 활용하여 DepthOfField 수치 조정.
              - 충돌되는 Actor가 없는 경우 기본 DOF 수치 이용.
        - SpringArm
             - Use Pawn Control Rotation 변수 활용.
               - 무기에 따라 카메라 Rotation과 캐릭터 Rotation을 일치시켜 캐릭터 회전 구현.
               - 해당 옵션을 활성화 한 무기들의 경우 카메라의 방향과 캐릭터 전방방향이 일치 -> 마우스와 플레이어 방향 일치.
               - 해당 옵션을 비활성화 한 무기들의 경우 카메라의 방향과 캐릭터 전방방향 일치 -> 카메라와 플레이어 방향 독립적으로 이동.
             - Enable Camera Lag 변수 활용.
               - 카메라 회전시 자연스러운 이동.
             - 마우스 휠 입력을 통해 Target Arm Length 변경.
               - 최대/최소값, Interp Speed는  구조체로 정의하여 설정.
               - FInterpTo함수 이용하여 Target Arm Length 변수 부드럽게 변경.
               - 매개변수로는 GetWorldDeltaSeconds할당.
                    

    + UI
        - 공통
             - Overlay 이용하여 모니터 크기와 무관하게 일정 비율의 위치에 출력되도록 함.  
             - Border 이용하여 아이콘의 BackGround 구현.
             - 필요한 경우 Grid 활용하여 정렬.
        - Player HP/MP/Stamina Bar
             - Tick Event마다 플레이어의 HP/MP/Stamina 수치를 불러와서 적용.(캐릭터의 LifeComponent 내부에 해당 변수들 정의.)
             - DynamicMaterial 이용하여 UI의 구슬 채워진 정도 조절.
             - 최대 수치/현재 수치 TextBar 이용하여 설정.
        - Boss HPBar
             - 해당 클래스에 매개변수로 출력할 적 클래스 변수 정의.
             - 해당 UI가 생성될 때 현재 맵에 존재하는 적 클래스 변수 액터의 HP 수치를 불러와 적용.(보스 캐릭터 기준이므로 한개의 스폰된 객체 존재한다 가정, 해당 Boss의                          LifeComopnent 내부에 해당 변수 정의.)
             - Progress Bar 이용하여 보스 몬스터 체력 표기.
             - Set Timer By Event 이용하여 보스 몬스터 체력 갱신.
        - Aim
             - TintColor 이용하여 조준된 적 존재시 색상 빨간색으로 변경.
             - TintColor 이용하여 조준된 적이 없는 경우 색상 흰색으로 변경.
        - Weapon
             - ctrl 키 입력시 게임 플레이 정지 후, UI창 등장.
             - 마우스 커서 활성화 되며, 등장하는 아이콘 클릭시 해당 무기로 변경(플레이어 캐릭터의 WeaponComopnent 내부 함수 호출하여 구현.)
             - 무기 아이콘 위로 마우스 올라가면 OnHorvered 이벤트 발생 -> 해당 아이콘의 Background BrushColor 색상 변경하여 효과 부여.
             - 무기 아이콘 바깥으로 마우스 이동시 OnUnhorvered 이벤트 발생 -> 해당 아이콘 Background BrushColor 색상 변경하여 효과 부여.
             - 변경할 무기 선택시 게임 플레이 재개, UI창 소멸.
        - Warp
             - 구조물에 접촉시 OpenLevel 이용하여 레벨 오픈.
             - UI창 이용하여 Fade In/Out 구현. (Timeline 이용하여 Alpha 값 조정.)
             - 현재는 로직 스레드에서 맵 이동.
             - Level Streaming 이용하여 비동기 로딩 구현 진행.
             
             
   ## Enemy Character
    + 공통
        - Behavior Tree
            - BlackBoard
            - BehaviorTree Service
            - BehaviorTree Decorator
            - BehaivorTree Sequence
            - BehaviorTree Selector
           
        - AIController
            - AI Perception
                - Sight
                - Hearing
        - NaviMesh
    + Normal Enemy
    + Boss
       - EQS
            - 공격 진행시 EQS 활용하여 적절한 위치 산출 후, 해당 위치로 이동하면서 공격.
       - MovementMode::Fly
            - 
       - BehaviorTree SimpleParallel          
    

## 공통 요소
    + Interface
        - Damage
            - 플레이어가 공격시 무기와 Overlap Event 발생한 Actor에 Damage 인터페이스 이용하여 전달.
            - 인터페이스가 구현되지 않은 액터는 무시됨.
    + Animation
        - Animation Blending
            - Blend In/Out
                - 애니메이션 Blending이 없는 경우 애니메이션 변경간 특정 시점을 기준으로 애니메이션이 끊겨서 변경되는것으로 보임.
                - Blend In/Out에 따라 기존 애니메이션과 변경될 애니메이션의 보간이 일어나 부드러운 애니메이션 변경이 이루어짐.
        - Animation Layering
            - Locomotion
                 - 기본적인 캐릭터 움직임.
                 - 각 무기에 따른 BlendSpace 선택 후, 해당 모션 출력.
            - Hand
                 - 캐릭터의 Hand IK 목적.
                 - 2 Bone IK
            - Feet
                 - 캐릭터의 Foot IK 목적.
                 - 2 Bone IK
                 - 플레이어의 (Foot Bone.x, Foot Bone.y, Pelvis.z) 에서 (0, 0, -1) 방향으로 Linetrace, 길이는 Character의 Half Collision
                 - 두 값의 차를 구하여 해당 값만큼 Foot 이동.
            - Bow
               
        - Animation Montage
            - Montage Section
                 - 몽타주의 구간을 분할.
                 - 필요에 따라 특정 구간 루프 기능 가능.
                 - 지속 공격등 구현시 지속될 구간 Looping하여 구현하였으며, 종료시 해당 loop 탈출 하는 방식으로 구현.
            - Anim Slot Manager
                 - 크게 Upper Body/Full Body 로 나뉘어짐.
                 - Upper Body 는 Bone Blend 이용하여 상체에만 영향을 미치도록 구현.
                 - FullBody는 전체 구조에 영향을 미치도록 구현.
                 - Locomotion -> Upper Body -> Full Body 순으로 영향을 미침.
        - Inverse Kinematics
            - Two Bone IK
            - Anim Curve
                 - Foot IK 구현시 전 구간 IK를 적용하면 캐릭터의 발이 과도하게 바닥에 붙어 있는 현상 발생.
                 - Anim Curve 이용하여 애니메이션의 특정 구간에만 IK가 적용되도록 구현.
        - Bone Transform
                 - 플레이어 캐릭터의 카메라 Rotation과 플레이어 캐릭터의 Bone(Neck) Rotation을 일치시킴.
                     -> 플레이어가 바라보는 방향을 캐릭터도 바라보게 구현.
                 - 카메라의 위치가 플레이어의 전방에 존재하는 경우 플레이어가 카메라를 바라보도록 구현.
                     -> 외적을 이용하여 전/후방 구분.
        - BlendSpace
            - Aim Offset
            - 1D/2D           
        - Anim Notify/Anim Notify State
            - Notify Trigger Mode
        - Animation Retargeting
        - CashPose
        - RootMotion
        - Addictive Animation
    + Sound
        - Sound Queue
            - Attenuation
    + Particle
        - Particle System
        - Niagara Particle System
    + Component Based Development
        - Weapon
        - Targeting
        - Vihicle
        - WebShooting
        - Sneak
        - Parkour
        - MiniMap
        -> Decoupling Pattern

맵
=============

* LevelStreaming
    + Asynchronous Loading
* SkySphere
* Landscape
    + Procedural Foliage
        - Procedural Foliage Spawner
            - Tree/Grass
                - LOD
                - Material
                    - MaterialParameterCollection
                    - Perlin Noise
                    - Material Instance
                    - Material Function
                    
        -> Instancing Pattern
        -> FlyWeigh Pattern
        
    + Landscape Material
        - World Displacement
    + Landscape Layering
        - Physical Material
        -> Texture Splatting
        
    + World machine
    + NavMeshVolume
