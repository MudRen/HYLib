//road7.c

inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
    ������һ��������ʯ��·�ϣ����Թ������죬����������ǰ����
һƬ�����֣�����·һֱͨ���������������ں�����ģ��㲻�ɵ�Ĭ
������ӷ𡱡�
LONG    );
        set("exits", ([ /* sizeof() == 2 */
   "north" : __DIR__"songlin-1",
  "south" : __DIR__"yuhua1",

   
]));
        set("no_clean_up", 0);
        set("outdoors", "������");

        setup();
        replace_program(ROOM);
}
