 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��·");
        set("long", @LONG
��ԭ�ϵ�һ���������۵���·������һ��ĬĬ��Ϫ�����ңɣ֣ţң���
�峺��Ϫˮ��ʹ�˸е�һ��������Ϣ����ΧȺɽ�������ˮ���ѣ����������
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"hongshan",
  "south" : __DIR__"beimen",
]));
        set("objects", ([
        __DIR__"npc/baiyi" : 1,
        "/d/zangbei/npc/xuedahan" : 1,
                        ]) );

        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","�峺��Ϫˮ");
        set("liquid/container", "Ϫ��");
        set("coor/x",-1120);
        set("coor/y",2120);
        set("coor/z",0);
        setup();
} 

