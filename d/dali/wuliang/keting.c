// Room: keting.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ٹȵ�����������һ������������������ʯ�̵ĵأ����߿�ǽ����
�ĵ�ǹ�ܣ�ʮ�˰����������ȫ������һ�Ű��������������һյ���Ա��ǹ�
������̫ʦ�Ρ�
LONG
        );
        set("exits", ([
            "east" : __DIR__"xiangfang",
            "north" : __DIR__"guzhong",
        ]));

        set("objects", ([
              __DIR__"npc/zhong_wanchou" : 1,
        ]));

        setup();
}

int valid_leave(object me,string dir)
{ 
     if( me->query("gender") == "����"
      && dir == "east"
      && (present("zhong wanchou", environment(me))))
         return notify_fail("�������ǰ��ס���ȥ·������С����Ҫ���ҷ���������\n");
         return ::valid_leave(me, dir);
}
