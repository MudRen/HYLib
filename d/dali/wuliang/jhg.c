// Room: jhg.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"������"NOR);
	set("long", @LONG 
�������Ŷ��ˣ������Ǹ���ʮ���ҵ�������ã������Ǹ���ʮ��������ߡ�
���׽��������������Ǳ�����ʿ�������е��Ƕ������������˹�ͬ���������
��֤�ˣ���������ǰ������ļα�����Щ�˶������������е�֪��֮ʿ��
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"wlj",
	    "north" : __DIR__"houyuan",
            "west" : __DIR__"xlgong",
            "east" : __DIR__"dlgong",
        ]));
        set("objects", ([
                __DIR__"npc/zuo_zimu" : 1,
                __DIR__"npc/xin_shuangqing" : 1,
                __DIR__"npc/gong_guangjie" : 1, 
        ]));

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir != "south"
      && (present("gong guangjie", environment(me))))
         return notify_fail("�������ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
     if( dir != "south"
      && (present("xin shuangqing", environment(me))))
         return notify_fail("��˫����ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
     if( dir != "south"
      && (present("zuo zimu", environment(me))))
         return notify_fail("��������ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
         return ::valid_leave(me, dir);
}
