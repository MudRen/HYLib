// Room: /d/japan/yijiguan
inherit ROOM;

void create()
{
  set ("short", "�ռ˹�");
  set ("long", @LONG
һ��װ�εúܵ��ŵķ���,��ΪѬ������ʹ�����Ե���Щ����.�м�
�İ�������һ����,�����Ů�������ղ������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedao",
]));
         set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/dashou" : 3,
                __DIR__"npc/mamasang" : 1,
]));
  setup();
        replace_program(ROOM);
}
