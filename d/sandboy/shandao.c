// Room: /d/sandboy/shandao 
#include <ansi.h>
inherit ROOM; 
 
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG
����һ���ľ���ɽ����̫��ů�������ͷ�ϣ�Ϫˮ�����õ��ڽű������� 
С���������ŷɹ���Զ�����֣�ǰ��·���и����� 
LONG);

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
  "west" : __DIR__"shandao2",
  "south" : __DIR__"shandao1",
  "northdown":__DIR__"sidehill",
]));

  setup();
}
void init()
{
   message("vision",HIC+"��Զ���������д���һ�ɿ�������ζ!\n"+NOR,this_object());
}
