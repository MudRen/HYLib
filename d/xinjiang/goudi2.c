 /*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������߳�������������ʹ��ʢ��������������¶�Ҳ�൱�ͣ�
һ�������紵��������ȫ����ʱ�䳤�ˣ�����е����䡣����һ��
���������ֵ����֮�⣬�������Ǿ�������ľ���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"goudi",
  "east" :  __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/venomsnake" : 2,
        __DIR__"npc/bandit" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1090);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
