//Room: /d/feitian/path3.c
inherit ROOM;

void create()
{
   set ("short", "��·");
  set ("long", @LONG
һ�������Ļ��������Զ�����쿪ȥ��������һƬԭʼɭ�ֲ�
ͣ�Ĵ��������Ǻ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
      "east" : __DIR__"senlin1",
//      "west" : "d/kyoto/pathe",
]));
  set("outdoors", "feitian");
  setup();
        replace_program(ROOM);
}
