// Room: /d/japan/jiedaoe2
inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
һ�������Ľֵ�,������һ�䷿�����������ע��,����һ���С��
����.���������ŹŹֵķ�.����ĵ����ſڹ��˴���ɫ����.�������˸�
��һ�����Ī���ֲ�.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guancai",
  "south" : __DIR__"zhanbu",
  "east" : __DIR__"jiedaoe3",
  "west" : __DIR__"jiedaoe1",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
