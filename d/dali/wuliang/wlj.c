// Room: wlj.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "ʯ��·");
	set("long", @LONG
������һ��������ʯ��·�ϡ�������һ�׼����ľ޴�ʯ��������ɵģ���
�Բ���ʮ������Ҳ�������⡣�����ǲ���Űأ�ֱ�����죬�϶������������
����ա�·�ľ�ͷ�����ǽ������ˡ�
LONG
	);
	set("exits", ([ 
	    "out" : __DIR__"wljmen",
	    "north" : __DIR__"jhg",
            "west" : __DIR__"xting",
            "east" : __DIR__"dting",
        ]));
        set("objects", ([
              __DIR__"npc/rong_ziju" : 1, 
        ]));
        set("outdoors", "����");

	setup();
}

int valid_leave(object me,string dir)
{ 
     if( dir != "out"
      && (present("rong ziju", environment(me))))
         return notify_fail("���Ӿ���ǰ��ס���ȥ·���������صأ��κ��˲����������ڡ�\n");
         return ::valid_leave(me, dir);
}
