// Room: /d/japan/haixian
inherit ROOM;

void create()
{
  set ("short", "���ʹ�");
  set ("long", @LONG
���Ŵֲ���������ͷ�����Ű�ë��.��ʱ�����ڴ����е���ʮ������
֮��.�ձ��Ǹ�����,�����Ǻܱ��˵�.������Ƭ����Ҳȷʵͦ��.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedaos",
]));
   set("objects",( [ /* sizeof() == 1 */
      __DIR__"npc/paotang":1,
]));
  setup();
           replace_program(ROOM);
}
