// Room: /d/japan/liusheng
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
һ��յ����ķ���,����Ӣ�۾��ڷ����м�,������ǰ����һ�Ű���,
������һ��δ�����Χ��,�ű߷���һ�ѽ�,���ھ���ʹ��,���п����Ѿ�
�ܾ���.
LONG);
  set("objects",( [ /* sizeof() == 1 */
    __DIR__"npc/li":1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"zoulang",
]));
  setup();
}
