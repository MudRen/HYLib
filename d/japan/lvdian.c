// Room: /d/japan/lvdian
inherit ROOM;

void create ()
{
  set ("short", "�õ�");
  set ("long", @LONG
����ÿ�����˵���һ������֮��,���ȵ�һ���¾���ס��.��������
��Ψһ��һ���ṩס�޷�����õ�.�����˶�,�㾭�������������һЩ
����.���Ҽ���������ȷ��.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"sleeproom",
  "west" : __DIR__"jiedao",
]));
        set("objects", ([ /* sizeof() == 1 */
             __DIR__"npc/daxiong" : 1,
]));

  setup();
        replace_program(ROOM);
}
