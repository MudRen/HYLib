// Room: /u/zqb/tiezhang/shuijing.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", HIM"����Ȫ"NOR);
	set("long", @LONG
    ����ǰ�У�һ·���̺���ϣ���ɽ��Ұ�����ʻ������������Ѽ���
ת��һ�����ԣ���ǰ����һ��Ȫˮ��Ȫˮ�峺���ף�ɢ����һ��������Ƣ�� 
������Ȫˮ���Աߣ�����һȺȺ�ĺ������򻨻�ף���ڻ��ϣ��������衣 
��������η�ˣ��ɽ�ʱ�������ǵ�����ͣ����
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"guajia",
]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
