#include <ansi.h> 

inherit ROOM;

void create()
{
	set("short", "��Һ���");
	set("long", @LONG
��������ҵĺ��������ڷǳ��Ŀ����������аڷ�����
������������ǽ���Ϲ���һЩ�ֻ���ֻ��һ����ɫ͸�ƣ�����
������ݸ߸����������ã����ǡ���������˷
LONG);
	set("exits", ([
  		"west"  : __DIR__"miaojia_zoulang1",
  		"north" : __DIR__"miaojia_zoulang2",
  		"south" : __DIR__"miaojia_shufang",
	]));
        set("objects", ([
                CLASS_D("miao") + "/miao" : 1,
                "/quest/menpai/newmp/shi7" : 1,
                "/d/biwu/champion_hj" : 1,


        ]));

        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("coor/x", -180);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        "/clone/board/miao_b"->foo();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "north" || dir == "south")
        {
                if ((string)me->query("family/family_name") != "�������"
                & objectp(present("miao renfeng", environment(me))))
                        return notify_fail(CYN "���˷�üͷ΢΢һ�壬�ȵ�������δ"
                                           "��̫�����������Ʋ�����ĳ����\n" NOR);
        }
        return ::valid_leave(me, dir);
}
