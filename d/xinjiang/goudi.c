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
  "west" : __DIR__"baiyang",
  "east" :  __DIR__"goudi2",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
        __DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1100);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
