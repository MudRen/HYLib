
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
������һƬ֦��Ҷï�İ����֣����ݳ��ñ�ض��ǣ�������ԭʼ
�����֣����ƺ���ʧ�˷���
LONG
);
    set("exits", ([
       "northeast" :__DIR__"boshulin2",
       "southeast" :__DIR__"boshulin2",
       "east" :__DIR__"boshulin2",
       "north" :__DIR__"boshulin2",
       "south" :__DIR__"boshulin3",
       "northwest" :__DIR__"boshulin1",
       "southwest" :__DIR__"boshulin2",
       "west" :__DIR__"boshulin2",
]));
    setup();
    replace_program(ROOM);
}
