 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ϳǿ�");
  set("long",@LONG
������Ǽ��ϳǵ���ڣ����˼��ϳǣ������̱�һ��ŨŨ����³������������
����������ǿ�ѧ֮�磬���ϳǵĴ�������˳�֮Ϊ�׵������ϡ����ס�������
�׸������֣��޴�������Բ�����Ŀ׼ҷ緶����Ⱦ����������ؤ�����ɰ��
���ÿ��ˡ�
LONG
  );
  set("exits",([
                 "west"  :  "/d/xuzhou/dadao1",
                 "south" : __DIR__"street1",
               ]));
    set("outdoors", "jinan");
        set("coor/x",30);
        set("coor/y",1990);
        set("coor/z",1);
        setup();
    replace_program(ROOM); 
}       
