inherit ROOM;
void create()
{
        set("short", "С�ƹ�");
        set("long", @LONG
���������ڳ�����һ��С�ƹݡ���ĺ�Զ�����ŵ�����Ʈ����������Ӷ�
�˿���������ЪЪ�����ԵĺȵĶ�������·�����������ӵ��ǲ��ᵽ����ġ�
LONG );
        set("exits", ([
                "south" : __DIR__"stxijie2",       	
	]));

	set("objects", ([
                __DIR__"npc/paotang" : 1,
      	]));

	setup();
}
