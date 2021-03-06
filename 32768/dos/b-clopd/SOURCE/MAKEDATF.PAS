USES Dos,Crt,ModiGraf;
CONST MaxFiles=1000;
      BackList='BackGrnd.lst';
      BackFile='BackGrnd.PAK';
      MidiList='Midis.lst';
      MidiFile='Midi.PAK';
      ObjList='ObjList.lst';
      ObjFile='ObjFile.PAK';
      PlFile='Player.PAK';
{      OtherList='Other.LST';
      OtherFile='Other.PAK';}
      MOtionList='Motion.lst';
      MotionFile='Motion.PAK';
      DataDir='DATA';

      MaxPlSpr=5;
      PreFix:ARRAY[1..MaxPlSpr]OF STRING=('w_','ma_','so_','ak_','yo_');

TYPE tVersion=ARRAY[1..4]OF Char;
CONST AktVersion:tVersion='IMG2';
TYPE tHeader=RECORD
              Version:tVersion;
              XSize,YSize:LongInt;
            END;
     tSprite=RECORD
               XSize,YSize:LongInt;
               XMid,YMid:LongInt;
               Dat:^tScreen;
             END;
VAR
    Header:tHeader;
    Files:LongInt;
    MSize:LongInt;
    SR:SearchRec;
    FName,OldDir:STRING;
    OutPas,T:Text;
    FI,FO:FILE;
    Temp:tSprite;
    I,K,M:LongInt;

PROCEDURE LoadSprite(VAR Sprite:tSprite;St:STRING);
VAR I,K,M:LongInt;
    F:FILE;
BEGIN
  Assign(F,ST);
  ReSet(F,1);
  BlockRead(F,Header,SizeOf(THeader));
  WITH Sprite DO BEGIN
    IF Dat<>NIL THEN FreeMem(Dat,XSize*YSize);
    XSize:=Header.XSize;
    YSize:=Header.YSize;
    XMid:=XSize DIV 2;
    YMid:=YSize DIV 2;
    GetMem(Dat,XSize*YSize);
    BlockRead(F,Dat^,XSize*YSize);
  END;
  Close(F);
END;

PROCEDURE WriteRaw(St:STRING);
VAR I,K,M,N,O,S:LongInt;
    A,B,W:Byte;
    Wo:Word;
    F:FILE;
BEGIN
  WriteLn('Coding ',St);
  Assign(F,St);
  ReSet(F,1);
  FOR I:=1 TO 4 DO BlockRead(F,B,1);
  BlockRead(F,S,4);
  Wo:=S;
  BlockWrite(FO,Wo,2);
  BlockRead(F,S,4);
  Wo:=S;
  BlockWrite(FO,Wo,2);
{  BlockRead(F,W,1);
  A:=1;}
  WHILE NOT EoF(F) DO BEGIN
    BlockRead(F,B,1);
    BlockWrite(FO,B,1);
{    BlockRead(F,B,1);
    IF(B=W)AND(A<63)THEN Inc(A)
                     ELSE BEGIN
                       IF(A=1)AND(W AND $c0<>$c0)THEN BEGIN
                         BlockWrite(FO,W,1);
                       END ELSE BEGIN
                         A:=$c0 OR A;
                         BlockWrite(FO,A,1);
                         BlockWrite(FO,W,1);
                         W:=B;
                         A:=1;
                       END;
                     END;}
  END;
{                       IF(A=1)AND(W AND $c0<>$c0)THEN BEGIN
                         BlockWrite(FO,W,1);
                       END ELSE BEGIN
                         A:=$c0 OR A;
                         BlockWrite(FO,A,1);
                         BlockWrite(FO,W,1);
                         W:=B;
                         A:=1;
                       END;}
  Close(F);
END;

PROCEDURE WriteOptSprite(ST:STRING);
VAR X1,X2,Y1,Y2,I,K,M,R,XM,YM,X,Y:LongInt;
    W:Word;
    F:FILE;
    Bool:Boolean;
BEGIN
  WriteRaw(St);
  Exit;
  LoadSprite(Temp,St);
  WITH Temp DO BEGIN
{    WriteLn('Old : ',XSize,', ',YSize);}
    XM:=XSize DIV 2;
    YM:=YSize DIV 2;
    IF XSize>YSize THEN R:=XM
                   ELSE R:=YM;
    REPEAT
      Dec(R);
      Bool:=False;
      FOR Y:=-R TO R DO BEGIN
        X:=Round(Sqrt(Sqr(R)-Sqr(Y)));
        FOR I:=0 TO XM-X DO
          IF(YM+Y>=0)AND(YM+Y<YSize)AND(I>=0)AND(I<XSize)AND
            (Dat^[(YM+Y)*XSize+I]<>0)THEN Bool:=True;

        FOR I:=XM+X TO XSize-1 DO
          IF(YM+Y>=0)AND(YM+Y<YSize)AND(I>=0)AND(I<XSize)AND
            (Dat^[(YM+Y)*XSize+I]<>0)THEN Bool:=True;
      END;
    UNTIL (R=1)OR(Bool);
    Inc(R);
    X1:=XM-R;IF(X1<0)THEN X1:=0;IF(X1>=XSize)THEN X1:=XSize-1;
    X2:=XM+R;IF(X2<0)THEN X2:=0;IF(X2>=XSize)THEN X2:=XSize-1;
    Y1:=YM-R;IF(Y1<0)THEN Y1:=0;IF(Y1>=YSize)THEN Y1:=YSize-1;
    Y2:=YM+R;IF(Y2<0)THEN Y2:=0;IF(Y2>=YSize)THEN Y2:=YSize-1;
{    WriteLn(X1,', ',X2,', ',Y1,', ',Y2);
    IF ReadKey=#27 THEN Halt(0);}
    X:=X2-X1+1;
    Y:=Y2-Y1+1;
    W:=X;
    BlockWrite(FO,W,2);
    W:=Y;
    BlockWrite(FO,W,2);
    FOR K:=Y1 TO Y2 DO
      FOR I:=X1 TO X2 DO
        BlockWrite(FO,Dat^[K*XSize+I],1);
{    WriteLn('New : ',X,', ',Y);
    IF ReadKey=#27 THEN Halt(0);}
  END;
END;

PROCEDURE WriteRRaw(St:STRING);
VAR I,K,M,N,O:LongInt;
    A,B,W:Byte;
    F:FILE;
BEGIN
  WriteLn('Coding ',St);
  Assign(F,St);
  ReSet(F,1);
  WHILE NOT EoF(F) DO BEGIN
    BlockRead(F,B,1);
    BlockWrite(FO,B,1);
  END;
  Close(F);
END;

PROCEDURE MakeNewDat(ProcName,FileN:STRING);
VAR T:TexT;
    F:FILE;
    I,K,M:LongInt;
    B:Byte;
BEGIN
  Assign(F,FileN);
  ReSet(F,1);
  WriteLn(OutPas,'PROCEDURE '+ProcName+';ASSEMBLER;');
  Write(OutPas,'  ASM');
  M:=0;
  WHILE NOT EoF(F) DO BEGIN
    BlockRead(F,B,1);
    IF M MOD 10=0 THEN BEGIN
      Write(OutPas,';');
      WriteLn(OutPas);
      Write(OutPas,'    db ',B);
    END ELSE Write(OutPas,',',B);
    Inc(M);
  END;
  WriteLn(OutPas);
  WriteLn(OutPas,'  END;');
  Close(F);
END;


PROCEDURE Convert;
VAR T:TexT;
    F:FILE;
    I,K,M:LongInt;
    B:Byte;
BEGIN
  Assign(OutPas,'DataFile.PAS');
  ReWrite(OutPas);
  WriteLn(OutPas,'UNIT DataFile;');
  WriteLn(OutPas,'INTERFACE');
  WRITELN(OutPas,'PROCEDURE PlDAT;');
  WRITELN(OutPas,'PROCEDURE MidIngame;');
  WRITELN(OutPas,'PROCEDURE MidBoss;');
  WRITELN(OutPas,'PROCEDURE MidDead;');
  WRITELN(OutPas,'PROCEDURE MidOver;');
  WRITELN(OutPas,'PROCEDURE MidWon;');
  WRITELN(OutPas,'PROCEDURE MidIntro;');
  WriteLn(OutPas,'PROCEDURE PaletteDAT;');


  WRITELN(OutPas,'PROCEDURE ObjDAT;');
  WRITELN(OutPas,'PROCEDURE BackGroundDAT;');
  WRITELN(OutPas,'PROCEDURE MotionDAT;');
  WriteLn(OutPas,'PROCEDURE IntroLev;');
  WriteLn(OutPas,'PROCEDURE Level1;');
  WriteLn(OutPas,'PROCEDURE Level2;');
  WriteLn(OutPas,'PROCEDURE Level3;');
{  WriteLn(OutPas,'PROCEDURE LevelS;');}

  WriteLn(OutPas,'IMPLEMENTATION');
  MakeNewDat('PlDAT',PlFile);
  MakeNewDat('ObjDAT',ObjFile);
  MakeNewDat('BackGroundDAT',BackFile);
  MakeNewDat('IntroLev','DATA\intro.LVL');
  MakeNewDat('Level1','DATA\level1.LVL');
  MakeNewDat('Level2','DATA\level4.LVL');
  MakeNewDat('Level3','DATA\boss.LVL');
{  MakeNewDat('LevelS','DATA\secret.LVL');}
  MakeNewDat('MotionDAT',MotionFile);
  MakeNewDat('MidIngame','data\ingame2.mid');
  MakeNewDat('MidBoss','data\Boss.mid');
  MakeNewDat('MidDead','data\SMwlose.MID');
  MakeNewDat('MidOver','data\smb-go.mid');
  MakeNewDat('MidWon','data\smb-dd.mid');
  MakeNewDat('MidIntro','data\papnew.mid');
  MakeNewDat('PaletteDAT','DATA\Palette.DAT');


  WriteLn(OutPas,'BEGIN');
  WriteLn(OutPas,'END.');
  Close(OutPas);

{  Assign(OutPas,'DataFil2.PAS');
  ReWrite(OutPas);
  WriteLn(OutPas,'UNIT DataFil2;');
  WriteLn(OutPas,'INTERFACE');
  WRITELN(OutPas,'PROCEDURE ObjDAT;');
  WRITELN(OutPas,'PROCEDURE BackGroundDAT;');
  WRITELN(OutPas,'PROCEDURE MotionDAT;');
  WriteLn(OutPas,'PROCEDURE IntroLev;');
  WriteLn(OutPas,'PROCEDURE Level1;');
  WriteLn(OutPas,'PROCEDURE Level2;');
  WriteLn(OutPas,'PROCEDURE Level3;');
  WriteLn(OutPas,'PROCEDURE LevelS;');
  WriteLn(OutPas,'IMPLEMENTATION');
  MakeNewDat('BackGroundDAT',BackFile);
  MakeNewDat('ObjDAT',ObjFile);
  MakeNewDat('IntroLev','DATA\INTRO.LVL');
  MakeNewDat('Level1','DATA\level1.LVL');
  MakeNewDat('Level2','DATA\level4.LVL');
  MakeNewDat('Level3','DATA\boss.LVL');
  MakeNewDat('LevelS','DATA\secret.LVL');
  MakeNewDat('MotionDAT',MotionFile);
  WriteLn(OutPas,'BEGIN');
  WriteLn(OutPas,'END.');
  Close(OutPas);}
END;

PROCEDURE List2File(ListSt,OutSt,Suffix:STRING;IsIMG:Boolean;OptImg:Boolean);
VAR
    T:Text;
BEGIN
  GetDir(0,OldDir);
  ChDir(DataDir);
  Assign(FO,'..\'+OutST);
  ReWrite(FO,1);
  Assign(T,'..\'+ListSt);
  ReSet(T);

  WHILE NOT EoF(T) DO BEGIN
    ReadLn(T,FName);
    IF IsIMG THEN BEGIN
               IF OptIMG THEN WriteOptSprite(FName+Suffix)
                         ELSE WriteRaw(FName+Suffix);
             END ELSE WriteRRaw(FName+Suffix);
  END;
  ChDir(OldDir);
  Close(T);
  Close(FO);

END;

PROCEDURE Pl2File(OutSt:STRING);
VAR
    T:Text;
    I,K,M:LongInt;
BEGIN
  GetDir(0,OldDir);
  ChDir(DataDir);
  Assign(FO,'..\'+OutST);
  ReWrite(FO,1);
  FOR I:=1 TO MaxPlSpr DO BEGIN
    WriteOptSprite(PreFix[I]+'Body.img');
    WriteOptSprite(PreFix[I]+'Head.img');
    WriteOptSprite(PreFix[I]+'Foot.img');
    WriteOptSprite(PreFix[I]+'Fist.img');
{    WriteRaw(PreFix[I]+'Body.img');
    WriteRaw(PreFix[I]+'Head.img');
    WriteRaw(PreFix[I]+'Foot.img');
    WriteRaw(PreFix[I]+'Fist.img');}
  END;
  ChDir(OldDir);
  Close(FO);

END;


BEGIN
  Temp.Dat:=NIL;
  ClrScr;
{ VORSICHT WEGEN IMAGEWRITE BEI WriteRAW }
  List2File(MidiList,MidiFile,'',False,False);
  List2File(BackList,BackFile,'.Img',True,False);
  List2File(ObjList,ObjFile,'.Img',True,True);
  List2File(MotionList,MotionFile,'.mot',False,False);
  Pl2File(PlFile);
{  List2File(OtherList,OtherFile,'',False,False);}

  Write('Converting ... ');
  Convert;
  WriteLn('Done');
END.