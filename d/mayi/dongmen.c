// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���������������򣬺�ͻ�ʽ������������ǵֿ�ͻ�ʵĵ�һ�����ߣ�
�峯�������ռ����У�ͻ�ʳ�ʽ���������أ����ط�����ͻ�ʽ���
��ԭ����ͷ�������ŵĹٱ���ϸ���̲������Ŀ��̣�һ˿���Ҵ��⡣
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "west" : __DIR__"dongjie",
                "southup" : __DIR__"changcheng11",

	]));
set("objects",([
  __DIR__"npc/bing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	replace_program(ROOM);
}
