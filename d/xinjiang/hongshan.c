 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
��ɽ��ɽ�ʺ��ɫ������ɽ���Ǻܸߣ�Ҳ���Ǻ���ΰ�������Ǻ�������
ɽ����һ�����ơ�������������������Կ���Զ���ĳ��źͳ���Ĵ��̡�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhenlong",
  "southdown" : __DIR__"tulu",
  "southup" : "/d/zangbei/echu",
   
])); 
        set("objects", ([
        "/clone/npc/man" : 1,
        ]) ); 
        
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",2130);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}      
