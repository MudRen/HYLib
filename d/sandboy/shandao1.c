// Room: /d/sandboy/shandao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ���ľ���ɽ����̫��ů�������ͷ�ϣ�Ϫˮ�����õ��ڽű�������
С���������ŷɹ���Զ�����֣�·�Ķ����и�����
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("item_desc", ([ /* sizeof() == 3 */
  "����" : "һƬ�����֣���Լ�кü�ʮ�á�
",
  "����" : "Զ��ȥ���������ҡҡ��׹����ʱ������̣������
",
  "Ϫˮ" : "ɽȪ�Ӹߴ����£��γɵ�СϪ����
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pomiao",
  "north" : __DIR__"shandao",
]));

	setup();
}
void init()
{
  tell_room(__DIR__"pomiao",HIC+"�����⴫��һ��Ų���!\n"+NOR);
}
