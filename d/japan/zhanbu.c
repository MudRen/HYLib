// Room: /d/japan/zhanbu
inherit ROOM;

void create()
{
  set ("short", "ռ����");
  set ("long", @LONG
һ��СС�ķ���,���ӵ��ı������˸��ַ�¼,�ڷ����м���һ����
ɫ�Ĵ�ԲȦ.һ��������Ů�Ӿ����ȶ���������.˫�����Ÿ�ˮ����,����
��ǰ��Զ�ĵط�,����һ֧������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedaoe2",
]));
  set("objects",( [ /* sizeof() == 1 */
  __DIR__"npc/nuwu":1,
]));
  setup();
        replace_program(ROOM);
}
