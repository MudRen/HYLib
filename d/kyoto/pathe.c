//Room: /d/feitian/path3.c
inherit ROOM;

void create()
{
   set ("short", "��·");
  set ("long", @LONG
һ�������Ļ��������Զ�����쿪ȥ��������һƬԭʼɭ�ֲ�
ͣ�Ĵ��������Ǻ���������������Ļʶ�����������
LONG);

  set("exits", ([ /* sizeof() == 1 */
      "east" : "d/feitian/path3",
      "west" : __DIR__"dongmen",
]));
  set("outdoors", "/d/japan");
  setup();
        replace_program(ROOM);
}
