// Room: /d/changan/ca2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "�򸣾�¥");
        set("long", @LONG
��Զ����Ѿ������ġ��ơ�������ԭ�������������ǳ�����
���������򸣾�¥���������̶��������⣬һЩ�Ͼ��Ͽ�������Ҳ
ϲ������Сס������·���㻹�����и����ſ��Գ�ȥ��
LONG
);
        set("exits", ([
  "south" : __DIR__"ca18",
  "up" : __DIR__"ca3",
]));
        set("objects", ([
  __DIR__"npc/xiao-er" : 1,
]));

        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if (present("xiao er",environment(me))){
        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
        if ( me->query_temp("rent_paid") && dir == "south" && dir=="north" )
        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }
        return 1;
}

