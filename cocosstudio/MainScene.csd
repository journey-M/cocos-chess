<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="21" Speed="1.0000" ActivedAnimationName="animation0">
        <Timeline ActionTag="1799543986" Property="Position">
          <PointFrame FrameIndex="0" X="190.6728" Y="252.8294">
            <EasingData Type="7" />
          </PointFrame>
          <PointFrame FrameIndex="21" X="764.8073" Y="361.3356">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1799543986" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="7" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1799543986" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="7" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="animation0" StartIndex="0" EndIndex="21">
          <RenderColor A="150" R="222" G="184" B="135" />
        </AnimationInfo>
        <AnimationInfo Name="animation1" StartIndex="0" EndIndex="21">
          <RenderColor A="150" R="147" G="112" B="219" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Default" ActionTag="953446860" Tag="5" IconVisible="False" LeftMargin="91.6492" RightMargin="-91.6492" TopMargin="-27.3851" BottomMargin="27.3851" ctype="SpriteObjectData">
            <Size X="960.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="571.6492" Y="347.3851" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5955" Y="0.5428" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="HelloWorld.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="chess_black_3" ActionTag="1799543986" Tag="6" IconVisible="False" LeftMargin="126.6728" RightMargin="705.3271" TopMargin="323.1706" BottomMargin="188.8294" ctype="SpriteObjectData">
            <Size X="128.0000" Y="128.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="190.6728" Y="252.8294" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1986" Y="0.3950" />
            <PreSize X="0.1333" Y="0.2000" />
            <FileData Type="Normal" Path="chess_black.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="chess_red_4" ActionTag="-89931748" Tag="7" IconVisible="False" LeftMargin="689.2156" RightMargin="142.7844" TopMargin="373.7379" BottomMargin="138.2621" ctype="SpriteObjectData">
            <Size X="128.0000" Y="128.0000" />
            <AnchorPoint ScaleX="0.4836" ScaleY="0.4918" />
            <Position X="751.1113" Y="201.2090" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7824" Y="0.3144" />
            <PreSize X="0.1333" Y="0.2000" />
            <FileData Type="Normal" Path="chess_red.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>