 /*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        object snow, lotus;
        set("short", "��ɽɽ��");
        set("long", @LONG
������ɽ������߷岩���壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ���嶥����
�ݺᣬ����������ڲ������ɽ����һ������������С������ˮ��Σ���ӳ��
������ƣ����б��弰�Ծ����̵����֣����˸е����޵�������
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"gela",
  "northup" : __DIR__"tianchi",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
        __DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",1990);
        set("coor/z",0);
        setup();
        snow = new(__DIR__"obj/snow");
        lotus= new(__DIR__"obj/lotus");
        snow->move(this_object());
        lotus->move(snow);
} 
